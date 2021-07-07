/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_page5_screen(lv_ui *ui){

	//Write codes page5_screen
	ui->page5_screen = lv_obj_create(NULL, NULL);

	//Write codes page5_screen_chart_tabview
	ui->page5_screen_chart_tabview = lv_tabview_create(ui->page5_screen, NULL);

	//title1
	ui->page5_screen_chart_tabview_title1 = lv_tabview_add_tab(ui->page5_screen_chart_tabview,"title1");
	lv_obj_t * page5_screen_chart_tabview_title1_label = lv_label_create(ui->page5_screen_chart_tabview_title1, NULL);
	lv_label_set_text(page5_screen_chart_tabview_title1_label, "con1");

	//title2
	ui->page5_screen_chart_tabview_title2 = lv_tabview_add_tab(ui->page5_screen_chart_tabview,"title2");
	lv_obj_t * page5_screen_chart_tabview_title2_label = lv_label_create(ui->page5_screen_chart_tabview_title2, NULL);
	lv_label_set_text(page5_screen_chart_tabview_title2_label, "con2");

	//title3
	ui->page5_screen_chart_tabview_title3 = lv_tabview_add_tab(ui->page5_screen_chart_tabview,"title3");
	lv_obj_t * page5_screen_chart_tabview_title3_label = lv_label_create(ui->page5_screen_chart_tabview_title3, NULL);
	lv_label_set_text(page5_screen_chart_tabview_title3_label, "con3");

	lv_tabview_set_anim_time(ui->page5_screen_chart_tabview, 1000);

	//Write style LV_TABVIEW_PART_BG for page5_screen_chart_tabview
	static lv_style_t style_page5_screen_chart_tabview_bg;
	lv_style_init(&style_page5_screen_chart_tabview_bg);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_bg
	lv_style_set_bg_color(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_text_font(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_line_space(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->page5_screen_chart_tabview, LV_TABVIEW_PART_BG, &style_page5_screen_chart_tabview_bg);

	//Write style LV_TABVIEW_PART_INDIC for page5_screen_chart_tabview
	static lv_style_t style_page5_screen_chart_tabview_indic;
	lv_style_init(&style_page5_screen_chart_tabview_indic);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_indic
	lv_style_set_bg_color(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page5_screen_chart_tabview, LV_TABVIEW_PART_INDIC, &style_page5_screen_chart_tabview_indic);

	//Write style LV_TABVIEW_PART_TAB_BG for page5_screen_chart_tabview
	static lv_style_t style_page5_screen_chart_tabview_tab_bg;
	lv_style_init(&style_page5_screen_chart_tabview_tab_bg);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_tab_bg
	lv_style_set_bg_color(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page5_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page5_screen_chart_tabview, LV_TABVIEW_PART_TAB_BG, &style_page5_screen_chart_tabview_tab_bg);

	//Write style LV_TABVIEW_PART_TAB_BTN for page5_screen_chart_tabview
	static lv_style_t style_page5_screen_chart_tabview_tab_btn;
	lv_style_init(&style_page5_screen_chart_tabview_tab_btn);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_tab_btn
	lv_style_set_text_color(&style_page5_screen_chart_tabview_tab_btn, LV_STATE_DEFAULT, lv_color_make(0x04, 0x2f, 0xc8));
	lv_style_set_text_letter_space(&style_page5_screen_chart_tabview_tab_btn, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page5_screen_chart_tabview, LV_TABVIEW_PART_TAB_BTN, &style_page5_screen_chart_tabview_tab_btn);
	lv_obj_set_pos(ui->page5_screen_chart_tabview, 0, 20);
	lv_obj_set_size(ui->page5_screen_chart_tabview, 480, 253);

	//Write codes page5_screen_chart_tabview_title1

	//Write codes page5_screen_chart_tabview_title2

	//Write codes page5_screen_chart_tabview_title3

	//Write codes page5_screen_chart_1
	ui->page5_screen_chart_1 = lv_chart_create(ui->page5_screen_chart_tabview_title3, NULL);

	//Write style LV_CHART_PART_BG for page5_screen_chart_1
	static lv_style_t style_page5_screen_chart_1_bg;
	lv_style_init(&style_page5_screen_chart_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_1_bg
	lv_style_set_bg_color(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_page5_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->page5_screen_chart_1, LV_CHART_PART_BG, &style_page5_screen_chart_1_bg);

	//Write style LV_CHART_PART_SERIES_BG for page5_screen_chart_1
	static lv_style_t style_page5_screen_chart_1_series_bg;
	lv_style_init(&style_page5_screen_chart_1_series_bg);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_1_series_bg
	lv_style_set_line_color(&style_page5_screen_chart_1_series_bg, LV_STATE_DEFAULT, lv_color_make(0xe8, 0xe8, 0xe8));
	lv_style_set_line_width(&style_page5_screen_chart_1_series_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_line_opa(&style_page5_screen_chart_1_series_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page5_screen_chart_1, LV_CHART_PART_SERIES_BG, &style_page5_screen_chart_1_series_bg);
	lv_obj_set_pos(ui->page5_screen_chart_1, 122, 28);
	lv_obj_set_size(ui->page5_screen_chart_1, 205, 155);
	lv_chart_set_type(ui->page5_screen_chart_1,LV_CHART_TYPE_LINE);
	lv_chart_set_range(ui->page5_screen_chart_1,0,100);
	lv_chart_set_div_line_count(ui->page5_screen_chart_1, 3, 5);
}