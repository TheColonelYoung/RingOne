ARM GAS  /tmp/ccbrBnXA.s 			page 1


   1              		.cpu cortex-m4
   2              		.eabi_attribute 27, 1
   3              		.eabi_attribute 28, 1
   4              		.eabi_attribute 20, 1
   5              		.eabi_attribute 21, 1
   6              		.eabi_attribute 23, 3
   7              		.eabi_attribute 24, 1
   8              		.eabi_attribute 25, 1
   9              		.eabi_attribute 26, 1
  10              		.eabi_attribute 30, 1
  11              		.eabi_attribute 34, 1
  12              		.eabi_attribute 18, 4
  13              		.file	"main.c"
  14              		.text
  15              	.Ltext0:
  16              		.cfi_sections	.debug_frame
  17              		.section	.text._ZL12MX_GPIO_Initv,"ax",%progbits
  18              		.align	1
  19              		.arch armv7e-m
  20              		.syntax unified
  21              		.thumb
  22              		.thumb_func
  23              		.fpu fpv4-sp-d16
  25              	_ZL12MX_GPIO_Initv:
  26              	.LFB3700:
  27              		.file 1 "Src/main.c"
   1:Src/main.c    **** /* USER CODE BEGIN Header */
   2:Src/main.c    **** 
   3:Src/main.c    **** /**
   4:Src/main.c    ****   ******************************************************************************
   5:Src/main.c    ****   * @file           : main.c
   6:Src/main.c    ****   * @brief          : Main program body
   7:Src/main.c    ****   ******************************************************************************
   8:Src/main.c    ****   * @attention
   9:Src/main.c    ****   *
  10:Src/main.c    ****   * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  11:Src/main.c    ****   * All rights reserved.</center></h2>
  12:Src/main.c    ****   *
  13:Src/main.c    ****   * This software component is licensed by ST under Ultimate Liberty license
  14:Src/main.c    ****   * SLA0044, the "License"; You may not use this file except in compliance with
  15:Src/main.c    ****   * the License. You may obtain a copy of the License at:
  16:Src/main.c    ****   *                             www.st.com/SLA0044
  17:Src/main.c    ****   *
  18:Src/main.c    ****   ******************************************************************************
  19:Src/main.c    ****   */
  20:Src/main.c    **** /* USER CODE END Header */
  21:Src/main.c    **** /* Includes ------------------------------------------------------------------*/
  22:Src/main.c    **** #include "main.h"
  23:Src/main.c    **** #include "usb_device.h"
  24:Src/main.c    **** 
  25:Src/main.c    **** /* Private includes ----------------------------------------------------------*/
  26:Src/main.c    **** /* USER CODE BEGIN Includes */
  27:Src/main.c    **** #include "device/device.hpp"
  28:Src/main.c    **** /* USER CODE END Includes */
  29:Src/main.c    **** 
  30:Src/main.c    **** /* Private typedef -----------------------------------------------------------*/
  31:Src/main.c    **** /* USER CODE BEGIN PTD */
