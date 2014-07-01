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

#include <stm32f4xx.h>
#include <prototypes.h>
#include <config.h>

/* Private variables */
int i = 0;
int j = 0;
char received_string[100];
char t = ' ';

/* Private helper function declartions */
void USART1_IRQHandler(void);
void USARTSendString(char *);

/* Private struct declarations */
GPIO_InitTypeDef  GPIO_InitStructure;
USART_InitTypeDef USART_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;


void initSerial(){

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitStructure.GPIO_Pin = TXPIN | RXPIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;           // the pins are configured as alternate function so the USART peripheral has access to them
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      // this defines the IO speed and has nothing to do with the baudrate!
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;         // this defines the output type as push pull mode (as opposed to open drain)
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;           // this activates the pullup resistors on the IO pins
    GPIO_Init(DATAPORT, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(DATAPORT, GPIO_PinSource6, GPIO_AF_USART1); //
    GPIO_PinAFConfig(DATAPORT, GPIO_PinSource7, GPIO_AF_USART1);

    USART_InitStructure.USART_BaudRate = BAUDRATE;             // the baudrate is set to the value we passed into this init function
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
    USART_InitStructure.USART_StopBits = USART_StopBits_1;     // we want 1 stop bit (standard)
    USART_InitStructure.USART_Parity = USART_Parity_No;        // we don't want a parity bit (standard)
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
    USART_Init(USART1, &USART_InitStructure);                  // again all the properties are passed to the USART_Init function which takes care of all the bit setting
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt
    
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;        // we want to configure the USART1 interrupts
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART1 interrupts
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;       // this sets the subpriority inside the group
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;          // the USART1 interrupts are globally enabled
    NVIC_Init(&NVIC_InitStructure);                          // the properties are passed to the NVIC_Init function which takes care of the low level stuff
   
    USART_Cmd(USART1, ENABLE);// finally this enables the complete USART1 peripheral
}

void USART1_IRQHandler(void){

    // check if the USART1 receive interrupt flag was set
    int i = 0;
    for(i = 0; i <= 100; i++){
        
        //if( USART_GetITStatus(USART1, USART_IT_RXNE) ){
            if(USART_ReceiveData(USART1) == 10){
                break;
            }
            else{
                received_string[i] = USART_ReceiveData(USART1); // the character from the USART1 data register is saved i
            }
        //}    
    }
}

void USARTSendString(char a[100]){
    int i = 0;
    for(i = 0; i <= 100; i++){
        if(a[i] == 10){
            USART_SendData(USART1, 10);
            break;
        }
        USART_SendData(USART1, a[i]);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); // Wait for Empty
    }

}