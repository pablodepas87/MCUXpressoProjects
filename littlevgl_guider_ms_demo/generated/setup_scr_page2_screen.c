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

void return_to_home_callback(lv_task_t *task);

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

void open_kb_callback(lv_task_t *task){
	lv_ui *ui = task->user_data;

	lv_event_send(ui->page2_screen_text_area, LV_EVENT_CLICKED, NULL);
	lv_task_del(task);
}

void send_char_cb(lv_task_t *task){
	lv_event_send(kb, LV_EVENT_VALUE_CHANGED , 5);
}

void setup_scr_page2_screen(lv_ui *ui){

	//Write codes page2_screen
	ui->page2_screen = lv_obj_create(NULL, NULL);

	//Write codes pag1_cont_1
	ui->pag1_cont_1 = lv_cont_create(ui->page2_screen, NULL);

	//Write style LV_CONT_PART_MAIN for pag1_cont_1
	static lv_style_t style_pag1_cont_1_main;
	lv_style_init(&style_pag1_cont_1_main);

	//Write style state: LV_STATE_DEFAULT for style_pag1_cont_1_main
	lv_style_set_radius(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pag1_cont_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_pag1_cont_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_pag1_cont_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_pag1_cont_1_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pag1_cont_1, LV_CONT_PART_MAIN, &style_pag1_cont_1_main);
	lv_obj_set_pos(ui->pag1_cont_1, 0, 0);
	lv_obj_set_size(ui->pag1_cont_1, 480, 30);
	lv_obj_set_click(ui->pag1_cont_1, false);
	lv_cont_set_layout(ui->pag1_cont_1, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->pag1_cont_1, LV_FIT_NONE);

	//Write codes pag1_page_title
	ui->pag1_page_title = lv_label_create(ui->page2_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "TEXT AREA - KEYBOARD");
	lv_label_set_long_mode(ui->pag1_page_title, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->pag1_page_title, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for pag1_page_title
	static lv_style_t style_pag1_page_title_main;
	lv_style_init(&style_pag1_page_title_main);

	//Write style state: LV_STATE_DEFAULT for style_pag1_page_title_main
	lv_style_set_radius(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pag1_page_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pag1_page_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pag1_page_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_pag1_page_title_main, LV_STATE_DEFAULT, lv_color_make(0x96, 0x96, 0x96));
	lv_style_set_text_font(&style_pag1_page_title_main, LV_STATE_DEFAULT, &lv_font_klavika_bold_16);
	lv_style_set_text_letter_space(&style_pag1_page_title_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pag1_page_title, LV_LABEL_PART_MAIN, &style_pag1_page_title_main);
	lv_obj_set_pos(ui->pag1_page_title, 80, 10);
	lv_obj_set_size(ui->pag1_page_title, 270, 30);

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
	lv_textarea_set_placeholder_text(ui->page2_screen_text_area, "");

	lv_task_t *show_kb = lv_task_create(open_kb_callback,500,LV_TASK_PRIO_HIGH,ui);

	lv_task_t *send_char_to_textarea = (send_char_cb,LV_TASK_PRIO_HIGH,ui);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(return_to_home_callback,30000, LV_TASK_PRIO_HIGH, ui);

}

void return_to_home_callback(lv_task_t *task){
	lv_ui *ui = task->user_data;

	lv_task_del(task);
	lv_event_send(ui->page2_screen, LV_EVENT_LEAVE, NULL);

}

