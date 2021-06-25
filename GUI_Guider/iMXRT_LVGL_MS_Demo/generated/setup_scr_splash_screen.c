/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_splash_screen(lv_ui *ui){

	//Write codes splash_screen
	ui->splash_screen = lv_obj_create(NULL, NULL);

	//Write codes splash_screen_bkg_panel
	ui->splash_screen_bkg_panel = lv_cont_create(ui->splash_screen, NULL);

	//Write style LV_CONT_PART_MAIN for splash_screen_bkg_panel
	static lv_style_t style_splash_screen_bkg_panel_main;
	lv_style_init(&style_splash_screen_bkg_panel_main);

	//Write style state: LV_STATE_DEFAULT for style_splash_screen_bkg_panel_main
	lv_style_set_radius(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, lv_color_make(0xd2, 0xde, 0x00));
	lv_style_set_border_width(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_splash_screen_bkg_panel_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->splash_screen_bkg_panel, LV_CONT_PART_MAIN, &style_splash_screen_bkg_panel_main);
	lv_obj_set_pos(ui->splash_screen_bkg_panel, 0, 0);
	lv_obj_set_size(ui->splash_screen_bkg_panel, 480, 272);
	lv_obj_set_click(ui->splash_screen_bkg_panel, false);
	lv_cont_set_layout(ui->splash_screen_bkg_panel, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->splash_screen_bkg_panel, LV_FIT_NONE);

	//Write codes splash_screen_img_logo
	ui->splash_screen_img_logo = lv_img_create(ui->splash_screen, NULL);

	//Write style LV_IMG_PART_MAIN for splash_screen_img_logo
	static lv_style_t style_splash_screen_img_logo_main;
	lv_style_init(&style_splash_screen_img_logo_main);

	//Write style state: LV_STATE_DEFAULT for style_splash_screen_img_logo_main
	lv_style_set_image_recolor(&style_splash_screen_img_logo_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_splash_screen_img_logo_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_splash_screen_img_logo_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->splash_screen_img_logo, LV_IMG_PART_MAIN, &style_splash_screen_img_logo_main);
	lv_obj_set_pos(ui->splash_screen_img_logo, 35, 45);
	lv_obj_set_size(ui->splash_screen_img_logo, 150, 93);
	lv_obj_set_click(ui->splash_screen_img_logo, true);
	lv_img_set_src(ui->splash_screen_img_logo,&_logo_micro_alpha_150x93);
	lv_img_set_pivot(ui->splash_screen_img_logo, 0,0);
	lv_img_set_angle(ui->splash_screen_img_logo, 0);

	//Write codes splash_screen_label_welcome
	ui->splash_screen_label_welcome = lv_label_create(ui->splash_screen, NULL);
	lv_label_set_text(ui->splash_screen_label_welcome, "Welcome to iMX.RT50 Demo");
	lv_label_set_long_mode(ui->splash_screen_label_welcome, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->splash_screen_label_welcome, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for splash_screen_label_welcome
	static lv_style_t style_splash_screen_label_welcome_main;
	lv_style_init(&style_splash_screen_label_welcome_main);

	//Write style state: LV_STATE_DEFAULT for style_splash_screen_label_welcome_main
	lv_style_set_radius(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, lv_color_make(0xa2, 0xab, 0xb0));
	lv_style_set_text_font(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, &lv_font_klavika_bold_14);
	lv_style_set_text_letter_space(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_splash_screen_label_welcome_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->splash_screen_label_welcome, LV_LABEL_PART_MAIN, &style_splash_screen_label_welcome_main);
	lv_obj_set_pos(ui->splash_screen_label_welcome, 208, 100);
	lv_obj_set_size(ui->splash_screen_label_welcome, 250, 0);

	//Write codes splash_screen_bar_1
	ui->splash_screen_bar_1 = lv_bar_create(ui->splash_screen, NULL);

	//Write style LV_BAR_PART_BG for splash_screen_bar_1
	static lv_style_t style_splash_screen_bar_1_bg;
	lv_style_init(&style_splash_screen_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_splash_screen_bar_1_bg
	lv_style_set_radius(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_splash_screen_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->splash_screen_bar_1, LV_BAR_PART_BG, &style_splash_screen_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for splash_screen_bar_1
	static lv_style_t style_splash_screen_bar_1_indic;
	lv_style_init(&style_splash_screen_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_splash_screen_bar_1_indic
	lv_style_set_radius(&style_splash_screen_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_splash_screen_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0xd2, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_splash_screen_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0xd2, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_splash_screen_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_splash_screen_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->splash_screen_bar_1, LV_BAR_PART_INDIC, &style_splash_screen_bar_1_indic);
	lv_obj_set_pos(ui->splash_screen_bar_1, 79, 206);
	lv_obj_set_size(ui->splash_screen_bar_1, 330, 20);
	lv_bar_set_anim_time(ui->splash_screen_bar_1,2000);
	lv_bar_set_value(ui->splash_screen_bar_1,100,LV_ANIM_ON);
	lv_bar_set_range(ui->splash_screen_bar_1,0,100);

	//Write codes splash_screen_label_1
	ui->splash_screen_label_1 = lv_label_create(ui->splash_screen, NULL);
	lv_label_set_text(ui->splash_screen_label_1, "Loading...");
	lv_label_set_long_mode(ui->splash_screen_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->splash_screen_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for splash_screen_label_1
	static lv_style_t style_splash_screen_label_1_main;
	lv_style_init(&style_splash_screen_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_splash_screen_label_1_main
	lv_style_set_radius(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xa2, 0xab, 0xb0));
	lv_style_set_text_font(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_style_set_text_letter_space(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_splash_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->splash_screen_label_1, LV_LABEL_PART_MAIN, &style_splash_screen_label_1_main);
	lv_obj_set_pos(ui->splash_screen_label_1, 188, 172);
	lv_obj_set_size(ui->splash_screen_label_1, 100, 0);

	//Init events for screen
	events_init_splash_screen(ui);
}