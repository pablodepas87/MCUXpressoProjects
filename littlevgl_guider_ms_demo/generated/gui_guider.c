/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void setup_ui(lv_ui *ui){
	setup_scr_splash_screen(ui);
	//setup_scr_page2_screen(ui);
	lv_scr_load(ui->splash_screen);
}
