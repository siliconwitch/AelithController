 /*
 * Brief:    Outputs to motor drivers (ESCs) and servo
 *
 * Uses:     TIM3
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
#include <prototypes.h>
#include <config.h>

/* Public variables */
PPMOutputs volatile PPMOutputStructure = {0,0,0,0,0,0,0,0};

/* Private variables */
int pulseIndex = 0;

/* Private helper function declartions */
uint32_t denormaliseSignal(double input); /* Turns the float speed value back into a timer count value */

/* Private struct declarations */
GPIO_InitTypeDef        GPIO_InitStructure;
NVIC_InitTypeDef        NVIC_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure; 


void initOutputs(void){
   
    /* enable the various periph clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);    
    
    /* Set up output pins */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_InitStructure.GPIO_Pin = MOTOR1PIN | MOTOR2PIN | MOTOR3PIN | MOTOR4PIN;
    GPIO_Init(MOTORPORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = AUX1PIN | AUX2PIN | AUX3PIN | AUX4PIN;
    GPIO_Init(AUXPORT, &GPIO_InitStructure);

    /* Set up the timer int */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    /* Set up the timer */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_Prescaler = PPMMEASUREPRESCALER;
    TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStructure.TIM_Period = 65535;
    TIM_InitStructure.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(TIM3, &TIM_InitStructure);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM3, ENABLE);

}

void TIM3_IRQHandler(void){
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET){
        switch(pulseIndex){
            case 0:
                TIM_SetAutoreload(TIM3, denormaliseSignal(PPMOutputStructure.MOT1));
                GPIO_SetBits(AUXPORT, AUX4PIN);
                GPIO_ResetBits(MOTORPORT, MOTOR1PIN);
                pulseIndex++;
                break;

            case 1:
                TIM_SetAutoreload(TIM3, denormaliseSignal(PPMOutputStructure.MOT2));
                GPIO_SetBits(MOTORPORT, MOTOR1PIN);
                GPIO_ResetBits(MOTORPORT, MOTOR2PIN);
                pulseIndex++;
                break;

            case 2:
                TIM_SetAutoreload(TIM3, denormaliseSignal(PPMOutputStructure.MOT3));
                GPIO_SetBits(MOTORPORT, MOTOR2PIN);
                GPIO_ResetBits(MOTORPORT, MOTOR3PIN);
                pulseIndex++;
                break;

            case 3:

                TIM_SetAutoreload(TIM3, denormaliseSignal(PPMOutputStructure.MOT4));
                GPIO_SetBits(MOTORPORT, MOTOR3PIN);
                GPIO_ResetBits(MOTORPORT, MOTOR4PIN);
                pulseIndex++;
                break;

            case 4:
                TIM_SetAutoreload(TIM3, denormaliseSignal(PPMOutputStructure.AUX4));
                GPIO_SetBits(MOTORPORT, MOTOR4PIN);
                GPIO_ResetBits(AUXPORT, AUX4PIN);
                pulseIndex = 0;
                break;
            }
        }
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
}

uint32_t denormaliseSignal(double input){
    if(input >  1.0){input =  1.0;}
    if(input < -1.0){input = -1.0;}
    return (uint32_t) (( (input+1) * ((RECEIVERMAXSIGNAL-RECEIVERMINSIGNAL)/2) ) + RECEIVERMINSIGNAL);
}

/* Halt the vehicle */
void safeMode(void){
    PPMOutputStructure.MOT1 = 0;
    PPMOutputStructure.MOT2 = 0;
    PPMOutputStructure.MOT3 = 0;
    PPMOutputStructure.MOT4 = 0;
    PPMOutputStructure.AUX4 = 0;
}