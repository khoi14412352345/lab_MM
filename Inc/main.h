/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define LED_RED_Pin GPIO_PIN_2
#define LED_RED_GPIO_Port GPIOA
#define MODE_Pin GPIO_PIN_3
#define MODE_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_4
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_5
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_6
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_7
#define EN3_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_0
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_1
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_2
#define BUTTON_3_GPIO_Port GPIOB
#define Way1_RED_Pin GPIO_PIN_10
#define Way1_RED_GPIO_Port GPIOB
#define Way1_YELLOW_Pin GPIO_PIN_11
#define Way1_YELLOW_GPIO_Port GPIOB
#define Way1_GREEN_Pin GPIO_PIN_12
#define Way1_GREEN_GPIO_Port GPIOB
#define Way2_RED_Pin GPIO_PIN_13
#define Way2_RED_GPIO_Port GPIOB
#define Way2_YELLOW_Pin GPIO_PIN_14
#define Way2_YELLOW_GPIO_Port GPIOB
#define Way2_GREEN_Pin GPIO_PIN_15
#define Way2_GREEN_GPIO_Port GPIOB
#define Led7_a_Pin GPIO_PIN_9
#define Led7_a_GPIO_Port GPIOA
#define Led7_b_Pin GPIO_PIN_10
#define Led7_b_GPIO_Port GPIOA
#define Led7_c_Pin GPIO_PIN_11
#define Led7_c_GPIO_Port GPIOA
#define Led7_d_Pin GPIO_PIN_12
#define Led7_d_GPIO_Port GPIOA
#define Led7_e_Pin GPIO_PIN_13
#define Led7_e_GPIO_Port GPIOA
#define Led7_f_Pin GPIO_PIN_14
#define Led7_f_GPIO_Port GPIOA
#define Led7_g_Pin GPIO_PIN_15
#define Led7_g_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
