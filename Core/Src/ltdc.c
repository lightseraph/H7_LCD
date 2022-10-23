/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    ltdc.c
 * @brief   This file provides code for the configuration
 *          of the LTDC instances.
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
/* Includes ------------------------------------------------------------------*/
#include "ltdc.h"

/* USER CODE BEGIN 0 */
//#include "dma2d.h"
// DMA2D_HandleTypeDef hdma2d;
_ltdc_dev lcdltdc;
u32 *ltdc_framebuf[2];

u32 ltdc_lcd_framebuf[800][480] __attribute__((section(".sdram")));
/* USER CODE END 0 */

LTDC_HandleTypeDef hltdc;

/* LTDC init function */
void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 47;
  hltdc.Init.VerticalSync = 2;
  hltdc.Init.AccumulatedHBP = 135;
  hltdc.Init.AccumulatedVBP = 34;
  hltdc.Init.AccumulatedActiveW = 935;
  hltdc.Init.AccumulatedActiveH = 514;
  hltdc.Init.TotalWidth = 975;
  hltdc.Init.TotalHeigh = 527;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 800;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 480;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
  pLayerCfg.FBStartAdress = 0xc0000000;
  pLayerCfg.ImageWidth = 800;
  pLayerCfg.ImageHeight = 480;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */
  HAL_LTDC_SetWindowPosition(&hltdc, 0, 0, 0); //设置窗口的位置
  HAL_LTDC_SetWindowSize(&hltdc, 800, 480, 0); //设置窗口大小
  /* USER CODE END LTDC_Init 2 */

}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef* ltdcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
    PeriphClkInitStruct.PLL3.PLL3M = 1;
    PeriphClkInitStruct.PLL3.PLL3N = 6;
    PeriphClkInitStruct.PLL3.PLL3P = 2;
    PeriphClkInitStruct.PLL3.PLL3Q = 2;
    PeriphClkInitStruct.PLL3.PLL3R = 10;
    PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_3;
    PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOMEDIUM;
    PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* LTDC clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();

    __HAL_RCC_GPIOK_CLK_ENABLE();
    __HAL_RCC_GPIOJ_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();
    /**LTDC GPIO Configuration
    PK5     ------> LTDC_B6
    PK4     ------> LTDC_B5
    PJ15     ------> LTDC_B3
    PK6     ------> LTDC_B7
    PK3     ------> LTDC_B4
    PK7     ------> LTDC_DE
    PJ14     ------> LTDC_B2
    PJ12     ------> LTDC_B0
    PJ13     ------> LTDC_B1
    PI12     ------> LTDC_HSYNC
    PI13     ------> LTDC_VSYNC
    PI14     ------> LTDC_CLK
    PK2     ------> LTDC_G7
    PK0     ------> LTDC_G5
    PK1     ------> LTDC_G6
    PJ11     ------> LTDC_G4
    PJ10     ------> LTDC_G3
    PJ9     ------> LTDC_G2
    PJ0     ------> LTDC_R1
    PJ8     ------> LTDC_G1
    PJ7     ------> LTDC_G0
    PJ6     ------> LTDC_R7
    PI15     ------> LTDC_R0
    PJ1     ------> LTDC_R2
    PJ5     ------> LTDC_R6
    PJ2     ------> LTDC_R3
    PJ3     ------> LTDC_R4
    PJ4     ------> LTDC_R5
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_3
                          |GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_15|GPIO_PIN_14|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_11|GPIO_PIN_10|GPIO_PIN_9|GPIO_PIN_0
                          |GPIO_PIN_8|GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_1
                          |GPIO_PIN_5|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    /* LTDC interrupt Init */
    HAL_NVIC_SetPriority(LTDC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspInit 1 */

  /* USER CODE END LTDC_MspInit 1 */
  }
}

