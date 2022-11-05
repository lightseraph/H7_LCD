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
        lv_label_set_text_fmt(clock->time_label, "%02d : %02d : %02d\n20%02d - %02d - %02d", hour, min, sec, year, month, date);

        if (clock->weekday_label != NULL)
        {
            lv_obj_align_to(clock->weekday_label, clock->time_label, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
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

    lv_obj_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(btn, 20, 10);
    lv_obj_set_size(btn, 140, 50);
    lv_obj_t *btn1 = lv_btn_create(lv_scr_act());
    lv_obj_set_pos(btn1, 20, 10);
    lv_obj_set_size(btn1, 140, 50);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "关闭");
    lv_obj_align_to(label, btn, LV_ALIGN_CENTER, -16, 0);
    lv_obj_set_style_text_font(label, &lv_font_yahei_16, LV_STATE_DEFAULT);
    lv_obj_t *label0 = lv_label_create(btn1);
    lv_label_set_text(label0, "播放");
    lv_obj_align_to(label0, btn1, LV_ALIGN_CENTER, -16, 0);
    lv_obj_set_style_text_font(label0, &lv_font_yahei_16, LV_STATE_DEFAULT);

    static lv_clock_t lv_clock = {0};

    lv_obj_t *time_label = lv_label_create(lv_scr_act());
    lv_obj_set_size(time_label, 200, 25);
    lv_obj_set_pos(time_label, 10, 10);
    // lv_obj_set_style_text_font(time_label, LV_FONT_MONTSERRAT_16, LV_STATE_DEFAULT);
    lv_clock.time_label = time_label;

    lv_obj_t *week_label = lv_label_create(lv_scr_act());
    lv_obj_set_size(time_label, 100, 25);
    lv_obj_set_style_text_font(week_label, &lv_font_yahei_16, LV_STATE_DEFAULT);
    lv_clock.weekday_label = week_label;

    lv_obj_t *sw1 = lv_switch_create(lv_scr_act());
    lv_obj_t *label_sw1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label_sw1, "红灯");
    lv_obj_set_style_text_color(label_sw1, lv_color_hex(0xff0000), 0);
    lv_obj_set_style_text_font(label_sw1, &lv_font_yahei_16, LV_STATE_DEFAULT);

    lv_obj_add_event_cb(sw1, event_handler, LV_EVENT_ALL, "sw1");
    lv_obj_t *sw2 = lv_switch_create(lv_scr_act());
    lv_obj_t *label_sw2 = lv_label_create(lv_scr_act());
    lv_label_set_text(label_sw2, "绿灯");
    lv_obj_set_style_text_color(label_sw2, lv_color_hex(0xff00), 0);
    lv_obj_set_style_text_font(label_sw2, &lv_font_yahei_16, LV_STATE_DEFAULT);
    lv_obj_align_to(label_sw2, sw2, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_add_event_cb(sw2, event_handler, LV_EVENT_ALL, "sw2");

    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "Hello,world!");
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align_to(btn, label1, LV_ALIGN_OUT_TOP_MID, 85, -20);
    lv_obj_align_to(btn1, btn, LV_ALIGN_OUT_LEFT_MID, -30, 0);
    lv_obj_align_to(sw1, label1, LV_ALIGN_OUT_BOTTOM_LEFT, -45, 30);
    lv_obj_align_to(sw2, sw1, LV_ALIGN_OUT_RIGHT_MID, 40, 0);
    lv_obj_align_to(label_sw1, sw1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align_to(label_sw2, sw2, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_timer_create(clock_date_task_callback, 1000, (void *)&lv_clock); // 创建定时任务，200ms刷新一次
}

void lvgl_clock_start()
{
    static lv_style_t date_time_clock_style;                         // 最外层对象的样式
    lv_style_reset(&date_time_clock_style);                          // 重置样式
    lv_style_init(&date_time_clock_style);                           // 初始化样式
    lv_style_set_radius(&date_time_clock_style, 5);                  // 设置样式圆角
    lv_style_set_bg_opa(&date_time_clock_style, LV_OPA_20);          // 设置样式背景透明度
    lv_style_set_border_width(&date_time_clock_style, 0);            // 设置样式边框宽度
    lv_style_set_bg_color(&date_time_clock_style, lv_color_white()); // 设置样式背景颜色，白色
    lv_style_set_pad_left(&date_time_clock_style, 1);                // 设置样式左边padding填充宽度
    lv_style_set_pad_right(&date_time_clock_style, 1);               // 设置样式右边padding填充宽度
    lv_style_set_pad_top(&date_time_clock_style, 0);                 // 设置样式顶部padding填充宽度
    lv_style_set_pad_bottom(&date_time_clock_style, 0);              // 设置样式底部padding填充宽度

    static lv_style_t time_style; // 时间对象样式
    lv_style_reset(&time_style);
    lv_style_init(&time_style);
    lv_style_set_bg_opa(&time_style, LV_OPA_COVER);
    lv_style_set_border_width(&time_style, 0);
    lv_style_set_radius(&time_style, 5);
    lv_style_set_bg_color(&time_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_pad_left(&time_style, 0);
    lv_style_set_pad_right(&time_style, 0);
    lv_style_set_pad_top(&time_style, 0);
    lv_style_set_pad_bottom(&time_style, 0);

    static lv_style_t date_style; // 日期对象样式
    lv_style_reset(&date_style);
    lv_style_init(&date_style);
    lv_style_set_bg_opa(&date_style, LV_OPA_COVER);
    lv_style_set_border_width(&date_style, 0);
    lv_style_set_radius(&date_style, 5);
    lv_style_set_bg_color(&date_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_pad_left(&date_style, 0);
    lv_style_set_pad_right(&date_style, 0);

    /* Time font */
    static lv_style_t time_label_style;                                // 时间标签样式
    lv_style_reset(&time_label_style);                                 // 重置样式
    lv_style_init(&time_label_style);                                  // 初始化样式
    lv_style_set_text_color(&time_label_style, lv_color_white());      // 设置标签样式文本颜色
    lv_style_set_text_font(&time_label_style, &lv_font_montserrat_16); // 设置字体风格
    lv_style_set_text_opa(&time_label_style, LV_OPA_COVER);            // 设置字体透明度
    lv_style_set_bg_opa(&time_label_style, LV_OPA_0);                  // 设置样式背景透明度

    /* Date font */
    static lv_style_t date_label_style; // 日期标签样式
    lv_style_reset(&date_label_style);
    lv_style_init(&date_label_style);
    lv_style_set_text_opa(&date_label_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&date_label_style, LV_OPA_0);
    lv_style_set_text_color(&date_label_style, lv_color_white());
    lv_style_set_text_font(&date_label_style, &lv_font_montserrat_16);

    /* Week font */
    static lv_style_t week_lable_style; // 日期标签样式
    lv_style_reset(&week_lable_style);
    lv_style_init(&week_lable_style);
    lv_style_set_text_opa(&week_lable_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&week_lable_style, LV_OPA_0);
    lv_style_set_text_color(&week_lable_style, lv_color_white());
    lv_style_set_text_font(&week_lable_style, &lv_font_montserrat_16);

    /* Time & Date */
    lv_obj_t *time_date_obj = lv_obj_create(lv_scr_act()); // 基于屏幕创建时间日期对象
    if (time_date_obj == NULL)
    {
        printf("[%s:%d] time_date_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }

    lv_obj_set_size(time_date_obj, 270, 40);                                   // 设置对象大小
    lv_obj_set_pos(time_date_obj, 265, 5);                                     // 对象居屏幕中间显示
    lv_obj_add_style(time_date_obj, &date_time_clock_style, LV_STATE_DEFAULT); //给time_date_obj对象添加样式

    /*Time display*/
    lv_obj_t *time_obj = lv_obj_create(time_date_obj); // 基于time_date_obj对象创建时间对象
    if (time_obj == NULL)
    {
        printf("[%s:%d] time_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }

    lv_obj_set_size(time_obj, 130, 50);                                // 设置对象大小
    lv_obj_align_to(time_obj, time_date_obj, LV_ALIGN_LEFT_MID, 0, 0); // 设置time_obj对象基于time_date_obj对象左边中间对齐
    lv_obj_add_style(time_obj, &time_style, LV_STATE_DEFAULT);         // 给time_obj对象添加样式

    static lv_clock_t lv_clock = {0};

    lv_clock.time_label = lv_label_create(time_obj); // 基于time_obj对象创建时间显示标签对象 lv_clock.time_label
    if (lv_clock.time_label == NULL)
    {
        printf("[%s:%d] time_label create failed\n", __FUNCTION__, __LINE__);
        return;
    }

    lv_obj_add_style(lv_clock.time_label, &time_label_style, LV_STATE_DEFAULT); // 给对象 lv_clock.time_label添加样式

    /*Date display*/
    lv_obj_t *date_obj = lv_obj_create(time_date_obj); // 基于time_date_obj对象创建date_obj对象
    if (date_obj == NULL)
    {
        printf("[%s:%d] date_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }
    lv_obj_set_size(date_obj, 130, 100);                                // 设置对象大小
    lv_obj_align_to(date_obj, time_date_obj, LV_ALIGN_RIGHT_MID, 0, 0); //设置date_obj对象基于time_date_obj对象右边中部对齐
    lv_obj_add_style(date_obj, &date_style, LV_STATE_DEFAULT);          // 给date_obj对象添加样式

    lv_clock.date_label = lv_label_create(date_obj); // 基于date_obj对象创建lv_clock.date_label日期显示对象
    if (lv_clock.date_label == NULL)
    {
        printf("[%s:%d] date_label create failed\n", __FUNCTION__, __LINE__);
        return;
    }
    lv_obj_add_style(lv_clock.date_label, &date_label_style, LV_STATE_DEFAULT); // 给lv_clock.date_label对象添加样式

    /*Week display*/
    lv_clock.weekday_label = lv_label_create(date_obj); // 基于date_obj对象创建星期显示lv_clock.weekday_label对象
    if (lv_clock.weekday_label == NULL)
    {
        printf("[%s:%d] weekday_label create failed\n", __FUNCTION__, __LINE__);
        return;
    }
    lv_obj_add_style(lv_clock.weekday_label, &week_lable_style, LV_STATE_DEFAULT); // 给对象lv_clock.weekday_label添加样式

    // 设置时间标签lv_clock.time_label对象基于父对象居中对齐
    lv_obj_align_to(lv_clock.time_label, lv_obj_get_parent(lv_clock.time_label), LV_ALIGN_CENTER, 0, 0);
    // 设置时间标签lv_clock.date_label对象基于父对象顶部中间对齐
    lv_obj_align_to(lv_clock.date_label, lv_obj_get_parent(lv_clock.date_label), LV_ALIGN_TOP_MID, 2, 0);
    // 设置时间标签lv_clock.weekday_label对象基于父对象底部中间对齐
    lv_obj_align_to(lv_clock.weekday_label, lv_obj_get_parent(lv_clock.weekday_label), LV_ALIGN_BOTTOM_MID, -2, 0);

    lv_timer_t *task_timer = lv_timer_create(clock_date_task_callback, 1000, (void *)&lv_clock); // 创建定时任务，200ms刷新一次
    if (task_timer == NULL)
    {
        printf("[%s:%d] lv_timer_create failed\n", __FUNCTION__, __LINE__);
    }
}