/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_obj_t * kb;
static void kb_event_cb(lv_obj_t * event_kb, lv_event_t event)
{
	/* Just call the regular event handler */
	lv_keyboard_def_event_cb(event_kb, event);
	if(event == LV_EVENT_APPLY || event == LV_EVENT_CANCEL){
		if(NULL != kb){
			lv_obj_del(kb);
		}
	}
}
static void text_area_event_cb(lv_obj_t* ta, lv_event_t event)
{

	if(event == LV_EVENT_CLICKED){
		 if( !lv_debug_check_obj_valid(kb) ){
			/* Create a keyboard and make it fill the width of the above text areas */
			kb = lv_keyboard_create(lv_scr_act(), NULL);
			lv_obj_set_event_cb(kb, kb_event_cb);
			lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);
		}
		lv_keyboard_set_textarea(kb, ta);
		lv_keyboard_set_cursor_manage(kb, true); 
	}
}

void setup_scr_page2_screen(lv_ui *ui){

	//Write codes page2_screen
	ui->page2_screen = lv_obj_create(NULL, NULL);

	//Write codes page2_screen_text_area
	ui->page2_screen_text_area = lv_textarea_create(ui->page2_screen, NULL);

	//Write style LV_PAGE_PART_BG for page2_screen_text_area
	static lv_style_t style_page2_screen_text_area_bg;
	lv_style_init(&style_page2_screen_text_area_bg);

	//Write style state: LV_STATE_DEFAULT for style_page2_screen_text_area_bg
	lv_style_set_radius(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_right(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_top(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_bottom(&style_page2_screen_text_area_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->page2_screen_text_area, LV_PAGE_PART_BG, &style_page2_screen_text_area_bg);

	//Write style LV_PAGE_PART_SCROLLABLE for page2_screen_text_area
	static lv_style_t style_page2_screen_text_area_scrollable;
	lv_style_init(&style_page2_screen_text_area_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_page2_screen_text_area_scrollable
	lv_style_set_radius(&style_page2_screen_text_area_scrollable, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_page2_screen_text_area_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page2_screen_text_area_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page2_screen_text_area_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page2_screen_text_area_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page2_screen_text_area, LV_PAGE_PART_SCROLLABLE, &style_page2_screen_text_area_scrollable);

	//Write style LV_PAGE_PART_EDGE_FLASH for page2_screen_text_area
	static lv_style_t style_page2_screen_text_area_edge_flash;
	lv_style_init(&style_page2_screen_text_area_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_page2_screen_text_area_edge_flash
	lv_style_set_radius(&style_page2_screen_text_area_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_page2_screen_text_area_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page2_screen_text_area_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page2_screen_text_area_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page2_screen_text_area_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page2_screen_text_area, LV_PAGE_PART_EDGE_FLASH, &style_page2_screen_text_area_edge_flash);
	lv_obj_set_pos(ui->page2_screen_text_area, 36, 54);
	lv_obj_set_size(ui->page2_screen_text_area, 410, 60);
	lv_obj_set_event_cb(ui->page2_screen_text_area, text_area_event_cb);
	lv_textarea_set_text_align(ui->page2_screen_text_area, LV_LABEL_ALIGN_LEFT);
}