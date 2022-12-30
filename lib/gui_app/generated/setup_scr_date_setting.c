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

static void date_setting_calendardraw_part_begin_event_cb(lv_event_t *e)
{
	lv_obj_t *obj = lv_event_get_target(e);
	lv_obj_draw_part_dsc_t *dsc = lv_event_get_param(e);
	if (dsc->part == LV_PART_ITEMS)
	{
		if (dsc->id < 7)
		{
			dsc->label_dsc->color = lv_color_make(0x0D, 0x30, 0x55);
			dsc->label_dsc->font = &lv_font_SourceHanSansCN_Regular_16;
		}
		else if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_DISABLED))
		{
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_opa = 0;
			dsc->label_dsc->color = lv_color_make(0xA9, 0xA2, 0xA2);
			dsc->label_dsc->font = &lv_font_SourceHanSansCN_Regular_16;
		}
		else if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_CUSTOM_1))
		{
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_opa = 255;
			dsc->rect_dsc->border_color = lv_color_make(0xc0, 0xc0, 0xc0);
			dsc->rect_dsc->border_width = 1;
			dsc->rect_dsc->border_opa = 255;
			dsc->label_dsc->color = lv_color_make(0x0D, 0x30, 0x55);
			dsc->label_dsc->font = &lv_font_SourceHanSansCN_Regular_16;
		}
		else if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_CUSTOM_2))
		{
			dsc->rect_dsc->bg_color = lv_color_make(0x21, 0x95, 0xf6);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x21, 0x95, 0xf6);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x21, 0x95, 0xf6);
			dsc->rect_dsc->bg_opa = 255;
			dsc->label_dsc->color = lv_color_make(0x0D, 0x30, 0x55);
			dsc->label_dsc->font = &lv_font_SourceHanSansCN_Regular_16;
		}
		else
		{
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_opa = 0;
			dsc->rect_dsc->border_color = lv_color_make(0xc0, 0xc0, 0xc0);
			dsc->rect_dsc->border_width = 1;
			dsc->rect_dsc->border_opa = 255;
			dsc->label_dsc->color = lv_color_make(0x0D, 0x30, 0x55);
			dsc->label_dsc->font = &lv_font_SourceHanSansCN_Regular_16;
		}
	}
}

static lv_calendar_date_t date;
static void date_setting_calendar_event_handler(lv_event_t *e)
{
	lv_obj_t *obj = lv_event_get_current_target(e);
	lv_calendar_get_pressed_date(obj, &date);
	lv_calendar_set_highlighted_dates(obj, &date, 2);
}
static lv_obj_t *date_setting_spinbox_min;
static void lv_date_setting_spinbox_min_increment_event_cb(lv_event_t *event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	{
		lv_spinbox_increment(date_setting_spinbox_min);
	}
}
static void lv_date_setting_spinbox_min_decrement_event_cb(lv_event_t *event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	{
		lv_spinbox_decrement(date_setting_spinbox_min);
	}
}
static lv_obj_t *date_setting_spinbox_hour;
static void lv_date_setting_spinbox_hour_increment_event_cb(lv_event_t *event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	{
		lv_spinbox_increment(date_setting_spinbox_hour);
	}
}
static void lv_date_setting_spinbox_hour_decrement_event_cb(lv_event_t *event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	{
		lv_spinbox_decrement(date_setting_spinbox_hour);
	}
}
static int date_setting_digital_clock_hour_value = 11;
static int date_setting_digital_clock_min_value = 25;
static int date_setting_digital_clock_sec_value = 50;
static char date_setting_digital_clock_meridiem[] = "AM";
void date_setting_digital_clock_timer(lv_timer_t *timer)
{
	clock_count_12(&date_setting_digital_clock_hour_value, &date_setting_digital_clock_min_value, &date_setting_digital_clock_sec_value, date_setting_digital_clock_meridiem);
	if (lv_obj_is_valid(guider_ui.date_setting_digital_clock))
	{
		lv_dclock_set_text_fmt(guider_ui.date_setting_digital_clock, "%02d:%02d:%02d %s", date_setting_digital_clock_hour_value, date_setting_digital_clock_min_value, date_setting_digital_clock_sec_value, date_setting_digital_clock_meridiem);
	}
}
static lv_obj_t *date_setting_spinbox_sec;
static void lv_date_setting_spinbox_sec_increment_event_cb(lv_event_t *event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	{
		lv_spinbox_increment(date_setting_spinbox_sec);
	}
}
static void lv_date_setting_spinbox_sec_decrement_event_cb(lv_event_t *event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	{
		lv_spinbox_decrement(date_setting_spinbox_sec);
	}
}

