/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_page8_screen(lv_ui *ui){

	//Write codes page8_screen
	ui->page8_screen = lv_obj_create(NULL, NULL);

	//Write codes page8_screen_title
	ui->page8_screen_title = lv_label_create(ui->page8_screen, NULL);
	lv_label_set_text(ui->page8_screen_title, "SCREEN 8");
	lv_label_set_long_mode(ui->page8_screen_title, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->page8_screen_title, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for page8_screen_title
	static lv_style_t style_page8_screen_title_main;
	lv_style_init(&style_page8_screen_title_main);

	//Write style state: LV_STATE_DEFAULT for style_page8_screen_title_main
	lv_style_set_radius(&style_page8_screen_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_page8_screen_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page8_screen_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page8_screen_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page8_screen_title_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_page8_screen_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_page8_screen_title_main, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_style_set_text_letter_space(&style_page8_screen_title_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_page8_screen_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page8_screen_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page8_screen_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page8_screen_title_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page8_screen_title, LV_LABEL_PART_MAIN, &style_page8_screen_title_main);
	lv_obj_set_pos(ui->page8_screen_title, 176, 36);
	lv_obj_set_size(ui->page8_screen_title, 100, 0);
}