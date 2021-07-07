/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

void change_tab_cb(lv_task_t *task);
void go_to_first_page_cb(lv_task_t *task);

lv_task_t *task_change_tab;

void setup_scr_page9_screen(lv_ui *ui){

	//Write codes page9_screen
	ui->page9_screen = lv_obj_create(NULL, NULL);

//	ui->pag1_cont_1 = lv_cont_create(ui->page9_screen, NULL);
//
//	//Write style LV_CONT_PART_MAIN for pag1_cont_1
//	static lv_style_t style_pag1_cont_1_main;
//	lv_style_init(&style_pag1_cont_1_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_pag1_cont_1_main
//	lv_style_set_radius(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_pag1_cont_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
//	lv_style_set_bg_grad_color(&style_pag1_cont_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
//	lv_style_set_bg_grad_dir(&style_pag1_cont_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_pag1_cont_1_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
//	lv_style_set_border_width(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 1);
//	lv_style_set_border_opa(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_pag1_cont_1_main, LV_STATE_DEFAULT, 0);
//	lv_obj_add_style(ui->pag1_cont_1, LV_CONT_PART_MAIN, &style_pag1_cont_1_main);
//	lv_obj_set_pos(ui->pag1_cont_1, 0, 0);
//	lv_obj_set_size(ui->pag1_cont_1, 480, 30);
//	lv_obj_set_click(ui->pag1_cont_1, false);
//	lv_cont_set_layout(ui->pag1_cont_1, LV_LAYOUT_OFF);
//	lv_cont_set_fit(ui->pag1_cont_1, LV_FIT_NONE);
//
//	//Write codes pag1_page_title
//	ui->pag1_page_title = lv_label_create(ui->page9_screen, NULL);
//	lv_label_set_text(ui->pag1_page_title, "CHARTS-INTO-TAB-VIEW \n");
//	lv_label_set_long_mode(ui->pag1_page_title, LV_LABEL_LONG_BREAK);
//	lv_label_set_align(ui->pag1_page_title, LV_LABEL_ALIGN_CENTER);
//
//	//Write style LV_LABEL_PART_MAIN for pag1_page_title
//	static lv_style_t style_pag1_page_title_main;
//	lv_style_init(&style_pag1_page_title_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_pag1_page_title_main
//	lv_style_set_radius(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_pag1_page_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_pag1_page_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_pag1_page_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_pag1_page_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_text_color(&style_pag1_page_title_main, LV_STATE_DEFAULT, lv_color_make(0x96, 0x96, 0x96));
//	lv_style_set_text_font(&style_pag1_page_title_main, LV_STATE_DEFAULT, &lv_font_klavika_bold_16);
//	lv_style_set_text_letter_space(&style_pag1_page_title_main, LV_STATE_DEFAULT, 1);
//	lv_style_set_pad_left(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
//	lv_style_set_pad_right(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
//	lv_style_set_pad_top(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
//	lv_style_set_pad_bottom(&style_pag1_page_title_main, LV_STATE_DEFAULT, 5);
//	lv_obj_add_style(ui->pag1_page_title, LV_LABEL_PART_MAIN, &style_pag1_page_title_main);
//	lv_obj_set_pos(ui->pag1_page_title, 80, 5);
//	lv_obj_set_size(ui->pag1_page_title, 270, 30);

	//Write codes page5_screen_chart_tabview
	ui->page9_screen_chart_tabview = lv_tabview_create(ui->page9_screen, NULL);

	//title1
	ui->page9_screen_chart_tabview_title1 = lv_tabview_add_tab(ui->page9_screen_chart_tabview,"LINEAR CHART");

	//title2
	ui->page9_screen_chart_tabview_title2 = lv_tabview_add_tab(ui->page9_screen_chart_tabview,"LINEAR CHART 2");

	//title3
	ui->page9_screen_chart_tabview_title3 = lv_tabview_add_tab(ui->page9_screen_chart_tabview,"COLUMN CHART");


	lv_tabview_set_anim_time(ui->page9_screen_chart_tabview, 1000);

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
	lv_style_set_text_font(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_line_space(&style_page5_screen_chart_tabview_bg, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->page9_screen_chart_tabview, LV_TABVIEW_PART_BG, &style_page5_screen_chart_tabview_bg);

	//Write style LV_TABVIEW_PART_INDIC for page5_screen_chart_tabview
	static lv_style_t style_page5_screen_chart_tabview_indic;
	lv_style_init(&style_page5_screen_chart_tabview_indic);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_indic
	lv_style_set_bg_color(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_chart_tabview_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page9_screen_chart_tabview, LV_TABVIEW_PART_INDIC, &style_page5_screen_chart_tabview_indic);

	//Write style LV_TABVIEW_PART_TAB_BG for page5_screen_chart_tabview
	static lv_style_t style_page9_screen_chart_tabview_tab_bg;
	lv_style_init(&style_page9_screen_chart_tabview_tab_bg);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_tab_bg
	lv_style_set_bg_color(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page9_screen_chart_tabview_tab_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page9_screen_chart_tabview, LV_TABVIEW_PART_TAB_BG, &style_page9_screen_chart_tabview_tab_bg);

	//Write style LV_TABVIEW_PART_TAB_BTN for page5_screen_chart_tabview
	static lv_style_t style_page9_screen_chart_tabview_tab_btn;
	lv_style_init(&style_page9_screen_chart_tabview_tab_btn);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_chart_tabview_tab_btn
	lv_style_set_text_color(&style_page9_screen_chart_tabview_tab_btn, LV_STATE_DEFAULT, lv_color_make(0x04, 0x2f, 0xc8));
	lv_style_set_text_letter_space(&style_page9_screen_chart_tabview_tab_btn, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page9_screen_chart_tabview_tab_btn, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_page9_screen_chart_tabview_tab_btn, LV_STATE_DEFAULT, 5); // imposto l'altezza dei bottoni
	lv_obj_add_style(ui->page9_screen_chart_tabview, LV_TABVIEW_PART_TAB_BTN, &style_page9_screen_chart_tabview_tab_btn);

	// modo alternativo per settare altezza dei bottoni
	//lv_obj_set_style_local_pad_top(tv, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, 1);
	//lv_obj_set_style_local_pad_bottom(tv, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, 1);
	//lv_obj_set_style_local_pad_top(tv, LV_TABVIEW_PART_TAB_BTN, LV_STATE_DEFAULT, 1);
	//lv_obj_set_style_local_pad_bottom(tv, LV_TABVIEW_PART_TAB_BTN, LV_STATE_DEFAULT, 1);

	lv_obj_set_pos(ui->page9_screen_chart_tabview, 0, 0);
	lv_obj_set_size(ui->page9_screen_chart_tabview, 480, 273);

	//Write codes page5_screen_chart_tabview_title1

	/*Create a chart INTO TAB*/
	lv_obj_t * chart;
	chart = lv_chart_create(ui->page9_screen_chart_tabview_title1, NULL);
	lv_obj_set_size(chart, 250, 200);
	lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

	/*Add two data series*/
	lv_chart_series_t * ser1 = lv_chart_add_series(chart, LV_COLOR_RED);
	lv_chart_series_t * ser2 = lv_chart_add_series(chart, LV_COLOR_GREEN);

	/*Set the next points on 'ser1'*/
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 10);
	lv_chart_set_next(chart, ser1, 30);
	lv_chart_set_next(chart, ser1, 70);
	lv_chart_set_next(chart, ser1, 90);

	/*Directly set points on 'ser2'*/
	ser2->points[0] = 90;
	ser2->points[1] = 70;
	ser2->points[2] = 65;
	ser2->points[3] = 65;
	ser2->points[4] = 65;
	ser2->points[5] = 65;
	ser2->points[6] = 65;
	ser2->points[7] = 65;
	ser2->points[8] = 65;
	ser2->points[9] = 65;

	lv_chart_refresh(chart); /*Required after direct set*/
	//Write codes page5_screen_chart_tabview_title2

	/*Create a chart*/
	lv_obj_t * chart2;
	chart2 = lv_chart_create(ui->page9_screen_chart_tabview_title2, NULL);
	lv_obj_set_size(chart2, 250, 200);
	lv_obj_align(chart2, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_chart_set_type(chart2, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

	/*Add a faded are effect*/
	lv_obj_set_style_local_bg_opa(chart2, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, LV_OPA_50); /*Max. opa.*/
	lv_obj_set_style_local_bg_grad_dir(chart2, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_obj_set_style_local_bg_main_stop(chart2, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, 255);    /*Max opa on the top*/
	lv_obj_set_style_local_bg_grad_stop(chart2, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, 0);      /*Transparent on the bottom*/


	/*Add two data series*/
	lv_chart_series_t * ser1_chart = lv_chart_add_series(chart2, LV_COLOR_RED);
	lv_chart_series_t * ser2_chart = lv_chart_add_series(chart2, LV_COLOR_GREEN);

	/*Set the next points on 'ser1'*/
	lv_chart_set_next(chart2, ser1_chart, 31);
	lv_chart_set_next(chart2, ser1_chart, 66);
	lv_chart_set_next(chart2, ser1_chart, 10);
	lv_chart_set_next(chart2, ser1_chart, 89);
	lv_chart_set_next(chart2, ser1_chart, 63);
	lv_chart_set_next(chart2, ser1_chart, 56);
	lv_chart_set_next(chart2, ser1_chart, 32);
	lv_chart_set_next(chart2, ser1_chart, 35);
	lv_chart_set_next(chart2, ser1_chart, 57);
	lv_chart_set_next(chart2, ser1_chart, 85);

	/*Directly set points on 'ser2'*/
	ser2_chart->points[0] = 92;
	ser2_chart->points[1] = 71;
	ser2_chart->points[2] = 61;
	ser2_chart->points[3] = 15;
	ser2_chart->points[4] = 21;
	ser2_chart->points[5] = 35;
	ser2_chart->points[6] = 35;
	ser2_chart->points[7] = 58;
	ser2_chart->points[8] = 31;
	ser2_chart->points[9] = 53;

	lv_chart_refresh(chart2); /*Required after direct set*/


	/*Create a chart*/
	lv_obj_t * chart3;
	chart3 = lv_chart_create(ui->page9_screen_chart_tabview_title3, NULL);
	lv_obj_set_size(chart3, 250, 200);
	lv_obj_align(chart3, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_chart_set_type(chart3, LV_CHART_TYPE_COLUMN);   /*Show lines and points too*/

	/*Add two data series*/
	lv_chart_series_t * ser1_chart3 = lv_chart_add_series(chart3, LV_COLOR_AQUA);
	lv_chart_series_t * ser2_chart3 = lv_chart_add_series(chart3, LV_COLOR_ORANGE);

	/*Directly set points on 'ser2'*/
	ser1_chart3->points[0] = 92;
	ser1_chart3->points[1] = 71;
	ser1_chart3->points[2] = 61;
	ser1_chart3->points[3] = 15;
	ser1_chart3->points[4] = 21;
	ser1_chart3->points[5] = 35;
	ser1_chart3->points[6] = 35;
	ser1_chart3->points[7] = 58;
	ser1_chart3->points[8] = 31;
	ser1_chart3->points[9] = 53;

	/*Directly set points on 'ser2'*/
	ser2_chart3->points[0] = 30;
	ser2_chart3->points[1] = 7;
	ser2_chart3->points[2] = 18;
	ser2_chart3->points[3] = 12;
	ser2_chart3->points[4] = 21;
	ser2_chart3->points[5] = 32;
	ser2_chart3->points[6] = 35;
	ser2_chart3->points[7] = 47;
	ser2_chart3->points[8] = 21;
	ser2_chart3->points[9] = 56;

	lv_chart_refresh(chart3); /*Required after direct set*/

	task_change_tab = lv_task_create(change_tab_cb,5000,LV_TASK_PRIO_HIGH,ui);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(go_to_first_page_cb,30000, LV_TASK_PRIO_HIGH, ui);
}

void change_tab_cb(lv_task_t *task)
{
	lv_ui *ui = task->user_data;

	switch (lv_tabview_get_tab_act(ui->page9_screen_chart_tabview))
	{
	case 0:
		lv_tabview_set_tab_act(ui->page9_screen_chart_tabview, 1, LV_ANIM_OFF);
		break;
	case 1:
		lv_tabview_set_tab_act(ui->page9_screen_chart_tabview, 2, LV_ANIM_OFF);
		break;
	case 2:
		lv_tabview_set_tab_act(ui->page9_screen_chart_tabview, 0, LV_ANIM_OFF);
		break;

	}

}

void go_to_first_page_cb(lv_task_t *task)
{
	lv_ui *ui = task->user_data;
	lv_event_send(ui->page9_screen, LV_EVENT_LEAVE, NULL);
	lv_task_del(task_change_tab);
	lv_task_del(task);
}
