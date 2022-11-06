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

static void clock_date_task_callback(lv_timer_t *timer)
{
    // static const char *week_day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    static const char *week_day_cn[7] = {"星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期日"};

    u8 hour, min, sec, ampm;
    u8 year, month, date, week;
    RTC_Get_Time(&hour, &min, &sec, &ampm);
    RTC_Get_Date(&year, &month, &date, &week);

    if (timer != NULL && timer->user_data != NULL)
    {
        lv_clock_t *clock = (lv_clock_t *)(timer->user_data);
        lv_label_set_text_fmt(clock->time_label, "%02d : %02d : %02d    20%02d - %02d - %02d", hour, min, sec, year, month, date);

        if (clock->weekday_label != NULL)
        {
            lv_obj_align_to(clock->weekday_label, clock->time_label, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
            lv_label_set_text_fmt(clock->weekday_label, "%s", week_day_cn[week - 1]); // RTC星期寄存器值 1～7
        }
    }
}

void lvgl_first_demo_start(void)
{
    /*  LV_IMG_DECLARE(debian_s);
     static lv_style_t style;
     lv_style_init(&style);
     lv_style_set_bg_img_src(&style, &debian_s);
     lv_obj_t *sy = lv_obj_create(lv_scr_act());
     lv_obj_add_style(sy, &style, 0);
     lv_obj_set_size(sy, 480, 800);
     lv_obj_center(sy); */

    static lv_style_t btn_style;
    lv_style_set_width(&btn_style, 120);
    lv_style_set_height(&btn_style, 40);
    lv_style_set_radius(&btn_style, 9);
    lv_obj_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_t *btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_style(btn, &btn_style, 0);
    lv_obj_add_style(btn1, &btn_style, 0);

    lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "关闭");
    lv_obj_align_to(label, btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label, &lv_font_siyuan_16, LV_STATE_DEFAULT);
    lv_obj_t *label0 = lv_label_create(btn1);
    lv_label_set_text(label0, "播放");
    lv_obj_align_to(label0, btn1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label0, &lv_font_siyuan_16, LV_STATE_DEFAULT);

    static lv_clock_t lv_clock = {0};

    lv_obj_t *time_label = lv_label_create(lv_scr_act());
    lv_obj_set_width(time_label, 200);
    lv_obj_set_pos(time_label, 10, 10);
    // lv_label_set_long_mode(time_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_align(time_label, LV_TEXT_ALIGN_LEFT, 0);
    // lv_obj_set_style_text_font(time_label, LV_FONT_MONTSERRAT_16, LV_STATE_DEFAULT);
    lv_clock.time_label = time_label;

    lv_obj_t *week_label = lv_label_create(lv_scr_act());
    // lv_obj_set_size(time_label, 100, 25);
    lv_obj_set_style_text_font(week_label, &lv_font_siyuan_16, LV_STATE_DEFAULT);
    lv_clock.weekday_label = week_label;

    lv_obj_t *sw1 = lv_switch_create(lv_scr_act());
    lv_obj_t *label_sw1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label_sw1, "红灯");
    lv_obj_set_style_text_color(label_sw1, lv_color_hex(0xff0000), 0);
    lv_obj_set_style_text_font(label_sw1, &lv_font_siyuan_16, LV_STATE_DEFAULT);

    lv_obj_add_event_cb(sw1, event_handler, LV_EVENT_VALUE_CHANGED, "sw1");
    lv_obj_t *sw2 = lv_switch_create(lv_scr_act());
    lv_obj_t *label_sw2 = lv_label_create(lv_scr_act());
    lv_label_set_text(label_sw2, "绿灯");
    lv_obj_set_style_text_color(label_sw2, lv_color_hex(0xff00), 0);
    lv_obj_set_style_text_font(label_sw2, &lv_font_siyuan_16, LV_STATE_DEFAULT);
    lv_obj_align_to(label_sw2, sw2, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_add_event_cb(sw2, event_handler, LV_EVENT_VALUE_CHANGED, "sw2");

    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "Hello,world!");
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align_to(btn, label1, LV_ALIGN_OUT_TOP_MID, 85, -20);
    lv_obj_align_to(btn1, btn, LV_ALIGN_OUT_LEFT_MID, -30, 0);
    lv_obj_align_to(sw1, label1, LV_ALIGN_OUT_BOTTOM_LEFT, -45, 30);
    lv_obj_align_to(sw2, sw1, LV_ALIGN_OUT_RIGHT_MID, 40, 0);
    lv_obj_align_to(label_sw1, sw1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align_to(label_sw2, sw2, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_timer_create(clock_date_task_callback, 1000, (void *)&lv_clock); // 创建定时任务，1000ms刷新一次
}