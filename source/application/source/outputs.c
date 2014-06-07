 /*
 * Brief:    Outputs to motor drivers (ESCs) and servo
 *
 * Uses:     Bunch'o'timers
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
#include <outputs.h>

GPIO_InitTypeDef  		GPIO_InitStructure;
NVIC_InitTypeDef  		NVIC_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure; 

void initOutputs(void){

/* enable the various periph clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
    //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
    
/* Set up output pins */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

}