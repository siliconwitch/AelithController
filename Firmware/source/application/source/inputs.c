 /*
 * Brief:     Manages all the interrupts into the system from external pins
 *			  i.e. all signals from RC radio and hall effect sensors.
 *
 *			  Decodes PPM signals from RC radio with TIM2 and EXTI0, 1, 6, 7
 *			  Hall effect sensors used are the AH3761.
 *
 * Uses:      Uses PORT A pins 0 - 7, TIM2, TIM4, TIM10, TIM11, TIM13, TIM14, EXTI 0 - 7
 *
 * Datasheet: http://diodes.com/datasheets/AH3761.pdf
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
RCRadio volatile RCRadioStructure = {0,0,0,0};
WheelRPM volatile WheelRPMStructure = {0,0,0,0};

/* Private variables */


/* Private helper function declartions */
double CalculateWheelRPM(uint32_t Count);
double normaliseSignal(uint32_t input);  /* Turns the Timer count value of the input, into a -1 to 1 float */

/* Private struct declarations */
GPIO_InitTypeDef  		GPIO_InitStructure;
NVIC_InitTypeDef  		NVIC_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure; 
EXTI_InitTypeDef  		EXTI_InitStructure;


void initInputs(){
    /* Enable all the periph clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);

    /* Init the input pins */
    GPIO_InitStructure.GPIO_Pin = REC1PIN | REC2PIN | REC3PIN | REC4PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(RECPORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = FB1PIN | FB2PIN | FB3PIN | FB4PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(FBPORT, &GPIO_InitStructure);

    /* Connect the external interrupts to the pins */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource2);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource3);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource4);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource5);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource6);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource7);

    /* Init the external interrupts */
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line1;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line2;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line3;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line4;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line5;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line6;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line7;
    EXTI_Init(&EXTI_InitStructure);

    /* init the NVIC for EXTI and TIM */
    /* Lowest priority for wheel speed sensors */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM11_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_TIM13_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM8_TRG_COM_TIM14_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    /* Highest priority for receiver inputs */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    /* init the timers */
    TIM_InitStructure.TIM_RepetitionCounter = 0;
    TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;

    /* This is the reciver timeout timer */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; /* This will div the TIM clock from 84MHz to 84MHz */
    TIM_InitStructure.TIM_Prescaler = PPMTIMEOUTPRESCALER; /* We div 84MHz by prescaler defined in config.h to get x MHz i.e. 1/x uS ticks*/
    TIM_InitStructure.TIM_Period = PPMTIMEOUTVALUE; /* After timeout*x uS = 20mS, there is an overflow timeout */

    TIM_TimeBaseInit(TIM4, &TIM_InitStructure);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM4, ENABLE);

    /* This is for the receiver count timer */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; /* This will div the TIM clock from 84MHz to 84MHz */
    TIM_InitStructure.TIM_Prescaler = PPMMEASUREPRESCALER; /* We div 84MHz by prescaler defined in config.h to get x MHz i.e. 1/x uS ticks*/
    TIM_InitStructure.TIM_Period = 65535; /* After timeout*x uS = 20mS, there is an overflow timeout */

    TIM_TimeBaseInit(TIM2, &TIM_InitStructure);
    TIM_Cmd(TIM2, ENABLE);

    /* This is for the four wheelspeed timers */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_Prescaler = 1600; /* These TIMs run at 168MHz, but we div 1680 to get 1uS ticks */
    TIM_InitStructure.TIM_Period = 10000; /* Overflow after 1mS, implies no speed */

    TIM_TimeBaseInit(TIM10, &TIM_InitStructure);
    TIM_ITConfig(TIM10, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM10, ENABLE);

    TIM_TimeBaseInit(TIM11, &TIM_InitStructure);
    TIM_ITConfig(TIM11, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM11, ENABLE);

    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_Prescaler = 840; /* These TIMs run at 84Hz, but we div 840 to get 1uS ticks */
    TIM_InitStructure.TIM_Period = 10000; /* Overflow after 1mS, implies no speed */

    TIM_TimeBaseInit(TIM13, &TIM_InitStructure);
    TIM_ITConfig(TIM13, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM13, ENABLE);

    TIM_TimeBaseInit(TIM14, &TIM_InitStructure);
    TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM14, ENABLE);
}

