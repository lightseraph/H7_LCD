/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "dma2d.h"
#include "fatfs.h"
#include "ltdc.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sdram.h"
#include "norflash.h"
#include "lvgl/lvgl.h"
#include "lvgl_port/lv_port_disp.h"
#include "lvgl_port/lv_port_indev.h"
//#include "lvgl_port/lv_port_fs.h"
#include "demos/lv_demos.h"
#include "touch.h"
#include "nand.h"
#include "malloc.h"
#include "ftl.h"
#include "mpu.h"
#include "ap3216c.h"
//#include "sdmmc_sdcard.h"
#include "gui_dev.h"
#include "gui_battery.h"
#include "generated/gui_guider.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
lv_ui guider_ui;
/*
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
} */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */
  SCB->VTOR = QSPI_BASE + 0x3C000; //设置中断向量表

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */
  // NAND_IDTypeDef id;
  // NAND_AddressTypeDef temp;

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_RTC_Init();
  MX_SPI2_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_FATFS_Init();
  MX_TIM3_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  __enable_irq();
  my_mem_init(SRAMIN);
  my_mem_init(SRAMEX);
  printf("Jump in ex_flash!\n");
  // MPU_Memory_Protection();
  AP3216C_Init();
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // PWM 频率 2KHz
  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 500);
  lv_init();
  lv_port_disp_init();
  lv_port_indev_init();

  // lv_port_fs_init();

  /* FRESULT res;
  FIL fp;
  char write_buf[] = "this is a write into nand data";
  UINT bw;
  char read_buff[sizeof(write_buf)] = ""; */

  // res = f_mount(&USERFatFS, "0:", 1);
  // printf("mount res = %d \n", res);
  /* res = f_open(&fp, "0:test22.txt", FA_READ | FA_OPEN_ALWAYS | FA_WRITE);
  printf("\r\n f_open     res = %d\r\n", res);
  res = f_write(&fp, write_buf, sizeof(write_buf), &bw);
  printf("\r\n f_write    res = %d\r\n", res);
  res = f_close(&fp);
  printf("\r\n f_close    res = %d\r\n", res); */
  /* res = f_open(&fp, "0:test.txt", FA_READ);
  printf("\r\n f_open     res = %d\r\n", res);
  res = f_read(&fp, read_buff, sizeof(write_buf), &bw);
  printf("\r\n read_data: %s, res = %d\r\n", read_buff, res);
  res = f_close(&fp);
  f_mount(NULL, "0:", 1); */

  // lv_disp_set_rotation(NULL, LV_DISP_ROT_90);
  // lvgl_clock_start();
  setup_ui(&guider_ui);
  lvgl_first_demo_start();
  draw_battery();

  // lv_demo_widgets();
  // lv_demo_benchmark();
  //   lv_demo_stress();
  // lv_demo_music();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int ap_count = 0;
  u8 pwm_factor = 0;
  u16 als, ir, ps;
  int bl_lumi = 500;
  int bl_lumi_count = 500;
  u8 adc_factor = 0;
  u8 adc_out = 0;
  float adc_sample = 0.0;
  while (1)
  {
    tp_dev.scan(0);
    lv_task_handler();
    delay_ms(4); //给4ms延时，是考虑循环里的其他任务，给lv_task差不多5ms间隔

    if (ap_count == 500) //每2秒读一次环境光数值   500 × 4ms
    {
      AP3216C_ReadData(&ir, &ps, &als); // als读取值范围 0～65536
      if (als >= 100 || als <= 4100)    // PWM最低占空比20%（100/500）
        bl_lumi = als / 10 + 90;
      if (als < 100)
        bl_lumi = 100;
      if (als > 4100)
        bl_lumi = 500;
      ap_count = 0;
    }
    else
      ap_count++;

    if (pwm_factor == 2) //每8ms PWM占空比调整1/500
    {
      if (bl_lumi_count > bl_lumi)
      {
        bl_lumi_count--;
        __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, bl_lumi_count);
      }
      else if (bl_lumi_count < bl_lumi)
      {
        bl_lumi_count++;
        __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, bl_lumi_count);
      }
      else
      {
      }
      pwm_factor = 0;
    }
    else
      pwm_factor++;

    if (adc_factor == 240) //约1s一次电压采样
    {
      adc_sample += Get_Adc();
      adc_factor = 0;
      adc_out++;
    }
    else
    {
      adc_factor++;
    }
    if (adc_out == 15) //采样15次输出一次电压平均值，约15秒输出一次电压平均值
    {
      printf("volt : %.3f v\n", adc_sample / adc_out);
      adc_out = 0;
      adc_sample = 0;
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
   */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
   */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
  {
  }

  /** Configure LSE Drive Capability
   */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Macro to configure the PLL clock source
   */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 2;
  RCC_OscInitStruct.PLL.PLLN = 48;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief Peripherals Common Clock Configuration
 * @retval None
 */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
   */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_SPI2 | RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLL3.PLL3M = 2;
  PeriphClkInitStruct.PLL3.PLL3N = 24;
  PeriphClkInitStruct.PLL3.PLL3P = 3;
  PeriphClkInitStruct.PLL3.PLL3Q = 10;
  PeriphClkInitStruct.PLL3.PLL3R = 9;
  PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_3;
  PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
  PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
  PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL3;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_PLL3;
  PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_PLL3;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL3;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  printf("an error occured!\n");
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