ARM GAS  /tmp/ccbrBnXA.s 			page 2


  32:Src/main.c    **** 
  33:Src/main.c    **** /* USER CODE END PTD */
  34:Src/main.c    **** 
  35:Src/main.c    **** /* Private define ------------------------------------------------------------*/
  36:Src/main.c    **** /* USER CODE BEGIN PD */
  37:Src/main.c    **** /* USER CODE END PD */
  38:Src/main.c    **** 
  39:Src/main.c    **** /* Private macro -------------------------------------------------------------*/
  40:Src/main.c    **** /* USER CODE BEGIN PM */
  41:Src/main.c    **** 
  42:Src/main.c    **** /* USER CODE END PM */
  43:Src/main.c    **** 
  44:Src/main.c    **** /* Private variables ---------------------------------------------------------*/
  45:Src/main.c    **** ADC_HandleTypeDef hadc1;
  46:Src/main.c    **** 
  47:Src/main.c    **** I2C_HandleTypeDef hi2c1;
  48:Src/main.c    **** 
  49:Src/main.c    **** UART_HandleTypeDef hlpuart1;
  50:Src/main.c    **** UART_HandleTypeDef huart3;
  51:Src/main.c    **** 
  52:Src/main.c    **** SPI_HandleTypeDef hspi2;
  53:Src/main.c    **** 
  54:Src/main.c    **** TIM_HandleTypeDef htim2;
  55:Src/main.c    **** 
  56:Src/main.c    **** /* USER CODE BEGIN PV */
  57:Src/main.c    **** 
  58:Src/main.c    **** /* USER CODE END PV */
  59:Src/main.c    **** 
  60:Src/main.c    **** /* Private function prototypes -----------------------------------------------*/
  61:Src/main.c    **** void SystemClock_Config(void);
  62:Src/main.c    **** static void MX_GPIO_Init(void);
  63:Src/main.c    **** static void MX_ADC1_Init(void);
  64:Src/main.c    **** static void MX_I2C1_Init(void);
  65:Src/main.c    **** static void MX_LPUART1_UART_Init(void);
  66:Src/main.c    **** static void MX_USART3_UART_Init(void);
  67:Src/main.c    **** static void MX_SPI2_Init(void);
  68:Src/main.c    **** static void MX_TIM2_Init(void);
  69:Src/main.c    **** /* USER CODE BEGIN PFP */
  70:Src/main.c    **** 
  71:Src/main.c    **** /* USER CODE END PFP */
  72:Src/main.c    **** 
  73:Src/main.c    **** /* Private user code ---------------------------------------------------------*/
  74:Src/main.c    **** /* USER CODE BEGIN 0 */
  75:Src/main.c    **** 
  76:Src/main.c    **** /* USER CODE END 0 */
  77:Src/main.c    **** 
  78:Src/main.c    **** /**
  79:Src/main.c    ****   * @brief  The application entry point.
  80:Src/main.c    ****   * @retval int
  81:Src/main.c    ****   */
  82:Src/main.c    **** int main(void)
  83:Src/main.c    **** {
  84:Src/main.c    ****   /* USER CODE BEGIN 1 */
  85:Src/main.c    **** 
  86:Src/main.c    ****   /* USER CODE END 1 */
  87:Src/main.c    **** 
  88:Src/main.c    ****   /* MCU Configuration--------------------------------------------------------*/
ARM GAS  /tmp/ccbrBnXA.s 			page 3


  89:Src/main.c    **** 
  90:Src/main.c    ****   /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  91:Src/main.c    ****   HAL_Init();
  92:Src/main.c    **** 
  93:Src/main.c    ****   /* USER CODE BEGIN Init */
  94:Src/main.c    **** 
  95:Src/main.c    ****   /* USER CODE END Init */
  96:Src/main.c    **** 
  97:Src/main.c    ****   /* Configure the system clock */
  98:Src/main.c    ****   SystemClock_Config();
  99:Src/main.c    **** 
 100:Src/main.c    ****   /* USER CODE BEGIN SysInit */
 101:Src/main.c    **** 
 102:Src/main.c    ****   /* USER CODE END SysInit */
 103:Src/main.c    **** 
 104:Src/main.c    ****   /* Initialize all configured peripherals */
 105:Src/main.c    ****   MX_GPIO_Init();
 106:Src/main.c    ****   MX_ADC1_Init();
 107:Src/main.c    ****   MX_I2C1_Init();
 108:Src/main.c    ****   MX_LPUART1_UART_Init();
 109:Src/main.c    ****   MX_USART3_UART_Init();
 110:Src/main.c    ****   MX_SPI2_Init();
 111:Src/main.c    ****   MX_USB_DEVICE_Init();
 112:Src/main.c    ****   MX_TIM2_Init();
 113:Src/main.c    ****   /* USER CODE BEGIN 2 */
 114:Src/main.c    **** 
 115:Src/main.c    ****     HAL_Delay(1);
 116:Src/main.c    **** 
 117:Src/main.c    ****     device()->Enable_CLI(device()->mcu->USB_port);
 118:Src/main.c    ****     device()->Enable_Filesystem();
 119:Src/main.c    ****     device()->cli->Enable_filesystem_executable(device()->fs);
 120:Src/main.c    **** 
 121:Src/main.c    ****   /* USER CODE END 2 */
 122:Src/main.c    **** 
 123:Src/main.c    ****   /* Infinite loop */
 124:Src/main.c    ****   /* USER CODE BEGIN WHILE */
 125:Src/main.c    ****     while (1) {
 126:Src/main.c    ****     /* USER CODE END WHILE */
 127:Src/main.c    **** 
 128:Src/main.c    ****     /* USER CODE BEGIN 3 */
 129:Src/main.c    ****     }
 130:Src/main.c    ****   /* USER CODE END 3 */
 131:Src/main.c    **** }
 132:Src/main.c    **** 
 133:Src/main.c    **** /**
 134:Src/main.c    ****   * @brief System Clock Configuration
 135:Src/main.c    ****   * @retval None
 136:Src/main.c    ****   */
 137:Src/main.c    **** void SystemClock_Config(void)
 138:Src/main.c    **** {
 139:Src/main.c    ****   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
 140:Src/main.c    ****   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
 141:Src/main.c    ****   RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
 142:Src/main.c    **** 
 143:Src/main.c    ****   /** Initializes the RCC Oscillators according to the specified parameters
 144:Src/main.c    ****   * in the RCC_OscInitTypeDef structure.
 145:Src/main.c    ****   */
ARM GAS  /tmp/ccbrBnXA.s 			page 4


 146:Src/main.c    ****   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
 147:Src/main.c    ****   RCC_OscInitStruct.MSIState = RCC_MSI_ON;
 148:Src/main.c    ****   RCC_OscInitStruct.MSICalibrationValue = 0;
 149:Src/main.c    ****   RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
 150:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
 151:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
 152:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLM = 1;
 153:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLN = 40;
 154:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
 155:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
 156:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
 157:Src/main.c    ****   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
 158:Src/main.c    ****   {
 159:Src/main.c    ****     Error_Handler();
 160:Src/main.c    ****   }
 161:Src/main.c    ****   /** Initializes the CPU, AHB and APB buses clocks
 162:Src/main.c    ****   */
 163:Src/main.c    ****   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
 164:Src/main.c    ****                               |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
 165:Src/main.c    ****   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
 166:Src/main.c    ****   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
 167:Src/main.c    ****   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 168:Src/main.c    ****   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
 169:Src/main.c    **** 
 170:Src/main.c    ****   if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
 171:Src/main.c    ****   {
 172:Src/main.c    ****     Error_Handler();
 173:Src/main.c    ****   }
 174:Src/main.c    ****   PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_LPUART1
 175:Src/main.c    ****                               |RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_USB
 176:Src/main.c    ****                               |RCC_PERIPHCLK_ADC;
 177:Src/main.c    ****   PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
 178:Src/main.c    ****   PeriphClkInit.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PCLK1;
 179:Src/main.c    ****   PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
 180:Src/main.c    ****   PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
 181:Src/main.c    ****   PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
 182:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;
 183:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
 184:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1N = 24;
 185:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
 186:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
 187:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
 188:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK|RCC_PLLSAI1_ADC1CLK;
 189:Src/main.c    ****   if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
 190:Src/main.c    ****   {
 191:Src/main.c    ****     Error_Handler();
 192:Src/main.c    ****   }
 193:Src/main.c    ****   /** Configure the main internal regulator output voltage
 194:Src/main.c    ****   */
 195:Src/main.c    ****   if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
 196:Src/main.c    ****   {
 197:Src/main.c    ****     Error_Handler();
 198:Src/main.c    ****   }
 199:Src/main.c    **** }
 200:Src/main.c    **** 
 201:Src/main.c    **** /**
 202:Src/main.c    ****   * @brief ADC1 Initialization Function
ARM GAS  /tmp/ccbrBnXA.s 			page 5


 203:Src/main.c    ****   * @param None
 204:Src/main.c    ****   * @retval None
 205:Src/main.c    ****   */
 206:Src/main.c    **** static void MX_ADC1_Init(void)
 207:Src/main.c    **** {
 208:Src/main.c    **** 
 209:Src/main.c    ****   /* USER CODE BEGIN ADC1_Init 0 */
 210:Src/main.c    **** 
 211:Src/main.c    ****   /* USER CODE END ADC1_Init 0 */
 212:Src/main.c    **** 
 213:Src/main.c    ****   ADC_ChannelConfTypeDef sConfig = {0};
 214:Src/main.c    **** 
 215:Src/main.c    ****   /* USER CODE BEGIN ADC1_Init 1 */
 216:Src/main.c    **** 
 217:Src/main.c    ****   /* USER CODE END ADC1_Init 1 */
 218:Src/main.c    ****   /** Common config
 219:Src/main.c    ****   */
 220:Src/main.c    ****   hadc1.Instance = ADC1;
 221:Src/main.c    ****   hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
 222:Src/main.c    ****   hadc1.Init.Resolution = ADC_RESOLUTION_12B;
 223:Src/main.c    ****   hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
 224:Src/main.c    ****   hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
 225:Src/main.c    ****   hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
 226:Src/main.c    ****   hadc1.Init.LowPowerAutoWait = DISABLE;
 227:Src/main.c    ****   hadc1.Init.ContinuousConvMode = DISABLE;
 228:Src/main.c    ****   hadc1.Init.NbrOfConversion = 1;
 229:Src/main.c    ****   hadc1.Init.DiscontinuousConvMode = DISABLE;
 230:Src/main.c    ****   hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
 231:Src/main.c    ****   hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
 232:Src/main.c    ****   hadc1.Init.DMAContinuousRequests = DISABLE;
 233:Src/main.c    ****   hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
 234:Src/main.c    ****   hadc1.Init.OversamplingMode = DISABLE;
 235:Src/main.c    ****   if (HAL_ADC_Init(&hadc1) != HAL_OK)
 236:Src/main.c    ****   {
 237:Src/main.c    ****     Error_Handler();
 238:Src/main.c    ****   }
 239:Src/main.c    ****   /** Configure Regular Channel
 240:Src/main.c    ****   */
 241:Src/main.c    ****   sConfig.Channel = ADC_CHANNEL_10;
 242:Src/main.c    ****   sConfig.Rank = ADC_REGULAR_RANK_1;
 243:Src/main.c    ****   sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
 244:Src/main.c    ****   sConfig.SingleDiff = ADC_SINGLE_ENDED;
 245:Src/main.c    ****   sConfig.OffsetNumber = ADC_OFFSET_NONE;
 246:Src/main.c    ****   sConfig.Offset = 0;
 247:Src/main.c    ****   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
 248:Src/main.c    ****   {
 249:Src/main.c    ****     Error_Handler();
 250:Src/main.c    ****   }
 251:Src/main.c    ****   /* USER CODE BEGIN ADC1_Init 2 */
 252:Src/main.c    **** 
 253:Src/main.c    ****   /* USER CODE END ADC1_Init 2 */
 254:Src/main.c    **** 
 255:Src/main.c    **** }
 256:Src/main.c    **** 
 257:Src/main.c    **** /**
 258:Src/main.c    ****   * @brief I2C1 Initialization Function
 259:Src/main.c    ****   * @param None
ARM GAS  /tmp/ccbrBnXA.s 			page 6


 260:Src/main.c    ****   * @retval None
 261:Src/main.c    ****   */
 262:Src/main.c    **** static void MX_I2C1_Init(void)
 263:Src/main.c    **** {
 264:Src/main.c    **** 
 265:Src/main.c    ****   /* USER CODE BEGIN I2C1_Init 0 */
 266:Src/main.c    **** 
 267:Src/main.c    ****   /* USER CODE END I2C1_Init 0 */
 268:Src/main.c    **** 
 269:Src/main.c    ****   /* USER CODE BEGIN I2C1_Init 1 */
 270:Src/main.c    **** 
 271:Src/main.c    ****   /* USER CODE END I2C1_Init 1 */
 272:Src/main.c    ****   hi2c1.Instance = I2C1;
 273:Src/main.c    ****   hi2c1.Init.Timing = 0x10909CEC;
 274:Src/main.c    ****   hi2c1.Init.OwnAddress1 = 0;
 275:Src/main.c    ****   hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
 276:Src/main.c    ****   hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
 277:Src/main.c    ****   hi2c1.Init.OwnAddress2 = 0;
 278:Src/main.c    ****   hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
 279:Src/main.c    ****   hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
 280:Src/main.c    ****   hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
 281:Src/main.c    ****   if (HAL_I2C_Init(&hi2c1) != HAL_OK)
 282:Src/main.c    ****   {
 283:Src/main.c    ****     Error_Handler();
 284:Src/main.c    ****   }
 285:Src/main.c    ****   /** Configure Analogue filter
 286:Src/main.c    ****   */
 287:Src/main.c    ****   if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
 288:Src/main.c    ****   {
 289:Src/main.c    ****     Error_Handler();
 290:Src/main.c    ****   }
 291:Src/main.c    ****   /** Configure Digital filter
 292:Src/main.c    ****   */
 293:Src/main.c    ****   if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
 294:Src/main.c    ****   {
 295:Src/main.c    ****     Error_Handler();
 296:Src/main.c    ****   }
 297:Src/main.c    ****   /* USER CODE BEGIN I2C1_Init 2 */
 298:Src/main.c    **** 
 299:Src/main.c    ****   /* USER CODE END I2C1_Init 2 */
 300:Src/main.c    **** 
 301:Src/main.c    **** }
 302:Src/main.c    **** 
 303:Src/main.c    **** /**
 304:Src/main.c    ****   * @brief LPUART1 Initialization Function
 305:Src/main.c    ****   * @param None
 306:Src/main.c    ****   * @retval None
 307:Src/main.c    ****   */
 308:Src/main.c    **** static void MX_LPUART1_UART_Init(void)
 309:Src/main.c    **** {
 310:Src/main.c    **** 
 311:Src/main.c    ****   /* USER CODE BEGIN LPUART1_Init 0 */
 312:Src/main.c    **** 
 313:Src/main.c    ****   /* USER CODE END LPUART1_Init 0 */
 314:Src/main.c    **** 
 315:Src/main.c    ****   /* USER CODE BEGIN LPUART1_Init 1 */
 316:Src/main.c    **** 
ARM GAS  /tmp/ccbrBnXA.s 			page 7


 317:Src/main.c    ****   /* USER CODE END LPUART1_Init 1 */
 318:Src/main.c    ****   hlpuart1.Instance = LPUART1;
 319:Src/main.c    ****   hlpuart1.Init.BaudRate = 209700;
 320:Src/main.c    ****   hlpuart1.Init.WordLength = UART_WORDLENGTH_7B;
 321:Src/main.c    ****   hlpuart1.Init.StopBits = UART_STOPBITS_1;
 322:Src/main.c    ****   hlpuart1.Init.Parity = UART_PARITY_NONE;
 323:Src/main.c    ****   hlpuart1.Init.Mode = UART_MODE_TX_RX;
 324:Src/main.c    ****   hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 325:Src/main.c    ****   hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
 326:Src/main.c    ****   hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 327:Src/main.c    ****   if (HAL_UART_Init(&hlpuart1) != HAL_OK)
 328:Src/main.c    ****   {
 329:Src/main.c    ****     Error_Handler();
 330:Src/main.c    ****   }
 331:Src/main.c    ****   /* USER CODE BEGIN LPUART1_Init 2 */
 332:Src/main.c    **** 
 333:Src/main.c    ****   /* USER CODE END LPUART1_Init 2 */
 334:Src/main.c    **** 
 335:Src/main.c    **** }
 336:Src/main.c    **** 
 337:Src/main.c    **** /**
 338:Src/main.c    ****   * @brief USART3 Initialization Function
 339:Src/main.c    ****   * @param None
 340:Src/main.c    ****   * @retval None
 341:Src/main.c    ****   */
 342:Src/main.c    **** static void MX_USART3_UART_Init(void)
 343:Src/main.c    **** {
 344:Src/main.c    **** 
 345:Src/main.c    ****   /* USER CODE BEGIN USART3_Init 0 */
 346:Src/main.c    **** 
 347:Src/main.c    ****   /* USER CODE END USART3_Init 0 */
 348:Src/main.c    **** 
 349:Src/main.c    ****   /* USER CODE BEGIN USART3_Init 1 */
 350:Src/main.c    **** 
 351:Src/main.c    ****   /* USER CODE END USART3_Init 1 */
 352:Src/main.c    ****   huart3.Instance = USART3;
 353:Src/main.c    ****   huart3.Init.BaudRate = 115200;
 354:Src/main.c    ****   huart3.Init.WordLength = UART_WORDLENGTH_8B;
 355:Src/main.c    ****   huart3.Init.StopBits = UART_STOPBITS_1;
 356:Src/main.c    ****   huart3.Init.Parity = UART_PARITY_NONE;
 357:Src/main.c    ****   huart3.Init.Mode = UART_MODE_TX_RX;
 358:Src/main.c    ****   huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 359:Src/main.c    ****   huart3.Init.OverSampling = UART_OVERSAMPLING_16;
 360:Src/main.c    ****   huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
 361:Src/main.c    ****   huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 362:Src/main.c    ****   if (HAL_UART_Init(&huart3) != HAL_OK)
 363:Src/main.c    ****   {
 364:Src/main.c    ****     Error_Handler();
 365:Src/main.c    ****   }
 366:Src/main.c    ****   /* USER CODE BEGIN USART3_Init 2 */
 367:Src/main.c    **** 
 368:Src/main.c    ****   /* USER CODE END USART3_Init 2 */
 369:Src/main.c    **** 
 370:Src/main.c    **** }
 371:Src/main.c    **** 
 372:Src/main.c    **** /**
 373:Src/main.c    ****   * @brief SPI2 Initialization Function
ARM GAS  /tmp/ccbrBnXA.s 			page 8


 374:Src/main.c    ****   * @param None
 375:Src/main.c    ****   * @retval None
 376:Src/main.c    ****   */
 377:Src/main.c    **** static void MX_SPI2_Init(void)
 378:Src/main.c    **** {
 379:Src/main.c    **** 
 380:Src/main.c    ****   /* USER CODE BEGIN SPI2_Init 0 */
 381:Src/main.c    **** 
 382:Src/main.c    ****   /* USER CODE END SPI2_Init 0 */
 383:Src/main.c    **** 
 384:Src/main.c    ****   /* USER CODE BEGIN SPI2_Init 1 */
 385:Src/main.c    **** 
 386:Src/main.c    ****   /* USER CODE END SPI2_Init 1 */
 387:Src/main.c    ****   /* SPI2 parameter configuration*/
 388:Src/main.c    ****   hspi2.Instance = SPI2;
 389:Src/main.c    ****   hspi2.Init.Mode = SPI_MODE_MASTER;
 390:Src/main.c    ****   hspi2.Init.Direction = SPI_DIRECTION_2LINES;
 391:Src/main.c    ****   hspi2.Init.DataSize = SPI_DATASIZE_4BIT;
 392:Src/main.c    ****   hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
 393:Src/main.c    ****   hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
 394:Src/main.c    ****   hspi2.Init.NSS = SPI_NSS_SOFT;
 395:Src/main.c    ****   hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
 396:Src/main.c    ****   hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
 397:Src/main.c    ****   hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
 398:Src/main.c    ****   hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
 399:Src/main.c    ****   hspi2.Init.CRCPolynomial = 7;
 400:Src/main.c    ****   hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
 401:Src/main.c    ****   hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
 402:Src/main.c    ****   if (HAL_SPI_Init(&hspi2) != HAL_OK)
 403:Src/main.c    ****   {
 404:Src/main.c    ****     Error_Handler();
 405:Src/main.c    ****   }
 406:Src/main.c    ****   /* USER CODE BEGIN SPI2_Init 2 */
 407:Src/main.c    **** 
 408:Src/main.c    ****   /* USER CODE END SPI2_Init 2 */
 409:Src/main.c    **** 
 410:Src/main.c    **** }
 411:Src/main.c    **** 
 412:Src/main.c    **** /**
 413:Src/main.c    ****   * @brief TIM2 Initialization Function
 414:Src/main.c    ****   * @param None
 415:Src/main.c    ****   * @retval None
 416:Src/main.c    ****   */
 417:Src/main.c    **** static void MX_TIM2_Init(void)
 418:Src/main.c    **** {
 419:Src/main.c    **** 
 420:Src/main.c    ****   /* USER CODE BEGIN TIM2_Init 0 */
 421:Src/main.c    **** 
 422:Src/main.c    ****   /* USER CODE END TIM2_Init 0 */
 423:Src/main.c    **** 
 424:Src/main.c    ****   TIM_ClockConfigTypeDef sClockSourceConfig = {0};
 425:Src/main.c    ****   TIM_MasterConfigTypeDef sMasterConfig = {0};
 426:Src/main.c    **** 
 427:Src/main.c    ****   /* USER CODE BEGIN TIM2_Init 1 */
 428:Src/main.c    **** 
 429:Src/main.c    ****   /* USER CODE END TIM2_Init 1 */
 430:Src/main.c    ****   htim2.Instance = TIM2;
ARM GAS  /tmp/ccbrBnXA.s 			page 9


 431:Src/main.c    ****   htim2.Init.Prescaler = 0;
 432:Src/main.c    ****   htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
 433:Src/main.c    ****   htim2.Init.Period = 4294967295;
 434:Src/main.c    ****   htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
 435:Src/main.c    ****   htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
 436:Src/main.c    ****   if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
 437:Src/main.c    ****   {
 438:Src/main.c    ****     Error_Handler();
 439:Src/main.c    ****   }
 440:Src/main.c    ****   sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
 441:Src/main.c    ****   if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
 442:Src/main.c    ****   {
 443:Src/main.c    ****     Error_Handler();
 444:Src/main.c    ****   }
 445:Src/main.c    ****   sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
 446:Src/main.c    ****   sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
 447:Src/main.c    ****   if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
 448:Src/main.c    ****   {
 449:Src/main.c    ****     Error_Handler();
 450:Src/main.c    ****   }
 451:Src/main.c    ****   /* USER CODE BEGIN TIM2_Init 2 */
 452:Src/main.c    **** 
 453:Src/main.c    ****   /* USER CODE END TIM2_Init 2 */
 454:Src/main.c    **** 
 455:Src/main.c    **** }
 456:Src/main.c    **** 
 457:Src/main.c    **** /**
 458:Src/main.c    ****   * @brief GPIO Initialization Function
 459:Src/main.c    ****   * @param None
 460:Src/main.c    ****   * @retval None
 461:Src/main.c    ****   */
 462:Src/main.c    **** static void MX_GPIO_Init(void)
 463:Src/main.c    **** {
  28              		.loc 1 463 1 view -0
  29              		.cfi_startproc
  30              		@ args = 0, pretend = 0, frame = 32
  31              		@ frame_needed = 0, uses_anonymous_args = 0
  32 0000 F0B5     		push	{r4, r5, r6, r7, lr}
  33              	.LCFI0:
  34              		.cfi_def_cfa_offset 20
  35              		.cfi_offset 4, -20
  36              		.cfi_offset 5, -16
  37              		.cfi_offset 6, -12
  38              		.cfi_offset 7, -8
  39              		.cfi_offset 14, -4
  40 0002 89B0     		sub	sp, sp, #36
  41              	.LCFI1:
  42              		.cfi_def_cfa_offset 56
 464:Src/main.c    ****   GPIO_InitTypeDef GPIO_InitStruct = {0};
  43              		.loc 1 464 3 view .LVU1
  44              		.loc 1 464 20 is_stmt 0 view .LVU2
  45 0004 0024     		movs	r4, #0
  46 0006 0394     		str	r4, [sp, #12]
  47 0008 0494     		str	r4, [sp, #16]
  48 000a 0594     		str	r4, [sp, #20]
  49 000c 0694     		str	r4, [sp, #24]
  50 000e 0794     		str	r4, [sp, #28]
ARM GAS  /tmp/ccbrBnXA.s 			page 10


 465:Src/main.c    **** 
 466:Src/main.c    ****   /* GPIO Ports Clock Enable */
 467:Src/main.c    ****   __HAL_RCC_GPIOC_CLK_ENABLE();
  51              		.loc 1 467 3 is_stmt 1 view .LVU3
  52              	.LBB4:
  53              		.loc 1 467 3 view .LVU4
  54              		.loc 1 467 3 view .LVU5
  55 0010 324B     		ldr	r3, .L3
  56 0012 DA6C     		ldr	r2, [r3, #76]
  57 0014 42F00402 		orr	r2, r2, #4
  58 0018 DA64     		str	r2, [r3, #76]
  59              		.loc 1 467 3 view .LVU6
  60 001a DA6C     		ldr	r2, [r3, #76]
  61 001c 02F00402 		and	r2, r2, #4
  62 0020 0092     		str	r2, [sp]
  63              		.loc 1 467 3 view .LVU7
  64 0022 009A     		ldr	r2, [sp]
  65              	.LBE4:
 468:Src/main.c    ****   __HAL_RCC_GPIOA_CLK_ENABLE();
  66              		.loc 1 468 3 view .LVU8
  67              	.LBB5:
  68              		.loc 1 468 3 view .LVU9
  69              		.loc 1 468 3 view .LVU10
  70 0024 DA6C     		ldr	r2, [r3, #76]
  71 0026 42F00102 		orr	r2, r2, #1
  72 002a DA64     		str	r2, [r3, #76]
  73              		.loc 1 468 3 view .LVU11
  74 002c DA6C     		ldr	r2, [r3, #76]
  75 002e 02F00102 		and	r2, r2, #1
  76 0032 0192     		str	r2, [sp, #4]
  77              		.loc 1 468 3 view .LVU12
  78 0034 019A     		ldr	r2, [sp, #4]
  79              	.LBE5:
 469:Src/main.c    ****   __HAL_RCC_GPIOB_CLK_ENABLE();
  80              		.loc 1 469 3 view .LVU13
  81              	.LBB6:
  82              		.loc 1 469 3 view .LVU14
  83              		.loc 1 469 3 view .LVU15
  84 0036 DA6C     		ldr	r2, [r3, #76]
  85 0038 42F00202 		orr	r2, r2, #2
  86 003c DA64     		str	r2, [r3, #76]
  87              		.loc 1 469 3 view .LVU16
  88 003e DB6C     		ldr	r3, [r3, #76]
  89 0040 03F00203 		and	r3, r3, #2
  90 0044 0293     		str	r3, [sp, #8]
  91              		.loc 1 469 3 view .LVU17
  92 0046 029B     		ldr	r3, [sp, #8]
  93              	.LBE6:
 470:Src/main.c    **** 
 471:Src/main.c    ****   /*Configure GPIO pin Output Level */
 472:Src/main.c    ****   HAL_GPIO_WritePin(PER_EN_GPIO_Port, PER_EN_Pin, GPIO_PIN_RESET);
  94              		.loc 1 472 3 view .LVU18
  95              		.loc 1 472 20 is_stmt 0 view .LVU19
  96 0048 254F     		ldr	r7, .L3+4
  97 004a 2246     		mov	r2, r4
  98 004c 4FF40051 		mov	r1, #8192
  99 0050 3846     		mov	r0, r7
ARM GAS  /tmp/ccbrBnXA.s 			page 11


 100 0052 FFF7FEFF 		bl	HAL_GPIO_WritePin
 101              	.LVL0:
 473:Src/main.c    **** 
 474:Src/main.c    ****   /*Configure GPIO pin Output Level */
 475:Src/main.c    ****   HAL_GPIO_WritePin(GPIOA, BAT_M_EN_Pin|PWR_MCU_Pin|CS_IMU_Pin|PWR_OR_Pin, GPIO_PIN_RESET);
 102              		.loc 1 475 3 is_stmt 1 view .LVU20
 103              		.loc 1 475 20 is_stmt 0 view .LVU21
 104 0056 2246     		mov	r2, r4
 105 0058 48F2C011 		movw	r1, #33216
 106 005c 4FF09040 		mov	r0, #1207959552
 107 0060 FFF7FEFF 		bl	HAL_GPIO_WritePin
 108              	.LVL1:
 476:Src/main.c    **** 
 477:Src/main.c    ****   /*Configure GPIO pin Output Level */
 478:Src/main.c    ****   HAL_GPIO_WritePin(IMU_INT1_GPIO_Port, IMU_INT1_Pin, GPIO_PIN_RESET);
 109              		.loc 1 478 3 is_stmt 1 view .LVU22
 110              		.loc 1 478 20 is_stmt 0 view .LVU23
 111 0064 1F4D     		ldr	r5, .L3+8
 112 0066 2246     		mov	r2, r4
 113 0068 4FF48051 		mov	r1, #4096
 114 006c 2846     		mov	r0, r5
 115 006e FFF7FEFF 		bl	HAL_GPIO_WritePin
 116              	.LVL2:
 479:Src/main.c    **** 
 480:Src/main.c    ****   /*Configure GPIO pin : PER_EN_Pin */
 481:Src/main.c    ****   GPIO_InitStruct.Pin = PER_EN_Pin;
 117              		.loc 1 481 3 is_stmt 1 view .LVU24
 118              		.loc 1 481 23 is_stmt 0 view .LVU25
 119 0072 4FF40053 		mov	r3, #8192
 120 0076 0393     		str	r3, [sp, #12]
 482:Src/main.c    ****   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 121              		.loc 1 482 3 is_stmt 1 view .LVU26
 122              		.loc 1 482 24 is_stmt 0 view .LVU27
 123 0078 0126     		movs	r6, #1
 124 007a 0496     		str	r6, [sp, #16]
 483:Src/main.c    ****   GPIO_InitStruct.Pull = GPIO_NOPULL;
 125              		.loc 1 483 3 is_stmt 1 view .LVU28
 126              		.loc 1 483 24 is_stmt 0 view .LVU29
 127 007c 0594     		str	r4, [sp, #20]
 484:Src/main.c    ****   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 128              		.loc 1 484 3 is_stmt 1 view .LVU30
 129              		.loc 1 484 25 is_stmt 0 view .LVU31
 130 007e 0694     		str	r4, [sp, #24]
 485:Src/main.c    ****   HAL_GPIO_Init(PER_EN_GPIO_Port, &GPIO_InitStruct);
 131              		.loc 1 485 3 is_stmt 1 view .LVU32
 132              		.loc 1 485 16 is_stmt 0 view .LVU33
 133 0080 03A9     		add	r1, sp, #12
 134 0082 3846     		mov	r0, r7
 135 0084 FFF7FEFF 		bl	HAL_GPIO_Init
 136              	.LVL3:
 486:Src/main.c    **** 
 487:Src/main.c    ****   /*Configure GPIO pins : BAT_M_EN_Pin PWR_MCU_Pin CS_IMU_Pin PWR_OR_Pin */
 488:Src/main.c    ****   GPIO_InitStruct.Pin = BAT_M_EN_Pin|PWR_MCU_Pin|CS_IMU_Pin|PWR_OR_Pin;
 137              		.loc 1 488 3 is_stmt 1 view .LVU34
 138              		.loc 1 488 23 is_stmt 0 view .LVU35
 139 0088 48F2C013 		movw	r3, #33216
 140 008c 0393     		str	r3, [sp, #12]
ARM GAS  /tmp/ccbrBnXA.s 			page 12


 489:Src/main.c    ****   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 141              		.loc 1 489 3 is_stmt 1 view .LVU36
 142              		.loc 1 489 24 is_stmt 0 view .LVU37
 143 008e 0496     		str	r6, [sp, #16]
 490:Src/main.c    ****   GPIO_InitStruct.Pull = GPIO_NOPULL;
 144              		.loc 1 490 3 is_stmt 1 view .LVU38
 145              		.loc 1 490 24 is_stmt 0 view .LVU39
 146 0090 0594     		str	r4, [sp, #20]
 491:Src/main.c    ****   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 147              		.loc 1 491 3 is_stmt 1 view .LVU40
 148              		.loc 1 491 25 is_stmt 0 view .LVU41
 149 0092 0694     		str	r4, [sp, #24]
 492:Src/main.c    ****   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
 150              		.loc 1 492 3 is_stmt 1 view .LVU42
 151              		.loc 1 492 16 is_stmt 0 view .LVU43
 152 0094 03A9     		add	r1, sp, #12
 153 0096 4FF09040 		mov	r0, #1207959552
 154 009a FFF7FEFF 		bl	HAL_GPIO_Init
 155              	.LVL4:
 493:Src/main.c    **** 
 494:Src/main.c    ****   /*Configure GPIO pins : CS_FLASH_Pin IMU_INT2_Pin USB_INT_Pin USB_VALID_Pin
 495:Src/main.c    ****                            USB_ATTACH_Pin */
 496:Src/main.c    ****   GPIO_InitStruct.Pin = CS_FLASH_Pin|IMU_INT2_Pin|USB_INT_Pin|USB_VALID_Pin
 156              		.loc 1 496 3 is_stmt 1 view .LVU44
 157              		.loc 1 496 23 is_stmt 0 view .LVU45
 158 009e 1F23     		movs	r3, #31
 159 00a0 0393     		str	r3, [sp, #12]
 497:Src/main.c    ****                           |USB_ATTACH_Pin;
 498:Src/main.c    ****   GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
 160              		.loc 1 498 3 is_stmt 1 view .LVU46
 161              		.loc 1 498 24 is_stmt 0 view .LVU47
 162 00a2 114B     		ldr	r3, .L3+12
 163 00a4 0493     		str	r3, [sp, #16]
 499:Src/main.c    ****   GPIO_InitStruct.Pull = GPIO_NOPULL;
 164              		.loc 1 499 3 is_stmt 1 view .LVU48
 165              		.loc 1 499 24 is_stmt 0 view .LVU49
 166 00a6 0594     		str	r4, [sp, #20]
 500:Src/main.c    ****   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
 167              		.loc 1 500 3 is_stmt 1 view .LVU50
 168              		.loc 1 500 16 is_stmt 0 view .LVU51
 169 00a8 03A9     		add	r1, sp, #12
 170 00aa 2846     		mov	r0, r5
 171 00ac FFF7FEFF 		bl	HAL_GPIO_Init
 172              	.LVL5:
 501:Src/main.c    **** 
 502:Src/main.c    ****   /*Configure GPIO pin : IMU_INT1_Pin */
 503:Src/main.c    ****   GPIO_InitStruct.Pin = IMU_INT1_Pin;
 173              		.loc 1 503 3 is_stmt 1 view .LVU52
 174              		.loc 1 503 23 is_stmt 0 view .LVU53
 175 00b0 4FF48053 		mov	r3, #4096
 176 00b4 0393     		str	r3, [sp, #12]
 504:Src/main.c    ****   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 177              		.loc 1 504 3 is_stmt 1 view .LVU54
 178              		.loc 1 504 24 is_stmt 0 view .LVU55
 179 00b6 0496     		str	r6, [sp, #16]
 505:Src/main.c    ****   GPIO_InitStruct.Pull = GPIO_NOPULL;
 180              		.loc 1 505 3 is_stmt 1 view .LVU56
ARM GAS  /tmp/ccbrBnXA.s 			page 13


 181              		.loc 1 505 24 is_stmt 0 view .LVU57
 182 00b8 0594     		str	r4, [sp, #20]
 506:Src/main.c    ****   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 183              		.loc 1 506 3 is_stmt 1 view .LVU58
 184              		.loc 1 506 25 is_stmt 0 view .LVU59
 185 00ba 0694     		str	r4, [sp, #24]
 507:Src/main.c    ****   HAL_GPIO_Init(IMU_INT1_GPIO_Port, &GPIO_InitStruct);
 186              		.loc 1 507 3 is_stmt 1 view .LVU60
 187              		.loc 1 507 16 is_stmt 0 view .LVU61
 188 00bc 03A9     		add	r1, sp, #12
 189 00be 2846     		mov	r0, r5
 190 00c0 FFF7FEFF 		bl	HAL_GPIO_Init
 191              	.LVL6:
 508:Src/main.c    **** 
 509:Src/main.c    ****   /*Configure GPIO pins : USB_DEBUG_Pin CHARG_STAT_Pin */
 510:Src/main.c    ****   GPIO_InitStruct.Pin = USB_DEBUG_Pin|CHARG_STAT_Pin;
 192              		.loc 1 510 3 is_stmt 1 view .LVU62
 193              		.loc 1 510 23 is_stmt 0 view .LVU63
 194 00c4 4FF4A073 		mov	r3, #320
 195 00c8 0393     		str	r3, [sp, #12]
 511:Src/main.c    ****   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
 196              		.loc 1 511 3 is_stmt 1 view .LVU64
 197              		.loc 1 511 24 is_stmt 0 view .LVU65
 198 00ca 0494     		str	r4, [sp, #16]
 512:Src/main.c    ****   GPIO_InitStruct.Pull = GPIO_NOPULL;
 199              		.loc 1 512 3 is_stmt 1 view .LVU66
 200              		.loc 1 512 24 is_stmt 0 view .LVU67
 201 00cc 0594     		str	r4, [sp, #20]
 513:Src/main.c    ****   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
 202              		.loc 1 513 3 is_stmt 1 view .LVU68
 203              		.loc 1 513 16 is_stmt 0 view .LVU69
 204 00ce 03A9     		add	r1, sp, #12
 205 00d0 2846     		mov	r0, r5
 206 00d2 FFF7FEFF 		bl	HAL_GPIO_Init
 207              	.LVL7:
 514:Src/main.c    **** 
 515:Src/main.c    **** }
 208              		.loc 1 515 1 view .LVU70
 209 00d6 09B0     		add	sp, sp, #36
 210              	.LCFI2:
 211              		.cfi_def_cfa_offset 20
 212              		@ sp needed
 213 00d8 F0BD     		pop	{r4, r5, r6, r7, pc}
 214              	.L4:
 215 00da 00BF     		.align	2
 216              	.L3:
 217 00dc 00100240 		.word	1073876992
 218 00e0 00080048 		.word	1207961600
 219 00e4 00040048 		.word	1207960576
 220 00e8 00001110 		.word	269549568
 221              		.cfi_endproc
 222              	.LFE3700:
 224              		.section	.text.Error_Handler,"ax",%progbits
 225              		.align	1
 226              		.global	Error_Handler
 227              		.syntax unified
 228              		.thumb
ARM GAS  /tmp/ccbrBnXA.s 			page 14


 229              		.thumb_func
 230              		.fpu fpv4-sp-d16
 232              	Error_Handler:
 233              	.LFB3701:
 516:Src/main.c    **** 
 517:Src/main.c    **** /* USER CODE BEGIN 4 */
 518:Src/main.c    **** 
 519:Src/main.c    **** /* USER CODE END 4 */
 520:Src/main.c    **** 
 521:Src/main.c    **** /**
 522:Src/main.c    ****   * @brief  This function is executed in case of error occurrence.
 523:Src/main.c    ****   * @retval None
 524:Src/main.c    ****   */
 525:Src/main.c    **** void Error_Handler(void)
 526:Src/main.c    **** {
 234              		.loc 1 526 1 is_stmt 1 view -0
 235              		.cfi_startproc
 236              		@ Volatile: function does not return.
 237              		@ args = 0, pretend = 0, frame = 0
 238              		@ frame_needed = 0, uses_anonymous_args = 0
 239              		@ link register save eliminated.
 527:Src/main.c    ****   /* USER CODE BEGIN Error_Handler_Debug */
 528:Src/main.c    ****     /* User can add his own implementation to report the HAL error return state */
 529:Src/main.c    ****     __disable_irq();
 240              		.loc 1 529 5 view .LVU72
 241              	.LBB7:
 242              	.LBI7:
 243              		.file 2 "Drivers/CMSIS/Include/cmsis_gcc.h"
   1:Drivers/CMSIS/Include/cmsis_gcc.h **** /**************************************************************************//**
   2:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @file     cmsis_gcc.h
   3:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @brief    CMSIS compiler GCC header file
   4:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @version  V5.2.0
   5:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @date     08. May 2019
   6:Drivers/CMSIS/Include/cmsis_gcc.h ****  ******************************************************************************/
   7:Drivers/CMSIS/Include/cmsis_gcc.h **** /*
   8:Drivers/CMSIS/Include/cmsis_gcc.h ****  * Copyright (c) 2009-2019 Arm Limited. All rights reserved.
   9:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  10:Drivers/CMSIS/Include/cmsis_gcc.h ****  * SPDX-License-Identifier: Apache-2.0
  11:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  12:Drivers/CMSIS/Include/cmsis_gcc.h ****  * Licensed under the Apache License, Version 2.0 (the License); you may
  13:Drivers/CMSIS/Include/cmsis_gcc.h ****  * not use this file except in compliance with the License.
  14:Drivers/CMSIS/Include/cmsis_gcc.h ****  * You may obtain a copy of the License at
  15:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  16:Drivers/CMSIS/Include/cmsis_gcc.h ****  * www.apache.org/licenses/LICENSE-2.0
  17:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  18:Drivers/CMSIS/Include/cmsis_gcc.h ****  * Unless required by applicable law or agreed to in writing, software
  19:Drivers/CMSIS/Include/cmsis_gcc.h ****  * distributed under the License is distributed on an AS IS BASIS, WITHOUT
  20:Drivers/CMSIS/Include/cmsis_gcc.h ****  * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  21:Drivers/CMSIS/Include/cmsis_gcc.h ****  * See the License for the specific language governing permissions and
  22:Drivers/CMSIS/Include/cmsis_gcc.h ****  * limitations under the License.
  23:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
  24:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  25:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __CMSIS_GCC_H
  26:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __CMSIS_GCC_H
  27:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  28:Drivers/CMSIS/Include/cmsis_gcc.h **** /* ignore some GCC warnings */
  29:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic push
ARM GAS  /tmp/ccbrBnXA.s 			page 15


  30:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic ignored "-Wsign-conversion"
  31:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic ignored "-Wconversion"
  32:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic ignored "-Wunused-parameter"
  33:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  34:Drivers/CMSIS/Include/cmsis_gcc.h **** /* Fallback for __has_builtin */
  35:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __has_builtin
  36:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __has_builtin(x) (0)
  37:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  38:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  39:Drivers/CMSIS/Include/cmsis_gcc.h **** /* CMSIS compiler specific defines */
  40:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __ASM
  41:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __ASM                                  __asm
  42:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  43:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __INLINE
  44:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __INLINE                               inline
  45:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  46:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __STATIC_INLINE
  47:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __STATIC_INLINE                        static inline
  48:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  49:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __STATIC_FORCEINLINE                 
  50:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
  51:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif                                           
  52:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __NO_RETURN
  53:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __NO_RETURN                            __attribute__((__noreturn__))
  54:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  55:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __USED
  56:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __USED                                 __attribute__((used))
  57:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  58:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __WEAK
  59:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __WEAK                                 __attribute__((weak))
  60:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  61:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __PACKED
  62:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __PACKED                               __attribute__((packed, aligned(1)))
  63:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  64:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __PACKED_STRUCT
  65:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __PACKED_STRUCT                        struct __attribute__((packed, aligned(1)))
  66:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  67:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __PACKED_UNION
  68:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __PACKED_UNION                         union __attribute__((packed, aligned(1)))
  69:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  70:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT32        /* deprecated */
  71:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  72:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  73:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  74:Drivers/CMSIS/Include/cmsis_gcc.h ****   struct __attribute__((packed)) T_UINT32 { uint32_t v; };
  75:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
  76:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT32(x)                  (((struct T_UINT32 *)(x))->v)
  77:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  78:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT16_WRITE
  79:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  80:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  81:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  82:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT16_WRITE { uint16_t v; };
  83:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
  84:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT16_WRITE(addr, val)    (void)((((struct T_UINT16_WRITE *)(void *)(addr))-
  85:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  86:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT16_READ
ARM GAS  /tmp/ccbrBnXA.s 			page 16


  87:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  88:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  89:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  90:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT16_READ { uint16_t v; };
  91:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
  92:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT16_READ(addr)          (((const struct T_UINT16_READ *)(const void *)(add
  93:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  94:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT32_WRITE
  95:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  96:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  97:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  98:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT32_WRITE { uint32_t v; };
  99:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
 100:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT32_WRITE(addr, val)    (void)((((struct T_UINT32_WRITE *)(void *)(addr))-
 101:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 102:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT32_READ
 103:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
 104:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
 105:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
 106:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT32_READ { uint32_t v; };
 107:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
 108:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT32_READ(addr)          (((const struct T_UINT32_READ *)(const void *)(add
 109:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 110:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __ALIGNED
 111:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __ALIGNED(x)                           __attribute__((aligned(x)))
 112:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 113:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __RESTRICT
 114:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __RESTRICT                             __restrict
 115:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 116:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __COMPILER_BARRIER
 117:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __COMPILER_BARRIER()                   __ASM volatile("":::"memory")
 118:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 119:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 120:Drivers/CMSIS/Include/cmsis_gcc.h **** /* #########################  Startup and Lowlevel Init  ######################## */
 121:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 122:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __PROGRAM_START
 123:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 124:Drivers/CMSIS/Include/cmsis_gcc.h **** /**
 125:Drivers/CMSIS/Include/cmsis_gcc.h ****   \brief   Initializes data and bss sections
 126:Drivers/CMSIS/Include/cmsis_gcc.h ****   \details This default implementations initialized all data and additional bss
 127:Drivers/CMSIS/Include/cmsis_gcc.h ****            sections relying on .copy.table and .zero.table specified properly
 128:Drivers/CMSIS/Include/cmsis_gcc.h ****            in the used linker script.
 129:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 130:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 131:Drivers/CMSIS/Include/cmsis_gcc.h **** __STATIC_FORCEINLINE __NO_RETURN void __cmsis_start(void)
 132:Drivers/CMSIS/Include/cmsis_gcc.h **** {
 133:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern void _start(void) __NO_RETURN;
 134:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 135:Drivers/CMSIS/Include/cmsis_gcc.h ****   typedef struct {
 136:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t const* src;
 137:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t* dest;
 138:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t  wlen;
 139:Drivers/CMSIS/Include/cmsis_gcc.h ****   } __copy_table_t;
 140:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 141:Drivers/CMSIS/Include/cmsis_gcc.h ****   typedef struct {
 142:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t* dest;
 143:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t  wlen;
ARM GAS  /tmp/ccbrBnXA.s 			page 17


 144:Drivers/CMSIS/Include/cmsis_gcc.h ****   } __zero_table_t;
 145:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 146:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __copy_table_t __copy_table_start__;
 147:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __copy_table_t __copy_table_end__;
 148:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __zero_table_t __zero_table_start__;
 149:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __zero_table_t __zero_table_end__;
 150:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 151:Drivers/CMSIS/Include/cmsis_gcc.h ****   for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable
 152:Drivers/CMSIS/Include/cmsis_gcc.h ****     for(uint32_t i=0u; i<pTable->wlen; ++i) {
 153:Drivers/CMSIS/Include/cmsis_gcc.h ****       pTable->dest[i] = pTable->src[i];
 154:Drivers/CMSIS/Include/cmsis_gcc.h ****     }
 155:Drivers/CMSIS/Include/cmsis_gcc.h ****   }
 156:Drivers/CMSIS/Include/cmsis_gcc.h ****  
 157:Drivers/CMSIS/Include/cmsis_gcc.h ****   for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable
 158:Drivers/CMSIS/Include/cmsis_gcc.h ****     for(uint32_t i=0u; i<pTable->wlen; ++i) {
 159:Drivers/CMSIS/Include/cmsis_gcc.h ****       pTable->dest[i] = 0u;
 160:Drivers/CMSIS/Include/cmsis_gcc.h ****     }
 161:Drivers/CMSIS/Include/cmsis_gcc.h ****   }
 162:Drivers/CMSIS/Include/cmsis_gcc.h ****  
 163:Drivers/CMSIS/Include/cmsis_gcc.h ****   _start();
 164:Drivers/CMSIS/Include/cmsis_gcc.h **** }
 165:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 166:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __PROGRAM_START           __cmsis_start
 167:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 168:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 169:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __INITIAL_SP
 170:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __INITIAL_SP              __StackTop
 171:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 172:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 173:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __STACK_LIMIT
 174:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __STACK_LIMIT             __StackLimit
 175:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 176:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 177:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __VECTOR_TABLE
 178:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __VECTOR_TABLE            __Vectors
 179:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 180:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 181:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __VECTOR_TABLE_ATTRIBUTE
 182:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __VECTOR_TABLE_ATTRIBUTE  __attribute((used, section(".vectors")))
 183:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 184:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 185:Drivers/CMSIS/Include/cmsis_gcc.h **** /* ###########################  Core Function Access  ########################### */
 186:Drivers/CMSIS/Include/cmsis_gcc.h **** /** \ingroup  CMSIS_Core_FunctionInterface
 187:Drivers/CMSIS/Include/cmsis_gcc.h ****     \defgroup CMSIS_Core_RegAccFunctions CMSIS Core Register Access Functions
 188:Drivers/CMSIS/Include/cmsis_gcc.h ****   @{
 189:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 190:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 191:Drivers/CMSIS/Include/cmsis_gcc.h **** /**
 192:Drivers/CMSIS/Include/cmsis_gcc.h ****   \brief   Enable IRQ Interrupts
 193:Drivers/CMSIS/Include/cmsis_gcc.h ****   \details Enables IRQ interrupts by clearing the I-bit in the CPSR.
 194:Drivers/CMSIS/Include/cmsis_gcc.h ****            Can only be executed in Privileged modes.
 195:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 196:Drivers/CMSIS/Include/cmsis_gcc.h **** __STATIC_FORCEINLINE void __enable_irq(void)
 197:Drivers/CMSIS/Include/cmsis_gcc.h **** {
 198:Drivers/CMSIS/Include/cmsis_gcc.h ****   __ASM volatile ("cpsie i" : : : "memory");
 199:Drivers/CMSIS/Include/cmsis_gcc.h **** }
 200:Drivers/CMSIS/Include/cmsis_gcc.h **** 
ARM GAS  /tmp/ccbrBnXA.s 			page 18


 201:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 202:Drivers/CMSIS/Include/cmsis_gcc.h **** /**
 203:Drivers/CMSIS/Include/cmsis_gcc.h ****   \brief   Disable IRQ Interrupts
 204:Drivers/CMSIS/Include/cmsis_gcc.h ****   \details Disables IRQ interrupts by setting the I-bit in the CPSR.
 205:Drivers/CMSIS/Include/cmsis_gcc.h ****            Can only be executed in Privileged modes.
 206:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 207:Drivers/CMSIS/Include/cmsis_gcc.h **** __STATIC_FORCEINLINE void __disable_irq(void)
 244              		.loc 2 207 27 view .LVU73
 245              	.LBB8:
 208:Drivers/CMSIS/Include/cmsis_gcc.h **** {
 209:Drivers/CMSIS/Include/cmsis_gcc.h ****   __ASM volatile ("cpsid i" : : : "memory");
 246              		.loc 2 209 3 view .LVU74
 247              		.loc 2 209 44 is_stmt 0 view .LVU75
 248              		.syntax unified
 249              	@ 209 "Drivers/CMSIS/Include/cmsis_gcc.h" 1
 250 0000 72B6     		cpsid i
 251              	@ 0 "" 2
 252              		.thumb
 253              		.syntax unified
 254              	.L6:
 255              	.LBE8:
 256              	.LBE7:
 530:Src/main.c    ****     while (1) { }
 257              		.loc 1 530 5 is_stmt 1 discriminator 1 view .LVU76
 258              		.loc 1 530 5 discriminator 1 view .LVU77
 259 0002 FEE7     		b	.L6
 260              		.cfi_endproc
 261              	.LFE3701:
 263              		.section	.text._ZL12MX_ADC1_Initv,"ax",%progbits
 264              		.align	1
 265              		.syntax unified
 266              		.thumb
 267              		.thumb_func
 268              		.fpu fpv4-sp-d16
 270              	_ZL12MX_ADC1_Initv:
 271              	.LFB3694:
 207:Src/main.c    **** 
 272              		.loc 1 207 1 view -0
 273              		.cfi_startproc
 274              		@ args = 0, pretend = 0, frame = 24
 275              		@ frame_needed = 0, uses_anonymous_args = 0
 276 0000 00B5     		push	{lr}
 277              	.LCFI3:
 278              		.cfi_def_cfa_offset 4
 279              		.cfi_offset 14, -4
 280 0002 87B0     		sub	sp, sp, #28
 281              	.LCFI4:
 282              		.cfi_def_cfa_offset 32
 213:Src/main.c    **** 
 283              		.loc 1 213 3 view .LVU79
 213:Src/main.c    **** 
 284              		.loc 1 213 26 is_stmt 0 view .LVU80
 285 0004 0023     		movs	r3, #0
 286 0006 0093     		str	r3, [sp]
 287 0008 0193     		str	r3, [sp, #4]
 288 000a 0293     		str	r3, [sp, #8]
 289 000c 0393     		str	r3, [sp, #12]
ARM GAS  /tmp/ccbrBnXA.s 			page 19


 290 000e 0493     		str	r3, [sp, #16]
 291 0010 0593     		str	r3, [sp, #20]
 220:Src/main.c    ****   hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
 292              		.loc 1 220 3 is_stmt 1 view .LVU81
 220:Src/main.c    ****   hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
 293              		.loc 1 220 18 is_stmt 0 view .LVU82
 294 0012 1848     		ldr	r0, .L13
 295 0014 184A     		ldr	r2, .L13+4
 296 0016 0260     		str	r2, [r0]
 221:Src/main.c    ****   hadc1.Init.Resolution = ADC_RESOLUTION_12B;
 297              		.loc 1 221 3 is_stmt 1 view .LVU83
 221:Src/main.c    ****   hadc1.Init.Resolution = ADC_RESOLUTION_12B;
 298              		.loc 1 221 29 is_stmt 0 view .LVU84
 299 0018 4360     		str	r3, [r0, #4]
 222:Src/main.c    ****   hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
 300              		.loc 1 222 3 is_stmt 1 view .LVU85
 222:Src/main.c    ****   hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
 301              		.loc 1 222 25 is_stmt 0 view .LVU86
 302 001a 8360     		str	r3, [r0, #8]
 223:Src/main.c    ****   hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
 303              		.loc 1 223 3 is_stmt 1 view .LVU87
 223:Src/main.c    ****   hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
 304              		.loc 1 223 24 is_stmt 0 view .LVU88
 305 001c C360     		str	r3, [r0, #12]
 224:Src/main.c    ****   hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
 306              		.loc 1 224 3 is_stmt 1 view .LVU89
 224:Src/main.c    ****   hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
 307              		.loc 1 224 27 is_stmt 0 view .LVU90
 308 001e 0361     		str	r3, [r0, #16]
 225:Src/main.c    ****   hadc1.Init.LowPowerAutoWait = DISABLE;
 309              		.loc 1 225 3 is_stmt 1 view .LVU91
 225:Src/main.c    ****   hadc1.Init.LowPowerAutoWait = DISABLE;
 310              		.loc 1 225 27 is_stmt 0 view .LVU92
 311 0020 0422     		movs	r2, #4
 312 0022 4261     		str	r2, [r0, #20]
 226:Src/main.c    ****   hadc1.Init.ContinuousConvMode = DISABLE;
 313              		.loc 1 226 3 is_stmt 1 view .LVU93
 226:Src/main.c    ****   hadc1.Init.ContinuousConvMode = DISABLE;
 314              		.loc 1 226 31 is_stmt 0 view .LVU94
 315 0024 0376     		strb	r3, [r0, #24]
 227:Src/main.c    ****   hadc1.Init.NbrOfConversion = 1;
 316              		.loc 1 227 3 is_stmt 1 view .LVU95
 227:Src/main.c    ****   hadc1.Init.NbrOfConversion = 1;
 317              		.loc 1 227 33 is_stmt 0 view .LVU96
 318 0026 4376     		strb	r3, [r0, #25]
 228:Src/main.c    ****   hadc1.Init.DiscontinuousConvMode = DISABLE;
 319              		.loc 1 228 3 is_stmt 1 view .LVU97
 228:Src/main.c    ****   hadc1.Init.DiscontinuousConvMode = DISABLE;
 320              		.loc 1 228 30 is_stmt 0 view .LVU98
 321 0028 0122     		movs	r2, #1
 322 002a C261     		str	r2, [r0, #28]
 229:Src/main.c    ****   hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
 323              		.loc 1 229 3 is_stmt 1 view .LVU99
 229:Src/main.c    ****   hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
 324              		.loc 1 229 36 is_stmt 0 view .LVU100
 325 002c 80F82030 		strb	r3, [r0, #32]
 230:Src/main.c    ****   hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
ARM GAS  /tmp/ccbrBnXA.s 			page 20


 326              		.loc 1 230 3 is_stmt 1 view .LVU101
 230:Src/main.c    ****   hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
 327              		.loc 1 230 31 is_stmt 0 view .LVU102
 328 0030 8362     		str	r3, [r0, #40]
 231:Src/main.c    ****   hadc1.Init.DMAContinuousRequests = DISABLE;
 329              		.loc 1 231 3 is_stmt 1 view .LVU103
 231:Src/main.c    ****   hadc1.Init.DMAContinuousRequests = DISABLE;
 330              		.loc 1 231 35 is_stmt 0 view .LVU104
 331 0032 C362     		str	r3, [r0, #44]
 232:Src/main.c    ****   hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
 332              		.loc 1 232 3 is_stmt 1 view .LVU105
 232:Src/main.c    ****   hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
 333              		.loc 1 232 36 is_stmt 0 view .LVU106
 334 0034 80F83030 		strb	r3, [r0, #48]
 233:Src/main.c    ****   hadc1.Init.OversamplingMode = DISABLE;
 335              		.loc 1 233 3 is_stmt 1 view .LVU107
 233:Src/main.c    ****   hadc1.Init.OversamplingMode = DISABLE;
 336              		.loc 1 233 22 is_stmt 0 view .LVU108
 337 0038 4363     		str	r3, [r0, #52]
 234:Src/main.c    ****   if (HAL_ADC_Init(&hadc1) != HAL_OK)
 338              		.loc 1 234 3 is_stmt 1 view .LVU109
 234:Src/main.c    ****   if (HAL_ADC_Init(&hadc1) != HAL_OK)
 339              		.loc 1 234 31 is_stmt 0 view .LVU110
 340 003a 80F83830 		strb	r3, [r0, #56]
 235:Src/main.c    ****   {
 341              		.loc 1 235 3 is_stmt 1 view .LVU111
 235:Src/main.c    ****   {
 342              		.loc 1 235 19 is_stmt 0 view .LVU112
 343 003e FFF7FEFF 		bl	HAL_ADC_Init
 344              	.LVL8:
 235:Src/main.c    ****   {
 345              		.loc 1 235 3 view .LVU113
 346 0042 90B9     		cbnz	r0, .L11
 241:Src/main.c    ****   sConfig.Rank = ADC_REGULAR_RANK_1;
 347              		.loc 1 241 3 is_stmt 1 view .LVU114
 241:Src/main.c    ****   sConfig.Rank = ADC_REGULAR_RANK_1;
 348              		.loc 1 241 19 is_stmt 0 view .LVU115
 349 0044 0D4B     		ldr	r3, .L13+8
 350 0046 0093     		str	r3, [sp]
 242:Src/main.c    ****   sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
 351              		.loc 1 242 3 is_stmt 1 view .LVU116
 242:Src/main.c    ****   sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
 352              		.loc 1 242 16 is_stmt 0 view .LVU117
 353 0048 0623     		movs	r3, #6
 354 004a 0193     		str	r3, [sp, #4]
 243:Src/main.c    ****   sConfig.SingleDiff = ADC_SINGLE_ENDED;
 355              		.loc 1 243 3 is_stmt 1 view .LVU118
 243:Src/main.c    ****   sConfig.SingleDiff = ADC_SINGLE_ENDED;
 356              		.loc 1 243 24 is_stmt 0 view .LVU119
 357 004c 0023     		movs	r3, #0
 358 004e 0293     		str	r3, [sp, #8]
 244:Src/main.c    ****   sConfig.OffsetNumber = ADC_OFFSET_NONE;
 359              		.loc 1 244 3 is_stmt 1 view .LVU120
 244:Src/main.c    ****   sConfig.OffsetNumber = ADC_OFFSET_NONE;
 360              		.loc 1 244 22 is_stmt 0 view .LVU121
 361 0050 7F22     		movs	r2, #127
 362 0052 0392     		str	r2, [sp, #12]
ARM GAS  /tmp/ccbrBnXA.s 			page 21


 245:Src/main.c    ****   sConfig.Offset = 0;
 363              		.loc 1 245 3 is_stmt 1 view .LVU122
 245:Src/main.c    ****   sConfig.Offset = 0;
 364              		.loc 1 245 24 is_stmt 0 view .LVU123
 365 0054 0422     		movs	r2, #4
 366 0056 0492     		str	r2, [sp, #16]
 246:Src/main.c    ****   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
 367              		.loc 1 246 3 is_stmt 1 view .LVU124
 246:Src/main.c    ****   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
 368              		.loc 1 246 18 is_stmt 0 view .LVU125
 369 0058 0593     		str	r3, [sp, #20]
 247:Src/main.c    ****   {
 370              		.loc 1 247 3 is_stmt 1 view .LVU126
 247:Src/main.c    ****   {
 371              		.loc 1 247 28 is_stmt 0 view .LVU127
 372 005a 6946     		mov	r1, sp
 373 005c 0548     		ldr	r0, .L13
 374 005e FFF7FEFF 		bl	HAL_ADC_ConfigChannel
 375              	.LVL9:
 247:Src/main.c    ****   {
 376              		.loc 1 247 3 view .LVU128
 377 0062 20B9     		cbnz	r0, .L12
 255:Src/main.c    **** 
 378              		.loc 1 255 1 view .LVU129
 379 0064 07B0     		add	sp, sp, #28
 380              	.LCFI5:
 381              		.cfi_remember_state
 382              		.cfi_def_cfa_offset 4
 383              		@ sp needed
 384 0066 5DF804FB 		ldr	pc, [sp], #4
 385              	.L11:
 386              	.LCFI6:
 387              		.cfi_restore_state
 237:Src/main.c    ****   }
 388              		.loc 1 237 5 is_stmt 1 view .LVU130
 237:Src/main.c    ****   }
 389              		.loc 1 237 18 is_stmt 0 view .LVU131
 390 006a FFF7FEFF 		bl	Error_Handler
 391              	.LVL10:
 392              	.L12:
 249:Src/main.c    ****   }
 393              		.loc 1 249 5 is_stmt 1 view .LVU132
 249:Src/main.c    ****   }
 394              		.loc 1 249 18 is_stmt 0 view .LVU133
 395 006e FFF7FEFF 		bl	Error_Handler
 396              	.LVL11:
 397              	.L14:
 398 0072 00BF     		.align	2
 399              	.L13:
 400 0074 00000000 		.word	.LANCHOR0
 401 0078 00000450 		.word	1342439424
 402 007c 0004002A 		.word	704644096
 403              		.cfi_endproc
 404              	.LFE3694:
 406              		.section	.text._ZL12MX_I2C1_Initv,"ax",%progbits
 407              		.align	1
 408              		.syntax unified
ARM GAS  /tmp/ccbrBnXA.s 			page 22


 409              		.thumb
 410              		.thumb_func
 411              		.fpu fpv4-sp-d16
 413              	_ZL12MX_I2C1_Initv:
 414              	.LFB3695:
 263:Src/main.c    **** 
 415              		.loc 1 263 1 is_stmt 1 view -0
 416              		.cfi_startproc
 417              		@ args = 0, pretend = 0, frame = 0
 418              		@ frame_needed = 0, uses_anonymous_args = 0
 419 0000 08B5     		push	{r3, lr}
 420              	.LCFI7:
 421              		.cfi_def_cfa_offset 8
 422              		.cfi_offset 3, -8
 423              		.cfi_offset 14, -4
 272:Src/main.c    ****   hi2c1.Init.Timing = 0x10909CEC;
 424              		.loc 1 272 3 view .LVU135
 272:Src/main.c    ****   hi2c1.Init.Timing = 0x10909CEC;
 425              		.loc 1 272 18 is_stmt 0 view .LVU136
 426 0002 1148     		ldr	r0, .L23
 427 0004 114B     		ldr	r3, .L23+4
 428 0006 0360     		str	r3, [r0]
 273:Src/main.c    ****   hi2c1.Init.OwnAddress1 = 0;
 429              		.loc 1 273 3 is_stmt 1 view .LVU137
 273:Src/main.c    ****   hi2c1.Init.OwnAddress1 = 0;
 430              		.loc 1 273 21 is_stmt 0 view .LVU138
 431 0008 114B     		ldr	r3, .L23+8
 432 000a 4360     		str	r3, [r0, #4]
 274:Src/main.c    ****   hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
 433              		.loc 1 274 3 is_stmt 1 view .LVU139
 274:Src/main.c    ****   hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
 434              		.loc 1 274 26 is_stmt 0 view .LVU140
 435 000c 0023     		movs	r3, #0
 436 000e 8360     		str	r3, [r0, #8]
 275:Src/main.c    ****   hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
 437              		.loc 1 275 3 is_stmt 1 view .LVU141
 275:Src/main.c    ****   hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
 438              		.loc 1 275 29 is_stmt 0 view .LVU142
 439 0010 0122     		movs	r2, #1
 440 0012 C260     		str	r2, [r0, #12]
 276:Src/main.c    ****   hi2c1.Init.OwnAddress2 = 0;
 441              		.loc 1 276 3 is_stmt 1 view .LVU143
 276:Src/main.c    ****   hi2c1.Init.OwnAddress2 = 0;
 442              		.loc 1 276 30 is_stmt 0 view .LVU144
 443 0014 0361     		str	r3, [r0, #16]
 277:Src/main.c    ****   hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
 444              		.loc 1 277 3 is_stmt 1 view .LVU145
 277:Src/main.c    ****   hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
 445              		.loc 1 277 26 is_stmt 0 view .LVU146
 446 0016 4361     		str	r3, [r0, #20]
 278:Src/main.c    ****   hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
 447              		.loc 1 278 3 is_stmt 1 view .LVU147
 278:Src/main.c    ****   hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
 448              		.loc 1 278 31 is_stmt 0 view .LVU148
 449 0018 8361     		str	r3, [r0, #24]
 279:Src/main.c    ****   hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
 450              		.loc 1 279 3 is_stmt 1 view .LVU149
ARM GAS  /tmp/ccbrBnXA.s 			page 23


 279:Src/main.c    ****   hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
 451              		.loc 1 279 30 is_stmt 0 view .LVU150
 452 001a C361     		str	r3, [r0, #28]
 280:Src/main.c    ****   if (HAL_I2C_Init(&hi2c1) != HAL_OK)
 453              		.loc 1 280 3 is_stmt 1 view .LVU151
 280:Src/main.c    ****   if (HAL_I2C_Init(&hi2c1) != HAL_OK)
 454              		.loc 1 280 28 is_stmt 0 view .LVU152
 455 001c 0362     		str	r3, [r0, #32]
 281:Src/main.c    ****   {
 456              		.loc 1 281 3 is_stmt 1 view .LVU153
 281:Src/main.c    ****   {
 457              		.loc 1 281 19 is_stmt 0 view .LVU154
 458 001e FFF7FEFF 		bl	HAL_I2C_Init
 459              	.LVL12:
 281:Src/main.c    ****   {
 460              		.loc 1 281 3 view .LVU155
 461 0022 50B9     		cbnz	r0, .L20
 287:Src/main.c    ****   {
 462              		.loc 1 287 3 is_stmt 1 view .LVU156
 287:Src/main.c    ****   {
 463              		.loc 1 287 35 is_stmt 0 view .LVU157
 464 0024 0021     		movs	r1, #0
 465 0026 0848     		ldr	r0, .L23
 466 0028 FFF7FEFF 		bl	HAL_I2CEx_ConfigAnalogFilter
 467              	.LVL13:
 287:Src/main.c    ****   {
 468              		.loc 1 287 3 view .LVU158
 469 002c 38B9     		cbnz	r0, .L21
 293:Src/main.c    ****   {
 470              		.loc 1 293 3 is_stmt 1 view .LVU159
 293:Src/main.c    ****   {
 471              		.loc 1 293 36 is_stmt 0 view .LVU160
 472 002e 0021     		movs	r1, #0
 473 0030 0548     		ldr	r0, .L23
 474 0032 FFF7FEFF 		bl	HAL_I2CEx_ConfigDigitalFilter
 475              	.LVL14:
 293:Src/main.c    ****   {
 476              		.loc 1 293 3 view .LVU161
 477 0036 20B9     		cbnz	r0, .L22
 301:Src/main.c    **** 
 478              		.loc 1 301 1 view .LVU162
 479 0038 08BD     		pop	{r3, pc}
 480              	.L20:
 283:Src/main.c    ****   }
 481              		.loc 1 283 5 is_stmt 1 view .LVU163
 283:Src/main.c    ****   }
 482              		.loc 1 283 18 is_stmt 0 view .LVU164
 483 003a FFF7FEFF 		bl	Error_Handler
 484              	.LVL15:
 485              	.L21:
 289:Src/main.c    ****   }
 486              		.loc 1 289 5 is_stmt 1 view .LVU165
 289:Src/main.c    ****   }
 487              		.loc 1 289 18 is_stmt 0 view .LVU166
 488 003e FFF7FEFF 		bl	Error_Handler
 489              	.LVL16:
 490              	.L22:
ARM GAS  /tmp/ccbrBnXA.s 			page 24


 295:Src/main.c    ****   }
 491              		.loc 1 295 5 is_stmt 1 view .LVU167
 295:Src/main.c    ****   }
 492              		.loc 1 295 18 is_stmt 0 view .LVU168
 493 0042 FFF7FEFF 		bl	Error_Handler
 494              	.LVL17:
 495              	.L24:
 496 0046 00BF     		.align	2
 497              	.L23:
 498 0048 00000000 		.word	.LANCHOR1
 499 004c 00540040 		.word	1073763328
 500 0050 EC9C9010 		.word	277912812
 501              		.cfi_endproc
 502              	.LFE3695:
 504              		.section	.text._ZL20MX_LPUART1_UART_Initv,"ax",%progbits
 505              		.align	1
 506              		.syntax unified
 507              		.thumb
 508              		.thumb_func
 509              		.fpu fpv4-sp-d16
 511              	_ZL20MX_LPUART1_UART_Initv:
 512              	.LFB3696:
 309:Src/main.c    **** 
 513              		.loc 1 309 1 is_stmt 1 view -0
 514              		.cfi_startproc
 515              		@ args = 0, pretend = 0, frame = 0
 516              		@ frame_needed = 0, uses_anonymous_args = 0
 517 0000 08B5     		push	{r3, lr}
 518              	.LCFI8:
 519              		.cfi_def_cfa_offset 8
 520              		.cfi_offset 3, -8
 521              		.cfi_offset 14, -4
 318:Src/main.c    ****   hlpuart1.Init.BaudRate = 209700;
 522              		.loc 1 318 3 view .LVU170
 318:Src/main.c    ****   hlpuart1.Init.BaudRate = 209700;
 523              		.loc 1 318 21 is_stmt 0 view .LVU171
 524 0002 0B48     		ldr	r0, .L29
 525 0004 0B4B     		ldr	r3, .L29+4
 526 0006 0360     		str	r3, [r0]
 319:Src/main.c    ****   hlpuart1.Init.WordLength = UART_WORDLENGTH_7B;
 527              		.loc 1 319 3 is_stmt 1 view .LVU172
 319:Src/main.c    ****   hlpuart1.Init.WordLength = UART_WORDLENGTH_7B;
 528              		.loc 1 319 26 is_stmt 0 view .LVU173
 529 0008 0B4B     		ldr	r3, .L29+8
 530 000a 4360     		str	r3, [r0, #4]
 320:Src/main.c    ****   hlpuart1.Init.StopBits = UART_STOPBITS_1;
 531              		.loc 1 320 3 is_stmt 1 view .LVU174
 320:Src/main.c    ****   hlpuart1.Init.StopBits = UART_STOPBITS_1;
 532              		.loc 1 320 28 is_stmt 0 view .LVU175
 533 000c 4FF08053 		mov	r3, #268435456
 534 0010 8360     		str	r3, [r0, #8]
 321:Src/main.c    ****   hlpuart1.Init.Parity = UART_PARITY_NONE;
 535              		.loc 1 321 3 is_stmt 1 view .LVU176
 321:Src/main.c    ****   hlpuart1.Init.Parity = UART_PARITY_NONE;
 536              		.loc 1 321 26 is_stmt 0 view .LVU177
 537 0012 0023     		movs	r3, #0
 538 0014 C360     		str	r3, [r0, #12]
ARM GAS  /tmp/ccbrBnXA.s 			page 25


 322:Src/main.c    ****   hlpuart1.Init.Mode = UART_MODE_TX_RX;
 539              		.loc 1 322 3 is_stmt 1 view .LVU178
 322:Src/main.c    ****   hlpuart1.Init.Mode = UART_MODE_TX_RX;
 540              		.loc 1 322 24 is_stmt 0 view .LVU179
 541 0016 0361     		str	r3, [r0, #16]
 323:Src/main.c    ****   hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 542              		.loc 1 323 3 is_stmt 1 view .LVU180
 323:Src/main.c    ****   hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 543              		.loc 1 323 22 is_stmt 0 view .LVU181
 544 0018 0C22     		movs	r2, #12
 545 001a 4261     		str	r2, [r0, #20]
 324:Src/main.c    ****   hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
 546              		.loc 1 324 3 is_stmt 1 view .LVU182
 324:Src/main.c    ****   hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
 547              		.loc 1 324 27 is_stmt 0 view .LVU183
 548 001c 8361     		str	r3, [r0, #24]
 325:Src/main.c    ****   hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 549              		.loc 1 325 3 is_stmt 1 view .LVU184
 325:Src/main.c    ****   hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 550              		.loc 1 325 32 is_stmt 0 view .LVU185
 551 001e 0362     		str	r3, [r0, #32]
 326:Src/main.c    ****   if (HAL_UART_Init(&hlpuart1) != HAL_OK)
 552              		.loc 1 326 3 is_stmt 1 view .LVU186
 326:Src/main.c    ****   if (HAL_UART_Init(&hlpuart1) != HAL_OK)
 553              		.loc 1 326 40 is_stmt 0 view .LVU187
 554 0020 4362     		str	r3, [r0, #36]
 327:Src/main.c    ****   {
 555              		.loc 1 327 3 is_stmt 1 view .LVU188
 327:Src/main.c    ****   {
 556              		.loc 1 327 20 is_stmt 0 view .LVU189
 557 0022 FFF7FEFF 		bl	HAL_UART_Init
 558              	.LVL18:
 327:Src/main.c    ****   {
 559              		.loc 1 327 3 view .LVU190
 560 0026 00B9     		cbnz	r0, .L28
 335:Src/main.c    **** 
 561              		.loc 1 335 1 view .LVU191
 562 0028 08BD     		pop	{r3, pc}
 563              	.L28:
 329:Src/main.c    ****   }
 564              		.loc 1 329 5 is_stmt 1 view .LVU192
 329:Src/main.c    ****   }
 565              		.loc 1 329 18 is_stmt 0 view .LVU193
 566 002a FFF7FEFF 		bl	Error_Handler
 567              	.LVL19:
 568              	.L30:
 569 002e 00BF     		.align	2
 570              	.L29:
 571 0030 00000000 		.word	.LANCHOR2
 572 0034 00800040 		.word	1073774592
 573 0038 24330300 		.word	209700
 574              		.cfi_endproc
 575              	.LFE3696:
 577              		.section	.text._ZL19MX_USART3_UART_Initv,"ax",%progbits
 578              		.align	1
 579              		.syntax unified
 580              		.thumb
ARM GAS  /tmp/ccbrBnXA.s 			page 26


 581              		.thumb_func
 582              		.fpu fpv4-sp-d16
 584              	_ZL19MX_USART3_UART_Initv:
 585              	.LFB3697:
 343:Src/main.c    **** 
 586              		.loc 1 343 1 is_stmt 1 view -0
 587              		.cfi_startproc
 588              		@ args = 0, pretend = 0, frame = 0
 589              		@ frame_needed = 0, uses_anonymous_args = 0
 590 0000 08B5     		push	{r3, lr}
 591              	.LCFI9:
 592              		.cfi_def_cfa_offset 8
 593              		.cfi_offset 3, -8
 594              		.cfi_offset 14, -4
 352:Src/main.c    ****   huart3.Init.BaudRate = 115200;
 595              		.loc 1 352 3 view .LVU195
 352:Src/main.c    ****   huart3.Init.BaudRate = 115200;
 596              		.loc 1 352 19 is_stmt 0 view .LVU196
 597 0002 0B48     		ldr	r0, .L35
 598 0004 0B4B     		ldr	r3, .L35+4
 599 0006 0360     		str	r3, [r0]
 353:Src/main.c    ****   huart3.Init.WordLength = UART_WORDLENGTH_8B;
 600              		.loc 1 353 3 is_stmt 1 view .LVU197
 353:Src/main.c    ****   huart3.Init.WordLength = UART_WORDLENGTH_8B;
 601              		.loc 1 353 24 is_stmt 0 view .LVU198
 602 0008 4FF4E133 		mov	r3, #115200
 603 000c 4360     		str	r3, [r0, #4]
 354:Src/main.c    ****   huart3.Init.StopBits = UART_STOPBITS_1;
 604              		.loc 1 354 3 is_stmt 1 view .LVU199
 354:Src/main.c    ****   huart3.Init.StopBits = UART_STOPBITS_1;
 605              		.loc 1 354 26 is_stmt 0 view .LVU200
 606 000e 0023     		movs	r3, #0
 607 0010 8360     		str	r3, [r0, #8]
 355:Src/main.c    ****   huart3.Init.Parity = UART_PARITY_NONE;
 608              		.loc 1 355 3 is_stmt 1 view .LVU201
 355:Src/main.c    ****   huart3.Init.Parity = UART_PARITY_NONE;
 609              		.loc 1 355 24 is_stmt 0 view .LVU202
 610 0012 C360     		str	r3, [r0, #12]
 356:Src/main.c    ****   huart3.Init.Mode = UART_MODE_TX_RX;
 611              		.loc 1 356 3 is_stmt 1 view .LVU203
 356:Src/main.c    ****   huart3.Init.Mode = UART_MODE_TX_RX;
 612              		.loc 1 356 22 is_stmt 0 view .LVU204
 613 0014 0361     		str	r3, [r0, #16]
 357:Src/main.c    ****   huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 614              		.loc 1 357 3 is_stmt 1 view .LVU205
 357:Src/main.c    ****   huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 615              		.loc 1 357 20 is_stmt 0 view .LVU206
 616 0016 0C22     		movs	r2, #12
 617 0018 4261     		str	r2, [r0, #20]
 358:Src/main.c    ****   huart3.Init.OverSampling = UART_OVERSAMPLING_16;
 618              		.loc 1 358 3 is_stmt 1 view .LVU207
 358:Src/main.c    ****   huart3.Init.OverSampling = UART_OVERSAMPLING_16;
 619              		.loc 1 358 25 is_stmt 0 view .LVU208
 620 001a 8361     		str	r3, [r0, #24]
 359:Src/main.c    ****   huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
 621              		.loc 1 359 3 is_stmt 1 view .LVU209
 359:Src/main.c    ****   huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
ARM GAS  /tmp/ccbrBnXA.s 			page 27


 622              		.loc 1 359 28 is_stmt 0 view .LVU210
 623 001c C361     		str	r3, [r0, #28]
 360:Src/main.c    ****   huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 624              		.loc 1 360 3 is_stmt 1 view .LVU211
 360:Src/main.c    ****   huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 625              		.loc 1 360 30 is_stmt 0 view .LVU212
 626 001e 0362     		str	r3, [r0, #32]
 361:Src/main.c    ****   if (HAL_UART_Init(&huart3) != HAL_OK)
 627              		.loc 1 361 3 is_stmt 1 view .LVU213
 361:Src/main.c    ****   if (HAL_UART_Init(&huart3) != HAL_OK)
 628              		.loc 1 361 38 is_stmt 0 view .LVU214
 629 0020 4362     		str	r3, [r0, #36]
 362:Src/main.c    ****   {
 630              		.loc 1 362 3 is_stmt 1 view .LVU215
 362:Src/main.c    ****   {
 631              		.loc 1 362 20 is_stmt 0 view .LVU216
 632 0022 FFF7FEFF 		bl	HAL_UART_Init
 633              	.LVL20:
 362:Src/main.c    ****   {
 634              		.loc 1 362 3 view .LVU217
 635 0026 00B9     		cbnz	r0, .L34
 370:Src/main.c    **** 
 636              		.loc 1 370 1 view .LVU218
 637 0028 08BD     		pop	{r3, pc}
 638              	.L34:
 364:Src/main.c    ****   }
 639              		.loc 1 364 5 is_stmt 1 view .LVU219
 364:Src/main.c    ****   }
 640              		.loc 1 364 18 is_stmt 0 view .LVU220
 641 002a FFF7FEFF 		bl	Error_Handler
 642              	.LVL21:
 643              	.L36:
 644 002e 00BF     		.align	2
 645              	.L35:
 646 0030 00000000 		.word	.LANCHOR3
 647 0034 00480040 		.word	1073760256
 648              		.cfi_endproc
 649              	.LFE3697:
 651              		.section	.text._ZL12MX_SPI2_Initv,"ax",%progbits
 652              		.align	1
 653              		.syntax unified
 654              		.thumb
 655              		.thumb_func
 656              		.fpu fpv4-sp-d16
 658              	_ZL12MX_SPI2_Initv:
 659              	.LFB3698:
 378:Src/main.c    **** 
 660              		.loc 1 378 1 is_stmt 1 view -0
 661              		.cfi_startproc
 662              		@ args = 0, pretend = 0, frame = 0
 663              		@ frame_needed = 0, uses_anonymous_args = 0
 664 0000 08B5     		push	{r3, lr}
 665              	.LCFI10:
 666              		.cfi_def_cfa_offset 8
 667              		.cfi_offset 3, -8
 668              		.cfi_offset 14, -4
 388:Src/main.c    ****   hspi2.Init.Mode = SPI_MODE_MASTER;
ARM GAS  /tmp/ccbrBnXA.s 			page 28


 669              		.loc 1 388 3 view .LVU222
 388:Src/main.c    ****   hspi2.Init.Mode = SPI_MODE_MASTER;
 670              		.loc 1 388 18 is_stmt 0 view .LVU223
 671 0002 0F48     		ldr	r0, .L41
 672 0004 0F4B     		ldr	r3, .L41+4
 673 0006 0360     		str	r3, [r0]
 389:Src/main.c    ****   hspi2.Init.Direction = SPI_DIRECTION_2LINES;
 674              		.loc 1 389 3 is_stmt 1 view .LVU224
 389:Src/main.c    ****   hspi2.Init.Direction = SPI_DIRECTION_2LINES;
 675              		.loc 1 389 19 is_stmt 0 view .LVU225
 676 0008 4FF48273 		mov	r3, #260
 677 000c 4360     		str	r3, [r0, #4]
 390:Src/main.c    ****   hspi2.Init.DataSize = SPI_DATASIZE_4BIT;
 678              		.loc 1 390 3 is_stmt 1 view .LVU226
 390:Src/main.c    ****   hspi2.Init.DataSize = SPI_DATASIZE_4BIT;
 679              		.loc 1 390 24 is_stmt 0 view .LVU227
 680 000e 0023     		movs	r3, #0
 681 0010 8360     		str	r3, [r0, #8]
 391:Src/main.c    ****   hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
 682              		.loc 1 391 3 is_stmt 1 view .LVU228
 391:Src/main.c    ****   hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
 683              		.loc 1 391 23 is_stmt 0 view .LVU229
 684 0012 4FF44072 		mov	r2, #768
 685 0016 C260     		str	r2, [r0, #12]
 392:Src/main.c    ****   hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
 686              		.loc 1 392 3 is_stmt 1 view .LVU230
 392:Src/main.c    ****   hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
 687              		.loc 1 392 26 is_stmt 0 view .LVU231
 688 0018 0361     		str	r3, [r0, #16]
 393:Src/main.c    ****   hspi2.Init.NSS = SPI_NSS_SOFT;
 689              		.loc 1 393 3 is_stmt 1 view .LVU232
 393:Src/main.c    ****   hspi2.Init.NSS = SPI_NSS_SOFT;
 690              		.loc 1 393 23 is_stmt 0 view .LVU233
 691 001a 4361     		str	r3, [r0, #20]
 394:Src/main.c    ****   hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
 692              		.loc 1 394 3 is_stmt 1 view .LVU234
 394:Src/main.c    ****   hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
 693              		.loc 1 394 18 is_stmt 0 view .LVU235
 694 001c 4FF40072 		mov	r2, #512
 695 0020 8261     		str	r2, [r0, #24]
 395:Src/main.c    ****   hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
 696              		.loc 1 395 3 is_stmt 1 view .LVU236
 395:Src/main.c    ****   hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
 697              		.loc 1 395 32 is_stmt 0 view .LVU237
 698 0022 C361     		str	r3, [r0, #28]
 396:Src/main.c    ****   hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
 699              		.loc 1 396 3 is_stmt 1 view .LVU238
 396:Src/main.c    ****   hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
 700              		.loc 1 396 23 is_stmt 0 view .LVU239
 701 0024 0362     		str	r3, [r0, #32]
 397:Src/main.c    ****   hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
 702              		.loc 1 397 3 is_stmt 1 view .LVU240
 397:Src/main.c    ****   hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
 703              		.loc 1 397 21 is_stmt 0 view .LVU241
 704 0026 4362     		str	r3, [r0, #36]
 398:Src/main.c    ****   hspi2.Init.CRCPolynomial = 7;
 705              		.loc 1 398 3 is_stmt 1 view .LVU242
ARM GAS  /tmp/ccbrBnXA.s 			page 29


 398:Src/main.c    ****   hspi2.Init.CRCPolynomial = 7;
 706              		.loc 1 398 29 is_stmt 0 view .LVU243
 707 0028 8362     		str	r3, [r0, #40]
 399:Src/main.c    ****   hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
 708              		.loc 1 399 3 is_stmt 1 view .LVU244
 399:Src/main.c    ****   hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
 709              		.loc 1 399 28 is_stmt 0 view .LVU245
 710 002a 0722     		movs	r2, #7
 711 002c C262     		str	r2, [r0, #44]
 400:Src/main.c    ****   hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
 712              		.loc 1 400 3 is_stmt 1 view .LVU246
 400:Src/main.c    ****   hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
 713              		.loc 1 400 24 is_stmt 0 view .LVU247
 714 002e 0363     		str	r3, [r0, #48]
 401:Src/main.c    ****   if (HAL_SPI_Init(&hspi2) != HAL_OK)
 715              		.loc 1 401 3 is_stmt 1 view .LVU248
 401:Src/main.c    ****   if (HAL_SPI_Init(&hspi2) != HAL_OK)
 716              		.loc 1 401 23 is_stmt 0 view .LVU249
 717 0030 0823     		movs	r3, #8
 718 0032 4363     		str	r3, [r0, #52]
 402:Src/main.c    ****   {
 719              		.loc 1 402 3 is_stmt 1 view .LVU250
 402:Src/main.c    ****   {
 720              		.loc 1 402 19 is_stmt 0 view .LVU251
 721 0034 FFF7FEFF 		bl	HAL_SPI_Init
 722              	.LVL22:
 402:Src/main.c    ****   {
 723              		.loc 1 402 3 view .LVU252
 724 0038 00B9     		cbnz	r0, .L40
 410:Src/main.c    **** 
 725              		.loc 1 410 1 view .LVU253
 726 003a 08BD     		pop	{r3, pc}
 727              	.L40:
 404:Src/main.c    ****   }
 728              		.loc 1 404 5 is_stmt 1 view .LVU254
 404:Src/main.c    ****   }
 729              		.loc 1 404 18 is_stmt 0 view .LVU255
 730 003c FFF7FEFF 		bl	Error_Handler
 731              	.LVL23:
 732              	.L42:
 733              		.align	2
 734              	.L41:
 735 0040 00000000 		.word	.LANCHOR4
 736 0044 00380040 		.word	1073756160
 737              		.cfi_endproc
 738              	.LFE3698:
 740              		.section	.text._ZL12MX_TIM2_Initv,"ax",%progbits
 741              		.align	1
 742              		.syntax unified
 743              		.thumb
 744              		.thumb_func
 745              		.fpu fpv4-sp-d16
 747              	_ZL12MX_TIM2_Initv:
 748              	.LFB3699:
 418:Src/main.c    **** 
 749              		.loc 1 418 1 is_stmt 1 view -0
 750              		.cfi_startproc
ARM GAS  /tmp/ccbrBnXA.s 			page 30


 751              		@ args = 0, pretend = 0, frame = 32
 752              		@ frame_needed = 0, uses_anonymous_args = 0
 753 0000 00B5     		push	{lr}
 754              	.LCFI11:
 755              		.cfi_def_cfa_offset 4
 756              		.cfi_offset 14, -4
 757 0002 89B0     		sub	sp, sp, #36
 758              	.LCFI12:
 759              		.cfi_def_cfa_offset 40
 424:Src/main.c    ****   TIM_MasterConfigTypeDef sMasterConfig = {0};
 760              		.loc 1 424 3 view .LVU257
 424:Src/main.c    ****   TIM_MasterConfigTypeDef sMasterConfig = {0};
 761              		.loc 1 424 26 is_stmt 0 view .LVU258
 762 0004 0023     		movs	r3, #0
 763 0006 0493     		str	r3, [sp, #16]
 764 0008 0593     		str	r3, [sp, #20]
 765 000a 0693     		str	r3, [sp, #24]
 766 000c 0793     		str	r3, [sp, #28]
 425:Src/main.c    **** 
 767              		.loc 1 425 3 is_stmt 1 view .LVU259
 425:Src/main.c    **** 
 768              		.loc 1 425 27 is_stmt 0 view .LVU260
 769 000e 0193     		str	r3, [sp, #4]
 770 0010 0293     		str	r3, [sp, #8]
 771 0012 0393     		str	r3, [sp, #12]
 430:Src/main.c    ****   htim2.Init.Prescaler = 0;
 772              		.loc 1 430 3 is_stmt 1 view .LVU261
 430:Src/main.c    ****   htim2.Init.Prescaler = 0;
 773              		.loc 1 430 18 is_stmt 0 view .LVU262
 774 0014 1348     		ldr	r0, .L51
 775 0016 4FF08042 		mov	r2, #1073741824
 776 001a 0260     		str	r2, [r0]
 431:Src/main.c    ****   htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
 777              		.loc 1 431 3 is_stmt 1 view .LVU263
 431:Src/main.c    ****   htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
 778              		.loc 1 431 24 is_stmt 0 view .LVU264
 779 001c 4360     		str	r3, [r0, #4]
 432:Src/main.c    ****   htim2.Init.Period = 4294967295;
 780              		.loc 1 432 3 is_stmt 1 view .LVU265
 432:Src/main.c    ****   htim2.Init.Period = 4294967295;
 781              		.loc 1 432 26 is_stmt 0 view .LVU266
 782 001e 8360     		str	r3, [r0, #8]
 433:Src/main.c    ****   htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
 783              		.loc 1 433 3 is_stmt 1 view .LVU267
 433:Src/main.c    ****   htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
 784              		.loc 1 433 21 is_stmt 0 view .LVU268
 785 0020 4FF0FF32 		mov	r2, #-1
 786 0024 C260     		str	r2, [r0, #12]
 434:Src/main.c    ****   htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
 787              		.loc 1 434 3 is_stmt 1 view .LVU269
 434:Src/main.c    ****   htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
 788              		.loc 1 434 28 is_stmt 0 view .LVU270
 789 0026 0361     		str	r3, [r0, #16]
 435:Src/main.c    ****   if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
 790              		.loc 1 435 3 is_stmt 1 view .LVU271
 435:Src/main.c    ****   if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
 791              		.loc 1 435 32 is_stmt 0 view .LVU272
ARM GAS  /tmp/ccbrBnXA.s 			page 31


 792 0028 8361     		str	r3, [r0, #24]
 436:Src/main.c    ****   {
 793              		.loc 1 436 3 is_stmt 1 view .LVU273
 436:Src/main.c    ****   {
 794              		.loc 1 436 24 is_stmt 0 view .LVU274
 795 002a FFF7FEFF 		bl	HAL_TIM_Base_Init
 796              	.LVL24:
 436:Src/main.c    ****   {
 797              		.loc 1 436 3 view .LVU275
 798 002e 90B9     		cbnz	r0, .L48
 440:Src/main.c    ****   if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
 799              		.loc 1 440 3 is_stmt 1 view .LVU276
 440:Src/main.c    ****   if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
 800              		.loc 1 440 34 is_stmt 0 view .LVU277
 801 0030 4FF48053 		mov	r3, #4096
 802 0034 0493     		str	r3, [sp, #16]
 441:Src/main.c    ****   {
 803              		.loc 1 441 3 is_stmt 1 view .LVU278
 441:Src/main.c    ****   {
 804              		.loc 1 441 32 is_stmt 0 view .LVU279
 805 0036 04A9     		add	r1, sp, #16
 806 0038 0A48     		ldr	r0, .L51
 807 003a FFF7FEFF 		bl	HAL_TIM_ConfigClockSource
 808              	.LVL25:
 441:Src/main.c    ****   {
 809              		.loc 1 441 3 view .LVU280
 810 003e 60B9     		cbnz	r0, .L49
 445:Src/main.c    ****   sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
 811              		.loc 1 445 3 is_stmt 1 view .LVU281
 445:Src/main.c    ****   sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
 812              		.loc 1 445 37 is_stmt 0 view .LVU282
 813 0040 0023     		movs	r3, #0
 814 0042 0193     		str	r3, [sp, #4]
 446:Src/main.c    ****   if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
 815              		.loc 1 446 3 is_stmt 1 view .LVU283
 446:Src/main.c    ****   if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
 816              		.loc 1 446 33 is_stmt 0 view .LVU284
 817 0044 0393     		str	r3, [sp, #12]
 447:Src/main.c    ****   {
 818              		.loc 1 447 3 is_stmt 1 view .LVU285
 447:Src/main.c    ****   {
 819              		.loc 1 447 44 is_stmt 0 view .LVU286
 820 0046 01A9     		add	r1, sp, #4
 821 0048 0648     		ldr	r0, .L51
 822 004a FFF7FEFF 		bl	HAL_TIMEx_MasterConfigSynchronization
 823              	.LVL26:
 447:Src/main.c    ****   {
 824              		.loc 1 447 3 view .LVU287
 825 004e 30B9     		cbnz	r0, .L50
 455:Src/main.c    **** 
 826              		.loc 1 455 1 view .LVU288
 827 0050 09B0     		add	sp, sp, #36
 828              	.LCFI13:
 829              		.cfi_remember_state
 830              		.cfi_def_cfa_offset 4
 831              		@ sp needed
 832 0052 5DF804FB 		ldr	pc, [sp], #4
ARM GAS  /tmp/ccbrBnXA.s 			page 32


 833              	.L48:
 834              	.LCFI14:
 835              		.cfi_restore_state
 438:Src/main.c    ****   }
 836              		.loc 1 438 5 is_stmt 1 view .LVU289
 438:Src/main.c    ****   }
 837              		.loc 1 438 18 is_stmt 0 view .LVU290
 838 0056 FFF7FEFF 		bl	Error_Handler
 839              	.LVL27:
 840              	.L49:
 443:Src/main.c    ****   }
 841              		.loc 1 443 5 is_stmt 1 view .LVU291
 443:Src/main.c    ****   }
 842              		.loc 1 443 18 is_stmt 0 view .LVU292
 843 005a FFF7FEFF 		bl	Error_Handler
 844              	.LVL28:
 845              	.L50:
 449:Src/main.c    ****   }
 846              		.loc 1 449 5 is_stmt 1 view .LVU293
 449:Src/main.c    ****   }
 847              		.loc 1 449 18 is_stmt 0 view .LVU294
 848 005e FFF7FEFF 		bl	Error_Handler
 849              	.LVL29:
 850              	.L52:
 851 0062 00BF     		.align	2
 852              	.L51:
 853 0064 00000000 		.word	.LANCHOR5
 854              		.cfi_endproc
 855              	.LFE3699:
 857              		.section	.text.SystemClock_Config,"ax",%progbits
 858              		.align	1
 859              		.global	SystemClock_Config
 860              		.syntax unified
 861              		.thumb
 862              		.thumb_func
 863              		.fpu fpv4-sp-d16
 865              	SystemClock_Config:
 866              	.LFB3693:
 138:Src/main.c    ****   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
 867              		.loc 1 138 1 is_stmt 1 view -0
 868              		.cfi_startproc
 869              		@ args = 0, pretend = 0, frame = 192
 870              		@ frame_needed = 0, uses_anonymous_args = 0
 871 0000 00B5     		push	{lr}
 872              	.LCFI15:
 873              		.cfi_def_cfa_offset 4
 874              		.cfi_offset 14, -4
 875 0002 B1B0     		sub	sp, sp, #196
 876              	.LCFI16:
 877              		.cfi_def_cfa_offset 200
 139:Src/main.c    ****   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
 878              		.loc 1 139 3 view .LVU296
 139:Src/main.c    ****   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
 879              		.loc 1 139 22 is_stmt 0 view .LVU297
 880 0004 2422     		movs	r2, #36
 881 0006 0021     		movs	r1, #0
 882 0008 20A8     		add	r0, sp, #128
ARM GAS  /tmp/ccbrBnXA.s 			page 33


 883 000a FFF7FEFF 		bl	memset
 884              	.LVL30:
 140:Src/main.c    ****   RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
 885              		.loc 1 140 3 is_stmt 1 view .LVU298
 140:Src/main.c    ****   RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
 886              		.loc 1 140 22 is_stmt 0 view .LVU299
 887 000e 0021     		movs	r1, #0
 888 0010 1A91     		str	r1, [sp, #104]
 889 0012 1B91     		str	r1, [sp, #108]
 890 0014 1C91     		str	r1, [sp, #112]
 891 0016 1D91     		str	r1, [sp, #116]
 892 0018 1E91     		str	r1, [sp, #120]
 141:Src/main.c    **** 
 893              		.loc 1 141 3 is_stmt 1 view .LVU300
 141:Src/main.c    **** 
 894              		.loc 1 141 28 is_stmt 0 view .LVU301
 895 001a 6822     		movs	r2, #104
 896 001c 6846     		mov	r0, sp
 897 001e FFF7FEFF 		bl	memset
 898              	.LVL31:
 146:Src/main.c    ****   RCC_OscInitStruct.MSIState = RCC_MSI_ON;
 899              		.loc 1 146 3 is_stmt 1 view .LVU302
 146:Src/main.c    ****   RCC_OscInitStruct.MSIState = RCC_MSI_ON;
 900              		.loc 1 146 36 is_stmt 0 view .LVU303
 901 0022 1023     		movs	r3, #16
 902 0024 1F93     		str	r3, [sp, #124]
 147:Src/main.c    ****   RCC_OscInitStruct.MSICalibrationValue = 0;
 903              		.loc 1 147 3 is_stmt 1 view .LVU304
 147:Src/main.c    ****   RCC_OscInitStruct.MSICalibrationValue = 0;
 904              		.loc 1 147 30 is_stmt 0 view .LVU305
 905 0026 0122     		movs	r2, #1
 906 0028 2592     		str	r2, [sp, #148]
 148:Src/main.c    ****   RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
 907              		.loc 1 148 3 is_stmt 1 view .LVU306
 149:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
 908              		.loc 1 149 3 view .LVU307
 149:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
 909              		.loc 1 149 35 is_stmt 0 view .LVU308
 910 002a 6023     		movs	r3, #96
 911 002c 2793     		str	r3, [sp, #156]
 150:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
 912              		.loc 1 150 3 is_stmt 1 view .LVU309
 150:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
 913              		.loc 1 150 34 is_stmt 0 view .LVU310
 914 002e 0223     		movs	r3, #2
 915 0030 2993     		str	r3, [sp, #164]
 151:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLM = 1;
 916              		.loc 1 151 3 is_stmt 1 view .LVU311
 151:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLM = 1;
 917              		.loc 1 151 35 is_stmt 0 view .LVU312
 918 0032 2A92     		str	r2, [sp, #168]
 152:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLN = 40;
 919              		.loc 1 152 3 is_stmt 1 view .LVU313
 152:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLN = 40;
 920              		.loc 1 152 30 is_stmt 0 view .LVU314
 921 0034 2B92     		str	r2, [sp, #172]
 153:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
ARM GAS  /tmp/ccbrBnXA.s 			page 34


 922              		.loc 1 153 3 is_stmt 1 view .LVU315
 153:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
 923              		.loc 1 153 30 is_stmt 0 view .LVU316
 924 0036 2822     		movs	r2, #40
 925 0038 2C92     		str	r2, [sp, #176]
 154:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
 926              		.loc 1 154 3 is_stmt 1 view .LVU317
 154:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
 927              		.loc 1 154 30 is_stmt 0 view .LVU318
 928 003a 0722     		movs	r2, #7
 929 003c 2D92     		str	r2, [sp, #180]
 155:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
 930              		.loc 1 155 3 is_stmt 1 view .LVU319
 155:Src/main.c    ****   RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
 931              		.loc 1 155 30 is_stmt 0 view .LVU320
 932 003e 2E93     		str	r3, [sp, #184]
 156:Src/main.c    ****   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
 933              		.loc 1 156 3 is_stmt 1 view .LVU321
 156:Src/main.c    ****   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
 934              		.loc 1 156 30 is_stmt 0 view .LVU322
 935 0040 2F93     		str	r3, [sp, #188]
 157:Src/main.c    ****   {
 936              		.loc 1 157 3 is_stmt 1 view .LVU323
 157:Src/main.c    ****   {
 937              		.loc 1 157 24 is_stmt 0 view .LVU324
 938 0042 1FA8     		add	r0, sp, #124
 939 0044 FFF7FEFF 		bl	HAL_RCC_OscConfig
 940              	.LVL32:
 157:Src/main.c    ****   {
 941              		.loc 1 157 3 view .LVU325
 942 0048 0028     		cmp	r0, #0
 943 004a 32D1     		bne	.L59
 163:Src/main.c    ****                               |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
 944              		.loc 1 163 3 is_stmt 1 view .LVU326
 163:Src/main.c    ****                               |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
 945              		.loc 1 163 31 is_stmt 0 view .LVU327
 946 004c 0F23     		movs	r3, #15
 947 004e 1A93     		str	r3, [sp, #104]
 165:Src/main.c    ****   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
 948              		.loc 1 165 3 is_stmt 1 view .LVU328
 165:Src/main.c    ****   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
 949              		.loc 1 165 34 is_stmt 0 view .LVU329
 950 0050 0323     		movs	r3, #3
 951 0052 1B93     		str	r3, [sp, #108]
 166:Src/main.c    ****   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 952              		.loc 1 166 3 is_stmt 1 view .LVU330
 166:Src/main.c    ****   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 953              		.loc 1 166 35 is_stmt 0 view .LVU331
 954 0054 0023     		movs	r3, #0
 955 0056 1C93     		str	r3, [sp, #112]
 167:Src/main.c    ****   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
 956              		.loc 1 167 3 is_stmt 1 view .LVU332
 167:Src/main.c    ****   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
 957              		.loc 1 167 36 is_stmt 0 view .LVU333
 958 0058 1D93     		str	r3, [sp, #116]
 168:Src/main.c    **** 
 959              		.loc 1 168 3 is_stmt 1 view .LVU334
ARM GAS  /tmp/ccbrBnXA.s 			page 35


 168:Src/main.c    **** 
 960              		.loc 1 168 36 is_stmt 0 view .LVU335
 961 005a 1E93     		str	r3, [sp, #120]
 170:Src/main.c    ****   {
 962              		.loc 1 170 3 is_stmt 1 view .LVU336
 170:Src/main.c    ****   {
 963              		.loc 1 170 26 is_stmt 0 view .LVU337
 964 005c 0421     		movs	r1, #4
 965 005e 1AA8     		add	r0, sp, #104
 966 0060 FFF7FEFF 		bl	HAL_RCC_ClockConfig
 967              	.LVL33:
 170:Src/main.c    ****   {
 968              		.loc 1 170 3 view .LVU338
 969 0064 38BB     		cbnz	r0, .L60
 174:Src/main.c    ****                               |RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_USB
 970              		.loc 1 174 3 is_stmt 1 view .LVU339
 174:Src/main.c    ****                               |RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_USB
 971              		.loc 1 174 38 is_stmt 0 view .LVU340
 972 0066 46F26403 		movw	r3, #24676
 973 006a 0093     		str	r3, [sp]
 177:Src/main.c    ****   PeriphClkInit.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PCLK1;
 974              		.loc 1 177 3 is_stmt 1 view .LVU341
 177:Src/main.c    ****   PeriphClkInit.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PCLK1;
 975              		.loc 1 177 38 is_stmt 0 view .LVU342
 976 006c 0023     		movs	r3, #0
 977 006e 0A93     		str	r3, [sp, #40]
 178:Src/main.c    ****   PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
 978              		.loc 1 178 3 is_stmt 1 view .LVU343
 178:Src/main.c    ****   PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
 979              		.loc 1 178 39 is_stmt 0 view .LVU344
 980 0070 0C93     		str	r3, [sp, #48]
 179:Src/main.c    ****   PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
 981              		.loc 1 179 3 is_stmt 1 view .LVU345
 179:Src/main.c    ****   PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
 982              		.loc 1 179 36 is_stmt 0 view .LVU346
 983 0072 0D93     		str	r3, [sp, #52]
 180:Src/main.c    ****   PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
 984              		.loc 1 180 3 is_stmt 1 view .LVU347
 180:Src/main.c    ****   PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
 985              		.loc 1 180 35 is_stmt 0 view .LVU348
 986 0074 4FF08053 		mov	r3, #268435456
 987 0078 1793     		str	r3, [sp, #92]
 181:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;
 988              		.loc 1 181 3 is_stmt 1 view .LVU349
 181:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;
 989              		.loc 1 181 35 is_stmt 0 view .LVU350
 990 007a 4FF08063 		mov	r3, #67108864
 991 007e 1493     		str	r3, [sp, #80]
 182:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
 992              		.loc 1 182 3 is_stmt 1 view .LVU351
 182:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
 993              		.loc 1 182 39 is_stmt 0 view .LVU352
 994 0080 0123     		movs	r3, #1
 995 0082 0193     		str	r3, [sp, #4]
 183:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1N = 24;
 996              		.loc 1 183 3 is_stmt 1 view .LVU353
 183:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1N = 24;
ARM GAS  /tmp/ccbrBnXA.s 			page 36


 997              		.loc 1 183 34 is_stmt 0 view .LVU354
 998 0084 0293     		str	r3, [sp, #8]
 184:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
 999              		.loc 1 184 3 is_stmt 1 view .LVU355
 184:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
 1000              		.loc 1 184 34 is_stmt 0 view .LVU356
 1001 0086 1823     		movs	r3, #24
 1002 0088 0393     		str	r3, [sp, #12]
 185:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
 1003              		.loc 1 185 3 is_stmt 1 view .LVU357
 185:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
 1004              		.loc 1 185 34 is_stmt 0 view .LVU358
 1005 008a 0723     		movs	r3, #7
 1006 008c 0493     		str	r3, [sp, #16]
 186:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
 1007              		.loc 1 186 3 is_stmt 1 view .LVU359
 186:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
 1008              		.loc 1 186 34 is_stmt 0 view .LVU360
 1009 008e 0223     		movs	r3, #2
 1010 0090 0593     		str	r3, [sp, #20]
 187:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK|RCC_PLLSAI1_ADC1CLK;
 1011              		.loc 1 187 3 is_stmt 1 view .LVU361
 187:Src/main.c    ****   PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK|RCC_PLLSAI1_ADC1CLK;
 1012              		.loc 1 187 34 is_stmt 0 view .LVU362
 1013 0092 0693     		str	r3, [sp, #24]
 188:Src/main.c    ****   if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
 1014              		.loc 1 188 3 is_stmt 1 view .LVU363
 188:Src/main.c    ****   if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
 1015              		.loc 1 188 41 is_stmt 0 view .LVU364
 1016 0094 4FF08873 		mov	r3, #17825792
 1017 0098 0793     		str	r3, [sp, #28]
 189:Src/main.c    ****   {
 1018              		.loc 1 189 3 is_stmt 1 view .LVU365
 189:Src/main.c    ****   {
 1019              		.loc 1 189 32 is_stmt 0 view .LVU366
 1020 009a 6846     		mov	r0, sp
 1021 009c FFF7FEFF 		bl	HAL_RCCEx_PeriphCLKConfig
 1022              	.LVL34:
 189:Src/main.c    ****   {
 1023              		.loc 1 189 3 view .LVU367
 1024 00a0 58B9     		cbnz	r0, .L61
 195:Src/main.c    ****   {
 1025              		.loc 1 195 3 is_stmt 1 view .LVU368
 195:Src/main.c    ****   {
 1026              		.loc 1 195 38 is_stmt 0 view .LVU369
 1027 00a2 4FF40070 		mov	r0, #512
 1028 00a6 FFF7FEFF 		bl	HAL_PWREx_ControlVoltageScaling
 1029              	.LVL35:
 195:Src/main.c    ****   {
 1030              		.loc 1 195 3 view .LVU370
 1031 00aa 40B9     		cbnz	r0, .L62
 199:Src/main.c    **** 
 1032              		.loc 1 199 1 view .LVU371
 1033 00ac 31B0     		add	sp, sp, #196
 1034              	.LCFI17:
 1035              		.cfi_remember_state
 1036              		.cfi_def_cfa_offset 4
ARM GAS  /tmp/ccbrBnXA.s 			page 37


 1037              		@ sp needed
 1038 00ae 5DF804FB 		ldr	pc, [sp], #4
 1039              	.L59:
 1040              	.LCFI18:
 1041              		.cfi_restore_state
 159:Src/main.c    ****   }
 1042              		.loc 1 159 5 is_stmt 1 view .LVU372
 159:Src/main.c    ****   }
 1043              		.loc 1 159 18 is_stmt 0 view .LVU373
 1044 00b2 FFF7FEFF 		bl	Error_Handler
 1045              	.LVL36:
 1046              	.L60:
 172:Src/main.c    ****   }
 1047              		.loc 1 172 5 is_stmt 1 view .LVU374
 172:Src/main.c    ****   }
 1048              		.loc 1 172 18 is_stmt 0 view .LVU375
 1049 00b6 FFF7FEFF 		bl	Error_Handler
 1050              	.LVL37:
 1051              	.L61:
 191:Src/main.c    ****   }
 1052              		.loc 1 191 5 is_stmt 1 view .LVU376
 191:Src/main.c    ****   }
 1053              		.loc 1 191 18 is_stmt 0 view .LVU377
 1054 00ba FFF7FEFF 		bl	Error_Handler
 1055              	.LVL38:
 1056              	.L62:
 197:Src/main.c    ****   }
 1057              		.loc 1 197 5 is_stmt 1 view .LVU378
 197:Src/main.c    ****   }
 1058              		.loc 1 197 18 is_stmt 0 view .LVU379
 1059 00be FFF7FEFF 		bl	Error_Handler
 1060              	.LVL39:
 1061              		.cfi_endproc
 1062              	.LFE3693:
 1064              		.section	.text.main,"ax",%progbits
 1065              		.align	1
 1066              		.global	main
 1067              		.syntax unified
 1068              		.thumb
 1069              		.thumb_func
 1070              		.fpu fpv4-sp-d16
 1072              	main:
 1073              	.LFB3692:
  83:Src/main.c    ****   /* USER CODE BEGIN 1 */
 1074              		.loc 1 83 1 is_stmt 1 view -0
 1075              		.cfi_startproc
 1076              		@ Volatile: function does not return.
 1077              		@ args = 0, pretend = 0, frame = 0
 1078              		@ frame_needed = 0, uses_anonymous_args = 0
 1079 0000 08B5     		push	{r3, lr}
 1080              	.LCFI19:
 1081              		.cfi_def_cfa_offset 8
 1082              		.cfi_offset 3, -8
 1083              		.cfi_offset 14, -4
  91:Src/main.c    **** 
 1084              		.loc 1 91 3 view .LVU381
  91:Src/main.c    **** 
ARM GAS  /tmp/ccbrBnXA.s 			page 38


 1085              		.loc 1 91 11 is_stmt 0 view .LVU382
 1086 0002 FFF7FEFF 		bl	HAL_Init
 1087              	.LVL40:
  98:Src/main.c    **** 
 1088              		.loc 1 98 3 is_stmt 1 view .LVU383
  98:Src/main.c    **** 
 1089              		.loc 1 98 21 is_stmt 0 view .LVU384
 1090 0006 FFF7FEFF 		bl	SystemClock_Config
 1091              	.LVL41:
 105:Src/main.c    ****   MX_ADC1_Init();
 1092              		.loc 1 105 3 is_stmt 1 view .LVU385
 105:Src/main.c    ****   MX_ADC1_Init();
 1093              		.loc 1 105 15 is_stmt 0 view .LVU386
 1094 000a FFF7FEFF 		bl	_ZL12MX_GPIO_Initv
 1095              	.LVL42:
 106:Src/main.c    ****   MX_I2C1_Init();
 1096              		.loc 1 106 3 is_stmt 1 view .LVU387
 106:Src/main.c    ****   MX_I2C1_Init();
 1097              		.loc 1 106 15 is_stmt 0 view .LVU388
 1098 000e FFF7FEFF 		bl	_ZL12MX_ADC1_Initv
 1099              	.LVL43:
 107:Src/main.c    ****   MX_LPUART1_UART_Init();
 1100              		.loc 1 107 3 is_stmt 1 view .LVU389
 107:Src/main.c    ****   MX_LPUART1_UART_Init();
 1101              		.loc 1 107 15 is_stmt 0 view .LVU390
 1102 0012 FFF7FEFF 		bl	_ZL12MX_I2C1_Initv
 1103              	.LVL44:
 108:Src/main.c    ****   MX_USART3_UART_Init();
 1104              		.loc 1 108 3 is_stmt 1 view .LVU391
 108:Src/main.c    ****   MX_USART3_UART_Init();
 1105              		.loc 1 108 23 is_stmt 0 view .LVU392
 1106 0016 FFF7FEFF 		bl	_ZL20MX_LPUART1_UART_Initv
 1107              	.LVL45:
 109:Src/main.c    ****   MX_SPI2_Init();
 1108              		.loc 1 109 3 is_stmt 1 view .LVU393
 109:Src/main.c    ****   MX_SPI2_Init();
 1109              		.loc 1 109 22 is_stmt 0 view .LVU394
 1110 001a FFF7FEFF 		bl	_ZL19MX_USART3_UART_Initv
 1111              	.LVL46:
 110:Src/main.c    ****   MX_USB_DEVICE_Init();
 1112              		.loc 1 110 3 is_stmt 1 view .LVU395
 110:Src/main.c    ****   MX_USB_DEVICE_Init();
 1113              		.loc 1 110 15 is_stmt 0 view .LVU396
 1114 001e FFF7FEFF 		bl	_ZL12MX_SPI2_Initv
 1115              	.LVL47:
 111:Src/main.c    ****   MX_TIM2_Init();
 1116              		.loc 1 111 3 is_stmt 1 view .LVU397
 111:Src/main.c    ****   MX_TIM2_Init();
 1117              		.loc 1 111 21 is_stmt 0 view .LVU398
 1118 0022 FFF7FEFF 		bl	MX_USB_DEVICE_Init
 1119              	.LVL48:
 112:Src/main.c    ****   /* USER CODE BEGIN 2 */
 1120              		.loc 1 112 3 is_stmt 1 view .LVU399
 112:Src/main.c    ****   /* USER CODE BEGIN 2 */
 1121              		.loc 1 112 15 is_stmt 0 view .LVU400
 1122 0026 FFF7FEFF 		bl	_ZL12MX_TIM2_Initv
 1123              	.LVL49:
ARM GAS  /tmp/ccbrBnXA.s 			page 39


 115:Src/main.c    **** 
 1124              		.loc 1 115 5 is_stmt 1 view .LVU401
 115:Src/main.c    **** 
 1125              		.loc 1 115 14 is_stmt 0 view .LVU402
 1126 002a 0120     		movs	r0, #1
 1127 002c FFF7FEFF 		bl	HAL_Delay
 1128              	.LVL50:
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1129              		.loc 1 117 5 is_stmt 1 view .LVU403
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1130              		.loc 1 117 25 is_stmt 0 view .LVU404
 1131 0030 FFF7FEFF 		bl	_Z6devicev
 1132              	.LVL51:
 1133 0034 0446     		mov	r4, r0
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1134              		.loc 1 117 32 view .LVU405
 1135 0036 FFF7FEFF 		bl	_Z6devicev
 1136              	.LVL52:
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1137              		.loc 1 117 36 view .LVU406
 1138 003a 0368     		ldr	r3, [r0]
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1139              		.loc 1 117 25 view .LVU407
 1140 003c D969     		ldr	r1, [r3, #28]
 1141 003e 2046     		mov	r0, r4
 1142 0040 FFF7FEFF 		bl	_ZN6Device10Enable_CLIEP11Serial_line
 1143              	.LVL53:
 118:Src/main.c    ****     device()->cli->Enable_filesystem_executable(device()->fs);
 1144              		.loc 1 118 5 is_stmt 1 view .LVU408
 118:Src/main.c    ****     device()->cli->Enable_filesystem_executable(device()->fs);
 1145              		.loc 1 118 32 is_stmt 0 view .LVU409
 1146 0044 FFF7FEFF 		bl	_Z6devicev
 1147              	.LVL54:
 1148 0048 FFF7FEFF 		bl	_ZN6Device17Enable_FilesystemEv
 1149              	.LVL55:
 119:Src/main.c    **** 
 1150              		.loc 1 119 5 is_stmt 1 view .LVU410
 119:Src/main.c    **** 
 1151              		.loc 1 119 11 is_stmt 0 view .LVU411
 1152 004c FFF7FEFF 		bl	_Z6devicev
 1153              	.LVL56:
 119:Src/main.c    **** 
 1154              		.loc 1 119 15 view .LVU412
 1155 0050 4468     		ldr	r4, [r0, #4]
 119:Src/main.c    **** 
 1156              		.loc 1 119 55 view .LVU413
 1157 0052 FFF7FEFF 		bl	_Z6devicev
 1158              	.LVL57:
 119:Src/main.c    **** 
 1159              		.loc 1 119 48 view .LVU414
 1160 0056 8168     		ldr	r1, [r0, #8]
 1161 0058 2046     		mov	r0, r4
 1162 005a FFF7FEFF 		bl	_ZN3CLI28Enable_filesystem_executableEP10Filesystem
 1163              	.LVL58:
 1164              	.L64:
 125:Src/main.c    ****     /* USER CODE END WHILE */
 1165              		.loc 1 125 5 is_stmt 1 discriminator 1 view .LVU415
ARM GAS  /tmp/ccbrBnXA.s 			page 40


 125:Src/main.c    ****     /* USER CODE END WHILE */
 1166              		.loc 1 125 5 discriminator 1 view .LVU416
 1167 005e FEE7     		b	.L64
 1168              		.cfi_endproc
 1169              	.LFE3692:
 1171              		.global	htim2
 1172              		.global	hspi2
 1173              		.global	huart3
 1174              		.global	hlpuart1
 1175              		.global	hi2c1
 1176              		.global	hadc1
 1177              		.section	.bss.hadc1,"aw",%nobits
 1178              		.align	2
 1179              		.set	.LANCHOR0,. + 0
 1182              	hadc1:
 1183 0000 00000000 		.space	104
 1183      00000000 
 1183      00000000 
 1183      00000000 
 1183      00000000 
 1184              		.section	.bss.hi2c1,"aw",%nobits
 1185              		.align	2
 1186              		.set	.LANCHOR1,. + 0
 1189              	hi2c1:
 1190 0000 00000000 		.space	76
 1190      00000000 
 1190      00000000 
 1190      00000000 
 1190      00000000 
 1191              		.section	.bss.hlpuart1,"aw",%nobits
 1192              		.align	2
 1193              		.set	.LANCHOR2,. + 0
 1196              	hlpuart1:
 1197 0000 00000000 		.space	128
 1197      00000000 
 1197      00000000 
 1197      00000000 
 1197      00000000 
 1198              		.section	.bss.hspi2,"aw",%nobits
 1199              		.align	2
 1200              		.set	.LANCHOR4,. + 0
 1203              	hspi2:
 1204 0000 00000000 		.space	100
 1204      00000000 
 1204      00000000 
 1204      00000000 
 1204      00000000 
 1205              		.section	.bss.htim2,"aw",%nobits
 1206              		.align	2
 1207              		.set	.LANCHOR5,. + 0
 1210              	htim2:
 1211 0000 00000000 		.space	76
 1211      00000000 
 1211      00000000 
 1211      00000000 
 1211      00000000 
 1212              		.section	.bss.huart3,"aw",%nobits
ARM GAS  /tmp/ccbrBnXA.s 			page 41


 1213              		.align	2
 1214              		.set	.LANCHOR3,. + 0
 1217              	huart3:
 1218 0000 00000000 		.space	128
 1218      00000000 
 1218      00000000 
 1218      00000000 
 1218      00000000 
 1219              		.text
 1220              	.Letext0:
 1221              		.file 3 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/machine/_default_types.h"
 1222              		.file 4 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/_stdint.h"
 1223              		.file 5 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/stdint.h"
 1224              		.file 6 "Drivers/CMSIS/Include/core_cm4.h"
 1225              		.file 7 "Drivers/CMSIS/Device/ST/STM32L4xx/Include/system_stm32l4xx.h"
 1226              		.file 8 "Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l452xx.h"
 1227              		.file 9 "Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"
 1228              		.file 10 "/opt/gcc-arm-none-eabi-9-2020-q2/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h"
 1229              		.file 11 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_def.h"
 1230              		.file 12 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_rcc.h"
 1231              		.file 13 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_rcc_ex.h"
 1232              		.file 14 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_gpio.h"
 1233              		.file 15 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_dma.h"
 1234              		.file 16 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_adc.h"
 1235              		.file 17 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_flash.h"
 1236              		.file 18 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_i2c.h"
 1237              		.file 19 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_spi.h"
 1238              		.file 20 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_tim.h"
 1239              		.file 21 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_uart.h"
 1240              		.file 22 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal.h"
 1241              		.file 23 "/opt/gcc-arm-none-eabi-9-2020-q2/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h"
 1242              		.file 24 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/_types.h"
 1243              		.file 25 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/reent.h"
 1244              		.file 26 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/lock.h"
 1245              		.file 27 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/stdio.h"
 1246              		.file 28 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h"
 1247              		.file 29 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cstdlib"
 1248              		.file 30 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/std_abs.h"
 1249              		.file 31 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/type_traits"
 1250              		.file 32 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/arm-none-eabi/thumb/v7e
 1251              		.file 33 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_pair.h"
 1252              		.file 34 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/debug/debug.h"
 1253              		.file 35 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cwchar"
 1254              		.file 36 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h"
 1255              		.file 37 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cstdint"
 1256              		.file 38 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/exception_ptr.h"
 1257              		.file 39 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/new"
 1258              		.file 40 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h"
 1259              		.file 41 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/clocale"
 1260              		.file 42 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/limits"
 1261              		.file 43 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/string_view"
 1262              		.file 44 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cstdio"
 1263              		.file 45 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h"
 1264              		.file 46 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/initializer_list"
 1265              		.file 47 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stringfwd.h"
 1266              		.file 48 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/utility"
 1267              		.file 49 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/algorithmfwd.h"
ARM GAS  /tmp/ccbrBnXA.s 			page 42


 1268              		.file 50 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/uses_allocator.h"
 1269              		.file 51 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/tuple"
 1270              		.file 52 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/optional"
 1271              		.file 53 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_function.h"
 1272              		.file 54 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/functional"
 1273              		.file 55 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_vector.h"
 1274              		.file 56 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/vector.tcc"
 1275              		.file 57 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_
 1276              		.file 58 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_tree.h"
 1277              		.file 59 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_map.h"
 1278              		.file 60 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/predefined_ops.h"
 1279              		.file 61 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h"
 1280              		.file 62 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/numeric_traits.h"
 1281              		.file 63 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/alloc_traits.h"
 1282              		.file 64 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator.h"
 1283              		.file 65 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/stdlib.h"
 1284              		.file 66 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/stdlib.h"
 1285              		.file 67 "Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"
 1286              		.file 68 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/wchar.h"
 1287              		.file 69 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/locale.h"
 1288              		.file 70 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/ctype.h"
 1289              		.file 71 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/errno.h"
 1290              		.file 72 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/pstl/execution_defs.h"
 1291              		.file 73 "alohal/globals.hpp"
 1292              		.file 74 "alohal/irq/irq_handler.hpp"
 1293              		.file 75 "alohal/irq/irq_observer.hpp"
 1294              		.file 76 "alohal/uart/serial_line.hpp"
 1295              		.file 77 "Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc/usbd_cdc.h"
 1296              		.file 78 "Inc/usbd_cdc_if.h"
 1297              		.file 79 "alohal/usb/cdc_vcp.hpp"
 1298              		.file 80 "alohal/mcu/configuration/externs.hpp"
 1299              		.file 81 "alohal/timer/TIM_channel.hpp"
 1300              		.file 82 "alohal/timer/timer.hpp"
 1301              		.file 83 "alohal/irq/irq_multi_handler.hpp"
 1302              		.file 84 "alohal/mcu/mcu.hpp"
 1303              		.file 85 "alohal/cli/command.hpp"
 1304              		.file 86 "alohal/cli/history.hpp"
 1305              		.file 87 "alohal/cli/cli.hpp"
 1306              		.file 88 "alohal/filesystem/filesystem.hpp"
 1307              		.file 89 "alohal/filesystem/entry.hpp"
 1308              		.file 90 "alohal/filesystem/directory.hpp"
 1309              		.file 91 "alohal/filesystem/executable.hpp"
 1310              		.file 92 "alohal/filesystem/file.hpp"
 1311              		.file 93 "alohal/misc/text_transform.hpp"
 1312              		.file 94 "alohal/events/planner/planner_phase.hpp"
 1313              		.file 95 "alohal/events/planner/planner.hpp"
 1314              		.file 96 "alohal/device/device.hpp"
 1315              		.file 97 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_tim_ex.h"
 1316              		.file 98 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_i2c_ex.h"
 1317              		.file 99 "Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal_pwr_ex.h"
 1318              		.file 100 "Inc/usb_device.h"
 1319              		.file 101 "<built-in>"
ARM GAS  /tmp/ccbrBnXA.s 			page 43


DEFINED SYMBOLS
                            *ABS*:0000000000000000 main.c
     /tmp/ccbrBnXA.s:18     .text._ZL12MX_GPIO_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:25     .text._ZL12MX_GPIO_Initv:0000000000000000 _ZL12MX_GPIO_Initv
     /tmp/ccbrBnXA.s:217    .text._ZL12MX_GPIO_Initv:00000000000000dc $d
     /tmp/ccbrBnXA.s:225    .text.Error_Handler:0000000000000000 $t
     /tmp/ccbrBnXA.s:232    .text.Error_Handler:0000000000000000 Error_Handler
     /tmp/ccbrBnXA.s:264    .text._ZL12MX_ADC1_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:270    .text._ZL12MX_ADC1_Initv:0000000000000000 _ZL12MX_ADC1_Initv
     /tmp/ccbrBnXA.s:400    .text._ZL12MX_ADC1_Initv:0000000000000074 $d
     /tmp/ccbrBnXA.s:407    .text._ZL12MX_I2C1_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:413    .text._ZL12MX_I2C1_Initv:0000000000000000 _ZL12MX_I2C1_Initv
     /tmp/ccbrBnXA.s:498    .text._ZL12MX_I2C1_Initv:0000000000000048 $d
     /tmp/ccbrBnXA.s:505    .text._ZL20MX_LPUART1_UART_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:511    .text._ZL20MX_LPUART1_UART_Initv:0000000000000000 _ZL20MX_LPUART1_UART_Initv
     /tmp/ccbrBnXA.s:571    .text._ZL20MX_LPUART1_UART_Initv:0000000000000030 $d
     /tmp/ccbrBnXA.s:578    .text._ZL19MX_USART3_UART_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:584    .text._ZL19MX_USART3_UART_Initv:0000000000000000 _ZL19MX_USART3_UART_Initv
     /tmp/ccbrBnXA.s:646    .text._ZL19MX_USART3_UART_Initv:0000000000000030 $d
     /tmp/ccbrBnXA.s:652    .text._ZL12MX_SPI2_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:658    .text._ZL12MX_SPI2_Initv:0000000000000000 _ZL12MX_SPI2_Initv
     /tmp/ccbrBnXA.s:735    .text._ZL12MX_SPI2_Initv:0000000000000040 $d
     /tmp/ccbrBnXA.s:741    .text._ZL12MX_TIM2_Initv:0000000000000000 $t
     /tmp/ccbrBnXA.s:747    .text._ZL12MX_TIM2_Initv:0000000000000000 _ZL12MX_TIM2_Initv
     /tmp/ccbrBnXA.s:853    .text._ZL12MX_TIM2_Initv:0000000000000064 $d
     /tmp/ccbrBnXA.s:858    .text.SystemClock_Config:0000000000000000 $t
     /tmp/ccbrBnXA.s:865    .text.SystemClock_Config:0000000000000000 SystemClock_Config
     /tmp/ccbrBnXA.s:1065   .text.main:0000000000000000 $t
     /tmp/ccbrBnXA.s:1072   .text.main:0000000000000000 main
     /tmp/ccbrBnXA.s:1210   .bss.htim2:0000000000000000 htim2
     /tmp/ccbrBnXA.s:1203   .bss.hspi2:0000000000000000 hspi2
     /tmp/ccbrBnXA.s:1217   .bss.huart3:0000000000000000 huart3
     /tmp/ccbrBnXA.s:1196   .bss.hlpuart1:0000000000000000 hlpuart1
     /tmp/ccbrBnXA.s:1189   .bss.hi2c1:0000000000000000 hi2c1
     /tmp/ccbrBnXA.s:1182   .bss.hadc1:0000000000000000 hadc1
     /tmp/ccbrBnXA.s:1178   .bss.hadc1:0000000000000000 $d
     /tmp/ccbrBnXA.s:1185   .bss.hi2c1:0000000000000000 $d
     /tmp/ccbrBnXA.s:1192   .bss.hlpuart1:0000000000000000 $d
     /tmp/ccbrBnXA.s:1199   .bss.hspi2:0000000000000000 $d
     /tmp/ccbrBnXA.s:1206   .bss.htim2:0000000000000000 $d
     /tmp/ccbrBnXA.s:1213   .bss.huart3:0000000000000000 $d

UNDEFINED SYMBOLS
HAL_GPIO_WritePin
HAL_GPIO_Init
HAL_ADC_Init
HAL_ADC_ConfigChannel
HAL_I2C_Init
HAL_I2CEx_ConfigAnalogFilter
HAL_I2CEx_ConfigDigitalFilter
HAL_UART_Init
HAL_SPI_Init
HAL_TIM_Base_Init
HAL_TIM_ConfigClockSource
HAL_TIMEx_MasterConfigSynchronization
memset
HAL_RCC_OscConfig
ARM GAS  /tmp/ccbrBnXA.s 			page 44


HAL_RCC_ClockConfig
HAL_RCCEx_PeriphCLKConfig
HAL_PWREx_ControlVoltageScaling
HAL_Init
MX_USB_DEVICE_Init
HAL_Delay
_Z6devicev
_ZN6Device10Enable_CLIEP11Serial_line
_ZN6Device17Enable_FilesystemEv
_ZN3CLI28Enable_filesystem_executableEP10Filesystem
