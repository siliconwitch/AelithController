 /*
 * Brief:    Takes the PPM signal from the RC radio and uses timers and EXTI
 *           interrupts to derrive a throttle & steering input value
 *
 * Uses:     TIM2, EXTI0, EXTI1, pins PA0 & PA1
 *
 * Datasheet: 
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
 
#include <stm32f4xx.h>

int steeringSignal = 0;
int throttleSignal = 0;
int invalidSignalFlag = 1;  /* This flag will only turn off when the signal has been fully read */

GPIO_InitTypeDef  		GPIOA_InitStructure;
GPIO_InitTypeDef  		GPIOD_InitStructure;
NVIC_InitTypeDef  		NVIC_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure; 
EXTI_InitTypeDef  		EXTI_InitStructure;

void initRCRadio(){

    /* Enable all the periph clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    /* init some output GPIO */
    GPIOD_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIOD_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIOD_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIOD_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIOD_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIOD_InitStructure);

    /* init the inputs */
    GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIOA_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOA, &GPIOA_InitStructure);

    /* connect the external interrupts to the pins */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);

    /* init the external interrupts */
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line1;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    /* init the NVIC for EXTI and TIM */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* init the timer */
    TIM_InitStructure.TIM_Prescaler = 1;
    TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStructure.TIM_Period = 220000; /* If the counter goes over this, there will be a overflow interrupt */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_InitStructure);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void){
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
    //TIM_Cmd(TIM2, DISABLE);
    invalidSignalFlag = 1;
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  }
}

void EXTI0_IRQHandler(void){

  if(EXTI_GetITStatus(EXTI_Line0) != RESET){

  	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != RESET){
        GPIO_SetBits(GPIOD, GPIO_Pin_12);
        TIM_SetCounter(TIM2, 0);
        invalidSignalFlag = 1;
  		throttleSignal = 0;
    }

    else{
    	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
    	throttleSignal = TIM_GetCounter(TIM2);
    	steeringSignal = 0;
        invalidSignalFlag = 1;
        GPIO_SetBits(GPIOD, GPIO_Pin_14);
    	TIM_SetCounter(TIM2, 0);
        
    }
    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}

void EXTI1_IRQHandler(void){

  if(EXTI_GetITStatus(EXTI_Line1) != RESET){

  	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == RESET){
    	GPIO_ResetBits(GPIOD, GPIO_Pin_14);
    	steeringSignal = TIM_GetCounter(TIM2);
        invalidSignalFlag = 0;
    	TIM_SetCounter(TIM2, 0);
    }

    EXTI_ClearITPendingBit(EXTI_Line1);
  }
}