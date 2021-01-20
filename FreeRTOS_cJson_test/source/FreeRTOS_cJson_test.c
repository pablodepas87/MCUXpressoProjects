/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "fsl_sd.h"
#include "fsl_debug_console.h"
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "board.h"
#include "sdmmc_config.h"
#include "pin_mux.h"
#include <stdbool.h>
#include "fsl_iocon.h"
#include "fsl_power.h"
#include "../cJSON/cJSON.h"
#include <math.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_TASK_GET_SEM_BLOCK_TICKS 1U
#define DEMO_TASK_ACCESS_SDCARD_TIMES 1U
/*! @brief Task stack size. */
#define ACCESSFILE_TASK_STACK_SIZE (1024U)
/*! @brief Task stack priority. */
#define ACCESSFILE_TASK_PRIORITY (configMAX_PRIORITIES - 2U)

/*! @brief Task stack size. */
#define CARDDETECT_TASK_STACK_SIZE (1024U)
/*! @brief Task stack priority. */
#define CARDDETECT_TASK_PRIORITY (configMAX_PRIORITIES - 1U)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief SD card access task 1.
 *
 * @param pvParameters Task parameter.
 */
extern void board_init();
extern char* createJson();
extern void parseJson( const char *json_string);
/* task*/
static void saveJsonIntoFileTask(void *pvParameters);

static void parseJSONTask(void *pvParameters);

static void CardDetectTask(void *pvParameters);

static void SDCARD_DetectCallBack(bool isInserted, void *userData);

