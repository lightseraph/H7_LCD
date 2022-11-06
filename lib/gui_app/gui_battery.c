#include "lvgl/lvgl.h"

#define OUTLINE_W 46 //电池图标宽度
#define OUTLINE_H 20 //电池图标高度

static void lv_anim_cb(void *p, int32_t v)
{
    //实现变色效果，电池电量低于20% 红色
    static int32_t cnt;
    if (cnt >= OUTLINE_W * 0.2 && v < OUTLINE_W * 0.2)
    {
        lv_obj_set_style_bg_color(p, lv_color_hex(0xff0000), 0);
    }
    else if (v >= OUTLINE_W * 0.2 && cnt < OUTLINE_W * 0.2)
    {
        lv_obj_set_style_bg_color(p, lv_color_hex(0xffc8c8c8), 0);
    }
    cnt = v;

    //修改电量颜色obj宽度
    lv_obj_set_width(p, v);

    //修改电池百分比
    lv_obj_t *text = lv_obj_get_child(lv_obj_get_parent(p), -1);
    lv_label_set_text_fmt(text, "%ld", v * 100 / (OUTLINE_W - 4));
}
void draw_battery(void)
{
    lv_obj_t *outline = lv_obj_create(lv_scr_act());

    //设置border和pading
    lv_obj_set_style_border_width(outline, 2, 0);
    lv_obj_set_style_pad_all(outline, 0, 0);

    //设置圆角
    lv_obj_set_style_radius(outline, 5, 0);

    //关闭滚动条
    lv_obj_clear_flag(outline, LV_OBJ_FLAG_SCROLLABLE);

    //设置宽高
    lv_obj_set_size(outline, OUTLINE_W, OUTLINE_H);

    //居中对齐
    lv_obj_align(outline, LV_ALIGN_TOP_RIGHT, -15, 7);
    lv_obj_set_style_border_color(outline, lv_color_hex(0xff505050), 0);

    //创建电池图标的正极
    lv_obj_t *bat_head = lv_obj_create(lv_scr_act());
    static lv_style_t style_batt_head;
    lv_style_init(&style_batt_head);
    lv_style_set_bg_color(&style_batt_head, lv_color_hex(0xFF909090));
    lv_style_set_outline_width(&style_batt_head, 0);
    lv_style_set_border_width(&style_batt_head, 0);
    lv_style_set_radius(&style_batt_head, 2);
    // lv_style_set_pad_all(&style_batt_head, 10);
    lv_obj_add_style(bat_head, &style_batt_head, 0);
    lv_obj_set_size(bat_head, 4, 10);
    lv_obj_align_to(bat_head, outline, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

    //电池电量填充obj
    lv_obj_t *pad = lv_obj_create(outline);

    //设置outline
    lv_obj_set_style_outline_width(pad, 0, 0);
    lv_obj_set_style_outline_pad(pad, 0, 0);
    lv_obj_set_style_border_width(pad, 0, 0);
    //设置背景色
    lv_obj_set_style_bg_color(pad, lv_color_hex(0xff0000), 0);

    //设置宽高
    lv_obj_set_size(pad, OUTLINE_W, OUTLINE_H - 4);
    lv_obj_set_style_border_width(pad, 0, 0);

    //设置圆角
    lv_obj_set_style_radius(pad, 5, 0);

    //居中对齐
    lv_obj_align(pad, LV_ALIGN_LEFT_MID, 0, 0);

    //关闭滚动条
    lv_obj_clear_flag(pad, LV_OBJ_FLAG_SCROLLABLE);

    //电池百分比
    lv_obj_t *label = lv_label_create(outline);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    //设置动画， 模仿电池电量变化
    lv_anim_t a;
    lv_anim_init(&a);

    /*Set the "animator" function*/
    lv_anim_set_exec_cb(&a, lv_anim_cb);

    /*Set the "animator" function*/
    lv_anim_set_var(&a, pad);

    /*Length of the animation [ms]*/
    lv_anim_set_time(&a, 20000);

    /*Set start and end values. E.g. 0, 150*/
    lv_anim_set_values(&a, 0, OUTLINE_W - 4);

    /*Time to wait before starting the animation [ms]*/
    lv_anim_set_delay(&a, 1000);

    /*Play the animation backward too with this duration. Default is 0 (disabled) [ms]*/
    lv_anim_set_playback_time(&a, 0);

    /*Delay before playback. Default is 0 (disabled) [ms]*/
    lv_anim_set_playback_delay(&a, 0);

    /*Number of repetitions. Default is 1.  LV_ANIM_REPEAT_INFINIT for infinite repetition*/
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);

    /*Delay before repeat. Default is 0 (disabled) [ms]*/
    lv_anim_set_repeat_delay(&a, 1000);

    /* START THE ANIMATION
     *------------------*/
    lv_anim_start(&a); /*Start the animation*/
}
