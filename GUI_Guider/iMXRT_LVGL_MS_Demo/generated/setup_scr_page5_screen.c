/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_page5_screen(lv_ui *ui){

	//Write codes page5_screen
	ui->page5_screen = lv_obj_create(NULL, NULL);
	lv_anim_path_t lv_anim_path_page5_screen_led_1 = {.cb = lv_anim_path_bounce};

	//Write codes page5_screen_led_1
	ui->page5_screen_led_1 = lv_led_create(ui->page5_screen, NULL);

	//Write style LV_LED_PART_MAIN for page5_screen_led_1
	static lv_style_t style_page5_screen_led_1_main;
	lv_style_init(&style_page5_screen_led_1_main);

	//Write style state: LV_STATE_DEFAULT for style_page5_screen_led_1_main
	lv_style_set_radius(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, 20);
	lv_style_set_bg_color(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_shadow_width(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_border_color(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_page5_screen_led_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->page5_screen_led_1, LV_LED_PART_MAIN, &style_page5_screen_led_1_main);
	lv_obj_set_pos(ui->page5_screen_led_1, 29, 212);
	lv_obj_set_size(ui->page5_screen_led_1, 40, 40);

	//Write animation: page5_screen_led_1move in x direction
	lv_anim_t page5_screen_led_1_x;
	lv_anim_init(&page5_screen_led_1_x);
	lv_anim_set_var(&page5_screen_led_1_x, ui->page5_screen_led_1);
	lv_anim_set_time(&page5_screen_led_1_x, 400);
	lv_anim_set_exec_cb(&page5_screen_led_1_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
	lv_anim_set_values(&page5_screen_led_1_x, lv_obj_get_x(ui->page5_screen_led_1), 240);
	_lv_memcpy_small(&page5_screen_led_1_x.path, &lv_anim_path_page5_screen_led_1, sizeof(lv_anim_path_cb_t));
	lv_anim_start(&page5_screen_led_1_x);

	//Write animation: page5_screen_led_1move in y direction
	lv_anim_t page5_screen_led_1_y;
	lv_anim_init(&page5_screen_led_1_y);
	lv_anim_set_var(&page5_screen_led_1_y, ui->page5_screen_led_1);
	lv_anim_set_time(&page5_screen_led_1_y, 400);
	lv_anim_set_exec_cb(&page5_screen_led_1_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
	lv_anim_set_values(&page5_screen_led_1_y, lv_obj_get_y(ui->page5_screen_led_1), 30);
	_lv_memcpy_small(&page5_screen_led_1_y.path, &lv_anim_path_page5_screen_led_1, sizeof(lv_anim_path_cb_t));
	lv_anim_start(&page5_screen_led_1_y);

	lv_led_set_bright(ui->page5_screen_led_1, 200);
}