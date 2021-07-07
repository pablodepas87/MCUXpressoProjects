/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

lv_task_t *increase_gauges_value_task;
lv_obj_t *gauge;

void increase_gauge_values_event_cb(lv_obj_t * obj, lv_event_t event);
void go_to_homepage_callb(lv_task_t *task);

void setup_scr_page8_screen(lv_ui *ui){

	//Write codes page8_screen
	ui->page8_screen = lv_obj_create(NULL, NULL);

	ui->pag1_cont_1 = lv_cont_create(ui->page8_screen, NULL);

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
	ui->pag1_page_title = lv_label_create(ui->page8_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "GAUGE \n");
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
	lv_style_set_pad_left(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->pag1_page_title, LV_LABEL_PART_MAIN, &style_pag1_page_title_main);
	lv_obj_set_pos(ui->pag1_page_title, 80, 5);
	lv_obj_set_size(ui->pag1_page_title, 270, 30);


	/*Describe the color for the needles*/
	static lv_color_t needle_colors[3];
	needle_colors[0] = LV_COLOR_BLUE;
	needle_colors[1] = LV_COLOR_ORANGE;
	needle_colors[2] = LV_COLOR_PURPLE;

	/*Create a gauge*/
	gauge = lv_gauge_create(ui->page8_screen, NULL);
	lv_gauge_set_needle_count(gauge, 3, needle_colors);
	lv_obj_set_size(gauge, 200, 200);
	lv_obj_align(gauge, NULL, LV_ALIGN_CENTER, 0, 0);

	/*Set the values*/
	lv_gauge_set_value(gauge, 0, 10);
	lv_gauge_set_value(gauge, 1, 26);
	lv_gauge_set_value(gauge, 2, 80);

	lv_obj_set_event_cb(gauge, increase_gauge_values_event_cb);

	increase_gauges_value_task = lv_task_create(increase_gauge_values_event_cb,150, LV_TASK_PRIO_HIGH, NULL);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(go_to_homepage_callb,30000, LV_TASK_PRIO_HIGH, ui);
}

void increase_gauges_cb(lv_task_t *task)
{
	lv_event_send(gauge, LV_EVENT_VALUE_CHANGED, NULL);
}

void increase_gauge_values_event_cb(lv_obj_t * obj, lv_event_t event)
{
	LV_UNUSED(event);

	if (lv_gauge_get_value(gauge, 0) < 20){
		lv_gauge_set_value(gauge, 0, lv_gauge_get_value(gauge, 0)+1);
	} else {
		lv_gauge_set_value(gauge, 0, 10);
	}

	if (lv_gauge_get_value(gauge, 1) < 70){
		lv_gauge_set_value(gauge, 1, lv_gauge_get_value(gauge, 1)+1);
	} else {
		lv_gauge_set_value(gauge, 1, 26);
	}

	if (lv_gauge_get_value(gauge, 2) < 100){
		lv_gauge_set_value(gauge, 2, lv_gauge_get_value(gauge, 2)+1);
	} else {
		lv_gauge_set_value(gauge, 2, 80);
	}


}

void go_to_homepage_callb(lv_task_t *task)
{
	lv_ui *ui = task->user_data;
	lv_event_send(ui->page8_screen, LV_EVENT_LEAVE, NULL);
	lv_task_del(increase_gauges_value_task);
	lv_task_del(task);
}