static status_t DEMO_MakeFileSystem(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static FATFS g_fileSystem; /* File system object */
static FIL g_fileObject;   /* File object */
static uint32_t s_taskSleepTicks = portMAX_DELAY;

/*! @brief SD card detect flag  */
static volatile bool s_cardInserted     = false;
static volatile bool s_cardInsertStatus = false;
static volatile	bool jsonCreated        = false;
static volatile	bool jsonParsed         = false;
/*! @brief Card semaphore  */
static SemaphoreHandle_t s_fileAccessSemaphore = NULL;
static SemaphoreHandle_t s_CardDetectSemaphore = NULL;
static TaskHandle_t parseJSONTask_Handle = NULL;
/*******************************************************************************
 * Code
 ******************************************************************************/
static void SDCARD_DetectCallBack(bool isInserted, void *userData)
{
    s_cardInsertStatus = isInserted;
    xSemaphoreGiveFromISR(s_CardDetectSemaphore, NULL);
}

static void CardDetectTask(void *pvParameters)
{
    s_fileAccessSemaphore = xSemaphoreCreateBinary();
    s_CardDetectSemaphore = xSemaphoreCreateBinary();

    BOARD_SD_Config(&g_sd, SDCARD_DetectCallBack, BOARD_SDMMC_SD_HOST_IRQ_PRIORITY, NULL);

    /* SD host init function */
    if (SD_HostInit(&g_sd) == kStatus_Success)
    {
        while (true)
        {
            /* take card detect semaphore */
            if (xSemaphoreTake(s_CardDetectSemaphore, portMAX_DELAY) == pdTRUE)
            {
                if (s_cardInserted != s_cardInsertStatus)
                {
                    s_cardInserted = s_cardInsertStatus;

                    /* power off card */
                    SD_SetCardPower(&g_sd, false);

                    if (s_cardInserted)
                    {
                        PRINTF("\r\nCard inserted.\r\n");
                       // jsonCreated = false;
                       // jsonParsed	= false;
                        /* power on the card */
                        SD_SetCardPower(&g_sd, true);
                        /* make file system */

                        if (DEMO_MakeFileSystem() != kStatus_Success)
                        {
                            continue;
                        }
                        xSemaphoreGive(s_fileAccessSemaphore);
                        s_taskSleepTicks = DEMO_TASK_GET_SEM_BLOCK_TICKS;
                    }
                }

                if (!s_cardInserted)
                {
                    PRINTF("\r\nPlease insert a card into board.\r\n");
                }
            }
        }
    }
    else
    {
        PRINTF("\r\nSD host init fail\r\n");
    }

    vTaskSuspend(NULL);
}

int main(void)
{
    board_init();

    PRINTF("\r\nSDCARD fatfs freertos example.\r\n");

    if (pdPASS != xTaskCreate(saveJsonIntoFileTask, "saveJsonIntoFileTask", ACCESSFILE_TASK_STACK_SIZE, NULL,
                              ACCESSFILE_TASK_PRIORITY, NULL))
    {
        return -1;
    }

    if (pdPASS != xTaskCreate(parseJSONTask, "parseJSONTask", ACCESSFILE_TASK_STACK_SIZE, NULL,
                              ACCESSFILE_TASK_PRIORITY, &parseJSONTask_Handle))
    {
        return -1;
    }

    if (pdPASS !=
        xTaskCreate(CardDetectTask, "CardDetectTask", CARDDETECT_TASK_STACK_SIZE, NULL, CARDDETECT_TASK_PRIORITY, NULL))
    {
        return -1;
    }

    /* Start the tasks and timer running. */
    vTaskStartScheduler();

    /* Scheduler should never reach this point. */
    while (true)
    {
    }
}

static status_t DEMO_MakeFileSystem(void)
{
    FRESULT error;
    const TCHAR driverNumberBuffer[3U] = {SDDISK + '0', ':', '/'};
    BYTE work[FF_MAX_SS];

    if (f_mount(&g_fileSystem, driverNumberBuffer, 0U))
    {
        PRINTF("Mount volume failed.\r\n");
        return kStatus_Fail;
    }

#if (FF_FS_RPATH >= 2U)
    error = f_chdrive((char const *)&driverNumberBuffer[0U]);
    if (error)
    {
        PRINTF("Change drive failed.\r\n");
        return kStatus_Fail;
    }
#endif

#if FF_USE_MKFS
    PRINTF("\r\nMake file system......The time may be long if the card capacity is big.\r\n");
    if (f_mkfs(driverNumberBuffer, 0, work, sizeof work))
    {
        PRINTF("Make file system failed.\r\n");
        return kStatus_Fail;
    }
#endif /* FF_USE_MKFS */

    return kStatus_Success;
}

static void saveJsonIntoFileTask(void *pvParameters)
{
    UINT bytesWritten   = 0U;
    FRESULT error;
    char *json_string;
    UINT count = 0;
    while (1)
    {
    	if(jsonCreated == false){
    		/* trying to take the file access semaphore */
    		if (xSemaphoreTake(s_fileAccessSemaphore, s_taskSleepTicks) == pdTRUE)
    		{
    			error = f_open(&g_fileObject, _T("studente.json"), FA_WRITE | FA_CREATE_NEW );
    			if (error != FR_EXIST )
    			{
    				json_string = createJson();
    				error = f_write(&g_fileObject, json_string, strlen(json_string), &bytesWritten);
    				if ((error) || (bytesWritten != strlen(json_string)))
    				{
    					PRINTF("Write file failed. \r\n");
    					break;
    				} else {
    					jsonCreated = true;
    				}
    				f_close(&g_fileObject);
    			}

    			xSemaphoreGive(s_fileAccessSemaphore);
    			vTaskDelay(1000U);
    		}
    		else
    		{
    			PRINTF("TASK1: file access is blocking.\r\n");
    		}
    	}
    }
    vTaskSuspend(NULL);
}

static void parseJSONTask(void *pvParameters)
{
	char *buffer = NULL;
	UINT filesize;
	UINT bytesRead;
    FRESULT error;


    while (1)
    {
    	if (jsonParsed == false) {
    		/* trying to take the file access semaphore */
    		if (xSemaphoreTake(s_fileAccessSemaphore, s_taskSleepTicks) == pdTRUE)
    		{
    			error = f_open(&g_fileObject, _T("studente.json"), FA_READ);
    			if (error)
    			{
    				PRINTF("Open file failed.\r\n");
    				break;
    			}

    			f_lseek(&g_fileObject, f_size(&g_fileObject)); // mi posiziono in fondo al file
    			filesize =f_tell(&g_fileObject);              // restituisce i byte dalla posizione del puntatore del file
    			f_rewind(&g_fileObject);                      // mi rimetto alla posizione 0

    			buffer = calloc(1,filesize+1);
    			error = f_read(&g_fileObject, buffer, filesize, &bytesRead);
    			if ((error) || bytesRead !=  filesize)
    			{
    				PRINTF("Read file failed. \r\n");
    				break;
    			} else {
    				jsonParsed = true;
    			}
    			parseJson(buffer);
    			f_close(&g_fileObject);
    			xSemaphoreGive(s_fileAccessSemaphore);
    			vTaskDelay(1000U);
    		}
    		else
    		{
    			PRINTF("TASK2: file access is blocking.\r\n");
    		}
    	}
    }
    vTaskSuspend(NULL);
}
