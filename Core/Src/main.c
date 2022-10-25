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
#include "dma2d.h"
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
#include "demos/lv_demos.h"
#include "touch.h"
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

static void lvgl_first_demo_start(void)
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
  lv_label_set_text(label, "button1");
  lv_obj_align_to(label, btn, LV_ALIGN_CENTER, 0, 0);
  lv_obj_t *label0 = lv_label_create(btn1);
  lv_label_set_text(label0, "button2");
  lv_obj_align_to(label0, btn1, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t *coord_x = lv_label_create(lv_scr_act());
  lv_obj_set_size(coord_x, 120, 20);

  lv_obj_t *coord_y = lv_label_create(lv_scr_act());
  lv_obj_set_size(coord_y, 120, 20);

  lv_obj_t *sw1 = lv_switch_create(lv_scr_act());
  lv_obj_add_event_cb(sw1, event_handler, LV_EVENT_ALL, "sw1");
  lv_obj_t *sw2 = lv_switch_create(lv_scr_act());
  lv_obj_add_event_cb(sw2, event_handler, LV_EVENT_ALL, "sw2");

  lv_obj_t *label1 = lv_label_create(lv_scr_act());
  lv_label_set_text(label1, "Hello,world!");
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
  lv_obj_align_to(btn, label1, LV_ALIGN_OUT_TOP_MID, 85, -20);
  lv_obj_align_to(btn1, btn, LV_ALIGN_OUT_LEFT_MID, -30, 0);
  lv_obj_align_to(coord_x, label1, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
  lv_obj_align_to(coord_y, coord_x, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
  lv_obj_align_to(sw1, coord_y, LV_ALIGN_OUT_BOTTOM_LEFT, -45, 30);
  lv_obj_align_to(sw2, sw1, LV_ALIGN_OUT_RIGHT_MID, 40, 0);

  // vUint16ConvertString(&(tp_dev.x), x, 2);
  // vUint16ConvertString(&(tp_dev.y), y, 2);

  // lv_label_set_text_fmt(coord_x, "X: %d", tp_dev.x[0]);
  // lv_label_set_text_fmt(coord_y, "Y: %d", tp_dev.y[0]);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  SCB->VTOR = QSPI_BASE; //设置中断向量表
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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_RTC_Init();
  MX_SPI2_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  __enable_irq();

  printf("Jump in ex_flash!\n");

  lv_init();
  lv_port_disp_init();
  lv_port_indev_init();
  //     printf("1: %s\r\n", temp2);

  /* __IO uint8_t *qspi_addr = (__IO uint8_t *)(0x90000000);
  for (int i = 0; i < 0x100; i++)
  {
    printf("0x%02X ", *qspi_addr);
    qspi_addr++;
  } */
  // lv_disp_set_rotation(NULL, LV_DISP_ROT_90);
  lvgl_first_demo_start();
  // lv_demo_widgets();
  // lv_demo_benchmark();
  // lv_demo_stress();
  // lv_demo_music();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // printf("Run in ex_flash_app main loop...\r\n");
    // HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
    // HAL_Delay(500);
    tp_dev.scan(0);
    lv_task_handler();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    // printf("2: %c%c%c%c%c\r\n", temp3[0], temp3[1], temp3[2], temp3[3], temp3[4]);
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

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
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
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI2|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLL3.PLL3M = 2;
  PeriphClkInitStruct.PLL3.PLL3N = 24;
  PeriphClkInitStruct.PLL3.PLL3P = 3;
  PeriphClkInitStruct.PLL3.PLL3Q = 10;
  PeriphClkInitStruct.PLL3.PLL3R = 8;
  PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_3;
  PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
  PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
  PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL3;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_PLL3;
  PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_PLL3;
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

#ifdef  USE_FULL_ASSERT
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
