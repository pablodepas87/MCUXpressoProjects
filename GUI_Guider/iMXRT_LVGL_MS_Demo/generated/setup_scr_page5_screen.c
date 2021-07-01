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

	//Write codes page5_screen_lmeter_1
	ui->page5_screen_lmeter_1 = lv_linemeter_create(ui->page5_screen, NULL);

	//Write style LV_LINEMETER_PART_MAIN for page5_screen_lmeter_1
	static lv_style_t style_page5_screen_lmeter_1_main;
	lv_style_init(&style_page5_screen_lmeter_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_lmeter_1_main
	lv_style_set_radius(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 1);
	lv_style_set_bg_color(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_line_color(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_line_width(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_style_set_line_opa(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x8f, 0x93, 0x94));
	lv_style_set_scale_end_color(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_width(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 16);
	lv_style_set_scale_end_line_width(&style_page5_screen_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(ui->page5_screen_lmeter_1, LV_LINEMETER_PART_MAIN, &style_page5_screen_lmeter_1_main);
	lv_obj_set_pos(ui->page5_screen_lmeter_1, 27, 100);
	lv_obj_set_size(ui->page5_screen_lmeter_1, 120, 120);
	lv_linemeter_set_scale(ui->page5_screen_lmeter_1, 300, 35);
	lv_linemeter_set_range(ui->page5_screen_lmeter_1, 0, 180);
	lv_linemeter_set_value(ui->page5_screen_lmeter_1, 100);
	lv_linemeter_set_angle_offset(ui->page5_screen_lmeter_1, 0);

	//Write codes page5_screen_label_1
	ui->page5_screen_label_1 = lv_label_create(ui->page5_screen, NULL);
	lv_label_set_text(ui->page5_screen_label_1, "20");
	lv_label_set_long_mode(ui->page5_screen_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->page5_screen_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for page5_screen_label_1
	static lv_style_t style_page5_screen_label_1_main;
	lv_style_init(&style_page5_screen_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_label_1_main
	lv_style_set_radius(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page5_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page5_screen_label_1, LV_LABEL_PART_MAIN, &style_page5_screen_label_1_main);
	lv_obj_set_pos(ui->page5_screen_label_1, 61, 151);
	lv_obj_set_size(ui->page5_screen_label_1, 50, 0);

	//Write codes page5_screen_arc_1
	ui->page5_screen_arc_1 = lv_arc_create(ui->page5_screen, NULL);

	//Write style LV_ARC_PART_BG for page5_screen_arc_1
	static lv_style_t style_page5_screen_arc_1_bg;
	lv_style_init(&style_page5_screen_arc_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_arc_1_bg
	lv_style_set_bg_color(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_width(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_line_width(&style_page5_screen_arc_1_bg, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->page5_screen_arc_1, LV_ARC_PART_BG, &style_page5_screen_arc_1_bg);

	//Write style LV_ARC_PART_INDIC for page5_screen_arc_1
	static lv_style_t style_page5_screen_arc_1_indic;
	lv_style_init(&style_page5_screen_arc_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_arc_1_indic
	lv_style_set_line_color(&style_page5_screen_arc_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_line_width(&style_page5_screen_arc_1_indic, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->page5_screen_arc_1, LV_ARC_PART_INDIC, &style_page5_screen_arc_1_indic);
	lv_obj_set_pos(ui->page5_screen_arc_1, 207, 101);
	lv_obj_set_size(ui->page5_screen_arc_1, 100, 100);
	lv_arc_set_angles(ui->page5_screen_arc_1, 0, 360);
	lv_arc_set_bg_angles(ui->page5_screen_arc_1, 0, 360);
	lv_arc_set_rotation(ui->page5_screen_arc_1, 0);
	lv_obj_set_style_local_pad_top(ui->page5_screen_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 5);
	lv_obj_set_style_local_pad_bottom(ui->page5_screen_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 5);
	lv_obj_set_style_local_pad_left(ui->page5_screen_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 5);
	lv_obj_set_style_local_pad_right(ui->page5_screen_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 5);
	lv_obj_set_style_local_line_rounded(ui->page5_screen_arc_1, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
}