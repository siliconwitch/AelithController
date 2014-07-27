/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @date    22/07/2014 00:19:04
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2014 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* External variables --------------------------------------------------------*/

extern DMA_HandleTypeDef hdma_adc1;
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim14;
extern DMA_HandleTypeDef hdma_usart1_rx;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles DMA2 Stream2 global interrupt.
*/
void DMA2_Stream2_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(DMA2_Stream2_IRQn);
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
}

/**
* @brief This function handles EXTI Line1 interrupt.
*/
void EXTI1_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI1_IRQn);
  
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}

/**
* @brief This function handles EXTI Line2 interrupt.
*/
void EXTI2_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI2_IRQn);
  
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

/**
* @brief This function handles EXTI Line3 interrupt.
*/
void EXTI3_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI3_IRQn);
  
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
}

/**
* @brief This function handles EXTI Line0 interrupt.
*/
void EXTI0_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI0_IRQn);
  
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

/**
* @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
*/
void TIM6_DAC_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM6_DAC_IRQn);
  HAL_TIM_IRQHandler(&htim6);
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

/**
* @brief This function handles TIM1 Trigger and Commutation interrupts and TIM11 global interrupt.
*/
void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM1_TRG_COM_TIM11_IRQn);
  HAL_TIM_IRQHandler(&htim11);
}

/**
* @brief This function handles TIM2 global interrupt.
*/
void TIM2_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM2_IRQn);
  HAL_TIM_IRQHandler(&htim2);
}

/**
* @brief This function handles I2C1 error interrupt.
*/
void I2C1_ER_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(I2C1_ER_IRQn);
  HAL_I2C_ER_IRQHandler(&hi2c1);
}

/**
* @brief This function handles DMA2 Stream0 global interrupt.
*/
void DMA2_Stream0_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(DMA2_Stream0_IRQn);
  HAL_DMA_IRQHandler(&hdma_adc1);
}

/**
* @brief This function handles EXTI Line4 interrupt.
*/
void EXTI4_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI4_IRQn);
  
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

/**
* @brief This function handles TIM8 Update interrupt and TIM13 global interrupt.
*/
void TIM8_UP_TIM13_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM8_UP_TIM13_IRQn);
  HAL_TIM_IRQHandler(&htim13);
}

/**
* @brief This function handles TIM8 Trigger and Commutation interrupts and TIM14 global interrupt.
*/
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM8_TRG_COM_TIM14_IRQn);
  HAL_TIM_IRQHandler(&htim14);
}

/**
* @brief This function handles TIM1 Update interrupt and TIM10 global interrupt.
*/
void TIM1_UP_TIM10_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM1_UP_TIM10_IRQn);
  HAL_TIM_IRQHandler(&htim10);
}

/**
* @brief This function handles TIM3 global interrupt.
*/
void TIM3_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM3_IRQn);
  HAL_TIM_IRQHandler(&htim3);
}

/**
* @brief This function handles EXTI Line[9:5] interrupts.
*/
void EXTI9_5_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI9_5_IRQn);
  
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
}

/**
* @brief This function handles TIM4 global interrupt.
*/
void TIM4_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM4_IRQn);
  HAL_TIM_IRQHandler(&htim4);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
