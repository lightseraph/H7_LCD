/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stdio.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_BL_Pin GPIO_PIN_5
#define LCD_BL_GPIO_Port GPIOB
#define NAND_NWAIT_Pin GPIO_PIN_6
#define NAND_NWAIT_GPIO_Port GPIOD
#define CT_RST_Pin GPIO_PIN_8
#define CT_RST_GPIO_Port GPIOI
#define CT_SDA_Pin GPIO_PIN_7
#define CT_SDA_GPIO_Port GPIOG
#define SPI_NSS_Pin GPIO_PIN_10
#define SPI_NSS_GPIO_Port GPIOF
#define LED_0_Pin GPIO_PIN_1
#define LED_0_GPIO_Port GPIOB
#define CT_SCL_Pin GPIO_PIN_6
#define CT_SCL_GPIO_Port GPIOH
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOB
#define CT_INT_Pin GPIO_PIN_7
#define CT_INT_GPIO_Port GPIOH
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