void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* ltdcHandle)
{

  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();

    /**LTDC GPIO Configuration
    PK5     ------> LTDC_B6
    PK4     ------> LTDC_B5
    PJ15     ------> LTDC_B3
    PK6     ------> LTDC_B7
    PK3     ------> LTDC_B4
    PK7     ------> LTDC_DE
    PJ14     ------> LTDC_B2
    PJ12     ------> LTDC_B0
    PJ13     ------> LTDC_B1
    PI12     ------> LTDC_HSYNC
    PI13     ------> LTDC_VSYNC
    PI14     ------> LTDC_CLK
    PK2     ------> LTDC_G7
    PK0     ------> LTDC_G5
    PK1     ------> LTDC_G6
    PJ11     ------> LTDC_G4
    PJ10     ------> LTDC_G3
    PJ9     ------> LTDC_G2
    PJ0     ------> LTDC_R1
    PJ8     ------> LTDC_G1
    PJ7     ------> LTDC_G0
    PJ6     ------> LTDC_R7
    PI15     ------> LTDC_R0
    PJ1     ------> LTDC_R2
    PJ5     ------> LTDC_R6
    PJ2     ------> LTDC_R3
    PJ3     ------> LTDC_R4
    PJ4     ------> LTDC_R5
    */
    HAL_GPIO_DeInit(GPIOK, GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_3
                          |GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1);

    HAL_GPIO_DeInit(GPIOJ, GPIO_PIN_15|GPIO_PIN_14|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_11|GPIO_PIN_10|GPIO_PIN_9|GPIO_PIN_0
                          |GPIO_PIN_8|GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_1
                          |GPIO_PIN_5|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);

    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);

    /* LTDC interrupt Deinit */
    HAL_NVIC_DisableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void LTDC_Switch(u8 sw)
{
  if (sw == 1)
    __HAL_LTDC_ENABLE(&hltdc);
  else if (sw == 0)
    __HAL_LTDC_DISABLE(&hltdc);
}

void LTDC_Layer_Switch(u8 layerx, u8 sw)
{
  if (sw == 1)
    __HAL_LTDC_LAYER_ENABLE(&hltdc, layerx);
  else if (sw == 0)
    __HAL_LTDC_LAYER_DISABLE(&hltdc, layerx);
  __HAL_LTDC_RELOAD_CONFIG(&hltdc);
}

void LTDC_Select_Layer(u8 layerx)
{
  lcdltdc.activelayer = layerx;
}

void LTDC_Display_Dir(u8 dir)
{
  lcdltdc.dir = dir; //显示方向
  if (dir == 0)      //竖屏
  {
    lcdltdc.width = lcdltdc.pheight;
    lcdltdc.height = lcdltdc.pwidth;
  }
  else if (dir == 1) //横屏
  {
    lcdltdc.width = lcdltdc.pwidth;
    lcdltdc.height = lcdltdc.pheight;
  }
}

void LTDC_Draw_Point(u16 x, u16 y, u32 color)
{
#if LCD_PIXFORMAT == LCD_PIXFORMAT_ARGB8888 || LCD_PIXFORMAT == LCD_PIXFORMAT_RGB888
  if (lcdltdc.dir) //横屏
  {
    *(u32 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * y + x)) = color;
  }
  else //竖屏
  {
    *(u32 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * (lcdltdc.pheight - x - 1) + y)) = color;
  }
#else
  if (lcdltdc.dir) //横屏
  {
    *(u16 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * y + x)) = color;
  }
  else //竖屏
  {
    *(u16 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * (lcdltdc.pheight - x - 1) + y)) = color;
  }
#endif
}

u32 LTDC_Read_Point(u16 x, u16 y)
{
#if LCD_PIXFORMAT == LCD_PIXFORMAT_ARGB8888 || LCD_PIXFORMAT == LCD_PIXFORMAT_RGB888
  if (lcdltdc.dir) //横屏
  {
    return *(u32 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * y + x));
  }
  else //竖屏
  {
    return *(u32 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * (lcdltdc.pheight - x - 1) + y));
  }
#else
  if (lcdltdc.dir) //横屏
  {
    return *(u16 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * y + x));
  }
  else //竖屏
  {
    return *(u16 *)((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * (lcdltdc.pheight - x - 1) + y));
  }
#endif
}

void LTDC_Fill(u16 sx, u16 sy, u16 ex, u16 ey, u32 color)
{
  u32 psx, psy, pex, pey; //以LCD面板为基准的坐标系,不随横竖屏变化而变化
  u32 timeout = 0;
  u16 offline;
  u32 addr;
  //坐标系转换
  if (lcdltdc.dir) //横屏
  {
    psx = sx;
    psy = sy;
    pex = ex;
    pey = ey;
  }
  else //竖屏
  {
    psx = sy;
    psy = lcdltdc.pheight - ex - 1;
    pex = ey;
    pey = lcdltdc.pheight - sx - 1;
  }
  offline = lcdltdc.pwidth - (pex - psx + 1);
  addr = ((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * psy + psx));
  RCC->AHB1ENR |= 1 << 23;                                //使能DM2D时钟
  DMA2D->CR = 3 << 16;                                    //寄存器到存储器模式
  DMA2D->OPFCCR = LCD_PIXFORMAT;                          //设置颜色格式
  DMA2D->OOR = offline;                                   //设置行偏移
  DMA2D->CR &= ~(1 << 0);                                 //先停止DMA2D
  DMA2D->OMAR = addr;                                     //输出存储器地址
  DMA2D->NLR = (pey - psy + 1) | ((pex - psx + 1) << 16); //设定行数寄存器
  DMA2D->OCOLR = color;                                   //设定输出颜色寄存器
  DMA2D->CR |= 1 << 0;                                    //启动DMA2D
  while ((DMA2D->ISR & (1 << 1)) == 0)                    //等待传输完成
  {
    timeout++;
    if (timeout > 0X1FFFFF)
      break; //超时退出
  }
  DMA2D->IFCR |= 1 << 1; //清除传输完成标志
}

