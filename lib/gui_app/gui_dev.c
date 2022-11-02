#include "gui_dev.h"
#include "gpio.h"
#include "rtc.h"

static void event_handler(lv_event_t *event)
{
    lv_obj_t *obj = lv_event_get_target(event);
    switch (lv_event_get_code(event))
    {
    case LV_EVENT_PRESSED:
        break;
    case LV_EVENT_RELEASED:

        break;
    case LV_EVENT_VALUE_CHANGED:
        if (strcmp((char *)lv_event_get_user_data(event), "sw1") == 0)
        {
            if (lv_obj_has_state(obj, LV_STATE_CHECKED))
                HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, 0);
            else
                HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, 1);
        }
        else if (strcmp((char *)lv_event_get_user_data(event), "sw2") == 0)
        {
            if (lv_obj_has_state(obj, LV_STATE_CHECKED))
                HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 0);
            else
                HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 1);
        }

        break;

    default:
        break;
    }
}

void lvgl_first_demo_start(void)
{
    u8 hour, min, sec, ampm;
    u8 year, month, date, week;

    /*  LV_IMG_DECLARE(debian_s);
     static lv_style_t style;
     lv_style_init(&style);
     lv_style_set_bg_img_src(&style, &debian_s);
     lv_obj_t *sy = lv_obj_create(lv_scr_act());
     lv_obj_add_style(sy, &style, 0);
     lv_obj_set_size(sy, 480, 800);
     lv_obj_center(sy); */

    lv_obj_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(btn, 20, 10);
    lv_obj_set_size(btn, 140, 50);
    lv_obj_t *btn1 = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(btn1, 20, 10);
    lv_obj_set_size(btn1, 140, 50);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "button1");
    lv_obj_align_to(label, btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_t *label0 = lv_label_create(btn1);
    lv_label_set_text(label0, "button2");
    lv_obj_align_to(label0, btn1, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *coord_x = lv_label_create(lv_scr_act());
    lv_obj_set_size(coord_x, 120, 20);

    lv_obj_t *coord_y = lv_label_create(lv_scr_act());
    lv_obj_set_size(coord_y, 120, 20);

    lv_obj_t *sw1 = lv_switch_create(lv_scr_act());
    lv_obj_add_event_cb(sw1, event_handler, LV_EVENT_ALL, "sw1");
    lv_obj_t *sw2 = lv_switch_create(lv_scr_act());
    lv_obj_add_event_cb(sw2, event_handler, LV_EVENT_ALL, "sw2");

    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "Hello,world!");
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align_to(btn, label1, LV_ALIGN_OUT_TOP_MID, 85, -20);
    lv_obj_align_to(btn1, btn, LV_ALIGN_OUT_LEFT_MID, -30, 0);
    lv_obj_align_to(coord_x, label1, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_obj_align_to(coord_y, coord_x, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_obj_align_to(sw1, coord_y, LV_ALIGN_OUT_BOTTOM_LEFT, -45, 30);
    lv_obj_align_to(sw2, sw1, LV_ALIGN_OUT_RIGHT_MID, 40, 0);

    // vUint16ConvertString(&(tp_dev.x), x, 2);
    // vUint16ConvertString(&(tp_dev.y), y, 2);
    RTC_Get_Time(&hour, &min, &sec, &ampm);
    RTC_Get_Date(&year, &month, &date, &week);

    lv_label_set_text_fmt(coord_x, "Time: %02d:%02d:%02d", hour, min, sec);
    lv_label_set_text_fmt(coord_y, "Date: 20%02d-%02d-%02d", year, month, date);
}