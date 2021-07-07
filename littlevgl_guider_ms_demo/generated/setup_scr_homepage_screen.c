/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static uint8_t  page_number =0;

void timer_changepage(lv_task_t * task);
void setup_scr_homepage_screen(lv_ui *ui){

	//Write codes homepage_screen
	ui->homepage_screen = lv_obj_create(NULL, NULL);

	//Write codes homepage_screen_bkg_obj
	ui->homepage_screen_bkg_obj = lv_cont_create(ui->homepage_screen, NULL);

//	//Write style LV_CONT_PART_MAIN for homepage_screen_bkg_obj
	static lv_style_t style_homepage_screen_bkg_obj_main;
	lv_style_init(&style_homepage_screen_bkg_obj_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_bkg_obj_main
	lv_style_set_radius(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, lv_color_make(0xd2, 0xde, 0x00));
	lv_style_set_border_width(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_homepage_screen_bkg_obj_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_bkg_obj, LV_CONT_PART_MAIN, &style_homepage_screen_bkg_obj_main);
	lv_obj_set_pos(ui->homepage_screen_bkg_obj, 0, 0);
	lv_obj_set_size(ui->homepage_screen_bkg_obj, 480, 272);
	lv_obj_set_click(ui->homepage_screen_bkg_obj, false);
	lv_cont_set_layout(ui->homepage_screen_bkg_obj, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->homepage_screen_bkg_obj, LV_FIT_NONE);

	//Write codes homepage_screen_img_ms_logo
	ui->homepage_screen_img_ms_logo = lv_img_create(ui->homepage_screen, NULL);

	//Write style LV_IMG_PART_MAIN for homepage_screen_img_ms_logo
	static lv_style_t style_homepage_screen_img_ms_logo_main;
	lv_style_init(&style_homepage_screen_img_ms_logo_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_img_ms_logo_main
	lv_style_set_image_recolor(&style_homepage_screen_img_ms_logo_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_homepage_screen_img_ms_logo_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_homepage_screen_img_ms_logo_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->homepage_screen_img_ms_logo, LV_IMG_PART_MAIN, &style_homepage_screen_img_ms_logo_main);
	lv_obj_set_pos(ui->homepage_screen_img_ms_logo, 10, 83);
	lv_obj_set_size(ui->homepage_screen_img_ms_logo, 150, 93);
	lv_obj_set_click(ui->homepage_screen_img_ms_logo, true);
	lv_img_set_src(ui->homepage_screen_img_ms_logo,&_logo_micro_alpha_150x93);
	lv_img_set_pivot(ui->homepage_screen_img_ms_logo, 0,0);
	lv_img_set_angle(ui->homepage_screen_img_ms_logo, 0);

	//Write codes homepage_screen_btn_1
	ui->homepage_screen_btn_1 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_1
	static lv_style_t style_homepage_screen_btn_1_main;
	lv_style_init(&style_homepage_screen_btn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_1_main
	lv_style_set_radius(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_1, LV_BTN_PART_MAIN, &style_homepage_screen_btn_1_main);
	lv_obj_set_pos(ui->homepage_screen_btn_1, 200, 30);
	lv_obj_set_size(ui->homepage_screen_btn_1, 80, 60);
	ui->homepage_screen_btn_1_label = lv_label_create(ui->homepage_screen_btn_1, NULL);
	lv_label_set_text(ui->homepage_screen_btn_1_label, "DATA/ORA");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_2
	ui->homepage_screen_btn_2 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_2
	static lv_style_t style_homepage_screen_btn_2_main;
	lv_style_init(&style_homepage_screen_btn_2_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_2_main
	lv_style_set_radius(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_2, LV_BTN_PART_MAIN, &style_homepage_screen_btn_2_main);
	lv_obj_set_pos(ui->homepage_screen_btn_2, 290, 30);
	lv_obj_set_size(ui->homepage_screen_btn_2, 80, 60);
	ui->homepage_screen_btn_2_label = lv_label_create(ui->homepage_screen_btn_2, NULL);
	lv_label_set_text(ui->homepage_screen_btn_2_label, "KEYBOARD");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_2_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_2_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_3
	ui->homepage_screen_btn_3 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_3
	static lv_style_t style_homepage_screen_btn_3_main;
	lv_style_init(&style_homepage_screen_btn_3_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_3_main
	lv_style_set_radius(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_3_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_3, LV_BTN_PART_MAIN, &style_homepage_screen_btn_3_main);
	lv_obj_set_pos(ui->homepage_screen_btn_3, 380, 30);
	lv_obj_set_size(ui->homepage_screen_btn_3, 80, 60);
	ui->homepage_screen_btn_3_label = lv_label_create(ui->homepage_screen_btn_3, NULL);
	lv_label_set_text(ui->homepage_screen_btn_3_label, "WIDGET\nVARI");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_3_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_3_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_4
	ui->homepage_screen_btn_4 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_4
	static lv_style_t style_homepage_screen_btn_4_main;
	lv_style_init(&style_homepage_screen_btn_4_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_4_main
	lv_style_set_radius(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_4_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_4, LV_BTN_PART_MAIN, &style_homepage_screen_btn_4_main);
	lv_obj_set_pos(ui->homepage_screen_btn_4, 200, 100);
	lv_obj_set_size(ui->homepage_screen_btn_4, 80, 60);
	ui->homepage_screen_btn_4_label = lv_label_create(ui->homepage_screen_btn_4, NULL);
	lv_label_set_text(ui->homepage_screen_btn_4_label, "TABLE");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_4_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_4_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_5
	ui->homepage_screen_btn_5 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_5
	static lv_style_t style_homepage_screen_btn_5_main;
	lv_style_init(&style_homepage_screen_btn_5_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_5_main
	lv_style_set_radius(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_5_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_5, LV_BTN_PART_MAIN, &style_homepage_screen_btn_5_main);
	lv_obj_set_pos(ui->homepage_screen_btn_5, 290, 100);
	lv_obj_set_size(ui->homepage_screen_btn_5, 80, 60);
	ui->homepage_screen_btn_5_label = lv_label_create(ui->homepage_screen_btn_5, NULL);
	lv_label_set_text(ui->homepage_screen_btn_5_label, "ANIMATIONS");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_6
	ui->homepage_screen_btn_6 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_6
	static lv_style_t style_homepage_screen_btn_6_main;
	lv_style_init(&style_homepage_screen_btn_6_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_6_main
	lv_style_set_radius(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_6, LV_BTN_PART_MAIN, &style_homepage_screen_btn_6_main);
	lv_obj_set_pos(ui->homepage_screen_btn_6, 380, 100);
	lv_obj_set_size(ui->homepage_screen_btn_6, 80, 60);
	ui->homepage_screen_btn_6_label = lv_label_create(ui->homepage_screen_btn_6, NULL);
	lv_label_set_text(ui->homepage_screen_btn_6_label, "SLIDERS \n IMAGE ");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_6_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_6_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_7
	ui->homepage_screen_btn_7 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_7
	static lv_style_t style_homepage_screen_btn_7_main;
	lv_style_init(&style_homepage_screen_btn_7_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_7_main
	lv_style_set_radius(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_7_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_7, LV_BTN_PART_MAIN, &style_homepage_screen_btn_7_main);
	lv_obj_set_pos(ui->homepage_screen_btn_7, 200, 170);
	lv_obj_set_size(ui->homepage_screen_btn_7, 80, 60);
	ui->homepage_screen_btn_7_label = lv_label_create(ui->homepage_screen_btn_7, NULL);
	lv_label_set_text(ui->homepage_screen_btn_7_label, "LINE-METER");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_7_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_7_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_8
	ui->homepage_screen_btn_8 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_8
	static lv_style_t style_homepage_screen_btn_8_main;
	lv_style_init(&style_homepage_screen_btn_8_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_8_main
	lv_style_set_radius(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_8, LV_BTN_PART_MAIN, &style_homepage_screen_btn_8_main);
	lv_obj_set_pos(ui->homepage_screen_btn_8, 290, 170);
	lv_obj_set_size(ui->homepage_screen_btn_8, 80, 60);
	ui->homepage_screen_btn_8_label = lv_label_create(ui->homepage_screen_btn_8, NULL);
	lv_label_set_text(ui->homepage_screen_btn_8_label, "GAUGE");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_8_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_8_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes homepage_screen_btn_9
	ui->homepage_screen_btn_9 = lv_btn_create(ui->homepage_screen, NULL);

	//Write style LV_BTN_PART_MAIN for homepage_screen_btn_9
	static lv_style_t style_homepage_screen_btn_9_main;
	lv_style_init(&style_homepage_screen_btn_9_main);

	//Write style state: LV_STATE_DEFAULT for style_homepage_screen_btn_9_main
	lv_style_set_radius(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_color(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x44, 0x95));
	lv_style_set_bg_grad_dir(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_opa(&style_homepage_screen_btn_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->homepage_screen_btn_9, LV_BTN_PART_MAIN, &style_homepage_screen_btn_9_main);
	lv_obj_set_pos(ui->homepage_screen_btn_9, 380, 170);
	lv_obj_set_size(ui->homepage_screen_btn_9, 80, 60);
	ui->homepage_screen_btn_9_label = lv_label_create(ui->homepage_screen_btn_9, NULL);
	lv_label_set_text(ui->homepage_screen_btn_9_label, "CHARTS");
	lv_obj_set_style_local_text_color(ui->homepage_screen_btn_9_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->homepage_screen_btn_9_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	events_init_homepage_screen(ui);

	lv_task_t * task = lv_task_create(timer_changepage, 5000, LV_TASK_PRIO_MID, ui);

}

void timer_changepage(lv_task_t * task){

	lv_ui * ui = task->user_data;

	if ( page_number < 9 ) {
		page_number++;
	} else {
		page_number = 1 ;
	}

	lv_event_send(ui->homepage_screen_bkg_obj, LV_EVENT_PRESSED, page_number );
	lv_task_del(task);
}


