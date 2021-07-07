/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

void return_to_home_cb(lv_task_t *task);
void change_obj_value_cb(lv_task_t *task);
void setup_scr_page3_screen(lv_ui *ui){

	//Write codes page3_screen
	ui->page3_screen = lv_obj_create(NULL, NULL);

	//Write codes pag1_cont_1
	ui->pag1_cont_1 = lv_cont_create(ui->page3_screen, NULL);

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
	ui->pag1_page_title = lv_label_create(ui->page3_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "WIDGET-VARI");
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

	//Write codes page3_screen_cb_1
	ui->page3_screen_cb_1 = lv_checkbox_create(ui->page3_screen, NULL);
	lv_checkbox_set_text(ui->page3_screen_cb_1, "checkbox 1");

	//Write style LV_CHECKBOX_PART_BG for page3_screen_cb_1
	static lv_style_t style_page3_screen_cb_1_bg;
	lv_style_init(&style_page3_screen_cb_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_1_bg
	lv_style_set_radius(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_style_set_text_letter_space(&style_page3_screen_cb_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_1, LV_CHECKBOX_PART_BG, &style_page3_screen_cb_1_bg);

	//Write style LV_CHECKBOX_PART_BULLET for page3_screen_cb_1
	static lv_style_t style_page3_screen_cb_1_bullet;
	lv_style_init(&style_page3_screen_cb_1_bullet);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_1_bullet
	lv_style_set_radius(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_border_width(&style_page3_screen_cb_1_bullet, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_1, LV_CHECKBOX_PART_BULLET, &style_page3_screen_cb_1_bullet);
	lv_obj_set_pos(ui->page3_screen_cb_1, 9, 58);

	//Write codes page3_screen_sw_1
	ui->page3_screen_sw_1 = lv_switch_create(ui->page3_screen, NULL);

	//Write style LV_SWITCH_PART_BG for page3_screen_sw_1
	static lv_style_t style_page3_screen_sw_1_bg;
	lv_style_init(&style_page3_screen_sw_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_sw_1_bg
	lv_style_set_radius(&style_page3_screen_sw_1_bg, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_page3_screen_sw_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_page3_screen_sw_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_page3_screen_sw_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_sw_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page3_screen_sw_1, LV_SWITCH_PART_BG, &style_page3_screen_sw_1_bg);

	//Write style LV_SWITCH_PART_INDIC for page3_screen_sw_1
	static lv_style_t style_page3_screen_sw_1_indic;
	lv_style_init(&style_page3_screen_sw_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_sw_1_indic
	lv_style_set_radius(&style_page3_screen_sw_1_indic, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_page3_screen_sw_1_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page3_screen_sw_1_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page3_screen_sw_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_sw_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page3_screen_sw_1, LV_SWITCH_PART_INDIC, &style_page3_screen_sw_1_indic);

	//Write style LV_SWITCH_PART_KNOB for page3_screen_sw_1
	static lv_style_t style_page3_screen_sw_1_knob;
	lv_style_init(&style_page3_screen_sw_1_knob);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_sw_1_knob
	lv_style_set_radius(&style_page3_screen_sw_1_knob, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_page3_screen_sw_1_knob, LV_STATE_DEFAULT, lv_color_make(0x96, 0x96, 0x96));
	lv_style_set_bg_grad_color(&style_page3_screen_sw_1_knob, LV_STATE_DEFAULT, lv_color_make(0x96, 0x96, 0x96));
	lv_style_set_bg_grad_dir(&style_page3_screen_sw_1_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_sw_1_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page3_screen_sw_1, LV_SWITCH_PART_KNOB, &style_page3_screen_sw_1_knob);
	lv_obj_set_pos(ui->page3_screen_sw_1, 10, 225);
	lv_obj_set_size(ui->page3_screen_sw_1, 40, 20);
	lv_switch_set_anim_time(ui->page3_screen_sw_1, 50);

	//Write codes page3_screen_ddlist_1
	ui->page3_screen_ddlist_1 = lv_dropdown_create(ui->page3_screen, NULL);
	lv_dropdown_set_options(ui->page3_screen_ddlist_1, "list1\nlist2\nlist3");
	lv_dropdown_set_max_height(ui->page3_screen_ddlist_1, 90);

	//Write style LV_DROPDOWN_PART_MAIN for page3_screen_ddlist_1
	static lv_style_t style_page3_screen_ddlist_1_main;
	lv_style_init(&style_page3_screen_ddlist_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_ddlist_1_main
	lv_style_set_radius(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_line_space(&style_page3_screen_ddlist_1_main, LV_STATE_DEFAULT, 20);
	lv_obj_add_style(ui->page3_screen_ddlist_1, LV_DROPDOWN_PART_MAIN, &style_page3_screen_ddlist_1_main);

	//Write style LV_DROPDOWN_PART_SELECTED for page3_screen_ddlist_1
	static lv_style_t style_page3_screen_ddlist_1_selected;
	lv_style_init(&style_page3_screen_ddlist_1_selected);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_ddlist_1_selected
	lv_style_set_radius(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_page3_screen_ddlist_1_selected, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_obj_add_style(ui->page3_screen_ddlist_1, LV_DROPDOWN_PART_SELECTED, &style_page3_screen_ddlist_1_selected);

	//Write style LV_DROPDOWN_PART_LIST for page3_screen_ddlist_1
	static lv_style_t style_page3_screen_ddlist_1_list;
	lv_style_init(&style_page3_screen_ddlist_1_list);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_ddlist_1_list
	lv_style_set_radius(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_ddlist_1_list, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_obj_add_style(ui->page3_screen_ddlist_1, LV_DROPDOWN_PART_LIST, &style_page3_screen_ddlist_1_list);
	lv_obj_set_pos(ui->page3_screen_ddlist_1, 325, 90);
	lv_obj_set_width(ui->page3_screen_ddlist_1, 130);

	//Write codes page3_screen_btn_1
	ui->page3_screen_btn_1 = lv_btn_create(ui->page3_screen, NULL);

	//Write style LV_BTN_PART_MAIN for page3_screen_btn_1
	static lv_style_t style_page3_screen_btn_1_main;
	lv_style_init(&style_page3_screen_btn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_btn_1_main
	lv_style_set_radius(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_border_width(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_page3_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page3_screen_btn_1, LV_BTN_PART_MAIN, &style_page3_screen_btn_1_main);
	lv_obj_set_pos(ui->page3_screen_btn_1, 365, 221);
	lv_obj_set_size(ui->page3_screen_btn_1, 88, 29);
	ui->page3_screen_btn_1_label = lv_label_create(ui->page3_screen_btn_1, NULL);
	lv_label_set_text(ui->page3_screen_btn_1_label, "Button");
	lv_obj_set_style_local_text_color(ui->page3_screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->page3_screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes page3_screen_slider_1
	ui->page3_screen_slider_1 = lv_slider_create(ui->page3_screen, NULL);

	//Write style LV_SLIDER_PART_INDIC for page3_screen_slider_1
	static lv_style_t style_page3_screen_slider_1_indic;
	lv_style_init(&style_page3_screen_slider_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_slider_1_indic
	lv_style_set_radius(&style_page3_screen_slider_1_indic, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_page3_screen_slider_1_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page3_screen_slider_1_indic, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page3_screen_slider_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_slider_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page3_screen_slider_1, LV_SLIDER_PART_INDIC, &style_page3_screen_slider_1_indic);

	//Write style LV_SLIDER_PART_BG for page3_screen_slider_1
	static lv_style_t style_page3_screen_slider_1_bg;
	lv_style_init(&style_page3_screen_slider_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_slider_1_bg
	lv_style_set_radius(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page3_screen_slider_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_slider_1, LV_SLIDER_PART_BG, &style_page3_screen_slider_1_bg);

	//Write style LV_SLIDER_PART_KNOB for page3_screen_slider_1
	static lv_style_t style_page3_screen_slider_1_knob;
	lv_style_init(&style_page3_screen_slider_1_knob);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_slider_1_knob
	lv_style_set_radius(&style_page3_screen_slider_1_knob, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_page3_screen_slider_1_knob, LV_STATE_DEFAULT, lv_color_make(0x96, 0x96, 0x96));
	lv_style_set_bg_grad_color(&style_page3_screen_slider_1_knob, LV_STATE_DEFAULT, lv_color_make(0x96, 0x96, 0x96));
	lv_style_set_bg_grad_dir(&style_page3_screen_slider_1_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_slider_1_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page3_screen_slider_1, LV_SLIDER_PART_KNOB, &style_page3_screen_slider_1_knob);
	lv_obj_set_pos(ui->page3_screen_slider_1, 166, 233);
	lv_obj_set_size(ui->page3_screen_slider_1, 160, 8);
	lv_slider_set_range(ui->page3_screen_slider_1,0, 100);
	lv_slider_set_value(ui->page3_screen_slider_1,50,false);

	//Write codes page3_screen_label_1
	ui->page3_screen_label_1 = lv_label_create(ui->page3_screen, NULL);
	lv_label_set_text(ui->page3_screen_label_1, "Switch");
	lv_label_set_long_mode(ui->page3_screen_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->page3_screen_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for page3_screen_label_1
	static lv_style_t style_page3_screen_label_1_main;
	lv_style_init(&style_page3_screen_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_label_1_main
	lv_style_set_radius(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page3_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_label_1, LV_LABEL_PART_MAIN, &style_page3_screen_label_1_main);
	lv_obj_set_pos(ui->page3_screen_label_1, 46, 229);
	lv_obj_set_size(ui->page3_screen_label_1, 100, 0);
	lv_obj_set_style_local_text_font(ui->page3_screen_label_1, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);

	//Write codes page3_screen_ddlist_2
	ui->page3_screen_ddlist_2 = lv_dropdown_create(ui->page3_screen, NULL);
	lv_dropdown_set_options(ui->page3_screen_ddlist_2, "list1\nlist2\nlist3");
	lv_dropdown_set_max_height(ui->page3_screen_ddlist_2, 90);
	lv_dropdown_set_dir(ui->page3_screen_ddlist_2, LV_DROPDOWN_DIR_LEFT);

	//Write style LV_DROPDOWN_PART_MAIN for page3_screen_ddlist_2
	static lv_style_t style_page3_screen_ddlist_2_main;
	lv_style_init(&style_page3_screen_ddlist_2_main);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_ddlist_2_main
	lv_style_set_radius(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_line_space(&style_page3_screen_ddlist_2_main, LV_STATE_DEFAULT, 20);
	lv_obj_add_style(ui->page3_screen_ddlist_2, LV_DROPDOWN_PART_MAIN, &style_page3_screen_ddlist_2_main);

	//Write style LV_DROPDOWN_PART_SELECTED for page3_screen_ddlist_2
	static lv_style_t style_page3_screen_ddlist_2_selected;
	lv_style_init(&style_page3_screen_ddlist_2_selected);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_ddlist_2_selected
	lv_style_set_radius(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_color(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_bg_grad_dir(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_page3_screen_ddlist_2_selected, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_obj_add_style(ui->page3_screen_ddlist_2, LV_DROPDOWN_PART_SELECTED, &style_page3_screen_ddlist_2_selected);

	//Write style LV_DROPDOWN_PART_LIST for page3_screen_ddlist_2
	static lv_style_t style_page3_screen_ddlist_2_list;
	lv_style_init(&style_page3_screen_ddlist_2_list);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_ddlist_2_list
	lv_style_set_radius(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_ddlist_2_list, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_obj_add_style(ui->page3_screen_ddlist_2, LV_DROPDOWN_PART_LIST, &style_page3_screen_ddlist_2_list);
	lv_obj_set_pos(ui->page3_screen_ddlist_2, 325, 60);
	lv_obj_set_width(ui->page3_screen_ddlist_2, 130);

	//Write codes page3_screen_label_2
	ui->page3_screen_label_2 = lv_label_create(ui->page3_screen, NULL);
	lv_label_set_text(ui->page3_screen_label_2, "slider");
	lv_label_set_long_mode(ui->page3_screen_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->page3_screen_label_2, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for page3_screen_label_2
	static lv_style_t style_page3_screen_label_2_main;
	lv_style_init(&style_page3_screen_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_label_2_main
	lv_style_set_radius(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_font(&style_page3_screen_label_2_main, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_obj_add_style(ui->page3_screen_label_2, LV_LABEL_PART_MAIN, &style_page3_screen_label_2_main);
	lv_obj_set_pos(ui->page3_screen_label_2, 187, 204);
	lv_obj_set_size(ui->page3_screen_label_2, 100, 0);


	//Write codes page3_screen_cb_2
	ui->page3_screen_cb_2 = lv_checkbox_create(ui->page3_screen, NULL);
	lv_checkbox_set_text(ui->page3_screen_cb_2, "checkbox 2");

	//Write style LV_CHECKBOX_PART_BG for page3_screen_cb_2
	static lv_style_t style_page3_screen_cb_2_bg;
	lv_style_init(&style_page3_screen_cb_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_2_bg
	lv_style_set_radius(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_style_set_text_letter_space(&style_page3_screen_cb_2_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_2, LV_CHECKBOX_PART_BG, &style_page3_screen_cb_2_bg);

	//Write style LV_CHECKBOX_PART_BULLET for page3_screen_cb_2
	static lv_style_t style_page3_screen_cb_2_bullet;
	lv_style_init(&style_page3_screen_cb_2_bullet);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_2_bullet
	lv_style_set_radius(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_border_width(&style_page3_screen_cb_2_bullet, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_2, LV_CHECKBOX_PART_BULLET, &style_page3_screen_cb_2_bullet);
	lv_obj_set_pos(ui->page3_screen_cb_2, 9, 97);

	//Write codes page3_screen_cb_3
	ui->page3_screen_cb_3 = lv_checkbox_create(ui->page3_screen, NULL);
	lv_checkbox_set_text(ui->page3_screen_cb_3, "checkbox 3");

	//Write style LV_CHECKBOX_PART_BG for page3_screen_cb_3
	static lv_style_t style_page3_screen_cb_3_bg;
	lv_style_init(&style_page3_screen_cb_3_bg);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_3_bg
	lv_style_set_radius(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_style_set_text_letter_space(&style_page3_screen_cb_3_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_3, LV_CHECKBOX_PART_BG, &style_page3_screen_cb_3_bg);

	//Write style LV_CHECKBOX_PART_BULLET for page3_screen_cb_3
	static lv_style_t style_page3_screen_cb_3_bullet;
	lv_style_init(&style_page3_screen_cb_3_bullet);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_3_bullet
	lv_style_set_radius(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_border_width(&style_page3_screen_cb_3_bullet, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_3, LV_CHECKBOX_PART_BULLET, &style_page3_screen_cb_3_bullet);
	lv_obj_set_pos(ui->page3_screen_cb_3, 9, 133);

	//Write codes page3_screen_cb_4
	ui->page3_screen_cb_4 = lv_checkbox_create(ui->page3_screen, NULL);
	lv_checkbox_set_text(ui->page3_screen_cb_4, "checkbox 4");

	//Write style LV_CHECKBOX_PART_BG for page3_screen_cb_4
	static lv_style_t style_page3_screen_cb_4_bg;
	lv_style_init(&style_page3_screen_cb_4_bg);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_4_bg
	lv_style_set_radius(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, &lv_font_klavika_bold_12);
	lv_style_set_text_letter_space(&style_page3_screen_cb_4_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_4, LV_CHECKBOX_PART_BG, &style_page3_screen_cb_4_bg);

	//Write style LV_CHECKBOX_PART_BULLET for page3_screen_cb_4
	static lv_style_t style_page3_screen_cb_4_bullet;
	lv_style_init(&style_page3_screen_cb_4_bullet);

	//Write style state: LV_STATE_DEFAULT for style_page3_screen_cb_4_bullet
	lv_style_set_radius(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_border_width(&style_page3_screen_cb_4_bullet, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->page3_screen_cb_4, LV_CHECKBOX_PART_BULLET, &style_page3_screen_cb_4_bullet);
	lv_obj_set_pos(ui->page3_screen_cb_4, 9, 171);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(return_to_home_cb,30000, LV_TASK_PRIO_HIGH, ui);
	lv_task_t *set_obj_value = lv_task_create(change_obj_value_cb,1000,LV_TASK_PRIO_HIGH,ui);

}

void change_obj_value_cb(lv_task_t *task)
{
	lv_ui *ui = task->user_data;
	lv_dropdown_open(ui->page3_screen_ddlist_2);
	lv_dropdown_open(ui->page3_screen_ddlist_1);
	lv_slider_set_value(ui->page3_screen_slider_1, 80, LV_ANIM_OFF);
	lv_switch_on(ui->page3_screen_sw_1, LV_ANIM_OFF);
	lv_checkbox_set_checked(ui->page3_screen_cb_2, 1 );
	lv_checkbox_set_checked(ui->page3_screen_cb_4, 1);
	lv_checkbox_set_disabled(ui->page3_screen_cb_1);
	lv_checkbox_set_disabled(ui->page3_screen_cb_3);
	lv_task_del(task);
}

void return_to_home_cb(lv_task_t *task){
	lv_ui *ui = task->user_data;

	lv_task_del(task);
	lv_event_send(ui->page3_screen, LV_EVENT_LEAVE, NULL);

}
