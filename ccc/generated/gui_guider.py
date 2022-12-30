# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=800,h=480)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(800*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 800
disp_drv.ver_res = 480
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


screen = lv.obj()
screen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_main_main_default
style_screen_main_main_default = lv.style_t()
style_screen_main_main_default.init()
style_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_main_main_default.set_bg_opa(255)

# add style for screen
screen.add_style(style_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_cont_1 = lv.obj(screen)
screen_cont_1.set_pos(int(364),int(78))
screen_cont_1.set_size(400,316)
screen_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_1 = lv.label(screen_cont_1)
screen_label_1.set_pos(int(55),int(215))
screen_label_1.set_size(30,30)
screen_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_1.set_text("\xEF\x80\xA7")
screen_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_1_main_main_default
style_screen_label_1_main_main_default = lv.style_t()
style_screen_label_1_main_main_default.init()
style_screen_label_1_main_main_default.set_radius(0)
style_screen_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_label_1_main_main_default.set_bg_opa(0)
style_screen_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_label_1_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_screen_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_1_main_main_default.set_text_letter_space(2)
style_screen_label_1_main_main_default.set_text_line_space(0)
style_screen_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_1_main_main_default.set_pad_left(0)
style_screen_label_1_main_main_default.set_pad_right(0)
style_screen_label_1_main_main_default.set_pad_top(8)
style_screen_label_1_main_main_default.set_pad_bottom(0)

# add style for screen_label_1
screen_label_1.add_style(style_screen_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label_2 = lv.label(screen_cont_1)
screen_label_2.set_pos(int(320),int(215))
screen_label_2.set_size(30,30)
screen_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_2.set_text("\xEF\x80\xA8")
screen_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_2_main_main_default
style_screen_label_2_main_main_default = lv.style_t()
style_screen_label_2_main_main_default.init()
style_screen_label_2_main_main_default.set_radius(0)
style_screen_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_label_2_main_main_default.set_bg_opa(0)
style_screen_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_label_2_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_screen_label_2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_2_main_main_default.set_text_letter_space(2)
style_screen_label_2_main_main_default.set_text_line_space(0)
style_screen_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_2_main_main_default.set_pad_left(0)
style_screen_label_2_main_main_default.set_pad_right(0)
style_screen_label_2_main_main_default.set_pad_top(8)
style_screen_label_2_main_main_default.set_pad_bottom(0)

# add style for screen_label_2
screen_label_2.add_style(style_screen_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_ddlist_1 = lv.dropdown(screen_cont_1)
screen_ddlist_1.set_pos(int(80),int(130))
screen_ddlist_1.set_size(242,40)
screen_ddlist_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_ddlist_1.set_options("list1\nlist2\nlist3")

screen_ddlist_1_list = screen_ddlist_1.get_list()
# create style style_screen_ddlist_1_extra_list_selected_checked
style_screen_ddlist_1_extra_list_selected_checked = lv.style_t()
style_screen_ddlist_1_extra_list_selected_checked.init()
style_screen_ddlist_1_extra_list_selected_checked.set_radius(3)
style_screen_ddlist_1_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_screen_ddlist_1_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_screen_ddlist_1_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_ddlist_1_extra_list_selected_checked.set_bg_opa(255)
style_screen_ddlist_1_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_screen_ddlist_1_extra_list_selected_checked.set_border_width(1)
style_screen_ddlist_1_extra_list_selected_checked.set_border_opa(255)
style_screen_ddlist_1_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for screen_ddlist_1_list
screen_ddlist_1_list.add_style(style_screen_ddlist_1_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_screen_ddlist_1_extra_list_main_default
style_screen_ddlist_1_extra_list_main_default = lv.style_t()
style_screen_ddlist_1_extra_list_main_default.init()
style_screen_ddlist_1_extra_list_main_default.set_radius(3)
style_screen_ddlist_1_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist_1_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist_1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_ddlist_1_extra_list_main_default.set_bg_opa(255)
style_screen_ddlist_1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_screen_ddlist_1_extra_list_main_default.set_border_width(1)
style_screen_ddlist_1_extra_list_main_default.set_border_opa(255)
style_screen_ddlist_1_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_screen_ddlist_1_extra_list_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_screen_ddlist_1_extra_list_main_default.set_max_height(155)

# add style for screen_ddlist_1_list
screen_ddlist_1_list.add_style(style_screen_ddlist_1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_ddlist_1_extra_list_scrollbar_default
style_screen_ddlist_1_extra_list_scrollbar_default = lv.style_t()
style_screen_ddlist_1_extra_list_scrollbar_default.init()
style_screen_ddlist_1_extra_list_scrollbar_default.set_radius(3)
style_screen_ddlist_1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_screen_ddlist_1_extra_list_scrollbar_default.set_bg_opa(255)

# add style for screen_ddlist_1_list
screen_ddlist_1_list.add_style(style_screen_ddlist_1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_screen_ddlist_1_main_main_default
style_screen_ddlist_1_main_main_default = lv.style_t()
style_screen_ddlist_1_main_main_default.init()
style_screen_ddlist_1_main_main_default.set_radius(8)
style_screen_ddlist_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_ddlist_1_main_main_default.set_bg_opa(255)
style_screen_ddlist_1_main_main_default.set_border_color(lv.color_make(0x4e,0x4f,0x50))
style_screen_ddlist_1_main_main_default.set_border_width(2)
style_screen_ddlist_1_main_main_default.set_border_opa(255)
style_screen_ddlist_1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_screen_ddlist_1_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_screen_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_ddlist_1_main_main_default.set_pad_left(6)
style_screen_ddlist_1_main_main_default.set_pad_right(6)
style_screen_ddlist_1_main_main_default.set_pad_top(8)

# add style for screen_ddlist_1
screen_ddlist_1.add_style(style_screen_ddlist_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_btn_2 = lv.btn(screen_cont_1)
screen_btn_2.set_pos(int(155),int(50))
screen_btn_2.set_size(90,35)
screen_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_btn_2.add_flag(lv.obj.FLAG.CHECKABLE)
screen_btn_2_label = lv.label(screen_btn_2)
screen_btn_2_label.set_text("暂停")
screen_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_screen_btn_2_main_main_default
style_screen_btn_2_main_main_default = lv.style_t()
style_screen_btn_2_main_main_default.init()
style_screen_btn_2_main_main_default.set_radius(6)
style_screen_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_btn_2_main_main_default.set_bg_opa(255)
style_screen_btn_2_main_main_default.set_shadow_width(5)
style_screen_btn_2_main_main_default.set_shadow_color(lv.color_make(0x85,0x93,0x9d))
style_screen_btn_2_main_main_default.set_shadow_opa(192)
style_screen_btn_2_main_main_default.set_shadow_spread(2)
style_screen_btn_2_main_main_default.set_shadow_ofs_x(1)
style_screen_btn_2_main_main_default.set_shadow_ofs_y(1)
style_screen_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_default.set_border_width(0)
style_screen_btn_2_main_main_default.set_border_opa(255)
style_screen_btn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_btn_2_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_screen_btn_2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_2
screen_btn_2.add_style(style_screen_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_btn_2_main_main_pressed
style_screen_btn_2_main_main_pressed = lv.style_t()
style_screen_btn_2_main_main_pressed.init()
style_screen_btn_2_main_main_pressed.set_radius(5)
style_screen_btn_2_main_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_btn_2_main_main_pressed.set_bg_opa(255)
style_screen_btn_2_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_2_main_main_pressed.set_border_width(0)
style_screen_btn_2_main_main_pressed.set_border_opa(255)
style_screen_btn_2_main_main_pressed.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_2_main_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_btn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_btn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for screen_btn_2
screen_btn_2.add_style(style_screen_btn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

screen_btn_1 = lv.btn(screen_cont_1)
screen_btn_1.set_pos(int(35),int(50))
screen_btn_1.set_size(90,35)
screen_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_btn_1.add_flag(lv.obj.FLAG.CHECKABLE)
screen_btn_1_label = lv.label(screen_btn_1)
screen_btn_1_label.set_text("播放")
screen_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_screen_btn_1_main_main_default
style_screen_btn_1_main_main_default = lv.style_t()
style_screen_btn_1_main_main_default.init()
style_screen_btn_1_main_main_default.set_radius(6)
style_screen_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_btn_1_main_main_default.set_bg_opa(255)
style_screen_btn_1_main_main_default.set_shadow_width(5)
style_screen_btn_1_main_main_default.set_shadow_color(lv.color_make(0x85,0x93,0x9d))
style_screen_btn_1_main_main_default.set_shadow_opa(192)
style_screen_btn_1_main_main_default.set_shadow_spread(2)
style_screen_btn_1_main_main_default.set_shadow_ofs_x(1)
style_screen_btn_1_main_main_default.set_shadow_ofs_y(1)
style_screen_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_default.set_border_width(0)
style_screen_btn_1_main_main_default.set_border_opa(255)
style_screen_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_btn_1_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_screen_btn_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_1
screen_btn_1.add_style(style_screen_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_btn_1_main_main_pressed
style_screen_btn_1_main_main_pressed = lv.style_t()
style_screen_btn_1_main_main_pressed.init()
style_screen_btn_1_main_main_pressed.set_radius(5)
style_screen_btn_1_main_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_btn_1_main_main_pressed.set_bg_opa(255)
style_screen_btn_1_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_1_main_main_pressed.set_border_width(0)
style_screen_btn_1_main_main_pressed.set_border_opa(255)
style_screen_btn_1_main_main_pressed.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_1_main_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_btn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_btn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for screen_btn_1
screen_btn_1.add_style(style_screen_btn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

screen_slider_1 = lv.slider(screen_cont_1)
screen_slider_1.set_pos(int(100),int(223))
screen_slider_1.set_size(200,18)
screen_slider_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_slider_1.set_range(0, 100)
screen_slider_1.set_value(50, False)

# create style style_screen_slider_1_main_main_default
style_screen_slider_1_main_main_default = lv.style_t()
style_screen_slider_1_main_main_default.init()
style_screen_slider_1_main_main_default.set_radius(50)
style_screen_slider_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_slider_1_main_main_default.set_bg_opa(60)
style_screen_slider_1_main_main_default.set_shadow_width(5)
style_screen_slider_1_main_main_default.set_shadow_color(lv.color_make(0x8e,0xab,0xc2))
style_screen_slider_1_main_main_default.set_shadow_opa(192)
style_screen_slider_1_main_main_default.set_shadow_spread(3)
style_screen_slider_1_main_main_default.set_shadow_ofs_x(0)
style_screen_slider_1_main_main_default.set_shadow_ofs_y(0)
style_screen_slider_1_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_main_default.set_outline_width(0)
style_screen_slider_1_main_main_default.set_outline_opa(0)

# add style for screen_slider_1
screen_slider_1.add_style(style_screen_slider_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_slider_1_main_indicator_default
style_screen_slider_1_main_indicator_default = lv.style_t()
style_screen_slider_1_main_indicator_default.init()
style_screen_slider_1_main_indicator_default.set_radius(50)
style_screen_slider_1_main_indicator_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_slider_1_main_indicator_default.set_bg_opa(255)

# add style for screen_slider_1
screen_slider_1.add_style(style_screen_slider_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_screen_slider_1_main_knob_default
style_screen_slider_1_main_knob_default = lv.style_t()
style_screen_slider_1_main_knob_default.init()
style_screen_slider_1_main_knob_default.set_radius(50)
style_screen_slider_1_main_knob_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_slider_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_slider_1_main_knob_default.set_bg_opa(255)

# add style for screen_slider_1
screen_slider_1.add_style(style_screen_slider_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_btn_3 = lv.btn(screen_cont_1)
screen_btn_3.set_pos(int(275),int(50))
screen_btn_3.set_size(90,35)
screen_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_btn_3.add_flag(lv.obj.FLAG.CHECKABLE)
screen_btn_3_label = lv.label(screen_btn_3)
screen_btn_3_label.set_text("停止")
screen_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_screen_btn_3_main_main_default
style_screen_btn_3_main_main_default = lv.style_t()
style_screen_btn_3_main_main_default.init()
style_screen_btn_3_main_main_default.set_radius(6)
style_screen_btn_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_btn_3_main_main_default.set_bg_opa(255)
style_screen_btn_3_main_main_default.set_shadow_width(5)
style_screen_btn_3_main_main_default.set_shadow_color(lv.color_make(0x85,0x93,0x9d))
style_screen_btn_3_main_main_default.set_shadow_opa(192)
style_screen_btn_3_main_main_default.set_shadow_spread(2)
style_screen_btn_3_main_main_default.set_shadow_ofs_x(1)
style_screen_btn_3_main_main_default.set_shadow_ofs_y(1)
style_screen_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_default.set_border_width(0)
style_screen_btn_3_main_main_default.set_border_opa(255)
style_screen_btn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_btn_3_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_screen_btn_3_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for screen_btn_3
screen_btn_3.add_style(style_screen_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_btn_3_main_main_pressed
style_screen_btn_3_main_main_pressed = lv.style_t()
style_screen_btn_3_main_main_pressed.init()
style_screen_btn_3_main_main_pressed.set_radius(5)
style_screen_btn_3_main_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_btn_3_main_main_pressed.set_bg_opa(255)
style_screen_btn_3_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_btn_3_main_main_pressed.set_border_width(0)
style_screen_btn_3_main_main_pressed.set_border_opa(255)
style_screen_btn_3_main_main_pressed.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_btn_3_main_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_btn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_btn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for screen_btn_3
screen_btn_3.add_style(style_screen_btn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_screen_cont_1_main_main_default
style_screen_cont_1_main_main_default = lv.style_t()
style_screen_cont_1_main_main_default.init()
style_screen_cont_1_main_main_default.set_radius(10)
style_screen_cont_1_main_main_default.set_bg_color(lv.color_make(0xa2,0xac,0xbe))
style_screen_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_cont_1_main_main_default.set_bg_opa(141)
style_screen_cont_1_main_main_default.set_shadow_width(10)
style_screen_cont_1_main_main_default.set_shadow_color(lv.color_make(0xc8,0xd4,0xdf))
style_screen_cont_1_main_main_default.set_shadow_opa(192)
style_screen_cont_1_main_main_default.set_shadow_spread(5)
style_screen_cont_1_main_main_default.set_shadow_ofs_x(2)
style_screen_cont_1_main_main_default.set_shadow_ofs_y(2)
style_screen_cont_1_main_main_default.set_border_color(lv.color_make(0x37,0x8a,0xcd))
style_screen_cont_1_main_main_default.set_border_width(2)
style_screen_cont_1_main_main_default.set_border_opa(206)
style_screen_cont_1_main_main_default.set_pad_left(0)
style_screen_cont_1_main_main_default.set_pad_right(0)
style_screen_cont_1_main_main_default.set_pad_top(0)
style_screen_cont_1_main_main_default.set_pad_bottom(0)

# add style for screen_cont_1
screen_cont_1.add_style(style_screen_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_sw_1 = lv.switch(screen)
screen_sw_1.set_pos(int(91),int(371))
screen_sw_1.set_size(55,30)
screen_sw_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_sw_1_main_main_default
style_screen_sw_1_main_main_default = lv.style_t()
style_screen_sw_1_main_main_default.init()
style_screen_sw_1_main_main_default.set_radius(50)
style_screen_sw_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_screen_sw_1_main_main_default.set_bg_grad_color(lv.color_make(0x75,0xbf,0xff))
style_screen_sw_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_sw_1_main_main_default.set_bg_opa(255)
style_screen_sw_1_main_main_default.set_shadow_width(5)
style_screen_sw_1_main_main_default.set_shadow_color(lv.color_make(0x9e,0x9e,0x9e))
style_screen_sw_1_main_main_default.set_shadow_opa(192)
style_screen_sw_1_main_main_default.set_shadow_spread(3)
style_screen_sw_1_main_main_default.set_shadow_ofs_x(1)
style_screen_sw_1_main_main_default.set_shadow_ofs_y(1)
style_screen_sw_1_main_main_default.set_border_color(lv.color_make(0x2b,0x2b,0x2b))
style_screen_sw_1_main_main_default.set_border_width(1)
style_screen_sw_1_main_main_default.set_border_opa(255)

# add style for screen_sw_1
screen_sw_1.add_style(style_screen_sw_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_sw_1_main_indicator_checked
style_screen_sw_1_main_indicator_checked = lv.style_t()
style_screen_sw_1_main_indicator_checked.init()
style_screen_sw_1_main_indicator_checked.set_bg_color(lv.color_make(0x9f,0xfe,0xda))
style_screen_sw_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0xcc,0xff,0xe9))
style_screen_sw_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_sw_1_main_indicator_checked.set_bg_opa(255)
style_screen_sw_1_main_indicator_checked.set_border_color(lv.color_make(0x70,0x70,0x70))
style_screen_sw_1_main_indicator_checked.set_border_width(1)
style_screen_sw_1_main_indicator_checked.set_border_opa(255)

# add style for screen_sw_1
screen_sw_1.add_style(style_screen_sw_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_screen_sw_1_main_knob_default
style_screen_sw_1_main_knob_default = lv.style_t()
style_screen_sw_1_main_knob_default.init()
style_screen_sw_1_main_knob_default.set_radius(100)
style_screen_sw_1_main_knob_default.set_bg_color(lv.color_make(0x33,0xff,0x5c))
style_screen_sw_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_sw_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_sw_1_main_knob_default.set_bg_opa(255)
style_screen_sw_1_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_sw_1_main_knob_default.set_border_width(0)
style_screen_sw_1_main_knob_default.set_border_opa(255)

# add style for screen_sw_1
screen_sw_1.add_style(style_screen_sw_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_sw_2 = lv.switch(screen)
screen_sw_2.set_pos(int(203),int(371))
screen_sw_2.set_size(55,30)
screen_sw_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_sw_2_main_main_default
style_screen_sw_2_main_main_default = lv.style_t()
style_screen_sw_2_main_main_default.init()
style_screen_sw_2_main_main_default.set_radius(50)
style_screen_sw_2_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_screen_sw_2_main_main_default.set_bg_grad_color(lv.color_make(0x75,0xbf,0xff))
style_screen_sw_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_sw_2_main_main_default.set_bg_opa(255)
style_screen_sw_2_main_main_default.set_shadow_width(5)
style_screen_sw_2_main_main_default.set_shadow_color(lv.color_make(0x9e,0x9e,0x9e))
style_screen_sw_2_main_main_default.set_shadow_opa(192)
style_screen_sw_2_main_main_default.set_shadow_spread(3)
style_screen_sw_2_main_main_default.set_shadow_ofs_x(1)
style_screen_sw_2_main_main_default.set_shadow_ofs_y(1)
style_screen_sw_2_main_main_default.set_border_color(lv.color_make(0x2b,0x2b,0x2b))
style_screen_sw_2_main_main_default.set_border_width(1)
style_screen_sw_2_main_main_default.set_border_opa(255)

# add style for screen_sw_2
screen_sw_2.add_style(style_screen_sw_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_sw_2_main_indicator_checked
style_screen_sw_2_main_indicator_checked = lv.style_t()
style_screen_sw_2_main_indicator_checked.init()
style_screen_sw_2_main_indicator_checked.set_bg_color(lv.color_make(0xff,0xa3,0xa3))
style_screen_sw_2_main_indicator_checked.set_bg_grad_color(lv.color_make(0xff,0xe5,0xe5))
style_screen_sw_2_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_sw_2_main_indicator_checked.set_bg_opa(255)
style_screen_sw_2_main_indicator_checked.set_border_color(lv.color_make(0x70,0x70,0x70))
style_screen_sw_2_main_indicator_checked.set_border_width(1)
style_screen_sw_2_main_indicator_checked.set_border_opa(255)

# add style for screen_sw_2
screen_sw_2.add_style(style_screen_sw_2_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_screen_sw_2_main_knob_default
style_screen_sw_2_main_knob_default = lv.style_t()
style_screen_sw_2_main_knob_default.init()
style_screen_sw_2_main_knob_default.set_radius(100)
style_screen_sw_2_main_knob_default.set_bg_color(lv.color_make(0xff,0x42,0x42))
style_screen_sw_2_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_sw_2_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_sw_2_main_knob_default.set_bg_opa(255)
style_screen_sw_2_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_sw_2_main_knob_default.set_border_width(0)
style_screen_sw_2_main_knob_default.set_border_opa(255)

# add style for screen_sw_2
screen_sw_2.add_style(style_screen_sw_2_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_label_3 = lv.label(screen)
screen_label_3.set_pos(int(710),int(2))
screen_label_3.set_size(30,30)
screen_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_3.set_text("\xEF\x83\xA7")
screen_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_3_main_main_default
style_screen_label_3_main_main_default = lv.style_t()
style_screen_label_3_main_main_default.init()
style_screen_label_3_main_main_default.set_radius(0)
style_screen_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_label_3_main_main_default.set_bg_opa(0)
style_screen_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_label_3_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_3_main_main_default.set_text_letter_space(2)
style_screen_label_3_main_main_default.set_text_line_space(0)
style_screen_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_3_main_main_default.set_pad_left(0)
style_screen_label_3_main_main_default.set_pad_right(0)
style_screen_label_3_main_main_default.set_pad_top(8)
style_screen_label_3_main_main_default.set_pad_bottom(0)

# add style for screen_label_3
screen_label_3.add_style(style_screen_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_tabview_1 = lv.tabview(screen, lv.DIR.TOP, 45)
screen_tabview_1_tab_btns = screen_tabview_1.get_tab_btns()
# create style style_screen_tabview_1_extra_btnm_main_default
style_screen_tabview_1_extra_btnm_main_default = lv.style_t()
style_screen_tabview_1_extra_btnm_main_default.init()
style_screen_tabview_1_extra_btnm_main_default.set_radius(5)
style_screen_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xfd,0xfc,0xed))
style_screen_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_screen_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_tabview_1_extra_btnm_main_default.set_border_width(0)
style_screen_tabview_1_extra_btnm_main_default.set_border_opa(206)

# add style for screen_tabview_1_tab_btns
screen_tabview_1_tab_btns.add_style(style_screen_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_tabview_1_extra_btnm_items_default
style_screen_tabview_1_extra_btnm_items_default = lv.style_t()
style_screen_tabview_1_extra_btnm_items_default.init()
style_screen_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_screen_tabview_1_extra_btnm_items_default.set_text_font(lv.font_SourceHanSansCN_Regular_15)
except AttributeError:
    try:
        style_screen_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_screen_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for screen_tabview_1_tab_btns
screen_tabview_1_tab_btns.add_style(style_screen_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_screen_tabview_1_extra_btnm_items_checked
style_screen_tabview_1_extra_btnm_items_checked = lv.style_t()
style_screen_tabview_1_extra_btnm_items_checked.init()
style_screen_tabview_1_extra_btnm_items_checked.set_radius(0)
style_screen_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_screen_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_screen_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_screen_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_screen_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_screen_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for screen_tabview_1_tab_btns
screen_tabview_1_tab_btns.add_style(style_screen_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

screen_tabview_1_tab_1 = screen_tabview_1.add_tab("tab_1")
screen_tabview_1_tab_1_label = lv.label(screen_tabview_1_tab_1)
screen_tabview_1_tab_1_label.set_text("con1")
screen_tabview_1_tab_2 = screen_tabview_1.add_tab("tab_2")
screen_tabview_1_tab_2_label = lv.label(screen_tabview_1_tab_2)
screen_tabview_1_tab_2_label.set_text("con2")
screen_tabview_1_tab_3 = screen_tabview_1.add_tab("tab_3")
screen_tabview_1_tab_3_label = lv.label(screen_tabview_1_tab_3)
screen_tabview_1_tab_3_label.set_text("con3")
screen_tabview_1.set_pos(int(40),int(78))
screen_tabview_1.set_size(295,250)
screen_tabview_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_tabview_1_main_main_default
style_screen_tabview_1_main_main_default = lv.style_t()
style_screen_tabview_1_main_main_default.init()
style_screen_tabview_1_main_main_default.set_radius(10)
style_screen_tabview_1_main_main_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_screen_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_screen_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_tabview_1_main_main_default.set_bg_opa(255)
style_screen_tabview_1_main_main_default.set_shadow_width(10)
style_screen_tabview_1_main_main_default.set_shadow_color(lv.color_make(0xc8,0xd4,0xdf))
style_screen_tabview_1_main_main_default.set_shadow_opa(192)
style_screen_tabview_1_main_main_default.set_shadow_spread(5)
style_screen_tabview_1_main_main_default.set_shadow_ofs_x(2)
style_screen_tabview_1_main_main_default.set_shadow_ofs_y(2)
style_screen_tabview_1_main_main_default.set_border_color(lv.color_make(0x37,0x8a,0xcd))
style_screen_tabview_1_main_main_default.set_border_width(2)
style_screen_tabview_1_main_main_default.set_border_opa(204)
style_screen_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_screen_tabview_1_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_screen_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_tabview_1_main_main_default.set_text_letter_space(2)
style_screen_tabview_1_main_main_default.set_text_line_space(16)

# add style for screen_tabview_1
screen_tabview_1.add_style(style_screen_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting = lv.obj()
date_setting.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_date_setting_main_main_default
style_date_setting_main_main_default = lv.style_t()
style_date_setting_main_main_default.init()
style_date_setting_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_main_main_default.set_bg_opa(255)

# add style for date_setting
date_setting.add_style(style_date_setting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_calendar = lv.calendar(date_setting)
date_setting_calendar.set_pos(int(50),int(73))
date_setting_calendar.set_size(385,360)
date_setting_calendar.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_calendar.set_today_date(time.localtime()[0], time.localtime()[1], time.localtime()[2])
date_setting_calendar.set_showed_date(time.localtime()[0], time.localtime()[1])
highlighted_days=[
    lv.calendar_date_t({'year':2020, 'month':5, 'day':14})
]
date_setting_calendar.set_highlighted_dates(highlighted_days, len(highlighted_days))
date_setting_calendar_header = lv.calendar_header_arrow(date_setting_calendar)
def style_date_setting_calendar_extra_ctrl_day_names_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id < 7:

        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
            try:
                lv.font_montserrat_16
                dsc.label_dsc.font = lv.font_montserrat_16
            except AttributeError:
                try:
                    lv.font_montserrat_17
                    dsc.label_dsc.font = lv.font_montserrat_17
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

date_setting_calendar.get_btnmatrix().add_event_cb(style_date_setting_calendar_extra_ctrl_day_names_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_date_setting_calendar_extra_ctrl_days_of_current_month_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if (dsc.id >= 7
        and not obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_1)
        and not obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_2)
        and not obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.DISABLED)):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)

        dsc.rect_dsc.bg_opa = 0
        dsc.rect_dsc.border_color = lv.color_make(0xc0,0xc0,0xc0)
        dsc.rect_dsc.border_width = 1
        dsc.rect_dsc.border_opa = 255
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
            try:
                lv.font_montserrat_16
                dsc.label_dsc.font = lv.font_montserrat_16
            except AttributeError:
                try:
                    lv.font_montserrat_17
                    dsc.label_dsc.font = lv.font_montserrat_17
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

date_setting_calendar.get_btnmatrix().add_event_cb(style_date_setting_calendar_extra_ctrl_days_of_current_month_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_date_setting_calendar_extra_ctrl_highlight_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_2):
        dsc.rect_dsc.bg_color = lv.color_make(0x21,0x95,0xf6)

        dsc.rect_dsc.bg_opa = 255
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
            try:
                lv.font_montserrat_16
                dsc.label_dsc.font = lv.font_montserrat_16
            except AttributeError:
                try:
                    lv.font_montserrat_17
                    dsc.label_dsc.font = lv.font_montserrat_17
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

date_setting_calendar.get_btnmatrix().add_event_cb(style_date_setting_calendar_extra_ctrl_highlight_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_date_setting_calendar_extra_ctrl_today_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_1):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)

        dsc.rect_dsc.bg_opa = 255
        dsc.rect_dsc.border_color = lv.color_make(0xc0,0xc0,0xc0)
        dsc.rect_dsc.border_width = 1
        dsc.rect_dsc.border_opa = 255
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
            try:
                lv.font_montserrat_16
                dsc.label_dsc.font = lv.font_montserrat_16
            except AttributeError:
                try:
                    lv.font_montserrat_17
                    dsc.label_dsc.font = lv.font_montserrat_17
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

date_setting_calendar.get_btnmatrix().add_event_cb(style_date_setting_calendar_extra_ctrl_today_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_date_setting_calendar_extra_ctrl_other_month_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.DISABLED):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)

        dsc.rect_dsc.bg_opa = 0
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0xA9,0xA2,0xA2)
            try:
                lv.font_montserrat_16
                dsc.label_dsc.font = lv.font_montserrat_16
            except AttributeError:
                try:
                    lv.font_montserrat_17
                    dsc.label_dsc.font = lv.font_montserrat_17
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

date_setting_calendar.get_btnmatrix().add_event_cb(style_date_setting_calendar_extra_ctrl_other_month_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

# create style style_date_setting_calendar_extra_header_main_default
style_date_setting_calendar_extra_header_main_default = lv.style_t()
style_date_setting_calendar_extra_header_main_default.init()
style_date_setting_calendar_extra_header_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_calendar_extra_header_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_calendar_extra_header_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_calendar_extra_header_main_default.set_bg_opa(255)
style_date_setting_calendar_extra_header_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_calendar_extra_header_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_calendar_extra_header_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_calendar_extra_header_main_default.set_text_font(lv.font_montserrat_16)

# add style for date_setting_calendar_header
date_setting_calendar_header.add_style(style_date_setting_calendar_extra_header_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_calendar_main_main_default
style_date_setting_calendar_main_main_default = lv.style_t()
style_date_setting_calendar_main_main_default.init()
style_date_setting_calendar_main_main_default.set_radius(10)
style_date_setting_calendar_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_calendar_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_calendar_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_calendar_main_main_default.set_bg_opa(255)
style_date_setting_calendar_main_main_default.set_shadow_width(12)
style_date_setting_calendar_main_main_default.set_shadow_color(lv.color_make(0x15,0x4f,0x7f))
style_date_setting_calendar_main_main_default.set_shadow_opa(181)
style_date_setting_calendar_main_main_default.set_shadow_spread(6)
style_date_setting_calendar_main_main_default.set_shadow_ofs_x(3)
style_date_setting_calendar_main_main_default.set_shadow_ofs_y(3)
style_date_setting_calendar_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_date_setting_calendar_main_main_default.set_border_width(2)
style_date_setting_calendar_main_main_default.set_border_opa(255)

# add style for date_setting_calendar
date_setting_calendar.add_style(style_date_setting_calendar_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_spinbox_min = lv.spinbox(date_setting)
date_setting_spinbox_min.set_pos(int(607),int(203))
date_setting_spinbox_min.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_spinbox_min.set_width(70)
date_setting_spinbox_min.set_height(40)
date_setting_spinbox_min.set_digit_format(2, 2)
date_setting_spinbox_min.step_prev()
date_setting_spinbox_min.set_range(-99, 99)

def date_setting_spinbox_min_increment_event_cb(e):
	code = e.get_code()
	if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
		date_setting_spinbox_min.increment()
def date_setting_spinbox_min_decrement_event_cb(e):
	code = e.get_code()
	if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
		date_setting_spinbox_min.decrement()

# create style style_date_setting_spinbox_min_extra_btns_main_default
style_date_setting_spinbox_min_extra_btns_main_default = lv.style_t()
style_date_setting_spinbox_min_extra_btns_main_default.init()
style_date_setting_spinbox_min_extra_btns_main_default.set_radius(5)
style_date_setting_spinbox_min_extra_btns_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_extra_btns_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_extra_btns_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_min_extra_btns_main_default.set_bg_opa(255)
style_date_setting_spinbox_min_extra_btns_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_extra_btns_main_default.set_border_width(0)
style_date_setting_spinbox_min_extra_btns_main_default.set_border_opa(255)
style_date_setting_spinbox_min_extra_btns_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_min_extra_btns_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_spinbox_min_extra_btns_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_spinbox_min_extra_btns_main_default.set_text_font(lv.font_montserrat_16)


# create style style_date_setting_spinbox_min_extra_btns_main_pressed
style_date_setting_spinbox_min_extra_btns_main_pressed = lv.style_t()
style_date_setting_spinbox_min_extra_btns_main_pressed.init()
style_date_setting_spinbox_min_extra_btns_main_pressed.set_radius(5)
style_date_setting_spinbox_min_extra_btns_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_extra_btns_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_extra_btns_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_min_extra_btns_main_pressed.set_bg_opa(255)
style_date_setting_spinbox_min_extra_btns_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_extra_btns_main_pressed.set_border_width(0)
style_date_setting_spinbox_min_extra_btns_main_pressed.set_border_opa(255)
style_date_setting_spinbox_min_extra_btns_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_min_extra_btns_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_spinbox_min_extra_btns_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_spinbox_min_extra_btns_main_pressed.set_text_font(lv.font_montserrat_16)


date_setting_spinbox_min_height = date_setting_spinbox_min.get_height()
date_setting_spinbox_min_btn = lv.btn(date_setting)
date_setting_spinbox_min_btn.set_size(date_setting_spinbox_min_height, date_setting_spinbox_min_height)
date_setting_spinbox_min_btn.align_to(date_setting_spinbox_min, lv.ALIGN.OUT_RIGHT_MID, 5, 0)
date_setting_spinbox_min_btn.set_style_bg_img_src(lv.SYMBOL.PLUS, 0)
date_setting_spinbox_min_btn.add_event_cb(date_setting_spinbox_min_increment_event_cb, lv.EVENT.ALL, None)
date_setting_spinbox_min_btn_minus = lv.btn(date_setting)
date_setting_spinbox_min_btn_minus.set_size(date_setting_spinbox_min_height, date_setting_spinbox_min_height)
date_setting_spinbox_min_btn_minus.align_to(date_setting_spinbox_min, lv.ALIGN.OUT_LEFT_MID, -5, 0)
date_setting_spinbox_min_btn_minus.set_style_bg_img_src(lv.SYMBOL.MINUS, 0)
date_setting_spinbox_min_btn_minus.add_event_cb(date_setting_spinbox_min_decrement_event_cb, lv.EVENT.ALL, None)

# add style for date_setting_spinbox_min_btn
date_setting_spinbox_min_btn.add_style(style_date_setting_spinbox_min_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# add style for date_setting_spinbox_min_btn
date_setting_spinbox_min_btn.add_style(style_date_setting_spinbox_min_extra_btns_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)


# add style for date_setting_spinbox_min_btn_minus
date_setting_spinbox_min_btn_minus.add_style(style_date_setting_spinbox_min_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# add style for date_setting_spinbox_min_btn_minus
date_setting_spinbox_min_btn_minus.add_style(style_date_setting_spinbox_min_extra_btns_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_date_setting_spinbox_min_main_main_default
style_date_setting_spinbox_min_main_main_default = lv.style_t()
style_date_setting_spinbox_min_main_main_default.init()
style_date_setting_spinbox_min_main_main_default.set_radius(5)
style_date_setting_spinbox_min_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_spinbox_min_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_spinbox_min_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_min_main_main_default.set_bg_opa(255)
style_date_setting_spinbox_min_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_main_main_default.set_border_width(2)
style_date_setting_spinbox_min_main_main_default.set_border_opa(255)
style_date_setting_spinbox_min_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_date_setting_spinbox_min_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_spinbox_min_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_spinbox_min_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_spinbox_min_main_main_default.set_text_letter_space(0)
style_date_setting_spinbox_min_main_main_default.set_pad_left(10)
style_date_setting_spinbox_min_main_main_default.set_pad_right(0)
style_date_setting_spinbox_min_main_main_default.set_pad_top(6)
style_date_setting_spinbox_min_main_main_default.set_pad_bottom(0)

# add style for date_setting_spinbox_min
date_setting_spinbox_min.add_style(style_date_setting_spinbox_min_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_spinbox_min_main_cursor_default
style_date_setting_spinbox_min_main_cursor_default = lv.style_t()
style_date_setting_spinbox_min_main_cursor_default.init()
style_date_setting_spinbox_min_main_cursor_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_main_cursor_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_min_main_cursor_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_min_main_cursor_default.set_bg_opa(255)
style_date_setting_spinbox_min_main_cursor_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_min_main_cursor_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_spinbox_min_main_cursor_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_spinbox_min_main_cursor_default.set_text_font(lv.font_montserrat_16)

# add style for date_setting_spinbox_min
date_setting_spinbox_min.add_style(style_date_setting_spinbox_min_main_cursor_default, lv.PART.CURSOR|lv.STATE.DEFAULT)

date_setting_spinbox_hour = lv.spinbox(date_setting)
date_setting_spinbox_hour.set_pos(int(607),int(142))
date_setting_spinbox_hour.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_spinbox_hour.set_width(70)
date_setting_spinbox_hour.set_height(40)
date_setting_spinbox_hour.set_digit_format(2, 2)
date_setting_spinbox_hour.step_prev()
date_setting_spinbox_hour.set_range(-99, 99)

def date_setting_spinbox_hour_increment_event_cb(e):
	code = e.get_code()
	if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
		date_setting_spinbox_hour.increment()
def date_setting_spinbox_hour_decrement_event_cb(e):
	code = e.get_code()
	if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
		date_setting_spinbox_hour.decrement()

# create style style_date_setting_spinbox_hour_extra_btns_main_default
style_date_setting_spinbox_hour_extra_btns_main_default = lv.style_t()
style_date_setting_spinbox_hour_extra_btns_main_default.init()
style_date_setting_spinbox_hour_extra_btns_main_default.set_radius(5)
style_date_setting_spinbox_hour_extra_btns_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_extra_btns_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_extra_btns_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_hour_extra_btns_main_default.set_bg_opa(255)
style_date_setting_spinbox_hour_extra_btns_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_extra_btns_main_default.set_border_width(0)
style_date_setting_spinbox_hour_extra_btns_main_default.set_border_opa(255)
style_date_setting_spinbox_hour_extra_btns_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_hour_extra_btns_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_spinbox_hour_extra_btns_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_spinbox_hour_extra_btns_main_default.set_text_font(lv.font_montserrat_16)


# create style style_date_setting_spinbox_hour_extra_btns_main_pressed
style_date_setting_spinbox_hour_extra_btns_main_pressed = lv.style_t()
style_date_setting_spinbox_hour_extra_btns_main_pressed.init()
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_radius(5)
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_bg_opa(255)
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_border_width(0)
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_border_opa(255)
style_date_setting_spinbox_hour_extra_btns_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_hour_extra_btns_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_spinbox_hour_extra_btns_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_spinbox_hour_extra_btns_main_pressed.set_text_font(lv.font_montserrat_16)


date_setting_spinbox_hour_height = date_setting_spinbox_hour.get_height()
date_setting_spinbox_hour_btn = lv.btn(date_setting)
date_setting_spinbox_hour_btn.set_size(date_setting_spinbox_hour_height, date_setting_spinbox_hour_height)
date_setting_spinbox_hour_btn.align_to(date_setting_spinbox_hour, lv.ALIGN.OUT_RIGHT_MID, 5, 0)
date_setting_spinbox_hour_btn.set_style_bg_img_src(lv.SYMBOL.PLUS, 0)
date_setting_spinbox_hour_btn.add_event_cb(date_setting_spinbox_hour_increment_event_cb, lv.EVENT.ALL, None)
date_setting_spinbox_hour_btn_minus = lv.btn(date_setting)
date_setting_spinbox_hour_btn_minus.set_size(date_setting_spinbox_hour_height, date_setting_spinbox_hour_height)
date_setting_spinbox_hour_btn_minus.align_to(date_setting_spinbox_hour, lv.ALIGN.OUT_LEFT_MID, -5, 0)
date_setting_spinbox_hour_btn_minus.set_style_bg_img_src(lv.SYMBOL.MINUS, 0)
date_setting_spinbox_hour_btn_minus.add_event_cb(date_setting_spinbox_hour_decrement_event_cb, lv.EVENT.ALL, None)

# add style for date_setting_spinbox_hour_btn
date_setting_spinbox_hour_btn.add_style(style_date_setting_spinbox_hour_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# add style for date_setting_spinbox_hour_btn
date_setting_spinbox_hour_btn.add_style(style_date_setting_spinbox_hour_extra_btns_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)


# add style for date_setting_spinbox_hour_btn_minus
date_setting_spinbox_hour_btn_minus.add_style(style_date_setting_spinbox_hour_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# add style for date_setting_spinbox_hour_btn_minus
date_setting_spinbox_hour_btn_minus.add_style(style_date_setting_spinbox_hour_extra_btns_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_date_setting_spinbox_hour_main_main_default
style_date_setting_spinbox_hour_main_main_default = lv.style_t()
style_date_setting_spinbox_hour_main_main_default.init()
style_date_setting_spinbox_hour_main_main_default.set_radius(5)
style_date_setting_spinbox_hour_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_spinbox_hour_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_spinbox_hour_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_hour_main_main_default.set_bg_opa(255)
style_date_setting_spinbox_hour_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_main_main_default.set_border_width(2)
style_date_setting_spinbox_hour_main_main_default.set_border_opa(255)
style_date_setting_spinbox_hour_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_date_setting_spinbox_hour_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_spinbox_hour_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_spinbox_hour_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_spinbox_hour_main_main_default.set_text_letter_space(0)
style_date_setting_spinbox_hour_main_main_default.set_pad_left(10)
style_date_setting_spinbox_hour_main_main_default.set_pad_right(0)
style_date_setting_spinbox_hour_main_main_default.set_pad_top(6)
style_date_setting_spinbox_hour_main_main_default.set_pad_bottom(0)

# add style for date_setting_spinbox_hour
date_setting_spinbox_hour.add_style(style_date_setting_spinbox_hour_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_spinbox_hour_main_cursor_default
style_date_setting_spinbox_hour_main_cursor_default = lv.style_t()
style_date_setting_spinbox_hour_main_cursor_default.init()
style_date_setting_spinbox_hour_main_cursor_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_main_cursor_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_hour_main_cursor_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_hour_main_cursor_default.set_bg_opa(255)
style_date_setting_spinbox_hour_main_cursor_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_hour_main_cursor_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_spinbox_hour_main_cursor_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_spinbox_hour_main_cursor_default.set_text_font(lv.font_montserrat_16)

# add style for date_setting_spinbox_hour
date_setting_spinbox_hour.add_style(style_date_setting_spinbox_hour_main_cursor_default, lv.PART.CURSOR|lv.STATE.DEFAULT)


date_setting_digital_clock = lv.dclock(date_setting, "11:25:50 AM")
date_setting_digital_clock.set_text("11:25:50 AM")



class date_setting_digital_clock_timerClass():
    def __init__(self):
        self.hour = 11
        self.minute = 25
        self.second = 50
        self.meridiem = "AM"
  
    def count_24(self, timer):
        self.second += 1
        if self.second == 60:
            self.second = 0
            self.minute += 1
	
        if self.minute == 60:
            self.minute = 0
            self.hour +=1
            
        if self.hour == 24:
            self.hour = 0

        date_setting_digital_clock.set_text("%02d:%02d:%02d" %(self.hour, self.minute, self.second))

    def count_12(self, timer):
        self.second += 1
        if self.second == 60:
            self.second = 0
            self.minute += 1
        if self.minute == 60:
            self.minute = 0
            if self.hour < 12:
                self.hour += 1
            else:
                self.hour += 1
                self.hour = self.hour % 12
        if (self.hour == 12 and self.second == 0 and self.minute == 0):
            if(self.meridiem == "PM"):
                self.meridiem = "AM"
            else:
                self.meridiem = "PM"
		
        date_setting_digital_clock.set_text("%02d:%02d:%02d %s" %(self.hour, self.minute, self.second, self.meridiem))

date_setting_digital_clock_timerInstance = date_setting_digital_clock_timerClass()

date_setting_digital_clock_timer = lv.timer_create_basic()
date_setting_digital_clock_timer.set_period(1000)

date_setting_digital_clock_timer.set_cb(lambda src: date_setting_digital_clock_timerInstance.count_12(date_setting_digital_clock_timer))
lv.dclock.set_style_text_align(date_setting_digital_clock, lv.TEXT_ALIGN.CENTER, 0);

date_setting_digital_clock.set_pos(int(556),int(73))
date_setting_digital_clock.set_size(165,40)
date_setting_digital_clock.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_date_setting_digital_clock_main_main_default
style_date_setting_digital_clock_main_main_default = lv.style_t()
style_date_setting_digital_clock_main_main_default.init()
style_date_setting_digital_clock_main_main_default.set_radius(0)
style_date_setting_digital_clock_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_digital_clock_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_digital_clock_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_digital_clock_main_main_default.set_bg_opa(255)
style_date_setting_digital_clock_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_digital_clock_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_digital_clock_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_digital_clock_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_digital_clock_main_main_default.set_text_letter_space(2)
style_date_setting_digital_clock_main_main_default.set_pad_left(0)
style_date_setting_digital_clock_main_main_default.set_pad_right(0)
style_date_setting_digital_clock_main_main_default.set_pad_top(8)
style_date_setting_digital_clock_main_main_default.set_pad_bottom(0)

# add style for date_setting_digital_clock
date_setting_digital_clock.add_style(style_date_setting_digital_clock_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_btn_set = lv.btn(date_setting)
date_setting_btn_set.set_pos(int(512),int(391))
date_setting_btn_set.set_size(100,40)
date_setting_btn_set.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_btn_set_label = lv.label(date_setting_btn_set)
date_setting_btn_set_label.set_text("设置")
date_setting_btn_set.set_style_pad_all(0, lv.STATE.DEFAULT)
date_setting_btn_set_label.align(lv.ALIGN.CENTER,0,0)
# create style style_date_setting_btn_set_main_main_default
style_date_setting_btn_set_main_main_default = lv.style_t()
style_date_setting_btn_set_main_main_default.init()
style_date_setting_btn_set_main_main_default.set_radius(5)
style_date_setting_btn_set_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_set_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_set_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_btn_set_main_main_default.set_bg_opa(255)
style_date_setting_btn_set_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_set_main_main_default.set_border_width(0)
style_date_setting_btn_set_main_main_default.set_border_opa(255)
style_date_setting_btn_set_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_btn_set_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_btn_set_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_btn_set_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_btn_set_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for date_setting_btn_set
date_setting_btn_set.add_style(style_date_setting_btn_set_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_btn_set_main_main_pressed
style_date_setting_btn_set_main_main_pressed = lv.style_t()
style_date_setting_btn_set_main_main_pressed.init()
style_date_setting_btn_set_main_main_pressed.set_radius(5)
style_date_setting_btn_set_main_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_set_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_set_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_btn_set_main_main_pressed.set_bg_opa(255)
style_date_setting_btn_set_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_set_main_main_pressed.set_border_width(0)
style_date_setting_btn_set_main_main_pressed.set_border_opa(255)
style_date_setting_btn_set_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_btn_set_main_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_btn_set_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_btn_set_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for date_setting_btn_set
date_setting_btn_set.add_style(style_date_setting_btn_set_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

date_setting_btn_quit = lv.btn(date_setting)
date_setting_btn_quit.set_pos(int(662),int(391))
date_setting_btn_quit.set_size(100,40)
date_setting_btn_quit.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_btn_quit_label = lv.label(date_setting_btn_quit)
date_setting_btn_quit_label.set_text("退出")
date_setting_btn_quit.set_style_pad_all(0, lv.STATE.DEFAULT)
date_setting_btn_quit_label.align(lv.ALIGN.CENTER,0,0)
# create style style_date_setting_btn_quit_main_main_default
style_date_setting_btn_quit_main_main_default = lv.style_t()
style_date_setting_btn_quit_main_main_default.init()
style_date_setting_btn_quit_main_main_default.set_radius(5)
style_date_setting_btn_quit_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_quit_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_quit_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_btn_quit_main_main_default.set_bg_opa(255)
style_date_setting_btn_quit_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_quit_main_main_default.set_border_width(0)
style_date_setting_btn_quit_main_main_default.set_border_opa(255)
style_date_setting_btn_quit_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_btn_quit_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_btn_quit_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_btn_quit_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_btn_quit_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for date_setting_btn_quit
date_setting_btn_quit.add_style(style_date_setting_btn_quit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_btn_quit_main_main_pressed
style_date_setting_btn_quit_main_main_pressed = lv.style_t()
style_date_setting_btn_quit_main_main_pressed.init()
style_date_setting_btn_quit_main_main_pressed.set_radius(5)
style_date_setting_btn_quit_main_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_quit_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_quit_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_btn_quit_main_main_pressed.set_bg_opa(255)
style_date_setting_btn_quit_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_btn_quit_main_main_pressed.set_border_width(0)
style_date_setting_btn_quit_main_main_pressed.set_border_opa(255)
style_date_setting_btn_quit_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_btn_quit_main_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_btn_quit_main_main_pressed.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_btn_quit_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for date_setting_btn_quit
date_setting_btn_quit.add_style(style_date_setting_btn_quit_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

date_setting_label_1 = lv.label(date_setting)
date_setting_label_1.set_pos(int(505),int(152))
date_setting_label_1.set_size(27,20)
date_setting_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_label_1.set_text("时")
date_setting_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_date_setting_label_1_main_main_default
style_date_setting_label_1_main_main_default = lv.style_t()
style_date_setting_label_1_main_main_default.init()
style_date_setting_label_1_main_main_default.set_radius(0)
style_date_setting_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_label_1_main_main_default.set_bg_opa(0)
style_date_setting_label_1_main_main_default.set_text_color(lv.color_make(0x0d,0x0e,0x12))
try:
    style_date_setting_label_1_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_label_1_main_main_default.set_text_letter_space(2)
style_date_setting_label_1_main_main_default.set_text_line_space(0)
style_date_setting_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_date_setting_label_1_main_main_default.set_pad_left(0)
style_date_setting_label_1_main_main_default.set_pad_right(0)
style_date_setting_label_1_main_main_default.set_pad_top(0)
style_date_setting_label_1_main_main_default.set_pad_bottom(0)

# add style for date_setting_label_1
date_setting_label_1.add_style(style_date_setting_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_label_2 = lv.label(date_setting)
date_setting_label_2.set_pos(int(505),int(212))
date_setting_label_2.set_size(27,20)
date_setting_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_label_2.set_text("分")
date_setting_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_date_setting_label_2_main_main_default
style_date_setting_label_2_main_main_default = lv.style_t()
style_date_setting_label_2_main_main_default.init()
style_date_setting_label_2_main_main_default.set_radius(0)
style_date_setting_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_label_2_main_main_default.set_bg_opa(0)
style_date_setting_label_2_main_main_default.set_text_color(lv.color_make(0x0d,0x0e,0x12))
try:
    style_date_setting_label_2_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_label_2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_label_2_main_main_default.set_text_letter_space(2)
style_date_setting_label_2_main_main_default.set_text_line_space(0)
style_date_setting_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_date_setting_label_2_main_main_default.set_pad_left(0)
style_date_setting_label_2_main_main_default.set_pad_right(0)
style_date_setting_label_2_main_main_default.set_pad_top(0)
style_date_setting_label_2_main_main_default.set_pad_bottom(0)

# add style for date_setting_label_2
date_setting_label_2.add_style(style_date_setting_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_label_3 = lv.label(date_setting)
date_setting_label_3.set_pos(int(505),int(273))
date_setting_label_3.set_size(27,20)
date_setting_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_label_3.set_text("秒")
date_setting_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_date_setting_label_3_main_main_default
style_date_setting_label_3_main_main_default = lv.style_t()
style_date_setting_label_3_main_main_default.init()
style_date_setting_label_3_main_main_default.set_radius(0)
style_date_setting_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_label_3_main_main_default.set_bg_opa(0)
style_date_setting_label_3_main_main_default.set_text_color(lv.color_make(0x0d,0x0e,0x12))
try:
    style_date_setting_label_3_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_label_3_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_label_3_main_main_default.set_text_letter_space(2)
style_date_setting_label_3_main_main_default.set_text_line_space(0)
style_date_setting_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_date_setting_label_3_main_main_default.set_pad_left(0)
style_date_setting_label_3_main_main_default.set_pad_right(0)
style_date_setting_label_3_main_main_default.set_pad_top(0)
style_date_setting_label_3_main_main_default.set_pad_bottom(0)

# add style for date_setting_label_3
date_setting_label_3.add_style(style_date_setting_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_spinbox_sec = lv.spinbox(date_setting)
date_setting_spinbox_sec.set_pos(int(607),int(264))
date_setting_spinbox_sec.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_spinbox_sec.set_width(70)
date_setting_spinbox_sec.set_height(40)
date_setting_spinbox_sec.set_digit_format(2, 2)
date_setting_spinbox_sec.step_prev()
date_setting_spinbox_sec.set_range(-99, 99)

def date_setting_spinbox_sec_increment_event_cb(e):
	code = e.get_code()
	if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
		date_setting_spinbox_sec.increment()
def date_setting_spinbox_sec_decrement_event_cb(e):
	code = e.get_code()
	if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
		date_setting_spinbox_sec.decrement()

# create style style_date_setting_spinbox_sec_extra_btns_main_default
style_date_setting_spinbox_sec_extra_btns_main_default = lv.style_t()
style_date_setting_spinbox_sec_extra_btns_main_default.init()
style_date_setting_spinbox_sec_extra_btns_main_default.set_radius(5)
style_date_setting_spinbox_sec_extra_btns_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_extra_btns_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_extra_btns_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_sec_extra_btns_main_default.set_bg_opa(255)
style_date_setting_spinbox_sec_extra_btns_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_extra_btns_main_default.set_border_width(0)
style_date_setting_spinbox_sec_extra_btns_main_default.set_border_opa(255)
style_date_setting_spinbox_sec_extra_btns_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_sec_extra_btns_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_spinbox_sec_extra_btns_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_spinbox_sec_extra_btns_main_default.set_text_font(lv.font_montserrat_16)


# create style style_date_setting_spinbox_sec_extra_btns_main_pressed
style_date_setting_spinbox_sec_extra_btns_main_pressed = lv.style_t()
style_date_setting_spinbox_sec_extra_btns_main_pressed.init()
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_radius(5)
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_bg_opa(255)
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_border_width(0)
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_border_opa(255)
style_date_setting_spinbox_sec_extra_btns_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_sec_extra_btns_main_pressed.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_spinbox_sec_extra_btns_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_spinbox_sec_extra_btns_main_pressed.set_text_font(lv.font_montserrat_16)


date_setting_spinbox_sec_height = date_setting_spinbox_sec.get_height()
date_setting_spinbox_sec_btn = lv.btn(date_setting)
date_setting_spinbox_sec_btn.set_size(date_setting_spinbox_sec_height, date_setting_spinbox_sec_height)
date_setting_spinbox_sec_btn.align_to(date_setting_spinbox_sec, lv.ALIGN.OUT_RIGHT_MID, 5, 0)
date_setting_spinbox_sec_btn.set_style_bg_img_src(lv.SYMBOL.PLUS, 0)
date_setting_spinbox_sec_btn.add_event_cb(date_setting_spinbox_sec_increment_event_cb, lv.EVENT.ALL, None)
date_setting_spinbox_sec_btn_minus = lv.btn(date_setting)
date_setting_spinbox_sec_btn_minus.set_size(date_setting_spinbox_sec_height, date_setting_spinbox_sec_height)
date_setting_spinbox_sec_btn_minus.align_to(date_setting_spinbox_sec, lv.ALIGN.OUT_LEFT_MID, -5, 0)
date_setting_spinbox_sec_btn_minus.set_style_bg_img_src(lv.SYMBOL.MINUS, 0)
date_setting_spinbox_sec_btn_minus.add_event_cb(date_setting_spinbox_sec_decrement_event_cb, lv.EVENT.ALL, None)

# add style for date_setting_spinbox_sec_btn
date_setting_spinbox_sec_btn.add_style(style_date_setting_spinbox_sec_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# add style for date_setting_spinbox_sec_btn
date_setting_spinbox_sec_btn.add_style(style_date_setting_spinbox_sec_extra_btns_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)


# add style for date_setting_spinbox_sec_btn_minus
date_setting_spinbox_sec_btn_minus.add_style(style_date_setting_spinbox_sec_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# add style for date_setting_spinbox_sec_btn_minus
date_setting_spinbox_sec_btn_minus.add_style(style_date_setting_spinbox_sec_extra_btns_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_date_setting_spinbox_sec_main_main_default
style_date_setting_spinbox_sec_main_main_default = lv.style_t()
style_date_setting_spinbox_sec_main_main_default.init()
style_date_setting_spinbox_sec_main_main_default.set_radius(5)
style_date_setting_spinbox_sec_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_spinbox_sec_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_spinbox_sec_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_sec_main_main_default.set_bg_opa(255)
style_date_setting_spinbox_sec_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_main_main_default.set_border_width(2)
style_date_setting_spinbox_sec_main_main_default.set_border_opa(255)
style_date_setting_spinbox_sec_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_date_setting_spinbox_sec_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_spinbox_sec_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_spinbox_sec_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_spinbox_sec_main_main_default.set_text_letter_space(0)
style_date_setting_spinbox_sec_main_main_default.set_pad_left(10)
style_date_setting_spinbox_sec_main_main_default.set_pad_right(0)
style_date_setting_spinbox_sec_main_main_default.set_pad_top(6)
style_date_setting_spinbox_sec_main_main_default.set_pad_bottom(0)

# add style for date_setting_spinbox_sec
date_setting_spinbox_sec.add_style(style_date_setting_spinbox_sec_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_spinbox_sec_main_cursor_default
style_date_setting_spinbox_sec_main_cursor_default = lv.style_t()
style_date_setting_spinbox_sec_main_cursor_default.init()
style_date_setting_spinbox_sec_main_cursor_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_main_cursor_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_spinbox_sec_main_cursor_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_spinbox_sec_main_cursor_default.set_bg_opa(255)
style_date_setting_spinbox_sec_main_cursor_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_date_setting_spinbox_sec_main_cursor_default.set_text_font(lv.font_SourceHanSansCN_Regular_20)
except AttributeError:
    try:
        style_date_setting_spinbox_sec_main_cursor_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_date_setting_spinbox_sec_main_cursor_default.set_text_font(lv.font_montserrat_16)

# add style for date_setting_spinbox_sec
date_setting_spinbox_sec.add_style(style_date_setting_spinbox_sec_main_cursor_default, lv.PART.CURSOR|lv.STATE.DEFAULT)

date_setting_sw_am = lv.switch(date_setting)
date_setting_sw_am.set_pos(int(610),int(328))
date_setting_sw_am.set_size(65,35)
date_setting_sw_am.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_date_setting_sw_am_main_main_default
style_date_setting_sw_am_main_main_default = lv.style_t()
style_date_setting_sw_am_main_main_default.init()
style_date_setting_sw_am_main_main_default.set_radius(100)
style_date_setting_sw_am_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_date_setting_sw_am_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_date_setting_sw_am_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_sw_am_main_main_default.set_bg_opa(255)
style_date_setting_sw_am_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_sw_am_main_main_default.set_border_width(0)
style_date_setting_sw_am_main_main_default.set_border_opa(255)

# add style for date_setting_sw_am
date_setting_sw_am.add_style(style_date_setting_sw_am_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_date_setting_sw_am_main_indicator_checked
style_date_setting_sw_am_main_indicator_checked = lv.style_t()
style_date_setting_sw_am_main_indicator_checked.init()
style_date_setting_sw_am_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_sw_am_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_sw_am_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_sw_am_main_indicator_checked.set_bg_opa(255)
style_date_setting_sw_am_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_sw_am_main_indicator_checked.set_border_width(0)
style_date_setting_sw_am_main_indicator_checked.set_border_opa(255)

# add style for date_setting_sw_am
date_setting_sw_am.add_style(style_date_setting_sw_am_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_date_setting_sw_am_main_knob_default
style_date_setting_sw_am_main_knob_default = lv.style_t()
style_date_setting_sw_am_main_knob_default.init()
style_date_setting_sw_am_main_knob_default.set_radius(100)
style_date_setting_sw_am_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_sw_am_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_date_setting_sw_am_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_sw_am_main_knob_default.set_bg_opa(255)
style_date_setting_sw_am_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_sw_am_main_knob_default.set_border_width(0)
style_date_setting_sw_am_main_knob_default.set_border_opa(255)

# add style for date_setting_sw_am
date_setting_sw_am.add_style(style_date_setting_sw_am_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

date_setting_label_4 = lv.label(date_setting)
date_setting_label_4.set_pos(int(480),int(336))
date_setting_label_4.set_size(81,20)
date_setting_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_label_4.set_text("AM/PM")
date_setting_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_date_setting_label_4_main_main_default
style_date_setting_label_4_main_main_default = lv.style_t()
style_date_setting_label_4_main_main_default.init()
style_date_setting_label_4_main_main_default.set_radius(0)
style_date_setting_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_label_4_main_main_default.set_bg_opa(0)
style_date_setting_label_4_main_main_default.set_text_color(lv.color_make(0x0d,0x0e,0x12))
try:
    style_date_setting_label_4_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_date_setting_label_4_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_date_setting_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_label_4_main_main_default.set_text_letter_space(2)
style_date_setting_label_4_main_main_default.set_text_line_space(0)
style_date_setting_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_date_setting_label_4_main_main_default.set_pad_left(0)
style_date_setting_label_4_main_main_default.set_pad_right(0)
style_date_setting_label_4_main_main_default.set_pad_top(0)
style_date_setting_label_4_main_main_default.set_pad_bottom(0)

# add style for date_setting_label_4
date_setting_label_4.add_style(style_date_setting_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

date_setting_label_charge = lv.label(date_setting)
date_setting_label_charge.set_pos(int(710),int(2))
date_setting_label_charge.set_size(30,30)
date_setting_label_charge.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
date_setting_label_charge.set_text("\xEF\x83\xA7")
date_setting_label_charge.set_long_mode(lv.label.LONG.WRAP)
# create style style_date_setting_label_charge_main_main_default
style_date_setting_label_charge_main_main_default = lv.style_t()
style_date_setting_label_charge_main_main_default.init()
style_date_setting_label_charge_main_main_default.set_radius(0)
style_date_setting_label_charge_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_charge_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_date_setting_label_charge_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_date_setting_label_charge_main_main_default.set_bg_opa(0)
style_date_setting_label_charge_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_date_setting_label_charge_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_date_setting_label_charge_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_date_setting_label_charge_main_main_default.set_text_font(lv.font_montserrat_16)
style_date_setting_label_charge_main_main_default.set_text_letter_space(2)
style_date_setting_label_charge_main_main_default.set_text_line_space(0)
style_date_setting_label_charge_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_date_setting_label_charge_main_main_default.set_pad_left(0)
style_date_setting_label_charge_main_main_default.set_pad_right(0)
style_date_setting_label_charge_main_main_default.set_pad_top(8)
style_date_setting_label_charge_main_main_default.set_pad_bottom(0)

# add style for date_setting_label_charge
date_setting_label_charge.add_style(style_date_setting_label_charge_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

zigbee_setting = lv.obj()
zigbee_setting.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_zigbee_setting_main_main_default
style_zigbee_setting_main_main_default = lv.style_t()
style_zigbee_setting_main_main_default.init()
style_zigbee_setting_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_zigbee_setting_main_main_default.set_bg_opa(255)

# add style for zigbee_setting
zigbee_setting.add_style(style_zigbee_setting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

zigbee_setting_label_1 = lv.label(zigbee_setting)
zigbee_setting_label_1.set_pos(int(710),int(2))
zigbee_setting_label_1.set_size(30,30)
zigbee_setting_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
zigbee_setting_label_1.set_text("\xEF\x83\xA7")
zigbee_setting_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_zigbee_setting_label_1_main_main_default
style_zigbee_setting_label_1_main_main_default = lv.style_t()
style_zigbee_setting_label_1_main_main_default.init()
style_zigbee_setting_label_1_main_main_default.set_radius(0)
style_zigbee_setting_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_zigbee_setting_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_zigbee_setting_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_zigbee_setting_label_1_main_main_default.set_bg_opa(0)
style_zigbee_setting_label_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_zigbee_setting_label_1_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_16)
except AttributeError:
    try:
        style_zigbee_setting_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_zigbee_setting_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_zigbee_setting_label_1_main_main_default.set_text_letter_space(2)
style_zigbee_setting_label_1_main_main_default.set_text_line_space(0)
style_zigbee_setting_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_zigbee_setting_label_1_main_main_default.set_pad_left(0)
style_zigbee_setting_label_1_main_main_default.set_pad_right(0)
style_zigbee_setting_label_1_main_main_default.set_pad_top(8)
style_zigbee_setting_label_1_main_main_default.set_pad_bottom(0)

# add style for zigbee_setting_label_1
zigbee_setting_label_1.add_style(style_zigbee_setting_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

zigbee_setting_label_2 = lv.label(zigbee_setting)
zigbee_setting_label_2.set_pos(int(68),int(53))
zigbee_setting_label_2.set_size(186,33)
zigbee_setting_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
zigbee_setting_label_2.set_text("Zigbee设置")
zigbee_setting_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_zigbee_setting_label_2_main_main_default
style_zigbee_setting_label_2_main_main_default = lv.style_t()
style_zigbee_setting_label_2_main_main_default.init()
style_zigbee_setting_label_2_main_main_default.set_radius(0)
style_zigbee_setting_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_zigbee_setting_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_zigbee_setting_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_zigbee_setting_label_2_main_main_default.set_bg_opa(255)
style_zigbee_setting_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_zigbee_setting_label_2_main_main_default.set_text_font(lv.font_SourceHanSansCN_Regular_18)
except AttributeError:
    try:
        style_zigbee_setting_label_2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_zigbee_setting_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_zigbee_setting_label_2_main_main_default.set_text_letter_space(2)
style_zigbee_setting_label_2_main_main_default.set_text_line_space(0)
style_zigbee_setting_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_zigbee_setting_label_2_main_main_default.set_pad_left(0)
style_zigbee_setting_label_2_main_main_default.set_pad_right(0)
style_zigbee_setting_label_2_main_main_default.set_pad_top(8)
style_zigbee_setting_label_2_main_main_default.set_pad_bottom(0)

# add style for zigbee_setting_label_2
zigbee_setting_label_2.add_style(style_zigbee_setting_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)




# content from custom.py

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)
