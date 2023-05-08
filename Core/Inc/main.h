/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define Center(str) 8*((16-strlen(str))/2)
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ILED_Pin GPIO_PIN_13
#define ILED_GPIO_Port GPIOC
#define DC_Pin GPIO_PIN_0
#define DC_GPIO_Port GPIOB
#define RES_Pin GPIO_PIN_1
#define RES_GPIO_Port GPIOB
#define D1_Pin GPIO_PIN_10
#define D1_GPIO_Port GPIOB
#define D0_Pin GPIO_PIN_11
#define D0_GPIO_Port GPIOB
#define KPD_RST_Pin GPIO_PIN_12
#define KPD_RST_GPIO_Port GPIOB
#define KPD_RST_EXTI_IRQn EXTI15_10_IRQn
#define SET_Pin GPIO_PIN_13
#define SET_GPIO_Port GPIOB
#define SET_EXTI_IRQn EXTI15_10_IRQn
#define MID_Pin GPIO_PIN_14
#define MID_GPIO_Port GPIOB
#define MID_EXTI_IRQn EXTI15_10_IRQn
#define RHT_Pin GPIO_PIN_15
#define RHT_GPIO_Port GPIOB
#define RHT_EXTI_IRQn EXTI15_10_IRQn
#define LFT_Pin GPIO_PIN_8
#define LFT_GPIO_Port GPIOA
#define LFT_EXTI_IRQn EXTI9_5_IRQn
#define DWN_Pin GPIO_PIN_9
#define DWN_GPIO_Port GPIOA
#define DWN_EXTI_IRQn EXTI9_5_IRQn
#define UP_Pin GPIO_PIN_10
#define UP_GPIO_Port GPIOA
#define UP_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define GPIO_SetBits(PORT,PIN) HAL_GPIO_WritePin(PORT,PIN,GPIO_PIN_SET)
#define GPIO_ResetBits(PORT,PIN) HAL_GPIO_WritePin(PORT,PIN,GPIO_PIN_RESET)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
