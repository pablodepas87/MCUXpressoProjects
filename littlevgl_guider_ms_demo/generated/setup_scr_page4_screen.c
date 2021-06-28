/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_page4_screen(lv_ui *ui){

	//Write codes page4_screen
	ui->page4_screen = lv_obj_create(NULL, NULL);

	ui->pag1_cont_1 = lv_cont_create(ui->page4_screen, NULL);

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
		ui->pag1_page_title = lv_label_create(ui->page4_screen, NULL);
		lv_label_set_text(ui->pag1_page_title, "TABLE");
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

		events_init_retun_to_homepage(ui);
		lv_task_t *go_back_task = lv_task_create(send_event_return_to_home,10000, LV_TASK_PRIO_HIGH, ui);
}
