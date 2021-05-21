/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
void SystemClock_Config(void);
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
#define PER_EN_Pin GPIO_PIN_13
#define PER_EN_GPIO_Port GPIOC
#define PWR_BTN_Pin GPIO_PIN_0
#define PWR_BTN_GPIO_Port GPIOA
#define BL_TX_LP_Pin GPIO_PIN_2
#define BL_TX_LP_GPIO_Port GPIOA
#define BL_RX_LP_Pin GPIO_PIN_3
#define BL_RX_LP_GPIO_Port GPIOA
#define BAT_V_MON_Pin GPIO_PIN_4
#define BAT_V_MON_GPIO_Port GPIOA
#define CS_MON_Pin GPIO_PIN_5
#define CS_MON_GPIO_Port GPIOA
#define BAT_M_EN_Pin GPIO_PIN_6
#define BAT_M_EN_GPIO_Port GPIOA
#define PWR_MCU_Pin GPIO_PIN_7
#define PWR_MCU_GPIO_Port GPIOA
#define CS_FLASH_Pin GPIO_PIN_0
#define CS_FLASH_GPIO_Port GPIOB
#define IMU_INT2_Pin GPIO_PIN_1
#define IMU_INT2_GPIO_Port GPIOB
#define USB_INT_Pin GPIO_PIN_2
#define USB_INT_GPIO_Port GPIOB
#define DBG_TX_Pin GPIO_PIN_10
#define DBG_TX_GPIO_Port GPIOB
#define DBG_RX_Pin GPIO_PIN_11
#define DBG_RX_GPIO_Port GPIOB
#define IMU_INT1_Pin GPIO_PIN_12
#define IMU_INT1_GPIO_Port GPIOB
#define CS_IMU_Pin GPIO_PIN_8
#define CS_IMU_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define PWR_OR_Pin GPIO_PIN_15
#define PWR_OR_GPIO_Port GPIOA
#define USB_VALID_Pin GPIO_PIN_3
#define USB_VALID_GPIO_Port GPIOB
#define USB_ATTACH_Pin GPIO_PIN_4
#define USB_ATTACH_GPIO_Port GPIOB
#define USB_DEBUG_Pin GPIO_PIN_6
#define USB_DEBUG_GPIO_Port GPIOB
#define CHARG_STAT_Pin GPIO_PIN_8
#define CHARG_STAT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
