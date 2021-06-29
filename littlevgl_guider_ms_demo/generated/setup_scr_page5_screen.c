/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

void return_to_home_cback(lv_task_t *task);

static void set_angle(void * img, int32_t v)
{
    lv_img_set_angle(img, v);
}

static void set_zoom(void * img, int32_t v)
{
    lv_img_set_zoom(img, v);
}

static void anim_x_cb(void * var, int32_t v)
{
    lv_obj_set_x(var, v);
}

static void anim_size_cb(void * var, int32_t v)
{
    lv_obj_set_size(var, v, v);
}

void setup_scr_page5_screen(lv_ui *ui){

	//Write codes page5_screen
	ui->page5_screen = lv_obj_create(NULL, NULL);

	ui->pag1_cont_1 = lv_cont_create(ui->page5_screen, NULL);

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
	ui->pag1_page_title = lv_label_create(ui->page5_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "ANIMATIONS");
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


	/*Now create the actual image*/
	lv_obj_t * img = lv_img_create(ui->page5_screen,NULL);
	lv_img_set_src(img, &_logo_micro_alpha_150x93);
	lv_obj_align(img,NULL, LV_ALIGN_IN_RIGHT_MID, 50, 50);
	lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_var(&a, img);
	lv_anim_set_exec_cb(&a, set_angle);
	lv_anim_set_values(&a, 0, 3600);
	lv_anim_set_time(&a, 5000);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);

	lv_anim_set_exec_cb(&a, set_zoom);
	lv_anim_set_values(&a, 90, 200);
	lv_anim_set_playback_time(&a, 3000);
	lv_anim_start(&a);


	lv_obj_t * circle = lv_obj_create(ui->page5_screen,NULL);
	lv_obj_set_style_local_radius(circle, NULL, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
	lv_obj_set_style_local_bg_color(circle,NULL,LV_STATE_DEFAULT, LV_COLOR_RED);

	lv_obj_align(circle,NULL, LV_ALIGN_IN_LEFT_MID, 10, 0);

	/* INITIALIZE AN ANIMATION
	 *-----------------------*/

	lv_anim_t anim;
	lv_anim_init(&anim);

	/* MANDATORY SETTINGS
	 *------------------*/

	/*Set the "animator" function*/
	lv_anim_set_exec_cb(&anim, (lv_anim_exec_xcb_t) anim_x_cb);

	/*Set the variable to animate*/
	lv_anim_set_var(&anim, circle);

	/*Length of the animation [ms]*/
	lv_anim_set_time(&anim, 3000);

	/*Set start and end values. E.g. 0, 150*/
	lv_anim_set_values(&anim, 0	, 200);

	/* OPTIONAL SETTINGS
	 *------------------*/

	/*Time to wait before starting the animation [ms]*/
	lv_anim_set_delay(&anim, 0);

	/*Play the animation backward too with this duration. Default is 0 (disabled) [ms]*/
	lv_anim_set_playback_time(&anim, 500);

	/*Delay before playback. Default is 0 (disabled) [ms]*/
	lv_anim_set_playback_delay(&anim, 500);

	/*Number of repetitions. Default is 1.  LV_ANIM_REPEAT_INFINIT for infinite repetition*/
	lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE);

	/*Delay before repeat. Default is 0 (disabled) [ms]*/
	lv_anim_set_repeat_delay(&anim, 0);

	/* START THE ANIMATION
	 *------------------*/
	lv_anim_start(&anim);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(return_to_home_cback,20000, LV_TASK_PRIO_HIGH, ui);

}


void return_to_home_cback(lv_task_t *task){
	lv_ui *ui = task->user_data;
	lv_event_send(ui->page5_screen, LV_EVENT_LEAVE, NULL);
	lv_task_del(task);
}
