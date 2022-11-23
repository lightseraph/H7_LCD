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
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main_main_default, 255);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img_1, 0, 0);
	lv_obj_set_size(ui->screen_img_1, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen_img_1, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_img_1_main_main_default
	static lv_style_t style_screen_img_1_main_main_default;
	if (style_screen_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_1_main_main_default);
	else
		lv_style_init(&style_screen_img_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_1, &style_screen_img_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
	lv_img_set_src(ui->screen_img_1, "C:/home/light/GUI-Guider-Projects/ccc/import/chris_barbalis.png");
#else
	lv_img_set_src(ui->screen_img_1, "S:/chris_barbalis.png");
#endif
	lv_img_set_pivot(ui->screen_img_1, 0, 0);
	lv_img_set_angle(ui->screen_img_1, 0);

	// Write codes screen_cont_1
	ui->screen_cont_1 = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_1, 375, 136);
	lv_obj_set_size(ui->screen_cont_1, 387, 290);
	lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_cont_1_main_main_default
	static lv_style_t style_screen_cont_1_main_main_default;
	if (style_screen_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_cont_1_main_main_default);
	else
		lv_style_init(&style_screen_cont_1_main_main_default);
	lv_style_set_radius(&style_screen_cont_1_main_main_default, 10);
	lv_style_set_bg_color(&style_screen_cont_1_main_main_default, lv_color_make(0xa2, 0xac, 0xbe));
	lv_style_set_bg_grad_color(&style_screen_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_cont_1_main_main_default, 141);
	lv_style_set_shadow_width(&style_screen_cont_1_main_main_default, 10);
	lv_style_set_shadow_color(&style_screen_cont_1_main_main_default, lv_color_make(0xc8, 0xd4, 0xdf));
	lv_style_set_shadow_opa(&style_screen_cont_1_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_cont_1_main_main_default, 5);
	lv_style_set_shadow_ofs_x(&style_screen_cont_1_main_main_default, 2);
	lv_style_set_shadow_ofs_y(&style_screen_cont_1_main_main_default, 2);
	lv_style_set_border_color(&style_screen_cont_1_main_main_default, lv_color_make(0x37, 0x8a, 0xcd));
	lv_style_set_border_width(&style_screen_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_screen_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_cont_1, &style_screen_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_1, 48, 195);
	lv_obj_set_size(ui->screen_label_1, 30, 30);
	lv_obj_set_scrollbar_mode(ui->screen_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_1, "\xEF\x80\xA7");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_screen_label_1_main_main_default
	static lv_style_t style_screen_label_1_main_main_default;
	if (style_screen_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_1_main_main_default);
	else
		lv_style_init(&style_screen_label_1_main_main_default);
	lv_style_set_radius(&style_screen_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_label_1_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_letter_space(&style_screen_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_label_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_1, &style_screen_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_label_2, 310, 195);
	lv_obj_set_size(ui->screen_label_2, 30, 30);
	lv_obj_set_scrollbar_mode(ui->screen_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_2, "\xEF\x80\xA8");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_screen_label_2_main_main_default
	static lv_style_t style_screen_label_2_main_main_default;
	if (style_screen_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_2_main_main_default);
	else
		lv_style_init(&style_screen_label_2_main_main_default);
	lv_style_set_radius(&style_screen_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_label_2_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_letter_space(&style_screen_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_label_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_2, &style_screen_label_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_btn_1
	ui->screen_btn_1 = lv_btn_create(ui->screen);
	lv_obj_set_pos(ui->screen_btn_1, 422, 185);
	lv_obj_set_size(ui->screen_btn_1, 80, 28);
	lv_obj_set_scrollbar_mode(ui->screen_btn_1, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_btn_1_main_main_default
	static lv_style_t style_screen_btn_1_main_main_default;
	if (style_screen_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_1_main_main_default);
	else
		lv_style_init(&style_screen_btn_1_main_main_default);
	lv_style_set_radius(&style_screen_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_btn_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_screen_btn_1_main_main_default, 5);
	lv_style_set_shadow_color(&style_screen_btn_1_main_main_default, lv_color_make(0x85, 0x93, 0x9d));
	lv_style_set_shadow_opa(&style_screen_btn_1_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_btn_1_main_main_default, 2);
	lv_style_set_shadow_ofs_x(&style_screen_btn_1_main_main_default, 1);
	lv_style_set_shadow_ofs_y(&style_screen_btn_1_main_main_default, 1);
	lv_style_set_border_color(&style_screen_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_btn_1_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_align(&style_screen_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_1, &style_screen_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_PRESSED for style_screen_btn_1_main_main_pressed
	static lv_style_t style_screen_btn_1_main_main_pressed;
	if (style_screen_btn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_1_main_main_pressed);
	else
		lv_style_init(&style_screen_btn_1_main_main_pressed);
	lv_style_set_radius(&style_screen_btn_1_main_main_pressed, 5);
	lv_style_set_bg_color(&style_screen_btn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_1_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_btn_1_main_main_pressed, 255);
	lv_style_set_border_color(&style_screen_btn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_1_main_main_pressed, 0);
	lv_style_set_border_opa(&style_screen_btn_1_main_main_pressed, 255);
	lv_style_set_text_color(&style_screen_btn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_btn_1_main_main_pressed, &lv_font_SourceHanSansCN_Regular_15);
	lv_obj_add_style(ui->screen_btn_1, &style_screen_btn_1_main_main_pressed, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_add_flag(ui->screen_btn_1, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
	lv_label_set_text(ui->screen_btn_1_label, "播放");
	lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes screen_btn_3
	ui->screen_btn_3 = lv_btn_create(ui->screen);
	lv_obj_set_pos(ui->screen_btn_3, 637, 185);
	lv_obj_set_size(ui->screen_btn_3, 80, 28);
	lv_obj_set_scrollbar_mode(ui->screen_btn_3, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_btn_3_main_main_default
	static lv_style_t style_screen_btn_3_main_main_default;
	if (style_screen_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_3_main_main_default);
	else
		lv_style_init(&style_screen_btn_3_main_main_default);
	lv_style_set_radius(&style_screen_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_btn_3_main_main_default, 255);
	lv_style_set_shadow_width(&style_screen_btn_3_main_main_default, 5);
	lv_style_set_shadow_color(&style_screen_btn_3_main_main_default, lv_color_make(0x85, 0x93, 0x9d));
	lv_style_set_shadow_opa(&style_screen_btn_3_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_btn_3_main_main_default, 2);
	lv_style_set_shadow_ofs_x(&style_screen_btn_3_main_main_default, 1);
	lv_style_set_shadow_ofs_y(&style_screen_btn_3_main_main_default, 1);
	lv_style_set_border_color(&style_screen_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_btn_3_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_align(&style_screen_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_3, &style_screen_btn_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_PRESSED for style_screen_btn_3_main_main_pressed
	static lv_style_t style_screen_btn_3_main_main_pressed;
	if (style_screen_btn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_3_main_main_pressed);
	else
		lv_style_init(&style_screen_btn_3_main_main_pressed);
	lv_style_set_radius(&style_screen_btn_3_main_main_pressed, 5);
	lv_style_set_bg_color(&style_screen_btn_3_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_3_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_3_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_btn_3_main_main_pressed, 255);
	lv_style_set_border_color(&style_screen_btn_3_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_3_main_main_pressed, 0);
	lv_style_set_border_opa(&style_screen_btn_3_main_main_pressed, 255);
	lv_style_set_text_color(&style_screen_btn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_btn_3_main_main_pressed, &lv_font_SourceHanSansCN_Regular_15);
	lv_obj_add_style(ui->screen_btn_3, &style_screen_btn_3_main_main_pressed, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_add_flag(ui->screen_btn_3, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_btn_3_label = lv_label_create(ui->screen_btn_3);
	lv_label_set_text(ui->screen_btn_3_label, "停止");
	lv_obj_set_style_pad_all(ui->screen_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes screen_btn_2
	ui->screen_btn_2 = lv_btn_create(ui->screen);
	lv_obj_set_pos(ui->screen_btn_2, 530, 185);
	lv_obj_set_size(ui->screen_btn_2, 80, 28);
	lv_obj_set_scrollbar_mode(ui->screen_btn_2, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_btn_2_main_main_default
	static lv_style_t style_screen_btn_2_main_main_default;
	if (style_screen_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_2_main_main_default);
	else
		lv_style_init(&style_screen_btn_2_main_main_default);
	lv_style_set_radius(&style_screen_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_btn_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_screen_btn_2_main_main_default, 5);
	lv_style_set_shadow_color(&style_screen_btn_2_main_main_default, lv_color_make(0x85, 0x93, 0x9d));
	lv_style_set_shadow_opa(&style_screen_btn_2_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_btn_2_main_main_default, 2);
	lv_style_set_shadow_ofs_x(&style_screen_btn_2_main_main_default, 1);
	lv_style_set_shadow_ofs_y(&style_screen_btn_2_main_main_default, 1);
	lv_style_set_border_color(&style_screen_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_screen_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_btn_2_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_align(&style_screen_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->screen_btn_2, &style_screen_btn_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_PRESSED for style_screen_btn_2_main_main_pressed
	static lv_style_t style_screen_btn_2_main_main_pressed;
	if (style_screen_btn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_screen_btn_2_main_main_pressed);
	else
		lv_style_init(&style_screen_btn_2_main_main_pressed);
	lv_style_set_radius(&style_screen_btn_2_main_main_pressed, 5);
	lv_style_set_bg_color(&style_screen_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_btn_2_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_btn_2_main_main_pressed, 255);
	lv_style_set_border_color(&style_screen_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_btn_2_main_main_pressed, 0);
	lv_style_set_border_opa(&style_screen_btn_2_main_main_pressed, 255);
	lv_style_set_text_color(&style_screen_btn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_btn_2_main_main_pressed, &lv_font_SourceHanSansCN_Regular_15);
	lv_obj_add_style(ui->screen_btn_2, &style_screen_btn_2_main_main_pressed, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_add_flag(ui->screen_btn_2, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_btn_2_label = lv_label_create(ui->screen_btn_2);
	lv_label_set_text(ui->screen_btn_2_label, "暂停");
	lv_obj_set_style_pad_all(ui->screen_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes screen_slider_1
	ui->screen_slider_1 = lv_slider_create(ui->screen);
	lv_obj_set_pos(ui->screen_slider_1, 465, 343);
	lv_obj_set_size(ui->screen_slider_1, 202, 11);
	lv_obj_set_scrollbar_mode(ui->screen_slider_1, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_slider_1_main_main_default
	static lv_style_t style_screen_slider_1_main_main_default;
	if (style_screen_slider_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_slider_1_main_main_default);
	else
		lv_style_init(&style_screen_slider_1_main_main_default);
	lv_style_set_radius(&style_screen_slider_1_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_slider_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_slider_1_main_main_default, 60);
	lv_style_set_shadow_width(&style_screen_slider_1_main_main_default, 5);
	lv_style_set_shadow_color(&style_screen_slider_1_main_main_default, lv_color_make(0x8e, 0xab, 0xc2));
	lv_style_set_shadow_opa(&style_screen_slider_1_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_slider_1_main_main_default, 3);
	lv_style_set_shadow_ofs_x(&style_screen_slider_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_screen_slider_1_main_main_default, 0);
	lv_style_set_outline_color(&style_screen_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_screen_slider_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_screen_slider_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_slider_1, &style_screen_slider_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_screen_slider_1_main_indicator_default
	static lv_style_t style_screen_slider_1_main_indicator_default;
	if (style_screen_slider_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_screen_slider_1_main_indicator_default);
	else
		lv_style_init(&style_screen_slider_1_main_indicator_default);
	lv_style_set_radius(&style_screen_slider_1_main_indicator_default, 50);
	lv_style_set_bg_color(&style_screen_slider_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_slider_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_slider_1_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_slider_1_main_indicator_default, 255);
	lv_obj_add_style(ui->screen_slider_1, &style_screen_slider_1_main_indicator_default, LV_PART_INDICATOR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_screen_slider_1_main_knob_default
	static lv_style_t style_screen_slider_1_main_knob_default;
	if (style_screen_slider_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_slider_1_main_knob_default);
	else
		lv_style_init(&style_screen_slider_1_main_knob_default);
	lv_style_set_radius(&style_screen_slider_1_main_knob_default, 50);
	lv_style_set_bg_color(&style_screen_slider_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_slider_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_slider_1_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_slider_1_main_knob_default, 255);
	lv_obj_add_style(ui->screen_slider_1, &style_screen_slider_1_main_knob_default, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_slider_set_range(ui->screen_slider_1, 0, 100);
	lv_slider_set_value(ui->screen_slider_1, 50, false);

	// Write codes screen_ddlist_1
	ui->screen_ddlist_1 = lv_dropdown_create(ui->screen);
	lv_obj_set_pos(ui->screen_ddlist_1, 447, 250);
	lv_obj_set_size(ui->screen_ddlist_1, 242, 34);
	lv_obj_set_scrollbar_mode(ui->screen_ddlist_1, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->screen_ddlist_1, "list1\nlist2\nlist3");

	// Write style state: LV_STATE_DEFAULT for style_screen_ddlist_1_main_main_default
	static lv_style_t style_screen_ddlist_1_main_main_default;
	if (style_screen_ddlist_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_main_main_default);
	else
		lv_style_init(&style_screen_ddlist_1_main_main_default);
	lv_style_set_radius(&style_screen_ddlist_1_main_main_default, 8);
	lv_style_set_bg_color(&style_screen_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_ddlist_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_main_main_default, lv_color_make(0x4e, 0x4f, 0x50));
	lv_style_set_border_width(&style_screen_ddlist_1_main_main_default, 2);
	lv_style_set_border_opa(&style_screen_ddlist_1_main_main_default, 255);
	lv_style_set_text_color(&style_screen_ddlist_1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_ddlist_1_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_pad_left(&style_screen_ddlist_1_main_main_default, 6);
	lv_style_set_pad_right(&style_screen_ddlist_1_main_main_default, 6);
	lv_style_set_pad_top(&style_screen_ddlist_1_main_main_default, 8);
	lv_obj_add_style(ui->screen_ddlist_1, &style_screen_ddlist_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_CHECKED for style_screen_ddlist_1_extra_list_selected_checked
	static lv_style_t style_screen_ddlist_1_extra_list_selected_checked;
	if (style_screen_ddlist_1_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_extra_list_selected_checked);
	else
		lv_style_init(&style_screen_ddlist_1_extra_list_selected_checked);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_screen_ddlist_1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_ddlist_1_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_screen_ddlist_1_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_selected_checked, &lv_font_SourceHanSansCN_Regular_16);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_1), &style_screen_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED | LV_STATE_CHECKED);

	// Write style state: LV_STATE_DEFAULT for style_screen_ddlist_1_extra_list_main_default
	static lv_style_t style_screen_ddlist_1_extra_list_main_default;
	if (style_screen_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_screen_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_ddlist_1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_ddlist_1_extra_list_main_default, 255);
	lv_style_set_text_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_max_height(&style_screen_ddlist_1_extra_list_main_default, 155);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_1), &style_screen_ddlist_1_extra_list_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_screen_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_screen_ddlist_1_extra_list_scrollbar_default;
	if (style_screen_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_screen_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_1), &style_screen_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

	// Write codes screen_sw_1
	ui->screen_sw_1 = lv_switch_create(ui->screen);
	lv_obj_set_pos(ui->screen_sw_1, 170, 314);
	lv_obj_set_size(ui->screen_sw_1, 50, 25);
	lv_obj_set_scrollbar_mode(ui->screen_sw_1, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_sw_1_main_main_default
	static lv_style_t style_screen_sw_1_main_main_default;
	if (style_screen_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_sw_1_main_main_default);
	else
		lv_style_init(&style_screen_sw_1_main_main_default);
	lv_style_set_radius(&style_screen_sw_1_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_sw_1_main_main_default, lv_color_make(0x75, 0xbf, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_sw_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_screen_sw_1_main_main_default, 5);
	lv_style_set_shadow_color(&style_screen_sw_1_main_main_default, lv_color_make(0x9e, 0x9e, 0x9e));
	lv_style_set_shadow_opa(&style_screen_sw_1_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_sw_1_main_main_default, 3);
	lv_style_set_shadow_ofs_x(&style_screen_sw_1_main_main_default, 1);
	lv_style_set_shadow_ofs_y(&style_screen_sw_1_main_main_default, 1);
	lv_style_set_border_color(&style_screen_sw_1_main_main_default, lv_color_make(0x2b, 0x2b, 0x2b));
	lv_style_set_border_width(&style_screen_sw_1_main_main_default, 1);
	lv_style_set_border_opa(&style_screen_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_sw_1, &style_screen_sw_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_CHECKED for style_screen_sw_1_main_indicator_checked
	static lv_style_t style_screen_sw_1_main_indicator_checked;
	if (style_screen_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_screen_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_screen_sw_1_main_indicator_checked);
	lv_style_set_bg_color(&style_screen_sw_1_main_indicator_checked, lv_color_make(0x9f, 0xfe, 0xda));
	lv_style_set_bg_grad_color(&style_screen_sw_1_main_indicator_checked, lv_color_make(0xcc, 0xff, 0xe9));
	lv_style_set_bg_grad_dir(&style_screen_sw_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw_1_main_indicator_checked, 255);
	lv_style_set_border_color(&style_screen_sw_1_main_indicator_checked, lv_color_make(0x70, 0x70, 0x70));
	lv_style_set_border_width(&style_screen_sw_1_main_indicator_checked, 1);
	lv_style_set_border_opa(&style_screen_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->screen_sw_1, &style_screen_sw_1_main_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

	// Write style state: LV_STATE_DEFAULT for style_screen_sw_1_main_knob_default
	static lv_style_t style_screen_sw_1_main_knob_default;
	if (style_screen_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_sw_1_main_knob_default);
	else
		lv_style_init(&style_screen_sw_1_main_knob_default);
	lv_style_set_radius(&style_screen_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_screen_sw_1_main_knob_default, lv_color_make(0x33, 0xff, 0x5c));
	lv_style_set_bg_grad_color(&style_screen_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw_1_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_sw_1_main_knob_default, 255);
	lv_style_set_border_color(&style_screen_sw_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_sw_1_main_knob_default, 0);
	lv_style_set_border_opa(&style_screen_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->screen_sw_1, &style_screen_sw_1_main_knob_default, LV_PART_KNOB | LV_STATE_DEFAULT);

	// Write codes screen_sw_2
	ui->screen_sw_2 = lv_switch_create(ui->screen);
	lv_obj_set_pos(ui->screen_sw_2, 250, 314);
	lv_obj_set_size(ui->screen_sw_2, 50, 25);
	lv_obj_set_scrollbar_mode(ui->screen_sw_2, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_screen_sw_2_main_main_default
	static lv_style_t style_screen_sw_2_main_main_default;
	if (style_screen_sw_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_sw_2_main_main_default);
	else
		lv_style_init(&style_screen_sw_2_main_main_default);
	lv_style_set_radius(&style_screen_sw_2_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_sw_2_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_sw_2_main_main_default, lv_color_make(0x75, 0xbf, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_sw_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_screen_sw_2_main_main_default, 5);
	lv_style_set_shadow_color(&style_screen_sw_2_main_main_default, lv_color_make(0x9e, 0x9e, 0x9e));
	lv_style_set_shadow_opa(&style_screen_sw_2_main_main_default, 192);
	lv_style_set_shadow_spread(&style_screen_sw_2_main_main_default, 3);
	lv_style_set_shadow_ofs_x(&style_screen_sw_2_main_main_default, 1);
	lv_style_set_shadow_ofs_y(&style_screen_sw_2_main_main_default, 1);
	lv_style_set_border_color(&style_screen_sw_2_main_main_default, lv_color_make(0x2b, 0x2b, 0x2b));
	lv_style_set_border_width(&style_screen_sw_2_main_main_default, 1);
	lv_style_set_border_opa(&style_screen_sw_2_main_main_default, 255);
	lv_obj_add_style(ui->screen_sw_2, &style_screen_sw_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_CHECKED for style_screen_sw_2_main_indicator_checked
	static lv_style_t style_screen_sw_2_main_indicator_checked;
	if (style_screen_sw_2_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_screen_sw_2_main_indicator_checked);
	else
		lv_style_init(&style_screen_sw_2_main_indicator_checked);
	lv_style_set_bg_color(&style_screen_sw_2_main_indicator_checked, lv_color_make(0xff, 0xa3, 0xa3));
	lv_style_set_bg_grad_color(&style_screen_sw_2_main_indicator_checked, lv_color_make(0xff, 0xe5, 0xe5));
	lv_style_set_bg_grad_dir(&style_screen_sw_2_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw_2_main_indicator_checked, 255);
	lv_style_set_border_color(&style_screen_sw_2_main_indicator_checked, lv_color_make(0x70, 0x70, 0x70));
	lv_style_set_border_width(&style_screen_sw_2_main_indicator_checked, 1);
	lv_style_set_border_opa(&style_screen_sw_2_main_indicator_checked, 255);
	lv_obj_add_style(ui->screen_sw_2, &style_screen_sw_2_main_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

	// Write style state: LV_STATE_DEFAULT for style_screen_sw_2_main_knob_default
	static lv_style_t style_screen_sw_2_main_knob_default;
	if (style_screen_sw_2_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_sw_2_main_knob_default);
	else
		lv_style_init(&style_screen_sw_2_main_knob_default);
	lv_style_set_radius(&style_screen_sw_2_main_knob_default, 100);
	lv_style_set_bg_color(&style_screen_sw_2_main_knob_default, lv_color_make(0xff, 0x42, 0x42));
	lv_style_set_bg_grad_color(&style_screen_sw_2_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw_2_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_sw_2_main_knob_default, 255);
	lv_style_set_border_color(&style_screen_sw_2_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_sw_2_main_knob_default, 0);
	lv_style_set_border_opa(&style_screen_sw_2_main_knob_default, 255);
	lv_obj_add_style(ui->screen_sw_2, &style_screen_sw_2_main_knob_default, LV_PART_KNOB | LV_STATE_DEFAULT);

	// Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label_3, 710, 2);
	lv_obj_set_size(ui->screen_label_3, 30, 30);
	lv_obj_set_scrollbar_mode(ui->screen_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_3, "\xEF\x83\xA7");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_screen_label_3_main_main_default
	static lv_style_t style_screen_label_3_main_main_default;
	if (style_screen_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_3_main_main_default);
	else
		lv_style_init(&style_screen_label_3_main_main_default);
	lv_style_set_radius(&style_screen_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_3_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_letter_space(&style_screen_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_label_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_3, &style_screen_label_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
}