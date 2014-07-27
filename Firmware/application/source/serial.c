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

/* Public variables */
uint8_t telemetryFlag = 0;

/* Private variables */
UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;
uint8_t rxBuffer = 0;
uint8_t rxString[100];
int rxindex = 0;

/* Private function prototypes */
void executeSerialCommand(uint8_t string[], int length);


void initSerial()
{
	__DMA2_CLK_ENABLE();
	HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

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

	/* Start the receiver */
	HAL_UART_Receive_DMA(&huart1, &rxBuffer, 1);
}

void sendSerialString(char string[])
{
	int lentest = 0;
	while((string[lentest] != 10) && lentest < 100){  lentest++;  } /* Determines size of string by looking for a \n or ASCII 'NL'. Cuts off after 100 chars */
	HAL_UART_Transmit(&huart1, (uint8_t*)string, lentest+1, 100);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	rxString[rxindex] = rxBuffer;
	
	if(rxBuffer == '\n')
	{
		executeSerialCommand(rxString, rxindex);
		rxindex = 0;
		int iter = 0;
		for (iter = 0; iter < 100; iter++){	rxString[iter] = '\000'; } /* Clear out the string to avoid reevaluating data */
	}

	else{
		rxindex++;
		if(rxindex > 100){rxindex = 0;}
	}

	HAL_UART_Receive_DMA(&huart1, &rxBuffer, 1);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	sendSerialString("[ERROR] Serial error\n");
}

void executeSerialCommand(uint8_t string[], int length)
{
	if(string[0] == '-') /* All commands start with a - */
	{ 
		switch(string[1])
		{
			case 'h': /* Help command */
				sendSerialString("display help\n");
				break;

			case 'c':
				sendSerialString("calibrate\n");
				break;

			case 't':
				if (telemetryFlag == 0)
				{
					telemetryFlag = 1;
					sendSerialString("Telemetry started\n");
				}

				else
				{
					telemetryFlag = 0;
					sendSerialString("Telemetry stopped\n");
				}
				break;
		}
	}
}

