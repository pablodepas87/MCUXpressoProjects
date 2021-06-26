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

static void splash_screen_event_handler(lv_obj_t * obj, lv_event_t event)
{
	int16_t bar_cur_value;
	bar_cur_value = lv_event_get_data();
	switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		if(bar_cur_value <100 ) {
			lv_bar_set_value(guider_ui.splash_screen_bar_1, bar_cur_value, LV_ANIM_OFF);
		} else {
			lv_obj_clean(lv_scr_act());
			setup_scr_homepage_screen(&guider_ui);
			lv_scr_load(guider_ui.homepage_screen);

		}
	}
		break;
	default:
		break;
	}
}

void events_init_splash_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->splash_screen_bar_1, splash_screen_event_handler);
}

static void homepage_screen_event_handler(lv_obj_t * obj, lv_event_t event)
{
	int16_t page_number_to_go;
	page_number_to_go = lv_event_get_data();

	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_clean(lv_scr_act());

		switch(page_number_to_go){
		case 1:
			setup_scr_page1_screen(&guider_ui);
			lv_scr_load(guider_ui.page1_screen);
			break;
		case 2:
			setup_scr_page2_screen(&guider_ui);
			lv_scr_load(guider_ui.page2_screen);
			break;
		case 3:
			setup_scr_page3_screen(&guider_ui);
			lv_scr_load(guider_ui.page3_screen);
			break;
		case 4:
			setup_scr_page4_screen(&guider_ui);
			lv_scr_load(guider_ui.page4_screen);
			break;
		case 5:
			setup_scr_page5_screen(&guider_ui);
			lv_scr_load(guider_ui.page5_screen);
			break;
		case 6:
			setup_scr_page6_screen(&guider_ui);
			lv_scr_load(guider_ui.page6_screen);
			break;
		case 7:
			setup_scr_page7_screen(&guider_ui);
			lv_scr_load(guider_ui.page7_screen);
			break;
		case 8:
			setup_scr_page8_screen(&guider_ui);
			lv_scr_load(guider_ui.page8_screen);
			break;
		case 9:
			setup_scr_page9_screen(&guider_ui);
			lv_scr_load(guider_ui.page9_screen);
			break;
		default: break;

		}
	}
	break;
	default:
		break;
	}
}

void events_init_homepage_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->homepage_screen_bkg_obj, homepage_screen_event_handler);
}

static void events_return_to_home_event_handler(lv_obj_t * obj, lv_event_t event){

	switch (event){
	case LV_EVENT_LEAVE:
		lv_obj_clean(lv_scr_act());
		setup_scr_homepage_screen(&guider_ui);
		lv_scr_load(guider_ui.homepage_screen);
		break;
	default: break;
	}
}

void events_init_retun_to_homepage(lv_ui *ui) {

	lv_obj_set_event_cb(ui->page1_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page2_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page3_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page4_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page5_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page6_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page7_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page8_screen,events_return_to_home_event_handler);
	lv_obj_set_event_cb(ui->page9_screen,events_return_to_home_event_handler);

}




