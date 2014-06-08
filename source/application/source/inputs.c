 /*
 * Brief:     Manages all the interrupts into the system from external pins
 *			  i.e. all signals from RC radio and hall effect sensors.
 *
 *			  Decodes PPM signals from RC radio with TIM2 and EXTI0, 1, 6, 7
 *			  Hall effect sensors used are the AH3761.
 *
 * Uses:      Uses PORT A with EXTI 2, 3, 4, 5. Also Uses TIM9, 10, 11, 12. TIM2, EXTI0, EXTI1, pins PA0 & PA1
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
 #include <inputs.h>

/* Public Variables */
RCRadio RCRadioStructure = {0,0,0,0,0};
WheelRPM WheelRPMStructure = {0,0,0,0};

/* Private variables */
typedef struct { uint32_t FL, FR, BL, BR; } WheelCount;
WheelCount WheelCountStructure = {0,0,0,0};

/* Private helper function declartions */
double CalculateWheelRPM(int Count);
void ClearInterupt(TIM_TypeDef* TIMx, uint32_t EXTI_Line);

GPIO_InitTypeDef  		GPIO_InitStructure;
NVIC_InitTypeDef  		NVIC_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure; 
EXTI_InitTypeDef  		EXTI_InitStructure;

void initInputs(){
    /* Enable all the periph clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);

    /* Init the input pins */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

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
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM8_CC_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM11_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    /* init the timers */
    TIM_InitStructure.TIM_Prescaler = 17;
    TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStructure.TIM_Period = 50000; /* Needs refining */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(TIM2, &TIM_InitStructure);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);

    TIM_InitStructure.TIM_Prescaler = 840; /* These TIMs run at 168MHz, but we div by 2, then by 840 to get 1uS ticks */
    TIM_InitStructure.TIM_Period = 1000; /* Overflow after 1mS, implies no speed */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV2;

    TIM_TimeBaseInit(TIM8, &TIM_InitStructure);
    TIM_ITConfig(TIM8, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM8, ENABLE);

    TIM_TimeBaseInit(TIM9, &TIM_InitStructure);
    TIM_ITConfig(TIM9, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM9, ENABLE);

    TIM_TimeBaseInit(TIM10, &TIM_InitStructure);
    TIM_ITConfig(TIM10, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM10, ENABLE);

    TIM_TimeBaseInit(TIM11, &TIM_InitStructure);
    TIM_ITConfig(TIM11, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM11, ENABLE);
}

/* Timer for working out RCRadio inputs */
void TIM2_IRQHandler(void){
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
    RCRadioStructure.valid = 1;
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  }
}

/* Interrupt on Steering pin */
void EXTI0_IRQHandler(void){
  if(EXTI_GetITStatus(EXTI_Line0) != RESET){
  	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != RESET){
        TIM_SetCounter(TIM2, 0);
        RCRadioStructure.valid = 1;
  		RCRadioStructure.throttle = 0;
    }

    else{
    	RCRadioStructure.throttle = TIM_GetCounter(TIM2);
    	RCRadioStructure.steering = 0;
        RCRadioStructure.valid = 1;
    	TIM_SetCounter(TIM2, 0);
    }
    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}

/* Interrupt on Throttle pin */
void EXTI1_IRQHandler(void){
  if(EXTI_GetITStatus(EXTI_Line1) != RESET){
  	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == RESET){
    	RCRadioStructure.steering = TIM_GetCounter(TIM2);
        RCRadioStructure.valid = 0;
    	TIM_SetCounter(TIM2, 0);
    }
    EXTI_ClearITPendingBit(EXTI_Line1);
  }
}

void EXTI2_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line2) != RESET){

	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}

void EXTI3_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line3) != RESET){

	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

/* Timer interrupts for the hallsensor count */
void TIM8_CC_IRQHandler(void){
    if (TIM_GetITStatus(TIM8, TIM_IT_Update) != RESET){
        WheelCountStructure.FL = 0;
        CalculateWheelRPM(WheelCountStructure.FL);
        TIM_ClearITPendingBit(TIM8, TIM_IT_Update);
    }
}

void TIM1_BRK_TIM9_IRQHandler(void){
	if (TIM_GetITStatus(TIM9, TIM_IT_Update) != RESET){
		WheelCountStructure.FR = 0;
        CalculateWheelRPM(WheelCountStructure.FR);
		TIM_ClearITPendingBit(TIM9, TIM_IT_Update);
	}
}

void TIM1_UP_TIM10_IRQHandler(void){
    if (TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET){
        WheelCountStructure.BL = 0;
        CalculateWheelRPM(WheelCountStructure.BL);
        TIM_ClearITPendingBit(TIM10, TIM_IT_Update);
    }
}

void TIM1_TRG_COM_TIM11_IRQHandler(void){
    if (TIM_GetITStatus(TIM11, TIM_IT_Update) != RESET){
        WheelCountStructure.BR = 0;
        CalculateWheelRPM(WheelCountStructure.BR);
        TIM_ClearITPendingBit(TIM11, TIM_IT_Update);
    }
}

/* Interrupts for feedback pins */
void EXTI4_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line4) != RESET){
		WheelCountStructure.FL = TIM_GetCounter(TIM9);
        WheelRPMStructure.FL = CalculateWheelRPM(WheelCountStructure.FL);
        ClearInterupt(TIM8, EXTI_Line4);
	}
}

void EXTI9_5_IRQHandler(void){
    if(EXTI_GetITStatus(EXTI_Line5) != RESET){
        WheelCountStructure.FR = TIM_GetCounter(TIM9);
        WheelRPMStructure.FR = CalculateWheelRPM(WheelCountStructure.FR);
        ClearInterupt(TIM9, EXTI_Line5);
    }

	if(EXTI_GetITStatus(EXTI_Line6) != RESET){
        WheelCountStructure.BL = TIM_GetCounter(TIM10);
        WheelRPMStructure.BL = CalculateWheelRPM(WheelCountStructure.BL);
        ClearInterupt(TIM10, EXTI_Line6);
    }

    if(EXTI_GetITStatus(EXTI_Line7) != RESET){
        WheelCountStructure.BR = TIM_GetCounter(TIM11);
        WheelRPMStructure.BR = CalculateWheelRPM(WheelCountStructure.BR);
        ClearInterupt(TIM11, EXTI_Line7);
    }
}

double CalculateWheelRPM(int Count){
    return 60.0 / ((Count/100000.0) * MOTORPOLES);
}

void ClearInterupt(TIM_TypeDef* TIMx, uint32_t EXTI_Line){
    TIM_SetCounter(TIMx, 0);
    EXTI_ClearITPendingBit(EXTI_Line);
}