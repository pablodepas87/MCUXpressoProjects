/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


static void line_meter_event_cb(lv_event_t * e);
void increase_line_meter_cb(lv_task_t *task);
void go_home_callb(lv_task_t *task);
static void arc_loader(lv_task_t * t);

char *lmeter_value_str;
lv_obj_t * lmeter;
lv_obj_t * arc;
lv_task_t *increase_line_meter_value;

void setup_scr_page7_screen(lv_ui *ui){

	//Write codes page7_screen
	ui->page7_screen = lv_obj_create(NULL, NULL);

	ui->pag1_cont_1 = lv_cont_create(ui->page7_screen, NULL);

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
	ui->pag1_page_title = lv_label_create(ui->page7_screen, NULL);
	lv_label_set_text(ui->pag1_page_title, "LINE-METER \n");
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


	//Write codes page5_screen_lmeter_1
	lmeter = lv_linemeter_create(ui->page7_screen, NULL);

	//Write style LV_LINEMETER_PART_MAIN for page5_screen_lmeter_1
	static lv_style_t style_page7_screen_lmeter_1_main;
	lv_style_init(&style_page7_screen_lmeter_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_lmeter_1_main
	lv_style_set_radius(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 1);
	lv_style_set_bg_color(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_line_color(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xc8, 0xde, 0x00));
	lv_style_set_line_width(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_style_set_line_opa(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x8f, 0x93, 0x94));
	lv_style_set_scale_end_color(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_width(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 16);
	lv_style_set_scale_end_line_width(&style_page7_screen_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(lmeter, LV_LINEMETER_PART_MAIN, &style_page7_screen_lmeter_1_main);
	lv_obj_align(lmeter, NULL, LV_ALIGN_IN_LEFT_MID, 10, 40);
	lv_obj_set_size(lmeter, 120, 120);
	lv_linemeter_set_scale(lmeter, 300, 35);
	lv_linemeter_set_range(lmeter, 0, 180);
	lv_linemeter_set_value(lmeter, 100);
	lv_linemeter_set_angle_offset(lmeter, 0);
    lv_obj_set_event_cb(lmeter, line_meter_event_cb);

	/*Create an Arc*/
	arc = lv_arc_create(ui->page7_screen, NULL);
	lv_obj_set_size(arc, 120, 120);
	lv_arc_set_bg_angles(arc, 0, 360);
	lv_arc_set_angles(arc, 270, 270);
	lv_obj_align(arc, NULL, LV_ALIGN_CENTER, 0, 0);

	//creo l'oggetto attraverso una task
	lv_task_create(arc_loader, 200, LV_TASK_PRIO_LOWEST, arc);

	increase_line_meter_value = lv_task_create(increase_line_meter_cb,50, LV_TASK_PRIO_HIGH, ui);


	/*Create a Preloader object*/
	lv_obj_t * preload = lv_spinner_create(ui->page7_screen, NULL);
	lv_obj_set_size(preload, 100, 100);
	lv_obj_align(preload, NULL, LV_ALIGN_IN_RIGHT_MID, -20, 0);

	events_init_retun_to_homepage(ui);
	lv_task_t *go_back_task = lv_task_create(go_home_callb,20000, LV_TASK_PRIO_HIGH, ui);
}

static void line_meter_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);

    /*Recolor the image based on the sliders' values*/
    if(lv_linemeter_get_value(lmeter)<180){
    	lv_linemeter_set_value(lmeter, lv_linemeter_get_value(lmeter)+1);
    } else {
    	lv_linemeter_set_value(lmeter, 0);
    }
}

void increase_line_meter_cb(lv_task_t *task)
{
	lv_event_send(lmeter, LV_EVENT_VALUE_CHANGED, NULL);
}

void go_home_callb(lv_task_t *task)
{
	lv_ui *ui = task->user_data;
	lv_event_send(ui->page7_screen, LV_EVENT_LEAVE, NULL);
	lv_task_del(increase_line_meter_value);
	lv_task_del(task);
}

static void arc_loader(lv_task_t * t)
{
    static int16_t a = 270;

    a+=5;

    lv_arc_set_end_angle(t->user_data, a);

    if(a >= 270 + 360) {
        lv_task_del(t);
        return;
    }
}

