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
		lv_obj_t *screen_img_1;
		lv_obj_t *screen_cont_1;
		lv_obj_t *screen_label_1;
		lv_obj_t *screen_label_2;
		lv_obj_t *screen_btn_1;
		lv_obj_t *screen_btn_1_label;
		lv_obj_t *screen_btn_3;
		lv_obj_t *screen_btn_3_label;
		lv_obj_t *screen_btn_2;
		lv_obj_t *screen_btn_2_label;
		lv_obj_t *screen_slider_1;
		lv_obj_t *screen_ddlist_1;
		lv_obj_t *screen_sw_1;
		lv_obj_t *screen_sw_2;
		lv_obj_t *screen_label_3;
	} lv_ui;

	void init_scr_del_flag(lv_ui *ui);
	void setup_ui(lv_ui *ui);
	extern lv_ui guider_ui;
	void setup_scr_screen(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif