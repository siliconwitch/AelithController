#ifndef __SERIAL_H
#define __SERIAL_H

void initSerial(int baudrate);
void USART1_IRQHandler(void);
void USARTSendString(char a[100]);

#endif