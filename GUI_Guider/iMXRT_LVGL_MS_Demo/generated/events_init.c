/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"

void events_init(lv_ui *ui)
{
}

static void splash_screen_img_logoevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_homepage_screen(&guider_ui);
		lv_scr_load(guider_ui.homepage_screen);
	}
		break;
	default:
		break;
	}
}

void events_init_splash_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->splash_screen_img_logo, splash_screen_img_logoevent_handler);
}
