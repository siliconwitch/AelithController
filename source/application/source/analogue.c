 /*
 * Brief:    Configures analogue inputs into the device, no uses for this yet
 *           but it works
 *
 * Uses:     
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
uint16_t rawADC[4];

/* Private structures */
GPIO_InitTypeDef      GPIO_InitStructure;
ADC_InitTypeDef       ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
DMA_InitTypeDef       DMA_InitStructure;


void initADC(void){
    /* Set all structures to default values */
    GPIO_StructInit(&GPIO_InitStructure);
    ADC_StructInit(&ADC_InitStructure);
    ADC_CommonStructInit(&ADC_CommonInitStructure);
    DMA_StructInit(&DMA_InitStructure);

    /* Enable peripheral clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);

    /* Initialization of the GPIO Pins */
    GPIO_InitStructure.GPIO_Pin = ANA1PIN | ANA2PIN | ANA3PIN | ANA4PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(ANAPORT, &GPIO_InitStructure);

    /* Configure the DMA  */
    DMA_DeInit(DMA2_Stream4);  /* Set DMA registers to default values */
    DMA_InitStructure.DMA_Channel = DMA_Channel_0;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR; /* Source */
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&rawADC[0]; /* Destination */
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_BufferSize = 4;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(DMA2_Stream4, &DMA_InitStructure);
    DMA_Cmd(DMA2_Stream4, ENABLE);

    /* Config ADC1 */
    ADC_DeInit();
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_NbrOfConversion = 4;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_Init(ADC1,&ADC_InitStructure);

    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInit(&ADC_CommonInitStructure);

    /* Sets up the sample size for the ADCs */
    ADC_RegularChannelConfig(ADC1,ADC_Channel_10,1,ADCSAMPLES);
    ADC_RegularChannelConfig(ADC1,ADC_Channel_11,2,ADCSAMPLES);
    ADC_RegularChannelConfig(ADC1,ADC_Channel_12,3,ADCSAMPLES);
    ADC_RegularChannelConfig(ADC1,ADC_Channel_13,4,ADCSAMPLES);

    ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);

    ADC_DMACmd(ADC1, ENABLE); /* Enable ADC1 DMA */

    ADC_Cmd(ADC1, ENABLE);   /* Enable ADC1 */

    ADC_SoftwareStartConv(ADC1); /* Start ADC1 conversion */
}