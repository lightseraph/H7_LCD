/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */
#ifndef GUIDER_FONTS_H
#define GUIDER_FONTS_H
#ifdef __cplusplus
extern "C"
{
#endif

#if LVGL_VERSION_MAJOR == 7
#include "lv_font/lv_font.h"
#else
#include "lvgl/src/font/lv_font.h"
#endif

    LV_FONT_DECLARE(lv_font_SourceHanSansCN_Regular_16)
    LV_FONT_DECLARE(lv_font_simsun_12)
    LV_FONT_DECLARE(lv_font_SourceHanSansCN_Regular_15)

#ifdef __cplusplus
}
#endif
#endif
