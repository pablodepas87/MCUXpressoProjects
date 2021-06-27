/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_calendar_date_t today;
static lv_calendar_date_t highlihted_days[1];

void setup_scr_page1_screen(lv_ui *ui){

	//Write codes page1_screen
	ui->page1_screen = lv_obj_create(NULL, NULL);


	//Write codes pag1_calendar_1
	ui->pag1_calendar_1 = lv_calendar_create(ui->page1_screen, NULL);

	//Write style LV_CALENDAR_PART_BG for pag1_calendar_1
	static lv_style_t style_pag1_calendar_1_bg;
	lv_style_init(&style_pag1_calendar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_pag1_calendar_1_bg
	lv_style_set_bg_color(&style_pag1_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pag1_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pag1_calendar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_calendar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_pag1_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_pag1_calendar_1_bg, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->pag1_calendar_1, LV_CALENDAR_PART_BG, &style_pag1_calendar_1_bg);

	//Write style LV_CALENDAR_PART_HEADER for pag1_calendar_1
	static lv_style_t style_pag1_calendar_1_header;
	lv_style_init(&style_pag1_calendar_1_header);

	//Write style state: LV_STATE_DEFAULT for style_pag1_calendar_1_header
	lv_style_set_text_color(&style_pag1_calendar_1_header, LV_STATE_DEFAULT, lv_color_make(0xc8, 0x32, 0x55));
	lv_style_set_text_font(&style_pag1_calendar_1_header, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pag1_calendar_1_header, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pag1_calendar_1, LV_CALENDAR_PART_HEADER, &style_pag1_calendar_1_header);

	//Write style LV_CALENDAR_PART_DAY_NAMES for pag1_calendar_1
	static lv_style_t style_pag1_calendar_1_day_names;
	lv_style_init(&style_pag1_calendar_1_day_names);

	//Write style state: LV_STATE_DEFAULT for style_pag1_calendar_1_day_names
	lv_style_set_text_color(&style_pag1_calendar_1_day_names, LV_STATE_DEFAULT, lv_color_make(0xc8, 0x38, 0x55));
	lv_style_set_text_font(&style_pag1_calendar_1_day_names, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_obj_add_style(ui->pag1_calendar_1, LV_CALENDAR_PART_DAY_NAMES, &style_pag1_calendar_1_day_names);

	//Write style LV_CALENDAR_PART_DATE for pag1_calendar_1
	static lv_style_t style_pag1_calendar_1_date;
	lv_style_init(&style_pag1_calendar_1_date);

	//Write style state: LV_STATE_DEFAULT for style_pag1_calendar_1_date
	lv_style_set_text_color(&style_pag1_calendar_1_date, LV_STATE_DEFAULT, lv_color_make(0x89, 0xa7, 0xc8));
	lv_style_set_text_font(&style_pag1_calendar_1_date, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_obj_add_style(ui->pag1_calendar_1, LV_CALENDAR_PART_DATE, &style_pag1_calendar_1_date);
	lv_obj_set_pos(ui->pag1_calendar_1, 19, 63);
	lv_obj_set_size(ui->pag1_calendar_1, 257, 180);
	today.year = 2020;
	today.month = 5;
	today.day = 7;
	lv_calendar_set_today_date(ui->pag1_calendar_1, &today);
	lv_calendar_set_showed_date(ui->pag1_calendar_1, &today);
	highlihted_days[0].year = 2020;
	highlihted_days[0].month = 5;
	highlihted_days[0].day = 14;
	lv_calendar_set_highlighted_dates(ui->pag1_calendar_1, highlihted_days, 1);

	//Write codes pag1_cont_1
	ui->pag1_cont_1 = lv_cont_create(ui->page1_screen, NULL);

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
	ui->pag1_page_title = lv_label_create(ui->page1_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "DATA   &   ORA");
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
	lv_obj_set_pos(ui->pag1_page_title, 157, 6);
	lv_obj_set_size(ui->pag1_page_title, 170, 0);

	//Write codes pag1_roller_hour
	ui->pag1_roller_hour = lv_roller_create(ui->page1_screen, NULL);

	//Write style LV_ROLLER_PART_BG for pag1_roller_hour
	static lv_style_t style_pag1_roller_hour_bg;
	lv_style_init(&style_pag1_roller_hour_bg);

	//Write style state: LV_STATE_DEFAULT for style_pag1_roller_hour_bg
	lv_style_set_radius(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_bg_color(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, lv_color_make(0xdf, 0xe7, 0xed));
	lv_style_set_border_width(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_pag1_roller_hour_bg, LV_STATE_DEFAULT, lv_color_make(0x33, 0x33, 0x33));
	lv_obj_add_style(ui->pag1_roller_hour, LV_ROLLER_PART_BG, &style_pag1_roller_hour_bg);

	//Write style LV_ROLLER_PART_SELECTED for pag1_roller_hour
	static lv_style_t style_pag1_roller_hour_selected;
	lv_style_init(&style_pag1_roller_hour_selected);

	//Write style state: LV_STATE_DEFAULT for style_pag1_roller_hour_selected
	lv_style_set_bg_color(&style_pag1_roller_hour_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_pag1_roller_hour_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_pag1_roller_hour_selected, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_roller_hour_selected, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_pag1_roller_hour_selected, LV_STATE_DEFAULT, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->pag1_roller_hour, LV_ROLLER_PART_SELECTED, &style_pag1_roller_hour_selected);
	lv_obj_set_pos(ui->pag1_roller_hour, 300, 50);
	lv_roller_set_options(ui->pag1_roller_hour,"00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",LV_ROLLER_MODE_INIFINITE);
	lv_obj_set_style_local_text_font(ui->pag1_roller_hour, LV_ROLLER_PART_BG, LV_STATE_DEFAULT, &lv_font_klavika_bold_16);
	lv_obj_set_style_local_text_font(ui->pag1_roller_hour, LV_ROLLER_PART_BG, LV_STATE_FOCUSED, &lv_font_klavika_bold_16);
	lv_obj_set_style_local_text_font(ui->pag1_roller_hour, LV_ROLLER_PART_SELECTED, LV_STATE_DEFAULT, &lv_font_klavika_bold_16);
	lv_roller_set_visible_row_count(ui->pag1_roller_hour,5);

	//Write codes pag1_label_double_dot
	ui->pag1_label_double_dot = lv_label_create(ui->page1_screen, NULL);
	lv_label_set_text(ui->pag1_label_double_dot, ":");
	lv_label_set_long_mode(ui->pag1_label_double_dot, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->pag1_label_double_dot, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for pag1_label_double_dot
	static lv_style_t style_pag1_label_double_dot_main;
	lv_style_init(&style_pag1_label_double_dot_main);

	//Write style state: LV_STATE_DEFAULT for style_pag1_label_double_dot_main
	lv_style_set_radius(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_pag1_label_double_dot_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pag1_label_double_dot, LV_LABEL_PART_MAIN, &style_pag1_label_double_dot_main);
	lv_obj_set_pos(ui->pag1_label_double_dot, 360, 135);
	lv_obj_set_size(ui->pag1_label_double_dot, 30, 0);

	//Write codes pag1_roller_minutes
	ui->pag1_roller_minutes = lv_roller_create(ui->page1_screen, NULL);

	//Write style LV_ROLLER_PART_BG for pag1_roller_minutes
	static lv_style_t style_pag1_roller_minutes_bg;
	lv_style_init(&style_pag1_roller_minutes_bg);

	//Write style state: LV_STATE_DEFAULT for style_pag1_roller_minutes_bg
	lv_style_set_radius(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_bg_color(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, lv_color_make(0xdf, 0xe7, 0xed));
	lv_style_set_border_width(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_pag1_roller_minutes_bg, LV_STATE_DEFAULT, lv_color_make(0x33, 0x33, 0x33));
	lv_obj_add_style(ui->pag1_roller_minutes, LV_ROLLER_PART_BG, &style_pag1_roller_minutes_bg);

	//Write style LV_ROLLER_PART_SELECTED for pag1_roller_minutes
	static lv_style_t style_pag1_roller_minutes_selected;
	lv_style_init(&style_pag1_roller_minutes_selected);

	//Write style state: LV_STATE_DEFAULT for style_pag1_roller_minutes_selected
	lv_style_set_bg_color(&style_pag1_roller_minutes_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_pag1_roller_minutes_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_pag1_roller_minutes_selected, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pag1_roller_minutes_selected, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_pag1_roller_minutes_selected, LV_STATE_DEFAULT, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->pag1_roller_minutes, LV_ROLLER_PART_SELECTED, &style_pag1_roller_minutes_selected);
	lv_obj_set_pos(ui->pag1_roller_minutes, 400, 50);
	lv_roller_set_options(ui->pag1_roller_minutes,"00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n26\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n59\n59",LV_ROLLER_MODE_INIFINITE);
	lv_obj_set_style_local_text_font(ui->pag1_roller_minutes, LV_ROLLER_PART_BG, LV_STATE_DEFAULT, &lv_font_klavika_bold_16);
	lv_obj_set_style_local_text_font(ui->pag1_roller_minutes, LV_ROLLER_PART_BG, LV_STATE_FOCUSED, &lv_font_klavika_bold_16);
	lv_obj_set_style_local_text_font(ui->pag1_roller_minutes, LV_ROLLER_PART_SELECTED, LV_STATE_DEFAULT, &lv_font_klavika_bold_16);
	lv_roller_set_visible_row_count(ui->pag1_roller_minutes,5);


	events_init_retun_to_homepage(ui);
	lv_task_t *task = lv_task_create(send_event_return_to_home, 10000, LV_TASK_PRIO_MID, 1);

}
