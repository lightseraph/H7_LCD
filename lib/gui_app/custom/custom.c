// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    uint8_t year, week;
    uint8_t hour, min, sec, ampm;
    RTC_Get_Date(&year, &today.month, &today.day, &week);
    RTC_Get_Time(&hour, &min, &sec, &ampm);
    today.year = 2000 + year;
    highlihted_days[0] = today;
    lv_calendar_set_today_date(ui->date_setting_calendar, today.year, today.month, today.day);
    lv_calendar_set_showed_date(ui->date_setting_calendar, today.year, today.month);
    lv_dclock_set_text_fmt(ui->date_setting_digital_clock, "%02d:%02d:%02d", hour, min, sec);
}
