 /*
 * Brief:       Main file for Project Aelith running on STM32F4 devices
 *
 * Datasheet:   http://www.st.com/web/en/resource/technical/document/datasheet/DM00037051.pdf
 *
 * Ref Manual:  http://www.st.com/st-web-ui/static/active/en/resource/technical/document/reference_manual/DM00031020.pdf
 *
 * Copyright (C) 2014 Rajesh Nakarja. All rights reserved
 * http://www.naklojik.com
 *
 * This is free software; you can redistribute it and/or modify it under the 
 * terms of the GNU Lesser General Public License version 3.0.
 *
 * http://opensource.org/licenses/lgpl-3.0.html
 *
 */


#include "stm32f4xx_hal.h"
#include <prototypes.h>
#include <config.h>
#include <fuzzyController.h>
#include <rtwtypes.h>

/* Public variables */
extern PPMOutputs PPMOutputStructure;
extern RCRadio RCRadioStructure;
extern IMUMotion Motion;

/* Private variables */
IWDG_HandleTypeDef hiwdg;

/* Private function prototypes */
void SystemClock_Config(void);

int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* System tick interrupt init*/
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

  /* Configure and start IWDG */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_4;
  hiwdg.Init.Reload = 2047;
  HAL_IWDG_Init(&hiwdg);
  HAL_IWDG_Start(&hiwdg);

  /* Init vehicle functions */
  initSerial();
  initIO();
  initADC(); 
  initIMU();
  
  /* Start up the controller */
  fuzzyController_initialize();

  /* Intro message */
  sendSerialString("\n");
  sendSerialString("Aelith Controller Ready\n");
  sendSerialString("(C) NakLojik 2014\n");
  sendSerialString("Enjoy your drive!\n");
  sendSerialString("\n");

  while(1)
  {
        
        IMUGetMotion();

        /* Send inputs into the controller */
        fuzzyController_U.gyroYaw = Motion.yaw/DEFAULTGYRORANGE;          
        fuzzyController_U.steeringSignal = RCRadioStructure.steering;   
        fuzzyController_U.throttleSignal = RCRadioStructure.throttle;   
        fuzzyController_U.frontDifferential = FRONTSLIP;
        fuzzyController_U.rearDifferential = REARSLIP; 
        fuzzyController_U.powerBias = POWERBIAS; 

        /* Run the controller */ 
        fuzzyController_step();

        /* Apply outputs from controller */
        PPMOutputStructure.AUX4 = fuzzyController_Y.steeringOutput;
        PPMOutputStructure.MOT1 = fuzzyController_Y.FLWheelOutput;
        PPMOutputStructure.MOT2 = fuzzyController_Y.FRWheelOutput;
        PPMOutputStructure.MOT3 = fuzzyController_Y.BLWheelOutput;
        PPMOutputStructure.MOT4 = fuzzyController_Y.BRWheelOutput;      

        /* Reset Watchdog */
        HAL_IWDG_Refresh(&hiwdg);
  }
  return 0;
}

/* System Clock Configuration */
void SystemClock_Config(void)
{

  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  __GPIOH_CLK_ENABLE(); /* Enable clock pins */

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

}

#ifdef USE_FULL_ASSERT
  /**
     * @brief Reports the name of the source file and the source line number
     * where the assert_param error has occurred.
     * @param file: pointer to the source file name
     * @param line: assert_param error line source number
     * @retval None
     */
  void assert_failed(uint8_t* file, uint32_t line)
  {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
      ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
  }
#endif