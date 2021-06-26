// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void send_event_return_to_home(lv_task_t *task) {

	uint8_t active_page_num;
	active_page_num = task->user_data;

	switch (active_page_num) {
	case 1:
		lv_event_send(guider_ui.page1_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 2:
		lv_event_send(guider_ui.page2_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 3:
		lv_event_send(guider_ui.page3_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 4:
		lv_event_send(guider_ui.page4_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 5:
		lv_event_send(guider_ui.page5_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 6:
		lv_event_send(guider_ui.page6_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 7:
		lv_event_send(guider_ui.page7_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 8:
		lv_event_send(guider_ui.page8_screen, LV_EVENT_LEAVE, NULL);
		break;
	case 9:
		lv_event_send(guider_ui.page9_screen, LV_EVENT_LEAVE, NULL);
		break;
	default:
		break;
	}

	lv_task_del(task);
}
