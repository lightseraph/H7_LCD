/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    rtc.h
 * @brief   This file contains all the function prototypes for
 *          the rtc.c file
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
#ifndef __RTC_H__
#define __RTC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "sys.h"
/* USER CODE END Includes */

extern RTC_HandleTypeDef hrtc;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_RTC_Init(void);

/* USER CODE BEGIN Prototypes */
  u8 RTC_Wait_Synchro(void);
  HAL_StatusTypeDef RTC_Set_Time(u8 hour, u8 min, u8 sec, u8 ampm);    // RTC时间设置
  HAL_StatusTypeDef RTC_Set_Date(u8 year, u8 month, u8 date, u8 week); // RTC日期设置
  void RTC_Set_WakeUp(u32 wksel, u16 cnt);                             //周期性唤醒定时器设置
  u8 RTC_DEC2BCD(u8 val);                                              //十进制转换为BCD码
  u8 RTC_BCD2DEC(u8 val);                                              // BCD码转换为十进制数据
  void RTC_Get_Time(u8 *hour, u8 *min, u8 *sec, u8 *ampm);
  void RTC_Get_Date(u8 *year, u8 *month, u8 *date, u8 *week);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __RTC_H__ */