void setup_scr_date_setting(lv_ui *ui)
{

	// Write codes date_setting
	ui->date_setting = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->date_setting, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_main_main_default
	static lv_style_t style_date_setting_main_main_default;
	if (style_date_setting_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_main_main_default);
	else
		lv_style_init(&style_date_setting_main_main_default);
	lv_style_set_bg_color(&style_date_setting_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_date_setting_main_main_default, 255);
	lv_obj_add_style(ui->date_setting, &style_date_setting_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_calendar
	ui->date_setting_calendar = lv_calendar_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_calendar, 50, 73);
	lv_obj_set_size(ui->date_setting_calendar, 385, 360);
	lv_obj_set_scrollbar_mode(ui->date_setting_calendar, LV_SCROLLBAR_MODE_OFF);
	today.year = 2020;
	today.month = 5;
	today.day = 7;
	lv_calendar_set_today_date(ui->date_setting_calendar, today.year, today.month, today.day);
	lv_calendar_set_showed_date(ui->date_setting_calendar, today.year, today.month);
	highlihted_days[0].year = 2020;
	highlihted_days[0].month = 5;
	highlihted_days[0].day = 14;
	lv_calendar_set_highlighted_dates(ui->date_setting_calendar, highlihted_days, 1);
	lv_obj_t *date_setting_calendar_header = lv_calendar_header_arrow_create(ui->date_setting_calendar);
	lv_calendar_t *date_setting_calendar = (lv_calendar_t *)ui->date_setting_calendar;
	lv_obj_add_event_cb(date_setting_calendar->btnm, date_setting_calendardraw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
	lv_obj_add_event_cb(ui->date_setting_calendar, date_setting_calendar_event_handler, LV_EVENT_CLICKED, NULL);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_calendar_main_main_default
	static lv_style_t style_date_setting_calendar_main_main_default;
	if (style_date_setting_calendar_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_calendar_main_main_default);
	else
		lv_style_init(&style_date_setting_calendar_main_main_default);
	lv_style_set_radius(&style_date_setting_calendar_main_main_default, 10);
	lv_style_set_bg_color(&style_date_setting_calendar_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_date_setting_calendar_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_date_setting_calendar_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_calendar_main_main_default, 255);
	lv_style_set_shadow_width(&style_date_setting_calendar_main_main_default, 12);
	lv_style_set_shadow_color(&style_date_setting_calendar_main_main_default, lv_color_make(0x15, 0x4f, 0x7f));
	lv_style_set_shadow_opa(&style_date_setting_calendar_main_main_default, 181);
	lv_style_set_shadow_spread(&style_date_setting_calendar_main_main_default, 6);
	lv_style_set_shadow_ofs_x(&style_date_setting_calendar_main_main_default, 3);
	lv_style_set_shadow_ofs_y(&style_date_setting_calendar_main_main_default, 3);
	lv_style_set_border_color(&style_date_setting_calendar_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_date_setting_calendar_main_main_default, 2);
	lv_style_set_border_opa(&style_date_setting_calendar_main_main_default, 255);
	lv_obj_add_style(ui->date_setting_calendar, &style_date_setting_calendar_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_calendar_extra_header_main_default
	static lv_style_t style_date_setting_calendar_extra_header_main_default;
	if (style_date_setting_calendar_extra_header_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_calendar_extra_header_main_default);
	else
		lv_style_init(&style_date_setting_calendar_extra_header_main_default);
	lv_style_set_bg_color(&style_date_setting_calendar_extra_header_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_calendar_extra_header_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_calendar_extra_header_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_calendar_extra_header_main_default, 255);
	lv_style_set_text_color(&style_date_setting_calendar_extra_header_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_calendar_extra_header_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_obj_add_style(date_setting_calendar_header, &style_date_setting_calendar_extra_header_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_spinbox_min
	ui->date_setting_spinbox_min = lv_spinbox_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_spinbox_min, 607, 203);
	lv_obj_set_scrollbar_mode(ui->date_setting_spinbox_min, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_min_main_main_default
	static lv_style_t style_date_setting_spinbox_min_main_main_default;
	if (style_date_setting_spinbox_min_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_min_main_main_default);
	else
		lv_style_init(&style_date_setting_spinbox_min_main_main_default);
	lv_style_set_radius(&style_date_setting_spinbox_min_main_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_min_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_min_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_min_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_min_main_main_default, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_min_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_min_main_main_default, 2);
	lv_style_set_border_opa(&style_date_setting_spinbox_min_main_main_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_min_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_date_setting_spinbox_min_main_main_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_style_set_text_letter_space(&style_date_setting_spinbox_min_main_main_default, 0);
	lv_style_set_pad_left(&style_date_setting_spinbox_min_main_main_default, 10);
	lv_style_set_pad_right(&style_date_setting_spinbox_min_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_spinbox_min_main_main_default, 6);
	lv_style_set_pad_bottom(&style_date_setting_spinbox_min_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_spinbox_min, &style_date_setting_spinbox_min_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_min_main_cursor_default
	static lv_style_t style_date_setting_spinbox_min_main_cursor_default;
	if (style_date_setting_spinbox_min_main_cursor_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_min_main_cursor_default);
	else
		lv_style_init(&style_date_setting_spinbox_min_main_cursor_default);
	lv_style_set_bg_color(&style_date_setting_spinbox_min_main_cursor_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_min_main_cursor_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_min_main_cursor_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_min_main_cursor_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_min_main_cursor_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_min_main_cursor_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_obj_add_style(ui->date_setting_spinbox_min, &style_date_setting_spinbox_min_main_cursor_default, LV_PART_CURSOR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_min_extra_btns_main_default
	static lv_style_t style_date_setting_spinbox_min_extra_btns_main_default;
	if (style_date_setting_spinbox_min_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_min_extra_btns_main_default);
	else
		lv_style_init(&style_date_setting_spinbox_min_extra_btns_main_default);
	lv_style_set_radius(&style_date_setting_spinbox_min_extra_btns_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_min_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_min_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_min_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_min_extra_btns_main_default, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_min_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_min_extra_btns_main_default, 0);
	lv_style_set_border_opa(&style_date_setting_spinbox_min_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_min_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_min_extra_btns_main_default, &lv_font_SourceHanSansCN_Regular_16);

	// Write style state: LV_STATE_PRESSED for style_date_setting_spinbox_min_extra_btns_main_pressed
	static lv_style_t style_date_setting_spinbox_min_extra_btns_main_pressed;
	if (style_date_setting_spinbox_min_extra_btns_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_min_extra_btns_main_pressed);
	else
		lv_style_init(&style_date_setting_spinbox_min_extra_btns_main_pressed);
	lv_style_set_radius(&style_date_setting_spinbox_min_extra_btns_main_pressed, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_min_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_min_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_min_extra_btns_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_min_extra_btns_main_pressed, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_min_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_min_extra_btns_main_pressed, 0);
	lv_style_set_border_opa(&style_date_setting_spinbox_min_extra_btns_main_pressed, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_min_extra_btns_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_min_extra_btns_main_pressed, &lv_font_SourceHanSansCN_Regular_16);
	lv_obj_set_width(ui->date_setting_spinbox_min, 70);
	lv_obj_set_height(ui->date_setting_spinbox_min, 40);
	lv_spinbox_set_digit_format(ui->date_setting_spinbox_min, 2, 2);
	lv_spinbox_set_range(ui->date_setting_spinbox_min, -99, 99);
	date_setting_spinbox_min = ui->date_setting_spinbox_min;
	lv_coord_t date_setting_spinbox_min_h = lv_obj_get_height(ui->date_setting_spinbox_min);
	ui->date_setting_spinbox_min_btn = lv_btn_create(ui->date_setting);
	lv_obj_set_size(ui->date_setting_spinbox_min_btn, date_setting_spinbox_min_h, date_setting_spinbox_min_h);
	lv_obj_align_to(ui->date_setting_spinbox_min_btn, ui->date_setting_spinbox_min, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->date_setting_spinbox_min_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->date_setting_spinbox_min_btn, lv_date_setting_spinbox_min_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->date_setting_spinbox_min_btn_minus = lv_btn_create(ui->date_setting);
	lv_obj_set_size(ui->date_setting_spinbox_min_btn_minus, date_setting_spinbox_min_h, date_setting_spinbox_min_h);
	lv_obj_align_to(ui->date_setting_spinbox_min_btn_minus, ui->date_setting_spinbox_min, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->date_setting_spinbox_min_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->date_setting_spinbox_min_btn_minus, lv_date_setting_spinbox_min_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_style(ui->date_setting_spinbox_min_btn, &style_date_setting_spinbox_min_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->date_setting_spinbox_min_btn_minus, &style_date_setting_spinbox_min_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_spinbox_hour
	ui->date_setting_spinbox_hour = lv_spinbox_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_spinbox_hour, 607, 142);
	lv_obj_set_scrollbar_mode(ui->date_setting_spinbox_hour, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_hour_main_main_default
	static lv_style_t style_date_setting_spinbox_hour_main_main_default;
	if (style_date_setting_spinbox_hour_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_hour_main_main_default);
	else
		lv_style_init(&style_date_setting_spinbox_hour_main_main_default);
	lv_style_set_radius(&style_date_setting_spinbox_hour_main_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_hour_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_hour_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_hour_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_hour_main_main_default, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_hour_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_hour_main_main_default, 2);
	lv_style_set_border_opa(&style_date_setting_spinbox_hour_main_main_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_hour_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_date_setting_spinbox_hour_main_main_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_style_set_text_letter_space(&style_date_setting_spinbox_hour_main_main_default, 0);
	lv_style_set_pad_left(&style_date_setting_spinbox_hour_main_main_default, 10);
	lv_style_set_pad_right(&style_date_setting_spinbox_hour_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_spinbox_hour_main_main_default, 6);
	lv_style_set_pad_bottom(&style_date_setting_spinbox_hour_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_spinbox_hour, &style_date_setting_spinbox_hour_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_hour_main_cursor_default
	static lv_style_t style_date_setting_spinbox_hour_main_cursor_default;
	if (style_date_setting_spinbox_hour_main_cursor_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_hour_main_cursor_default);
	else
		lv_style_init(&style_date_setting_spinbox_hour_main_cursor_default);
	lv_style_set_bg_color(&style_date_setting_spinbox_hour_main_cursor_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_hour_main_cursor_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_hour_main_cursor_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_hour_main_cursor_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_hour_main_cursor_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_hour_main_cursor_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_obj_add_style(ui->date_setting_spinbox_hour, &style_date_setting_spinbox_hour_main_cursor_default, LV_PART_CURSOR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_hour_extra_btns_main_default
	static lv_style_t style_date_setting_spinbox_hour_extra_btns_main_default;
	if (style_date_setting_spinbox_hour_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_hour_extra_btns_main_default);
	else
		lv_style_init(&style_date_setting_spinbox_hour_extra_btns_main_default);
	lv_style_set_radius(&style_date_setting_spinbox_hour_extra_btns_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_hour_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_hour_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_hour_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_hour_extra_btns_main_default, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_hour_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_hour_extra_btns_main_default, 0);
	lv_style_set_border_opa(&style_date_setting_spinbox_hour_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_hour_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_hour_extra_btns_main_default, &lv_font_SourceHanSansCN_Regular_16);

	// Write style state: LV_STATE_PRESSED for style_date_setting_spinbox_hour_extra_btns_main_pressed
	static lv_style_t style_date_setting_spinbox_hour_extra_btns_main_pressed;
	if (style_date_setting_spinbox_hour_extra_btns_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_hour_extra_btns_main_pressed);
	else
		lv_style_init(&style_date_setting_spinbox_hour_extra_btns_main_pressed);
	lv_style_set_radius(&style_date_setting_spinbox_hour_extra_btns_main_pressed, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_hour_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_hour_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_hour_extra_btns_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_hour_extra_btns_main_pressed, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_hour_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_hour_extra_btns_main_pressed, 0);
	lv_style_set_border_opa(&style_date_setting_spinbox_hour_extra_btns_main_pressed, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_hour_extra_btns_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_hour_extra_btns_main_pressed, &lv_font_SourceHanSansCN_Regular_16);
	lv_obj_set_width(ui->date_setting_spinbox_hour, 70);
	lv_obj_set_height(ui->date_setting_spinbox_hour, 40);
	lv_spinbox_set_digit_format(ui->date_setting_spinbox_hour, 2, 2);
	lv_spinbox_set_range(ui->date_setting_spinbox_hour, -99, 99);
	date_setting_spinbox_hour = ui->date_setting_spinbox_hour;
	lv_coord_t date_setting_spinbox_hour_h = lv_obj_get_height(ui->date_setting_spinbox_hour);
	ui->date_setting_spinbox_hour_btn = lv_btn_create(ui->date_setting);
	lv_obj_set_size(ui->date_setting_spinbox_hour_btn, date_setting_spinbox_hour_h, date_setting_spinbox_hour_h);
	lv_obj_align_to(ui->date_setting_spinbox_hour_btn, ui->date_setting_spinbox_hour, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->date_setting_spinbox_hour_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->date_setting_spinbox_hour_btn, lv_date_setting_spinbox_hour_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->date_setting_spinbox_hour_btn_minus = lv_btn_create(ui->date_setting);
	lv_obj_set_size(ui->date_setting_spinbox_hour_btn_minus, date_setting_spinbox_hour_h, date_setting_spinbox_hour_h);
	lv_obj_align_to(ui->date_setting_spinbox_hour_btn_minus, ui->date_setting_spinbox_hour, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->date_setting_spinbox_hour_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->date_setting_spinbox_hour_btn_minus, lv_date_setting_spinbox_hour_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_style(ui->date_setting_spinbox_hour_btn, &style_date_setting_spinbox_hour_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->date_setting_spinbox_hour_btn_minus, &style_date_setting_spinbox_hour_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	static bool date_setting_digital_clock_timer_enabled = false;

	// Write codes date_setting_digital_clock
	ui->date_setting_digital_clock = lv_dclock_create(ui->date_setting, "11:25:50 AM");
	lv_obj_set_style_text_align(ui->date_setting_digital_clock, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_pos(ui->date_setting_digital_clock, 556, 73);
	lv_obj_set_size(ui->date_setting_digital_clock, 165, 40);

	// create timer
	if (!date_setting_digital_clock_timer_enabled)
	{
		lv_timer_create(date_setting_digital_clock_timer, 1000, NULL);
		date_setting_digital_clock_timer_enabled = true;
	}
	// Write style state: LV_STATE_DEFAULT for style_date_setting_digital_clock_main_main_default
	static lv_style_t style_date_setting_digital_clock_main_main_default;
	if (style_date_setting_digital_clock_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_digital_clock_main_main_default);
	else
		lv_style_init(&style_date_setting_digital_clock_main_main_default);
	lv_style_set_radius(&style_date_setting_digital_clock_main_main_default, 0);
	lv_style_set_bg_color(&style_date_setting_digital_clock_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_digital_clock_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_digital_clock_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_digital_clock_main_main_default, 255);
	lv_style_set_text_color(&style_date_setting_digital_clock_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_digital_clock_main_main_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_style_set_text_letter_space(&style_date_setting_digital_clock_main_main_default, 2);
	lv_style_set_pad_left(&style_date_setting_digital_clock_main_main_default, 0);
	lv_style_set_pad_right(&style_date_setting_digital_clock_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_digital_clock_main_main_default, 8);
	lv_style_set_pad_bottom(&style_date_setting_digital_clock_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_digital_clock, &style_date_setting_digital_clock_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_btn_set
	ui->date_setting_btn_set = lv_btn_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_btn_set, 512, 391);
	lv_obj_set_size(ui->date_setting_btn_set, 100, 40);
	lv_obj_set_scrollbar_mode(ui->date_setting_btn_set, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_btn_set_main_main_default
	static lv_style_t style_date_setting_btn_set_main_main_default;
	if (style_date_setting_btn_set_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_btn_set_main_main_default);
	else
		lv_style_init(&style_date_setting_btn_set_main_main_default);
	lv_style_set_radius(&style_date_setting_btn_set_main_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_btn_set_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_btn_set_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_btn_set_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_btn_set_main_main_default, 255);
	lv_style_set_border_color(&style_date_setting_btn_set_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_btn_set_main_main_default, 0);
	lv_style_set_border_opa(&style_date_setting_btn_set_main_main_default, 255);
	lv_style_set_text_color(&style_date_setting_btn_set_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_btn_set_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_align(&style_date_setting_btn_set_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->date_setting_btn_set, &style_date_setting_btn_set_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_PRESSED for style_date_setting_btn_set_main_main_pressed
	static lv_style_t style_date_setting_btn_set_main_main_pressed;
	if (style_date_setting_btn_set_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_date_setting_btn_set_main_main_pressed);
	else
		lv_style_init(&style_date_setting_btn_set_main_main_pressed);
	lv_style_set_radius(&style_date_setting_btn_set_main_main_pressed, 5);
	lv_style_set_bg_color(&style_date_setting_btn_set_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_btn_set_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_btn_set_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_btn_set_main_main_pressed, 255);
	lv_style_set_border_color(&style_date_setting_btn_set_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_btn_set_main_main_pressed, 0);
	lv_style_set_border_opa(&style_date_setting_btn_set_main_main_pressed, 255);
	lv_style_set_text_color(&style_date_setting_btn_set_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_btn_set_main_main_pressed, &lv_font_SourceHanSansCN_Regular_16);
	lv_obj_add_style(ui->date_setting_btn_set, &style_date_setting_btn_set_main_main_pressed, LV_PART_MAIN | LV_STATE_PRESSED);
	ui->date_setting_btn_set_label = lv_label_create(ui->date_setting_btn_set);
	lv_label_set_text(ui->date_setting_btn_set_label, "设置");
	lv_obj_set_style_pad_all(ui->date_setting_btn_set, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->date_setting_btn_set_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes date_setting_btn_quit
	ui->date_setting_btn_quit = lv_btn_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_btn_quit, 662, 391);
	lv_obj_set_size(ui->date_setting_btn_quit, 100, 40);
	lv_obj_set_scrollbar_mode(ui->date_setting_btn_quit, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_btn_quit_main_main_default
	static lv_style_t style_date_setting_btn_quit_main_main_default;
	if (style_date_setting_btn_quit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_btn_quit_main_main_default);
	else
		lv_style_init(&style_date_setting_btn_quit_main_main_default);
	lv_style_set_radius(&style_date_setting_btn_quit_main_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_btn_quit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_btn_quit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_btn_quit_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_btn_quit_main_main_default, 255);
	lv_style_set_border_color(&style_date_setting_btn_quit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_btn_quit_main_main_default, 0);
	lv_style_set_border_opa(&style_date_setting_btn_quit_main_main_default, 255);
	lv_style_set_text_color(&style_date_setting_btn_quit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_btn_quit_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_align(&style_date_setting_btn_quit_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->date_setting_btn_quit, &style_date_setting_btn_quit_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_PRESSED for style_date_setting_btn_quit_main_main_pressed
	static lv_style_t style_date_setting_btn_quit_main_main_pressed;
	if (style_date_setting_btn_quit_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_date_setting_btn_quit_main_main_pressed);
	else
		lv_style_init(&style_date_setting_btn_quit_main_main_pressed);
	lv_style_set_radius(&style_date_setting_btn_quit_main_main_pressed, 5);
	lv_style_set_bg_color(&style_date_setting_btn_quit_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_btn_quit_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_btn_quit_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_btn_quit_main_main_pressed, 255);
	lv_style_set_border_color(&style_date_setting_btn_quit_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_btn_quit_main_main_pressed, 0);
	lv_style_set_border_opa(&style_date_setting_btn_quit_main_main_pressed, 255);
	lv_style_set_text_color(&style_date_setting_btn_quit_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_btn_quit_main_main_pressed, &lv_font_SourceHanSansCN_Regular_18);
	lv_obj_add_style(ui->date_setting_btn_quit, &style_date_setting_btn_quit_main_main_pressed, LV_PART_MAIN | LV_STATE_PRESSED);
	ui->date_setting_btn_quit_label = lv_label_create(ui->date_setting_btn_quit);
	lv_label_set_text(ui->date_setting_btn_quit_label, "退出");
	lv_obj_set_style_pad_all(ui->date_setting_btn_quit, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->date_setting_btn_quit_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes date_setting_label_1
	ui->date_setting_label_1 = lv_label_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_label_1, 505, 152);
	lv_obj_set_size(ui->date_setting_label_1, 27, 20);
	lv_obj_set_scrollbar_mode(ui->date_setting_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->date_setting_label_1, "时");
	lv_label_set_long_mode(ui->date_setting_label_1, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_label_1_main_main_default
	static lv_style_t style_date_setting_label_1_main_main_default;
	if (style_date_setting_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_label_1_main_main_default);
	else
		lv_style_init(&style_date_setting_label_1_main_main_default);
	lv_style_set_radius(&style_date_setting_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_date_setting_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_date_setting_label_1_main_main_default, lv_color_make(0x0d, 0x0e, 0x12));
	lv_style_set_text_font(&style_date_setting_label_1_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_letter_space(&style_date_setting_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_date_setting_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_date_setting_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_date_setting_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_date_setting_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_date_setting_label_1_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_label_1, &style_date_setting_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_label_2
	ui->date_setting_label_2 = lv_label_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_label_2, 505, 212);
	lv_obj_set_size(ui->date_setting_label_2, 27, 20);
	lv_obj_set_scrollbar_mode(ui->date_setting_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->date_setting_label_2, "分");
	lv_label_set_long_mode(ui->date_setting_label_2, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_label_2_main_main_default
	static lv_style_t style_date_setting_label_2_main_main_default;
	if (style_date_setting_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_label_2_main_main_default);
	else
		lv_style_init(&style_date_setting_label_2_main_main_default);
	lv_style_set_radius(&style_date_setting_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_date_setting_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_date_setting_label_2_main_main_default, lv_color_make(0x0d, 0x0e, 0x12));
	lv_style_set_text_font(&style_date_setting_label_2_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_letter_space(&style_date_setting_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_date_setting_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_date_setting_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_date_setting_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_date_setting_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_date_setting_label_2_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_label_2, &style_date_setting_label_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_label_3
	ui->date_setting_label_3 = lv_label_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_label_3, 505, 273);
	lv_obj_set_size(ui->date_setting_label_3, 27, 20);
	lv_obj_set_scrollbar_mode(ui->date_setting_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->date_setting_label_3, "秒");
	lv_label_set_long_mode(ui->date_setting_label_3, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_label_3_main_main_default
	static lv_style_t style_date_setting_label_3_main_main_default;
	if (style_date_setting_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_label_3_main_main_default);
	else
		lv_style_init(&style_date_setting_label_3_main_main_default);
	lv_style_set_radius(&style_date_setting_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_date_setting_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_date_setting_label_3_main_main_default, lv_color_make(0x0d, 0x0e, 0x12));
	lv_style_set_text_font(&style_date_setting_label_3_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_letter_space(&style_date_setting_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_date_setting_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_date_setting_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_date_setting_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_date_setting_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_date_setting_label_3_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_label_3, &style_date_setting_label_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_spinbox_sec
	ui->date_setting_spinbox_sec = lv_spinbox_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_spinbox_sec, 607, 264);
	lv_obj_set_scrollbar_mode(ui->date_setting_spinbox_sec, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_sec_main_main_default
	static lv_style_t style_date_setting_spinbox_sec_main_main_default;
	if (style_date_setting_spinbox_sec_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_sec_main_main_default);
	else
		lv_style_init(&style_date_setting_spinbox_sec_main_main_default);
	lv_style_set_radius(&style_date_setting_spinbox_sec_main_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_sec_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_sec_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_sec_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_sec_main_main_default, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_sec_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_sec_main_main_default, 2);
	lv_style_set_border_opa(&style_date_setting_spinbox_sec_main_main_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_sec_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_date_setting_spinbox_sec_main_main_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_style_set_text_letter_space(&style_date_setting_spinbox_sec_main_main_default, 0);
	lv_style_set_pad_left(&style_date_setting_spinbox_sec_main_main_default, 10);
	lv_style_set_pad_right(&style_date_setting_spinbox_sec_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_spinbox_sec_main_main_default, 6);
	lv_style_set_pad_bottom(&style_date_setting_spinbox_sec_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_spinbox_sec, &style_date_setting_spinbox_sec_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_sec_main_cursor_default
	static lv_style_t style_date_setting_spinbox_sec_main_cursor_default;
	if (style_date_setting_spinbox_sec_main_cursor_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_sec_main_cursor_default);
	else
		lv_style_init(&style_date_setting_spinbox_sec_main_cursor_default);
	lv_style_set_bg_color(&style_date_setting_spinbox_sec_main_cursor_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_sec_main_cursor_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_sec_main_cursor_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_sec_main_cursor_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_sec_main_cursor_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_sec_main_cursor_default, &lv_font_SourceHanSansCN_Regular_20);
	lv_obj_add_style(ui->date_setting_spinbox_sec, &style_date_setting_spinbox_sec_main_cursor_default, LV_PART_CURSOR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_spinbox_sec_extra_btns_main_default
	static lv_style_t style_date_setting_spinbox_sec_extra_btns_main_default;
	if (style_date_setting_spinbox_sec_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_sec_extra_btns_main_default);
	else
		lv_style_init(&style_date_setting_spinbox_sec_extra_btns_main_default);
	lv_style_set_radius(&style_date_setting_spinbox_sec_extra_btns_main_default, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_sec_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_sec_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_sec_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_sec_extra_btns_main_default, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_sec_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_sec_extra_btns_main_default, 0);
	lv_style_set_border_opa(&style_date_setting_spinbox_sec_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_sec_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_sec_extra_btns_main_default, &lv_font_SourceHanSansCN_Regular_16);

	// Write style state: LV_STATE_PRESSED for style_date_setting_spinbox_sec_extra_btns_main_pressed
	static lv_style_t style_date_setting_spinbox_sec_extra_btns_main_pressed;
	if (style_date_setting_spinbox_sec_extra_btns_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_date_setting_spinbox_sec_extra_btns_main_pressed);
	else
		lv_style_init(&style_date_setting_spinbox_sec_extra_btns_main_pressed);
	lv_style_set_radius(&style_date_setting_spinbox_sec_extra_btns_main_pressed, 5);
	lv_style_set_bg_color(&style_date_setting_spinbox_sec_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_spinbox_sec_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_spinbox_sec_extra_btns_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_spinbox_sec_extra_btns_main_pressed, 255);
	lv_style_set_border_color(&style_date_setting_spinbox_sec_extra_btns_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_spinbox_sec_extra_btns_main_pressed, 0);
	lv_style_set_border_opa(&style_date_setting_spinbox_sec_extra_btns_main_pressed, 255);
	lv_style_set_text_color(&style_date_setting_spinbox_sec_extra_btns_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_date_setting_spinbox_sec_extra_btns_main_pressed, &lv_font_SourceHanSansCN_Regular_16);
	lv_obj_set_width(ui->date_setting_spinbox_sec, 70);
	lv_obj_set_height(ui->date_setting_spinbox_sec, 40);
	lv_spinbox_set_digit_format(ui->date_setting_spinbox_sec, 2, 2);
	lv_spinbox_set_range(ui->date_setting_spinbox_sec, -99, 99);
	date_setting_spinbox_sec = ui->date_setting_spinbox_sec;
	lv_coord_t date_setting_spinbox_sec_h = lv_obj_get_height(ui->date_setting_spinbox_sec);
	ui->date_setting_spinbox_sec_btn = lv_btn_create(ui->date_setting);
	lv_obj_set_size(ui->date_setting_spinbox_sec_btn, date_setting_spinbox_sec_h, date_setting_spinbox_sec_h);
	lv_obj_align_to(ui->date_setting_spinbox_sec_btn, ui->date_setting_spinbox_sec, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->date_setting_spinbox_sec_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->date_setting_spinbox_sec_btn, lv_date_setting_spinbox_sec_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->date_setting_spinbox_sec_btn_minus = lv_btn_create(ui->date_setting);
	lv_obj_set_size(ui->date_setting_spinbox_sec_btn_minus, date_setting_spinbox_sec_h, date_setting_spinbox_sec_h);
	lv_obj_align_to(ui->date_setting_spinbox_sec_btn_minus, ui->date_setting_spinbox_sec, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->date_setting_spinbox_sec_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->date_setting_spinbox_sec_btn_minus, lv_date_setting_spinbox_sec_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_style(ui->date_setting_spinbox_sec_btn, &style_date_setting_spinbox_sec_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->date_setting_spinbox_sec_btn_minus, &style_date_setting_spinbox_sec_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_sw_am
	ui->date_setting_sw_am = lv_switch_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_sw_am, 610, 328);
	lv_obj_set_size(ui->date_setting_sw_am, 65, 35);
	lv_obj_set_scrollbar_mode(ui->date_setting_sw_am, LV_SCROLLBAR_MODE_OFF);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_sw_am_main_main_default
	static lv_style_t style_date_setting_sw_am_main_main_default;
	if (style_date_setting_sw_am_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_sw_am_main_main_default);
	else
		lv_style_init(&style_date_setting_sw_am_main_main_default);
	lv_style_set_radius(&style_date_setting_sw_am_main_main_default, 100);
	lv_style_set_bg_color(&style_date_setting_sw_am_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_date_setting_sw_am_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_date_setting_sw_am_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_sw_am_main_main_default, 255);
	lv_style_set_border_color(&style_date_setting_sw_am_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_sw_am_main_main_default, 0);
	lv_style_set_border_opa(&style_date_setting_sw_am_main_main_default, 255);
	lv_obj_add_style(ui->date_setting_sw_am, &style_date_setting_sw_am_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_CHECKED for style_date_setting_sw_am_main_indicator_checked
	static lv_style_t style_date_setting_sw_am_main_indicator_checked;
	if (style_date_setting_sw_am_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_date_setting_sw_am_main_indicator_checked);
	else
		lv_style_init(&style_date_setting_sw_am_main_indicator_checked);
	lv_style_set_bg_color(&style_date_setting_sw_am_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_sw_am_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_sw_am_main_indicator_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_sw_am_main_indicator_checked, 255);
	lv_style_set_border_color(&style_date_setting_sw_am_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_sw_am_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_date_setting_sw_am_main_indicator_checked, 255);
	lv_obj_add_style(ui->date_setting_sw_am, &style_date_setting_sw_am_main_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_sw_am_main_knob_default
	static lv_style_t style_date_setting_sw_am_main_knob_default;
	if (style_date_setting_sw_am_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_sw_am_main_knob_default);
	else
		lv_style_init(&style_date_setting_sw_am_main_knob_default);
	lv_style_set_radius(&style_date_setting_sw_am_main_knob_default, 100);
	lv_style_set_bg_color(&style_date_setting_sw_am_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_date_setting_sw_am_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_date_setting_sw_am_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_sw_am_main_knob_default, 255);
	lv_style_set_border_color(&style_date_setting_sw_am_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_date_setting_sw_am_main_knob_default, 0);
	lv_style_set_border_opa(&style_date_setting_sw_am_main_knob_default, 255);
	lv_obj_add_style(ui->date_setting_sw_am, &style_date_setting_sw_am_main_knob_default, LV_PART_KNOB | LV_STATE_DEFAULT);

	// Write codes date_setting_label_4
	ui->date_setting_label_4 = lv_label_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_label_4, 480, 336);
	lv_obj_set_size(ui->date_setting_label_4, 81, 20);
	lv_obj_set_scrollbar_mode(ui->date_setting_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->date_setting_label_4, "AM/PM");
	lv_label_set_long_mode(ui->date_setting_label_4, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_label_4_main_main_default
	static lv_style_t style_date_setting_label_4_main_main_default;
	if (style_date_setting_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_label_4_main_main_default);
	else
		lv_style_init(&style_date_setting_label_4_main_main_default);
	lv_style_set_radius(&style_date_setting_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_date_setting_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_date_setting_label_4_main_main_default, lv_color_make(0x0d, 0x0e, 0x12));
	lv_style_set_text_font(&style_date_setting_label_4_main_main_default, &lv_font_SourceHanSansCN_Regular_18);
	lv_style_set_text_letter_space(&style_date_setting_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_date_setting_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_date_setting_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_date_setting_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_date_setting_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_date_setting_label_4_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_label_4, &style_date_setting_label_4_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes date_setting_label_charge
	ui->date_setting_label_charge = lv_label_create(ui->date_setting);
	lv_obj_set_pos(ui->date_setting_label_charge, 710, 2);
	lv_obj_set_size(ui->date_setting_label_charge, 30, 30);
	lv_obj_set_scrollbar_mode(ui->date_setting_label_charge, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->date_setting_label_charge, "\xEF\x83\xA7");
	lv_label_set_long_mode(ui->date_setting_label_charge, LV_LABEL_LONG_WRAP);

	// Write style state: LV_STATE_DEFAULT for style_date_setting_label_charge_main_main_default
	static lv_style_t style_date_setting_label_charge_main_main_default;
	if (style_date_setting_label_charge_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_date_setting_label_charge_main_main_default);
	else
		lv_style_init(&style_date_setting_label_charge_main_main_default);
	lv_style_set_radius(&style_date_setting_label_charge_main_main_default, 0);
	lv_style_set_bg_color(&style_date_setting_label_charge_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_date_setting_label_charge_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_date_setting_label_charge_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_date_setting_label_charge_main_main_default, 0);
	lv_style_set_text_color(&style_date_setting_label_charge_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_date_setting_label_charge_main_main_default, &lv_font_SourceHanSansCN_Regular_16);
	lv_style_set_text_letter_space(&style_date_setting_label_charge_main_main_default, 2);
	lv_style_set_text_line_space(&style_date_setting_label_charge_main_main_default, 0);
	lv_style_set_text_align(&style_date_setting_label_charge_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_date_setting_label_charge_main_main_default, 0);
	lv_style_set_pad_right(&style_date_setting_label_charge_main_main_default, 0);
	lv_style_set_pad_top(&style_date_setting_label_charge_main_main_default, 8);
	lv_style_set_pad_bottom(&style_date_setting_label_charge_main_main_default, 0);
	lv_obj_add_style(ui->date_setting_label_charge, &style_date_setting_label_charge_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
}