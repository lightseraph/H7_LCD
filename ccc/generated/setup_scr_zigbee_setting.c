/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_zigbee_setting(lv_ui *ui){

	//Write codes zigbee_setting
	ui->zigbee_setting = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->zigbee_setting, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_zigbee_setting_main_main_default
	static lv_style_t style_zigbee_setting_main_main_default;
	if (style_zigbee_setting_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_zigbee_setting_main_main_default);
	else
		lv_style_init(&style_zigbee_setting_main_main_default);
	lv_style_set_bg_color(&style_zigbee_setting_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_zigbee_setting_main_main_default, 255);
	lv_obj_add_style(ui->zigbee_setting, &style_zigbee_setting_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes zigbee_setting_label_1
	ui->zigbee_setting_label_1 = lv_label_create(ui->zigbee_setting);
	lv_obj_set_pos(ui->zigbee_setting_label_1, 710, 2);
	lv_obj_set_size(ui->zigbee_setting_label_1, 30, 30);
	lv_obj_set_scrollbar_mode(ui->zigbee_setting_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->zigbee_setting_label_1, "\xEF\x83\xA7");
	lv_label_set_long_mode(ui->zigbee_setting_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_zigbee_setting_label_1_main_main_default
	static lv_style_t style_zigbee_setting_label_1_main_main_default;
	if (style_zigbee_setting_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_zigbee_setting_label_1_main_main_default);
	else
		lv_style_init(&style_zigbee_setting_label_1_main_main_default);
	lv_style_set_radius(&style_zigbee_setting_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_zigbee_setting_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_zigbee_setting_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_zigbee_setting_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_zigbee_setting_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_zigbee_setting_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_zigbee_setting_label_1_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_letter_space(&style_zigbee_setting_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_zigbee_setting_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_zigbee_setting_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_zigbee_setting_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_zigbee_setting_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_zigbee_setting_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_zigbee_setting_label_1_main_main_default, 0);
	lv_obj_add_style(ui->zigbee_setting_label_1, &style_zigbee_setting_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes zigbee_setting_label_2
	ui->zigbee_setting_label_2 = lv_label_create(ui->zigbee_setting);
	lv_obj_set_pos(ui->zigbee_setting_label_2, 68, 53);
	lv_obj_set_size(ui->zigbee_setting_label_2, 186, 33);
	lv_obj_set_scrollbar_mode(ui->zigbee_setting_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->zigbee_setting_label_2, "Zigbee设置");
	lv_label_set_long_mode(ui->zigbee_setting_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_zigbee_setting_label_2_main_main_default
	static lv_style_t style_zigbee_setting_label_2_main_main_default;
	if (style_zigbee_setting_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_zigbee_setting_label_2_main_main_default);
	else
		lv_style_init(&style_zigbee_setting_label_2_main_main_default);
	lv_style_set_radius(&style_zigbee_setting_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_zigbee_setting_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_zigbee_setting_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_zigbee_setting_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_zigbee_setting_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_zigbee_setting_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_zigbee_setting_label_2_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_letter_space(&style_zigbee_setting_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_zigbee_setting_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_zigbee_setting_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_zigbee_setting_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_zigbee_setting_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_zigbee_setting_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_zigbee_setting_label_2_main_main_default, 0);
	lv_obj_add_style(ui->zigbee_setting_label_2, &style_zigbee_setting_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}