/* Timer for detecting overflow on receiver timer, i.e no data in the last 20mS, brings down the signal valid flag */
void TIM4_IRQHandler(void){
  if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET){
    RCRadioStructure.steering = 0;
    RCRadioStructure.throttle = 0;
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
  }
}

/* Interrupt on receiver steering pin */
void EXTI0_IRQHandler(void){
  if(EXTI_GetITStatus(EXTI_Line0) != RESET){
  	if(GPIO_ReadInputDataBit(RECPORT, REC1PIN) == RESET){    RCRadioStructure.steering = normaliseSignal( TIM_GetCounter(TIM2) );   }  
    TIM_SetCounter(TIM2, 0);
    TIM_SetCounter(TIM4, 0); /* Reset Lost signal timer */
    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}

/* Interrupt on receiver throttle pin */
void EXTI1_IRQHandler(void){
  if(EXTI_GetITStatus(EXTI_Line1) != RESET){
  	if(GPIO_ReadInputDataBit(RECPORT, REC2PIN) == RESET){    RCRadioStructure.throttle = normaliseSignal( TIM_GetCounter(TIM2) );   }
    TIM_SetCounter(TIM2, 0);
    EXTI_ClearITPendingBit(EXTI_Line1);
  }
}

/* Interrupt on receiver aux1 pin */
void EXTI2_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line2) != RESET){

	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}

/* Interrupt on receiver aux2 pin */
void EXTI3_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line3) != RESET){

	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

/* Timer interrupts for the hallsensor count */
void TIM1_UP_TIM10_IRQHandler(void){
    if (TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET){
        WheelRPMStructure.FL = 0;
        TIM_ClearITPendingBit(TIM10, TIM_IT_Update);
    }
}

void TIM1_TRG_COM_TIM11_IRQHandler(void){
	if (TIM_GetITStatus(TIM11, TIM_IT_Update) != RESET){
		WheelRPMStructure.FR = 0;
		TIM_ClearITPendingBit(TIM11, TIM_IT_Update);
	}
}

void TIM8_UP_TIM13_IRQHandler(void){
    if (TIM_GetITStatus(TIM13, TIM_IT_Update) != RESET){
        WheelRPMStructure.BL = 0;
        TIM_ClearITPendingBit(TIM13, TIM_IT_Update);
    }
}

void TIM8_TRG_COM_TIM14_IRQHandler(void){
    if (TIM_GetITStatus(TIM14, TIM_IT_Update) != RESET){
        WheelRPMStructure.BR = 0;
        TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
    }
}

/* Interrupts for feedback pins */
void EXTI4_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line4) != RESET){
        WheelRPMStructure.FL = CalculateWheelRPM(TIM_GetCounter(TIM10));
        TIM_SetCounter(TIM10, 0);
        EXTI_ClearITPendingBit(EXTI_Line4);
	}
}

void EXTI9_5_IRQHandler(void){
    if(EXTI_GetITStatus(EXTI_Line5) != RESET){
        WheelRPMStructure.FR = CalculateWheelRPM(TIM_GetCounter(TIM11));
        TIM_SetCounter(TIM11, 0);
        EXTI_ClearITPendingBit(EXTI_Line5);
    }

	if(EXTI_GetITStatus(EXTI_Line6) != RESET){
        WheelRPMStructure.BL = CalculateWheelRPM(TIM_GetCounter(TIM13));
        TIM_SetCounter(TIM13, 0);
        EXTI_ClearITPendingBit(EXTI_Line6);
    }

    if(EXTI_GetITStatus(EXTI_Line7) != RESET){
        WheelRPMStructure.BR = CalculateWheelRPM(TIM_GetCounter(TIM14));
        TIM_SetCounter(TIM14, 0);
        EXTI_ClearITPendingBit(EXTI_Line7);
    }
}

double CalculateWheelRPM(uint32_t Count){
    return 60.0 / ((Count/100000.0) * MOTORPOLES);
}

double normaliseSignal(uint32_t input){
    if(input > RECEIVERMINSIGNAL && input < RECEIVERMAXSIGNAL){
        return (((double)input-RECEIVERMINSIGNAL) / ((RECEIVERMAXSIGNAL-RECEIVERMINSIGNAL)/2)) - 1;
    }

    else{
        return 0.0;
    }
}