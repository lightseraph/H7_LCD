#include "lvgl/lvgl.h"
#include "sys.h"

typedef struct _lv_clock
{
    lv_obj_t *time_label;    // 时间标签
    lv_obj_t *date_label;    // 日期标签
    lv_obj_t *weekday_label; // 星期标签
} lv_clock_t;

// void event_handler(lv_event_t *event);
void lvgl_first_demo_start(void);
void lvgl_clock_start();