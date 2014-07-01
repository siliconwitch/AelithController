 /*
 * Brief:       These are all the functions prototypes for the project
 *
 *				These are the function prototypes for all the .c files within
 *				the /application/source folder. Global variables can be found
 *				in the config.h file.
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
#ifndef __OUTPUTS_H
#define __OUTPUTS_H

/* analogue.c Function prototypes */ 
	void initADC(void);

/* imu.c Function prototypes */
	void initIMU(void);
	uint8_t IMUReadByte(uint8_t address);
	void IMUWriteByte(uint8_t address, uint8_t data);
	void IMUGetMotion(void);
	void IMUConfig(int accelrange, int gyrorange);

/* inputs.c Function prototypes */
	void initInputs(void);

	void EXTI0_IRQHandler(void);
	void EXTI1_IRQHandler(void);
	void EXTI2_IRQHandler(void);
	void EXTI3_IRQHandler(void);
	void EXTI4_IRQHandler(void);
	void EXTI9_5_IRQHandler(void);

	void TIM2_IRQHandler(void);
	void TIM8_CC_IRQHandler(void);
	void TIM1_BRK_TIM9_IRQHandler(void);
	void TIM1_UP_TIM10_IRQHandler(void);
	void TIM11_IRQHandler(void);

/* outputs.c Function prototypes */
	void initOutputs(void);
	void TIM3_IRQHandler(void);

/* serial.c Function prototypes */
	void initSerial();
	void USART1_IRQHandler(void);
	void USARTSendString(char a[100]);

#endif