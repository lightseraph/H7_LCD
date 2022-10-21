/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    ltdc.h
 * @brief   This file contains all the function prototypes for
 *          the ltdc.c file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LTDC_H__
#define __LTDC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "sys.h"
/* USER CODE END Includes */

extern LTDC_HandleTypeDef hltdc;

/* USER CODE BEGIN Private defines */
#define LCD_PIXEL_FORMAT_ARGB8888 0X00
#define LCD_PIXEL_FORMAT_RGB888 0X01
#define LCD_PIXEL_FORMAT_RGB565 0X02
#define LCD_PIXEL_FORMAT_ARGB1555 0X03
#define LCD_PIXEL_FORMAT_ARGB4444 0X04
#define LCD_PIXEL_FORMAT_L8 0X05
#define LCD_PIXEL_FORMAT_AL44 0X06
#define LCD_PIXEL_FORMAT_AL88 0X07

//定义颜色像素格式,一般用RGB565
#define LCD_PIXFORMAT LCD_PIXEL_FORMAT_ARGB8888
//定义默认背景层颜色
#define LTDC_BACKLAYERCOLOR 0X00000000
// LCD帧缓冲区首地址,这里定义在SDRAM里面.
#define LCD_FRAME_BUF_ADDR 0XC0000000
/* USER CODE END Private defines */

void MX_LTDC_Init(void);

/* USER CODE BEGIN Prototypes */
  // LCD LTDC重要参数集
  typedef struct
  {
    u32 pwidth;     // LCD面板的宽度,固定参数,不随显示方向改变,如果为0,说明没有任何RGB屏接入
    u32 pheight;    // LCD面板的高度,固定参数,不随显示方向改变
    u16 hsw;        //水平同步宽度
    u16 vsw;        //垂直同步宽度
    u16 hbp;        //水平后廊
    u16 vbp;        //垂直后廊
    u16 hfp;        //水平前廊
    u16 vfp;        //垂直前廊
    u8 activelayer; //当前层编号:0/1
    u8 dir;         // 0,竖屏;1,横屏;
    u16 width;      // LCD宽度
    u16 height;     // LCD高度
    u32 pixsize;    //每个像素所占字节数
  } _ltdc_dev;

  extern _ltdc_dev lcdltdc;
  extern u32 *ltdc_framebuf[2];

  void LTDC_Switch(u8 sw);                                          // LTDC开关
  void LTDC_Layer_Switch(u8 layerx, u8 sw);                         //层开关
  void LTDC_Select_Layer(u8 layerx);                                //层选择
  void LTDC_Display_Dir(u8 dir);                                    //显示方向控制
  void LTDC_Draw_Point(u16 x, u16 y, u32 color);                    //画点函数
  u32 LTDC_Read_Point(u16 x, u16 y);                                //读点函数
  void LTDC_Fill(u16 sx, u16 sy, u16 ex, u16 ey, u32 color);        //矩形单色填充函数
  void LTDC_Color_Fill(u16 sx, u16 sy, u16 ex, u16 ey, u32 *color); //矩形彩色填充函数
  void LTDC_Clear(u32 color);                                       //清屏函数
  void LTDC_Init(void);
  void LTDC_HALF_ClearV(u32 color1, u32 color2);
  void LTDC_HALF_ClearH(u32 color1, u32 color2);
  // u16 LTDC_PanelID_Read(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __LTDC_H__ */

