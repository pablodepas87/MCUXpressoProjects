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

		/*Create a page*/
		lv_obj_t * page = lv_page_create(ui->page4_screen, NULL);
		lv_obj_set_size(page, 480, 230);
		lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 20);

//		/*Create a label on the page*/
//		lv_obj_t * label = lv_label_create(page, NULL);
//		lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
//		lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
//		lv_label_set_text(label, "Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n"
//				"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
//				"Ut enim ad minim veniam, quis nostrud exercitation ullamco\n"
//				"laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure\n"
//				"dolor in reprehenderit in voluptate velit esse cillum dolore\n"
//				"eu fugiat nulla pariatur.\n"
//				"Excepteur sint occaecat cupidatat non proident, sunt in culpa\n"
//				"qui officia deserunt mollit anim id est laborum.");


		//Write codes page4_screen_table_1
		ui->page4_screen_table_1 = lv_table_create(page, NULL);

		//Write style LV_TABLE_PART_BG for page4_screen_table_1
		static lv_style_t style_page4_screen_table_1_bg;
		lv_style_init(&style_page4_screen_table_1_bg);

		//Write style state: LV_STATE_DEFAULT for style_page4_screen_table_1_bg
		lv_style_set_bg_color(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd9, 0xdb, 0xdd));
		lv_style_set_bg_grad_color(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
		lv_style_set_bg_grad_dir(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
		lv_style_set_bg_opa(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, 255);
		lv_style_set_border_color(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, lv_color_make(0xae, 0xbf, 0xc5));
		lv_style_set_border_width(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, 1);
		lv_style_set_text_color(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, lv_color_make(0x2a, 0x4e, 0xcf));
		lv_style_set_text_decor(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, LV_TEXT_DECOR_NONE);
		lv_style_set_pad_left(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, 5);
		lv_style_set_pad_right(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, 5);
		lv_style_set_pad_top(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, 5);
		lv_style_set_pad_bottom(&style_page4_screen_table_1_bg, LV_STATE_DEFAULT, 5);
		lv_obj_add_style(ui->page4_screen_table_1, LV_TABLE_PART_BG, &style_page4_screen_table_1_bg);

		//Write style LV_TABLE_PART_CELL1 for page4_screen_table_1
		static lv_style_t style_page4_screen_table_1_cell1;
		lv_style_init(&style_page4_screen_table_1_cell1);

		//Write style state: LV_STATE_DEFAULT for style_page4_screen_table_1_cell1
		lv_style_set_border_color(&style_page4_screen_table_1_cell1, LV_STATE_DEFAULT, lv_color_make(0xd5, 0xde, 0xe6));
		lv_style_set_border_width(&style_page4_screen_table_1_cell1, LV_STATE_DEFAULT, 1);
		lv_obj_add_style(ui->page4_screen_table_1, LV_TABLE_PART_CELL1, &style_page4_screen_table_1_cell1);
		lv_obj_set_pos(ui->page4_screen_table_1, 0, 0);
		lv_table_set_col_cnt(ui->page4_screen_table_1,8);
		lv_table_set_row_cnt(ui->page4_screen_table_1,8);
		lv_table_set_cell_value(ui->page4_screen_table_1,0,0,"Name");
		lv_table_set_cell_value(ui->page4_screen_table_1,1,0,"Apple");
		lv_table_set_cell_value(ui->page4_screen_table_1,2,0,"Banana");
		lv_table_set_cell_value(ui->page4_screen_table_1,3,0,"Citron");
		lv_table_set_cell_value(ui->page4_screen_table_1,4,0,"Lime");
		lv_table_set_cell_value(ui->page4_screen_table_1,5,0,"Strawberry");
		lv_table_set_cell_value(ui->page4_screen_table_1,6,0,"Orange");
		lv_table_set_cell_value(ui->page4_screen_table_1,7,0,"Lime");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,1,"Price");
		lv_table_set_cell_value(ui->page4_screen_table_1,1,1,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,2,1,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,3,1,"$3");
		lv_table_set_cell_value(ui->page4_screen_table_1,4,1,"$6");
		lv_table_set_cell_value(ui->page4_screen_table_1,5,1,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,6,1,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,7,1,"$6");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,2,"eiusmod");
		lv_table_set_cell_value(ui->page4_screen_table_1,1,2,"4");
		lv_table_set_cell_value(ui->page4_screen_table_1,2,2,"8");
		lv_table_set_cell_value(ui->page4_screen_table_1,3,2,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,4,2,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,5,2,"8");
		lv_table_set_cell_value(ui->page4_screen_table_1,6,2,"9");
		lv_table_set_cell_value(ui->page4_screen_table_1,7,2,"$1");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,3,"tempor");
		lv_table_set_cell_value(ui->page4_screen_table_1,1,3,"16");
		lv_table_set_cell_value(ui->page4_screen_table_1,2,3,"12");
		lv_table_set_cell_value(ui->page4_screen_table_1,3,3,"8");
		lv_table_set_cell_value(ui->page4_screen_table_1,4,3,"8");
		lv_table_set_cell_value(ui->page4_screen_table_1,5,3,"12");
		lv_table_set_cell_value(ui->page4_screen_table_1,6,3,"12");
		lv_table_set_cell_value(ui->page4_screen_table_1,7,3,"8");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,4," incididunt");
		lv_table_set_cell_value(ui->page4_screen_table_1,1,4,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,2,4,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,3,4,"12");
		lv_table_set_cell_value(ui->page4_screen_table_1,4,4,"10");
		lv_table_set_cell_value(ui->page4_screen_table_1,5,4,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,6,4,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,7,4,"10");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,5,"ut");
		lv_table_set_cell_value(ui->page4_screen_table_1,1,5,"ipsum");
		lv_table_set_cell_value(ui->page4_screen_table_1,2,5,"ipsum");
		lv_table_set_cell_value(ui->page4_screen_table_1,3,5,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,4,5,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,5,5,"ipsum");
		lv_table_set_cell_value(ui->page4_screen_table_1,6,5,"ipsum");
		lv_table_set_cell_value(ui->page4_screen_table_1,7,5,"lorem");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,6,"labore");
		lv_table_set_cell_value(ui->page4_screen_table_1,0,7," dolore");
		lv_obj_set_style_local_pad_left(ui->page4_screen_table_1, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);
		lv_obj_set_style_local_pad_right(ui->page4_screen_table_1, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);
		lv_obj_set_style_local_pad_top(ui->page4_screen_table_1, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);
		lv_obj_set_style_local_pad_bottom(ui->page4_screen_table_1, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);


		events_init_retun_to_homepage(ui);
		lv_task_t *go_back_task = lv_task_create(send_event_return_to_home,10000, LV_TASK_PRIO_HIGH, ui);
}
