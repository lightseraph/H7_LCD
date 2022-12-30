/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts/guider_fonts.h"

	typedef struct
	{
		lv_obj_t *screen;
		bool screen_del;
		lv_obj_t *screen_cont_1;
		lv_obj_t *screen_label_1;
		lv_obj_t *screen_label_2;
		lv_obj_t *screen_ddlist_1;
		lv_obj_t *screen_btn_2;
		lv_obj_t *screen_btn_2_label;
		lv_obj_t *screen_btn_1;
		lv_obj_t *screen_btn_1_label;
		lv_obj_t *screen_slider_1;
		lv_obj_t *screen_btn_3;
		lv_obj_t *screen_btn_3_label;
		lv_obj_t *screen_sw_1;
		lv_obj_t *screen_sw_2;
		lv_obj_t *screen_label_3;
		lv_obj_t *screen_tabview_1;
		lv_obj_t *screen_tabview_1_tab_1;
		lv_obj_t *screen_tabview_1_tab_2;
		lv_obj_t *screen_tabview_1_tab_3;
		lv_obj_t *date_setting;
		bool date_setting_del;
		lv_obj_t *date_setting_calendar;
		lv_obj_t *date_setting_spinbox_min;
		lv_obj_t *date_setting_spinbox_min_btn;
		lv_obj_t *date_setting_spinbox_min_btn_minus;
		lv_obj_t *date_setting_spinbox_hour;
		lv_obj_t *date_setting_spinbox_hour_btn;
		lv_obj_t *date_setting_spinbox_hour_btn_minus;
		lv_obj_t *date_setting_digital_clock;
		lv_obj_t *date_setting_btn_set;
		lv_obj_t *date_setting_btn_set_label;
		lv_obj_t *date_setting_btn_quit;
		lv_obj_t *date_setting_btn_quit_label;
		lv_obj_t *date_setting_label_1;
		lv_obj_t *date_setting_label_2;
		lv_obj_t *date_setting_label_3;
		lv_obj_t *date_setting_spinbox_sec;
		lv_obj_t *date_setting_spinbox_sec_btn;
		lv_obj_t *date_setting_spinbox_sec_btn_minus;
		lv_obj_t *date_setting_sw_am;
		lv_obj_t *date_setting_label_4;
		lv_obj_t *date_setting_label_charge;
		lv_obj_t *zigbee_setting;
		bool zigbee_setting_del;
		lv_obj_t *zigbee_setting_label_1;
		lv_obj_t *zigbee_setting_label_2;
	} lv_ui;

	void init_scr_del_flag(lv_ui *ui);
	void setup_ui(lv_ui *ui);
	extern lv_ui guider_ui;
	void setup_scr_screen(lv_ui *ui);
	void setup_scr_date_setting(lv_ui *ui);
	static lv_calendar_date_t today;
	static lv_calendar_date_t highlihted_days[1];
	void setup_scr_zigbee_setting(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif