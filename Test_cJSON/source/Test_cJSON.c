#include <stdio.h>
#include <string.h>
#include "fsl_sd.h"
#include "fsl_debug_console.h"
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "sdmmc_config.h"
#include <math.h>
#include <stdbool.h>
#include "fsl_iocon.h"
#include "cJSON.h"


/*******************************************************************************
 * Variables
 ******************************************************************************/
static FATFS g_fileSystem; /* File system object */
static FIL g_fileObject;   /* File object */

/*******************************************************************************
 * Code
 ******************************************************************************/

extern void board_init();
extern status_t sdcardWaitCardInsert();
extern UINT sd_is_mount();
extern UINT change_driver();
extern UINT make_file_systems();
extern UINT make_dir(char *path);
extern UINT create_file_into_sd(char *filepath, FIL* g_fileObject );
extern UINT create_dir_in_dir(char *dirpath);
extern UINT show_list_file_in_dir(char *path);
extern UINT close_file(FIL* g_fileObject);
extern char* readAllFile(char *filepath , FIL* g_fileObject);
extern char* createJson();
extern void parseJson( const char *json_string);

int main(void)
{

    FRESULT error;
    UINT bytesWritten;
    char *json_string;

    board_init();

    PRINTF("\r\nFATFS example to demonstrate how to use FATFS with SD card.\r\n");

    PRINTF("\r\nPlease insert a card into board.\r\n");

    if (sdcardWaitCardInsert() != kStatus_Success)
    {
        return -1;
    }

    if (sd_is_mount() != -1 ) {

    	change_driver();
     	make_file_systems();
     	create_file_into_sd("studente.json", &g_fileObject);
     	json_string = createJson();
     	error = f_write(&g_fileObject, json_string, strlen(json_string), &bytesWritten);
     	if ((error) || (bytesWritten != strlen(json_string)))
     	{
     		PRINTF("Write file failed. \r\n");
        }
     	close_file(&g_fileObject);
     	parseJson(readAllFile("studente.json" ,&g_fileObject));
     	close_file(&g_fileObject);

    }

    while (true){}
}


