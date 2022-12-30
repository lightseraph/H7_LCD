/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

void init_scr_del_flag(lv_ui *ui)
{
	ui->screen_del = true;
	ui->date_setting_del = true;
	ui->zigbee_setting_del = true;
}

void setup_ui(lv_ui *ui)
{
	init_scr_del_flag(ui);
	setup_scr_screen(ui);
	setup_scr_date_setting(ui);
	lv_scr_load(ui->date_setting);
}
