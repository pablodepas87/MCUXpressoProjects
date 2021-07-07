/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_obj_t * create_slider(lv_color_t color);
static void slider_event_cb(lv_event_t * e);
static void sliders_change_value_task(lv_task_t *task);
static void go_home_callb(lv_task_t *task);

static lv_obj_t * red_slider, * green_slider, * blue_slider, * intense_slider;
static lv_obj_t * img_logo_micro;
static lv_group_t *g;
static lv_task_t *scroll_task;

void setup_scr_page6_screen(lv_ui *ui){

	//Write codes page6_screen
	ui->page6_screen = lv_obj_create(NULL, NULL);

	ui->pag1_cont_1 = lv_cont_create(ui->page6_screen, NULL);

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
	ui->pag1_page_title = lv_label_create(ui->page6_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "SLIDERS-IMAGE");
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

	/*Create 4 sliders to adjust RGB color and re-color intensity*/
	red_slider = create_slider(LV_COLOR_RED);
	green_slider = create_slider(LV_COLOR_GREEN);
	blue_slider = create_slider(LV_COLOR_BLUE);
	intense_slider = create_slider(LV_COLOR_GRAY);

	lv_slider_set_value(red_slider, LV_OPA_20, LV_ANIM_OFF);
	lv_slider_set_value(green_slider, LV_OPA_90, LV_ANIM_OFF);
	lv_slider_set_value(blue_slider, LV_OPA_60, LV_ANIM_OFF);
	lv_slider_set_value(intense_slider, LV_OPA_50, LV_ANIM_OFF);

	lv_obj_align(red_slider, NULL, LV_ALIGN_IN_LEFT_MID, 50, 10);
	lv_obj_align(green_slider, red_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
	lv_obj_align(blue_slider, green_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
	lv_obj_align(intense_slider, blue_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);

	img_logo_micro = lv_img_create(ui->page6_screen,NULL);
	lv_img_set_src(img_logo_micro, &_logo_micro_alpha_150x93);
	lv_obj_align(img_logo_micro,NULL, LV_ALIGN_IN_RIGHT_MID, -40, 0);

	lv_event_send(intense_slider, LV_EVENT_VALUE_CHANGED, 80);

	lv_group_add_obj(g, red_slider);
	lv_group_add_obj(g, green_slider);
	lv_group_add_obj(g, blue_slider);
	lv_group_add_obj(g, intense_slider);

	scroll_task = lv_task_create(sliders_change_value_task,100,LV_TASK_PRIO_HIGH,ui);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(go_home_callb,30000, LV_TASK_PRIO_HIGH, ui);
}

static void slider_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);

    /*Recolor the image based on the sliders' values*/
    lv_color_t color  = lv_color_make(lv_slider_get_value(red_slider), lv_slider_get_value(green_slider), lv_slider_get_value(blue_slider));
    lv_opa_t intense = lv_slider_get_value(intense_slider);
    lv_obj_set_style_local_image_recolor_opa(img_logo_micro, NULL, LV_STATE_DEFAULT, intense);
    lv_obj_set_style_local_image_recolor(img_logo_micro,NULL,LV_STATE_DEFAULT, color);
}

static lv_obj_t * create_slider(lv_color_t color)
{
    lv_obj_t * slider = lv_slider_create(guider_ui.page6_screen,NULL);
    lv_slider_set_range(slider, 0, 255);
    lv_obj_set_size(slider, 10, 200);
    lv_obj_set_style_local_bg_color(slider,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT, color);
    lv_obj_set_style_local_bg_color(slider, LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,lv_color_darken(color, LV_OPA_40));
    lv_obj_set_event_cb(slider, slider_event_cb);

    return slider;
}

void sliders_change_value_task(lv_task_t *task)
{
	if (lv_slider_get_value(red_slider) < 255)
	{
		lv_slider_set_value(red_slider, lv_slider_get_value(red_slider)+1, LV_ANIM_OFF);
		lv_event_send(red_slider, LV_EVENT_VALUE_CHANGED,NULL);
	} else {
		lv_slider_set_value(red_slider, 0, LV_ANIM_OFF);
		lv_event_send(red_slider, LV_EVENT_VALUE_CHANGED, 0);
	}


	if (lv_slider_get_value(blue_slider) < 255)
	{
		lv_slider_set_value(blue_slider, lv_slider_get_value(blue_slider)+1, LV_ANIM_OFF);
		lv_event_send(blue_slider, LV_EVENT_VALUE_CHANGED, NULL);
	} else {
		lv_slider_set_value(blue_slider, 0, LV_ANIM_OFF);
		lv_event_send(blue_slider, LV_EVENT_VALUE_CHANGED, 0);
	}

	if (lv_slider_get_value(green_slider) < 255)
	{
		lv_slider_set_value(green_slider, lv_slider_get_value(green_slider)+1, LV_ANIM_OFF);
		lv_event_send(green_slider, LV_EVENT_VALUE_CHANGED,NULL);
	} else {
		lv_slider_set_value(green_slider, 0, LV_ANIM_OFF);
		lv_event_send(green_slider, LV_EVENT_VALUE_CHANGED, 0);
	}

	if (lv_slider_get_value(intense_slider) < 255)
	{
		lv_slider_set_value(intense_slider, lv_slider_get_value(intense_slider)+1, LV_ANIM_OFF);
		lv_event_send(intense_slider, LV_EVENT_VALUE_CHANGED, NULL);
	} else {
		lv_slider_set_value(intense_slider, 0, LV_ANIM_OFF);
		lv_event_send(intense_slider, LV_EVENT_VALUE_CHANGED, NULL);
	}
}

void go_home_callb(lv_task_t *task)
{
	lv_ui *ui = task->user_data;
	lv_task_del(scroll_task);
	lv_obj_del(intense_slider);
	lv_obj_del(red_slider);
	lv_obj_del(blue_slider);
	lv_obj_del(green_slider);

	lv_task_del(task);
	lv_event_send(ui->page6_screen, LV_EVENT_LEAVE, NULL);
}
