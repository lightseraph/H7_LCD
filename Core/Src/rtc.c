/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    rtc.c
 * @brief   This file provides code for the configuration
 *          of the RTC instances.
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
#include "rtc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

RTC_HandleTypeDef hrtc;

/* RTC init function */
void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */
  if (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) != 0X5050)
  {
  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 19;
  sTime.Minutes = 28;
  sTime.Seconds = 0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_WEDNESDAY;
  sDate.Month = RTC_MONTH_NOVEMBER;
  sDate.Date = 2;
  sDate.Year = 22;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */
    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 0X5050);
  }
  /* USER CODE END RTC_Init 2 */

}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* RTC clock enable */
    __HAL_RCC_RTC_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void RTC_Get_Time(u8 *hour, u8 *min, u8 *sec, u8 *ampm)
{
  u32 temp = 0;
  while (RTC_Wait_Synchro())
    ; //等待同步
  temp = RTC->TR;
  *hour = RTC_BCD2DEC((temp >> 16) & 0X3F);
  *min = RTC_BCD2DEC((temp >> 8) & 0X7F);
  *sec = RTC_BCD2DEC(temp & 0X7F);
  *ampm = temp >> 22;
}

void RTC_Get_Date(u8 *year, u8 *month, u8 *date, u8 *week)
{
  u32 temp = 0;
  while (RTC_Wait_Synchro())
    ; //等待同步
  temp = RTC->DR;
  *year = RTC_BCD2DEC((temp >> 16) & 0XFF);
  *month = RTC_BCD2DEC((temp >> 8) & 0X1F);
  *date = RTC_BCD2DEC(temp & 0X3F);
  *week = (temp >> 13) & 0X07; // RTC星期寄存器获取的值是1～7
}

u8 RTC_Wait_Synchro(void)
{
  u32 retry = 0XFFFFF;
  //关闭RTC寄存器写保护
  RTC->WPR = 0xCA;
  RTC->WPR = 0x53;
  RTC->ISR &= ~(1 << 5); //清除RSF位
  while (retry && ((RTC->ISR & (1 << 5)) == 0x00))
    retry--; //等待影子寄存器同步
  if (retry == 0)
    return 1;      //同步失败
  RTC->WPR = 0xFF; //使能RTC寄存器写保护
  return 0;
}

HAL_StatusTypeDef RTC_Set_Time(u8 hour, u8 min, u8 sec, u8 ampm) // RTC时间设置
{
  RTC_TimeTypeDef RTC_TimeStructure;

  RTC_TimeStructure.Hours = hour;
  RTC_TimeStructure.Minutes = min;
  RTC_TimeStructure.Seconds = sec;
  RTC_TimeStructure.TimeFormat = ampm;
  RTC_TimeStructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  RTC_TimeStructure.StoreOperation = RTC_STOREOPERATION_RESET;
  return HAL_RTC_SetTime(&hrtc, &RTC_TimeStructure, RTC_FORMAT_BIN);
}

HAL_StatusTypeDef RTC_Set_Date(u8 year, u8 month, u8 date, u8 week) // RTC日期设置
{
  RTC_DateTypeDef RTC_DateStructure;

  RTC_DateStructure.Date = date;
  RTC_DateStructure.Month = month;
  RTC_DateStructure.WeekDay = week;
  RTC_DateStructure.Year = year;
  return HAL_RTC_SetDate(&hrtc, &RTC_DateStructure, RTC_FORMAT_BIN);
}

//周期性唤醒定时器设置
/*wksel:  @ref RTCEx_Wakeup_Timer_Definitions
#define RTC_WAKEUPCLOCK_RTCCLK_DIV16        ((uint32_t)0x00000000)
#define RTC_WAKEUPCLOCK_RTCCLK_DIV8         ((uint32_t)0x00000001)
#define RTC_WAKEUPCLOCK_RTCCLK_DIV4         ((uint32_t)0x00000002)
#define RTC_WAKEUPCLOCK_RTCCLK_DIV2         ((uint32_t)0x00000003)
#define RTC_WAKEUPCLOCK_CK_SPRE_16BITS      ((uint32_t)0x00000004)
#define RTC_WAKEUPCLOCK_CK_SPRE_17BITS      ((uint32_t)0x00000006)
*/
// cnt:自动重装载值.减到0,产生中断.
void RTC_Set_WakeUp(u32 wksel, u16 cnt)
{
  __HAL_RTC_WAKEUPTIMER_CLEAR_FLAG(&hrtc, RTC_FLAG_WUTF); //清除RTC WAKE UP的标志

  HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, cnt, wksel); //设置重装载值和时钟

  HAL_NVIC_SetPriority(RTC_WKUP_IRQn, 0x02, 0x02); //抢占优先级1,子优先级2
  HAL_NVIC_EnableIRQ(RTC_WKUP_IRQn);
}

//十进制转换为BCD码
// val:要转换的十进制数
//返回值:BCD码
u8 RTC_DEC2BCD(u8 val)
{
  u8 bcdhigh = 0;
  while (val >= 10)
  {
    bcdhigh++;
    val -= 10;
  }
  return ((u8)(bcdhigh << 4) | val);
}
// BCD码转换为十进制数据
// val:要转换的BCD码
//返回值:十进制数据
u8 RTC_BCD2DEC(u8 val)
{
  u8 temp = 0;
  temp = (val >> 4) * 10;
  return (temp + (val & 0X0F));
}
/* USER CODE END 1 */
