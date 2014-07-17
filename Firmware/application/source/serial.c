 /*
 * Brief:    UART Serial to communicate with Xbee or btooth module
 *
 * Uses:     Uses the PB6 and PB7 pins
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

#include "stm32f4xx_hal.h"
#include <prototypes.h>
#include <config.h>

/* Private variables */
UART_HandleTypeDef huart1;

/* Private function prototypes */


void initSerial(){
	huart1.Instance = USART1;
	huart1.Init.BaudRate = BAUDRATE;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart1);
	sendSerialString("[OK] Serial started..\n");
}

void sendSerialString(char string[]){
	int lentest = 0;
	while((string[lentest] != 10) && lentest < 100){  lentest++;  } /* Determines size of string by looking for a \n or ASCII 'NL'. Cuts off after 100 chars */
	HAL_UART_Transmit(&huart1, (uint8_t*)string, lentest+1, 100);
}