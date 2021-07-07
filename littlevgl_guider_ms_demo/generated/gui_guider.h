/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *splash_screen;
	lv_obj_t *splash_screen_bkg_panel;
	lv_obj_t *splash_screen_img_logo;
	lv_obj_t *splash_screen_label_welcome;
	lv_obj_t *splash_screen_bar_1;
	lv_obj_t *splash_screen_label_1;
	lv_obj_t *homepage_screen;
	lv_obj_t *homepage_screen_bkg_obj;
	lv_obj_t *homepage_screen_img_ms_logo;
	lv_obj_t *homepage_screen_btn_1;
	lv_obj_t *homepage_screen_btn_1_label;
	lv_obj_t *homepage_screen_btn_2;
	lv_obj_t *homepage_screen_btn_2_label;
	lv_obj_t *homepage_screen_btn_3;
	lv_obj_t *homepage_screen_btn_3_label;
	lv_obj_t *homepage_screen_btn_4;
	lv_obj_t *homepage_screen_btn_4_label;
	lv_obj_t *homepage_screen_btn_5;
	lv_obj_t *homepage_screen_btn_5_label;
	lv_obj_t *homepage_screen_btn_6;
	lv_obj_t *homepage_screen_btn_6_label;
	lv_obj_t *homepage_screen_btn_7;
	lv_obj_t *homepage_screen_btn_7_label;
	lv_obj_t *homepage_screen_btn_8;
	lv_obj_t *homepage_screen_btn_8_label;
	lv_obj_t *homepage_screen_btn_9;
	lv_obj_t *homepage_screen_btn_9_label;
	lv_obj_t *page1_screen;
	lv_obj_t *page1_screen_title;
	lv_obj_t *page1_screen_cont;
	lv_obj_t *pag1_calendar_1;
	lv_obj_t *pag1_cont_1;
	lv_obj_t *page1_calendar;
	lv_obj_t *pag1_page_title;
	lv_obj_t *pag1_roller_minutes;
	lv_obj_t *pag1_label_double_dot;
	lv_obj_t *pag1_roller_hour;
	lv_obj_t *page2_screen;
	lv_obj_t *page2_screen_text_area;
	lv_obj_t *page2_screen_title;
	lv_obj_t *page3_screen;
	lv_obj_t *page3_screen_title;
	lv_obj_t *page3_screen_cb_1;
	lv_obj_t *page3_screen_cb_2;
	lv_obj_t *page3_screen_cb_3;
	lv_obj_t *page3_screen_cb_4;
	lv_obj_t *page3_screen_ddlist_1;
	lv_obj_t *page3_screen_ddlist_2;
	lv_obj_t *page3_screen_btn_1;
	lv_obj_t *page3_screen_btn_1_label;
	lv_obj_t *page3_screen_sw_1;
	lv_obj_t *page3_screen_label_1;
	lv_obj_t *page3_screen_label_2;
	lv_obj_t *page3_screen_slider_1;
	lv_obj_t *page4_screen;
	lv_obj_t *page4_screen_table_1;
	lv_obj_t *page5_screen;
	lv_obj_t *page5_screen_title;
	lv_obj_t *page6_screen;
	lv_obj_t *page6_screen_title;
	lv_obj_t *page7_screen;
	lv_obj_t *page7_screen_label_1;
	lv_obj_t *page7_screen_title;
	lv_obj_t *page8_screen;
	lv_obj_t *page8_screen_title;
	lv_obj_t *page9_screen;
	lv_obj_t *page9_screen_chart_tabview;
	lv_obj_t *page9_screen_chart_tabview_title1;
	lv_obj_t *page9_screen_chart_tabview_title2;
	lv_obj_t *page9_screen_chart_tabview_title3;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_splash_screen(lv_ui *ui);
void setup_scr_homepage_screen(lv_ui *ui);
void setup_scr_page1_screen(lv_ui *ui);
void setup_scr_page2_screen(lv_ui *ui);
void setup_scr_page3_screen(lv_ui *ui);
void setup_scr_page4_screen(lv_ui *ui);
void setup_scr_page5_screen(lv_ui *ui);
void setup_scr_page6_screen(lv_ui *ui);
void setup_scr_page7_screen(lv_ui *ui);
void setup_scr_page8_screen(lv_ui *ui);
void setup_scr_page9_screen(lv_ui *ui);

LV_IMG_DECLARE(_logo_micro_alpha_150x93);

#ifdef __cplusplus
}
#endif
#endif
