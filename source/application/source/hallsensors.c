/*------------------------------------------------------
 hallsensors.c & hallsensors.h
 v0.1 - 18/05/2014
 
 Counts pulses from the hall sensors and wors our rpm
 Uses TIM9, TIM10, TIM11, TIM12
 Uses up IRQn for TIM1 and TIM8
 Uses up IRQn for EXTI 2 - 9

 By Rajesh Nakarja
------------------------------------------------------*/

#include <stm32f4xx.h>
#include <hallsensors.h>

GPIO_InitTypeDef  		GPIOA_InitStructure;
NVIC_InitTypeDef  		NVIC_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure; 
EXTI_InitTypeDef  		EXTI_InitStructure;

WheelCount WheelCountStructure = {0,0,0,0};
WheelRPM WheelRPMStructure = {0,0,0,0};

void initHallSensors(void){

/* enable the various periph clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);

/* Link up the interrupt ports */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource2);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource3);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource4);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource5);

/* init the inputs */
    GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIOA_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIOA_InitStructure);

/* init the external interrupts */
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    EXTI_InitStructure.EXTI_Line = EXTI_Line2;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line3;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line4;
    EXTI_Init(&EXTI_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line5;
    EXTI_Init(&EXTI_InitStructure);

/* init the NVIC for EXTI and TIM */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM11_IRQn;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM8_BRK_TIM12_IRQn;
    NVIC_Init(&NVIC_InitStructure);

/* init the timers */
    TIM_InitStructure.TIM_Prescaler = 840;
    TIM_InitStructure.TIM_Period = 4000; /* If the counter goes over this, there will be a overflow interrupt */
    TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStructure.TIM_RepetitionCounter = 0;
    

    TIM_TimeBaseInit(TIM9, &TIM_InitStructure);
    TIM_ITConfig(TIM9, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM9, ENABLE);

    TIM_TimeBaseInit(TIM10, &TIM_InitStructure);
    TIM_ITConfig(TIM10, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM10, ENABLE);

    TIM_TimeBaseInit(TIM11, &TIM_InitStructure);
    TIM_ITConfig(TIM11, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM11, ENABLE);

    TIM_TimeBaseInit(TIM12, &TIM_InitStructure);
    TIM_ITConfig(TIM12, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM12, ENABLE);
}

void TIM1_BRK_TIM9_IRQHandler(void){
	if (TIM_GetITStatus(TIM9, TIM_IT_Update) != RESET){

		WheelCountStructure.FL = 0;

		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
		TIM_ClearITPendingBit(TIM9, TIM_IT_Update);
	}
}

void TIM1_UP_TIM10_IRQHandler(void){
    if (TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET){

        WheelCountStructure.FR = 0;

        GPIO_ResetBits(GPIOD, GPIO_Pin_15);
        TIM_ClearITPendingBit(TIM10, TIM_IT_Update);
    }
}

void TIM1_TRG_COM_TIM11_IRQHandler(void){
    if (TIM_GetITStatus(TIM11, TIM_IT_Update) != RESET){

        WheelCountStructure.BL = 0;

        GPIO_ResetBits(GPIOD, GPIO_Pin_15);
        TIM_ClearITPendingBit(TIM11, TIM_IT_Update);
    }
}

void TIM8_BRK_TIM12_IRQHandler(void){
    if (TIM_GetITStatus(TIM12, TIM_IT_Update) != RESET){

        WheelCountStructure.BR = 0;

        GPIO_ResetBits(GPIOD, GPIO_Pin_15);
        TIM_ClearITPendingBit(TIM12, TIM_IT_Update);
    }
}

/* Caluclation for working out wheel RPM - doc pending */
double CalculateWheelRPM(int Count){
    return 60.0 / ((Count/100000.0) * MOTORPOLES);
}

/* Helper function for clearing interupt - doc pending */
void ClearInterupt(TIM_TypeDef* TIMx, uint32_t EXTI_Line){
    TIM_SetCounter(TIMx, 0);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
    EXTI_ClearITPendingBit(EXTI_Line);
}

void EXTI2_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line2) != RESET){
		WheelCountStructure.FL = TIM_GetCounter(TIM9);

		//FLWheelRPM = 60.0 / ((FLWheelCount/100000.0) * MOTORPOLES); /* HOLY SHIT IT WORKS! */
        WheelRPMStructure.FL = CalculateWheelRPM(WheelCountStructure.FL);
        ClearInterupt(TIM9, EXTI_Line2);
		//TIM_SetCounter(TIM9, 0);
		//GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
		//EXTI_ClearITPendingBit(EXTI_Line2);
	}
}

void EXTI3_IRQHandler(void){
    if(EXTI_GetITStatus(EXTI_Line3) != RESET){
        WheelCountStructure.FR = TIM_GetCounter(TIM10);

        WheelRPMStructure.FR = CalculateWheelRPM(WheelCountStructure.FR);
        ClearInterupt(TIM10, EXTI_Line3);

        //FRWheelRPM = 60.0 / ((FRWheelCount/100000.0) * MOTORPOLES); /* HOLY SHIT IT WORKS! */
//
        //TIM_SetCounter(TIM10, 0);
        //GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
        //EXTI_ClearITPendingBit(EXTI_Line3);
    }
}

void EXTI4_IRQHandler(void){
    if(EXTI_GetITStatus(EXTI_Line4) != RESET){
        WheelCountStructure.BL = TIM_GetCounter(TIM11);

        WheelRPMStructure.BL = CalculateWheelRPM(WheelCountStructure.BL);
        ClearInterupt(TIM11, EXTI_Line4);

        //BLWheelRPM = 60.0 / ((BLWheelCount/100000.0) * MOTORPOLES); /* HOLY SHIT IT WORKS! */
//
        //TIM_SetCounter(TIM11, 0);
        //GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
        //EXTI_ClearITPendingBit(EXTI_Line4);
    }
}

void EXTI9_5_IRQHandler(void){
    if(EXTI_GetITStatus(EXTI_Line5) != RESET){
        WheelCountStructure.BR = TIM_GetCounter(TIM12);

        WheelRPMStructure.BR = CalculateWheelRPM(WheelCountStructure.BR);
        ClearInterupt(TIM12, EXTI_Line5);
        //BRWheelRPM = 60.0 / ((BRWheelCount/100000.0) * MOTORPOLES); /* Answer seemes multiplied by 2, dont know why */ 
//
        //TIM_SetCounter(TIM12, 0);
        //GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
        //EXTI_ClearITPendingBit(EXTI_Line5);
    }
}