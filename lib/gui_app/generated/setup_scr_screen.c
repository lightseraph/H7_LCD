/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom/custom.h"

void setup_scr_screen(lv_ui *ui)
{

	// Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
	static lv_style_t style_screen_main_main_default;
	if (style_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_main_main_default);
	else
		lv_style_init(&style_screen_main_main_default);
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xd6, 0xff, 0xfa));
	lv_style_set_bg_opa(&style_screen_main_main_default, 255);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_counter
	ui->screen_counter = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_counter, 190, 256);
	lv_obj_set_size(ui->screen_counter, 100, 147);
	lv_obj_set_scrollbar_mode(ui->screen_counter, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_counter, "0");
	lv_label_set_long_mode(ui->screen_counter, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_screen_counter_main_main_default
	static lv_style_t style_screen_counter_main_main_default;
	if (style_screen_counter_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_counter_main_main_default);
	else
		lv_style_init(&style_screen_counter_main_main_default);
	lv_style_set_radius(&style_screen_counter_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_counter_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_counter_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_counter_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_counter_main_main_default, 0);
	lv_style_set_text_color(&style_screen_counter_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_counter_main_main_default, &lv_font_arial_48);
	lv_style_set_text_letter_space(&style_screen_counter_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_counter_main_main_default, 0);
	lv_style_set_text_align(&style_screen_counter_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_counter_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_counter_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_counter_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_counter_main_main_default, 0);
	lv_obj_add_style(ui->screen_counter, &style_screen_counter_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_plus
	ui->screen_plus = lv_btn_create(ui->screen);
	lv_obj_set_pos(ui->screen_plus, 88, 551);
	lv_obj_set_size(ui->screen_plus, 120, 33);
	lv_obj_set_scrollbar_mode(ui->screen_plus, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_plus_main_main_default
	static lv_style_t style_screen_plus_main_main_default;
	if (style_screen_plus_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_plus_main_main_default);
	else
		lv_style_init(&style_screen_plus_main_main_default);
	lv_style_set_radius(&style_screen_plus_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_plus_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_plus_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_plus_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_plus_main_main_default, 255);
	lv_style_set_border_color(&style_screen_plus_main_main_default, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_plus_main_main_default, 2);
	lv_style_set_border_opa(&style_screen_plus_main_main_default, 255);
	lv_style_set_text_color(&style_screen_plus_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_plus_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_screen_plus_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_plus, &style_screen_plus_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->screen_plus_label = lv_label_create(ui->screen_plus);
	lv_label_set_text(ui->screen_plus_label, "Plus");
	lv_obj_set_style_pad_all(ui->screen_plus, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_plus_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes screen_minus
	ui->screen_minus = lv_btn_create(ui->screen);
	lv_obj_set_pos(ui->screen_minus, 272, 545);
	lv_obj_set_size(ui->screen_minus, 120, 39);
	lv_obj_set_scrollbar_mode(ui->screen_minus, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_minus_main_main_default
	static lv_style_t style_screen_minus_main_main_default;
	if (style_screen_minus_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_minus_main_main_default);
	else
		lv_style_init(&style_screen_minus_main_main_default);
	lv_style_set_radius(&style_screen_minus_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_minus_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_minus_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_minus_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_minus_main_main_default, 255);
	lv_style_set_border_color(&style_screen_minus_main_main_default, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_minus_main_main_default, 2);
	lv_style_set_border_opa(&style_screen_minus_main_main_default, 255);
	lv_style_set_text_color(&style_screen_minus_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_minus_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_screen_minus_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_minus, &style_screen_minus_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->screen_minus_label = lv_label_create(ui->screen_minus);
	lv_label_set_text(ui->screen_minus_label, "Minus");
	lv_obj_set_style_pad_all(ui->screen_minus, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_minus_label, LV_ALIGN_CENTER, 0, 0);

	// Init events for screen
	events_init_screen(ui);
}