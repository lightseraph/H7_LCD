/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */
#ifndef GUIDER_CUSTOMER_FONTS_H
#define GUIDER_CUSTOMER_FONTS_H
#ifdef __cplusplus
extern "C" {
#endif

#if LVGL_VERSION_MAJOR == 7
#include "lv_font/lv_font.h"
#else
#include "font/lv_font.h"
#endif

LV_FONT_DECLARE(lv_customer_font_SourceHanSansCN_Regular_20)
LV_FONT_DECLARE(lv_customer_font_SourceHanSansCN_Regular_18)
LV_FONT_DECLARE(lv_customer_font_SourceHanSansCN_Regular_16)


#ifdef __cplusplus
}
#endif
#endif