void LTDC_Color_Fill(u16 sx, u16 sy, u16 ex, u16 ey, u32 *color)
{
  u32 psx, psy, pex, pey; //以LCD面板为基准的坐标系,不随横竖屏变化而变化
  u32 timeout = 0;
  u16 offline;
  u32 addr;
  //坐标系转换
  if (lcdltdc.dir) //横屏
  {
    psx = sx;
    psy = sy;
    pex = ex;
    pey = ey;
  }
  else //竖屏
  {
    psx = sy;
    psy = lcdltdc.pheight - ex - 1;
    pex = ey;
    pey = lcdltdc.pheight - sx - 1;
  }
  offline = lcdltdc.pwidth - (pex - psx + 1);
  addr = ((u32)ltdc_framebuf[lcdltdc.activelayer] + lcdltdc.pixsize * (lcdltdc.pwidth * psy + psx));
  RCC->AHB1ENR |= 1 << 23;                                //使能DM2D时钟
  DMA2D->CR = 0 << 16;                                    //存储器到存储器模式
  DMA2D->FGPFCCR = LCD_PIXFORMAT;                         //设置颜色格式
  DMA2D->FGOR = 0;                                        //前景层行偏移为0
  DMA2D->OOR = offline;                                   //设置行偏移
  DMA2D->CR &= ~(1 << 0);                                 //先停止DMA2D
  DMA2D->FGMAR = (u32)color;                              //源地址
  DMA2D->OMAR = addr;                                     //输出存储器地址
  DMA2D->NLR = (pey - psy + 1) | ((pex - psx + 1) << 16); //设定行数寄存器
  DMA2D->CR |= 1 << 0;                                    //启动DMA2D
  while ((DMA2D->ISR & (1 << 1)) == 0)                    //等待传输完成
  {
    timeout++;
    if (timeout > 0X1FFFFF)
      break; //超时退出
  }
  DMA2D->IFCR |= 1 << 1; //清除传输完成标志
}

void LTDC_Clear(u32 color)
{
  LTDC_Fill(0, 0, lcdltdc.width - 1, lcdltdc.height - 1, color);
}

void LTDC_HALF_ClearV(u32 color1, u32 color2)
{
  LTDC_Fill(0, 0, lcdltdc.height - 1, lcdltdc.width / 2, color1);
  LTDC_Fill(0, lcdltdc.width / 2, lcdltdc.height - 1, lcdltdc.width - 1, color2);
}

void LTDC_HALF_ClearH(u32 color1, u32 color2)
{
  LTDC_Fill(0, 0, lcdltdc.width - 1, lcdltdc.height / 2, color1);
  LTDC_Fill(0, lcdltdc.height / 2, lcdltdc.width - 1, lcdltdc.height - 1, color2);
}

void LTDC_Init(void)
{
  lcdltdc.pwidth = 800;  //面板宽度,单位:像素
  lcdltdc.pheight = 480; //面板高度,单位:像素
  lcdltdc.hbp = 88;      //水平后廊
  lcdltdc.hfp = 40;      //水平前廊
  lcdltdc.hsw = 48;      //水平同步宽度
  lcdltdc.vbp = 32;      //垂直后廊
  lcdltdc.vfp = 13;      //垂直前廊
  lcdltdc.vsw = 3;       //垂直同步宽度

  // lcddev.width=lcdltdc.pwidth;
  // lcddev.height=lcdltdc.pheight;
  ltdc_framebuf[0] = (u32 *)&ltdc_lcd_framebuf;
  lcdltdc.pixsize = 4;    //每个像素占4个字节
  LTDC_Display_Dir(1);    //默认竖屏，在LCD_Init函数里面设置
  LTDC_Select_Layer(0);   //选择第1层
  LTDC_Clear(0XFF0FF0F0); //清屏
  // LTDC_HALF_ClearH(0xFFF00000, 0xFF0F0FF0);
  //  LTDC_HALF_ClearV(0xFFF00000, 0xFF0F0FF0);
}

/* USER CODE END 1 */
