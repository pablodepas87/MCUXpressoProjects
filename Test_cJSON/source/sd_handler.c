/*
 * sd_handler.c
 *
 *  Created on: 22 dic 2020
 *      Author: rapicano
 */

#include <stdio.h>
#include <string.h>
#include "fsl_sd.h"
#include "fsl_debug_console.h"
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "sdmmc_config.h"

#include <stdbool.h>
#include "fsl_iocon.h"

static FATFS g_fileSystem; /* File system object */
static FIL g_fileObject;   /* File object */
BYTE work[FF_MAX_SS];
const TCHAR driverNumberBuffer[3U] = {SDDISK + '0', ':', '/'};
FRESULT error;
DIR directory;
UINT bytesWritten;
UINT bytesRead;
FILINFO fileInformation;
volatile bool failedFlag           = false;
char ch                            = '0';

status_t sdcardWaitCardInsert(void)
{
    BOARD_SD_Config(&g_sd, NULL, BOARD_SDMMC_SD_HOST_IRQ_PRIORITY, NULL);

    /* SD host init function */
    if (SD_HostInit(&g_sd) != kStatus_Success)
    {
        PRINTF("\r\nSD host init fail\r\n");
        return kStatus_Fail;
    }
    /* power off card */
    SD_SetCardPower(&g_sd, false);

    /* wait card insert */
    if (SD_PollingCardInsert(&g_sd, kSD_Inserted) == kStatus_Success)
    {
        PRINTF("\r\nCard inserted.\r\n");
        /* power on the card */
        SD_SetCardPower(&g_sd, true);
    }
    else
    {
        PRINTF("\r\nCard detect fail.\r\n");
        return kStatus_Fail;
    }

    return kStatus_Success;
}
UINT sd_is_mount(){

	if (f_mount(&g_fileSystem, driverNumberBuffer, 0U))
	{
	        PRINTF("Mount volume failed.\r\n");
	        return -1;
	}
	return 1;
}

UINT change_driver(){

  if (FF_FS_RPATH >= 2U) {
    error = f_chdrive((char const *)&driverNumberBuffer[0U]);
    if (error)
    {
        PRINTF("Change drive failed.\r\n");
        return -1;
    }
    return 1;
  } else {
	  return -1;
  }

}

UINT make_file_systems(){
	if( FF_USE_MKFS ) {
		PRINTF("\r\nMake file system......The time may be long if the card capacity is big.\r\n");
		if (f_mkfs(driverNumberBuffer, 0, work, sizeof work))
		{
			PRINTF("Make file system failed.\r\n");
			return -1;
		}
		return 1;
	} else {
		return -1;
	}
}

UINT make_dir(char *path){
	PRINTF("\r\nCreating directory......\r\n");
	error = f_mkdir(_T(path));
	if (error)
	{
		if (error == FR_EXIST)
		{
			PRINTF("Directory exists.\r\n");
			return 1;
		}
		else
		{
			PRINTF("Make directory failed.\r\n");
			return -1;
		}
	}
}

UINT create_file_dir(char *dirpath , char *filename) {
	char *path;
	PRINTF("\r\nCreate %s file in %s.....\r\n",filename,dirpath);
	path = strcpy(dirpath,"/");
    path = strcpy(path,filename);
	error = f_open(&g_fileObject, _T(path), (FA_WRITE | FA_READ | FA_CREATE_ALWAYS));
	if (error)
	{
		if (error == FR_EXIST)
		{
	 		PRINTF("File exists.\r\n");
	 		return 1;
		}
		else
		{
			PRINTF("Open file failed.\r\n");
			return -1;
		}
	}
	return 1;

}

UINT create_dir_in_dir(char *dirpath, char *newdirpath){
	char *path;
	PRINTF("\r\nCreate a directory in that directory......\r\n");
	path = strcpy(dirpath,"/");
	path = strcpy(path,newdirpath);
	error = f_mkdir(_T(path));

	if (error)
	{
		if (error == FR_EXIST)
		{
			PRINTF("Directory exists.\r\n");
			return 1;
		}
		else
		{
			PRINTF("Directory creation failed.\r\n");
			return -1;
		}
	}
	return 1;
}

UINT show_list_file_in_dir(char *path) {

		PRINTF("\r\nList the file in that directory......\r\n");
	    if (f_opendir(&directory, path))
	    {
	        PRINTF("Open directory failed.\r\n");
	        return -1;
	    }

	    for (;;)
	    {
	        error = f_readdir(&directory, &fileInformation);

	        /* To the end. */
	        if ((error != FR_OK) || (fileInformation.fname[0U] == 0U))
	        {
	            break;
	        }
	        if (fileInformation.fname[0] == '.')
	        {
	            continue;
	        }
	        if (fileInformation.fattrib & AM_DIR)
	        {
	            PRINTF("Directory file : %s.\r\n", fileInformation.fname);
	        }
	        else
	        {
	            PRINTF("General file : %s.\r\n", fileInformation.fname);
	        }
	    }
}
