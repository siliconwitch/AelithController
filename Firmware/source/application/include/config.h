 /*
 * Brief:       Main config, pin mappings and global variables for Project Aelith.
 *
 *				From here we can see all the major variables shared	between the 
 *				vehicle control system as well as all the peripherals. There are
 *				also many config values that can be tweaked for different setups.
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

#ifndef __PINMAPPINGS_H
#define __PINMAPPINGS_H

#define ARM_MATH_CM4
/*------------------------*/
/* INITIAL CONFIGURATION  */
/*------------------------*/
	/* Motor related */
	#define MOTORPOLES	14

	/* ADC related */
	#define ADCSAMPLES	ADC_SampleTime_480Cycles

	/* Serial related */
	#define BAUDRATE 	9600

	/* Receiver related */
 	#define PPMTIMEOUTVALUE		50000
 	#define PPMTIMEOUTPRESCALER	42

 	#define PPMMEASUREPRESCALER	4
 	#define RECEIVERMINSIGNAL	16000
 	#define RECEIVERMIDSIGNAL	25000
 	#define RECEIVERMAXSIGNAL	34000

	/* IMU related */
	#define DEFAULTACCELRANGE	4
	#define DEFAULTGYRORANGE	500

	/* Control related */
	#define POWERBIAS 0.0
	#define FRONTSLIP 0.0
	#define REARSLIP 0.0

/*------------------------*/
/* PIN MAPPINGS FOR BOARD */
/*------------------------*/
	/* This is just a reference, don't change these pins without 
	   checking where they are used. Each pin also have
	   interrupts tied to them, so they'd also need changing */

	/* Pins and port for motor outputs */
	#define MOTOR1PIN	GPIO_Pin_6		/* FL Wheel */
	#define MOTOR2PIN	GPIO_Pin_7		/* FR Wheel */
	#define MOTOR3PIN	GPIO_Pin_8		/* BL Wheel */
	#define MOTOR4PIN	GPIO_Pin_9		/* BR Wheel */
	#define MOTORPORT	GPIOC

	/* Pins and port for AUX outputs */
	#define AUX1PIN		GPIO_Pin_12
	#define AUX2PIN		GPIO_Pin_13
	#define AUX3PIN		GPIO_Pin_14
	#define AUX4PIN		GPIO_Pin_15
	#define AUXPORT		GPIOB

	/* Serial port pins */
	#define TXPIN		GPIO_Pin_6
	#define RXPIN		GPIO_Pin_7
	#define SCLPIN		GPIO_Pin_8
	#define SDAPIN		GPIO_Pin_9
	#define DATAPORT	GPIOB

	/* Hallsensor feedback input pins */
	#define FB1PIN		GPIO_Pin_4
	#define FB2PIN		GPIO_Pin_5
	#define FB3PIN		GPIO_Pin_6
	#define FB4PIN		GPIO_Pin_7
	#define FBPORT		GPIOA

	/* Receiver input channel pins */
	#define REC1PIN		GPIO_Pin_0
	#define REC2PIN		GPIO_Pin_1
	#define REC3PIN		GPIO_Pin_2
	#define REC4PIN		GPIO_Pin_3
	#define RECPORT		GPIOA

	/* Analogue input pins */
	#define ANA1PIN		GPIO_Pin_0
	#define ANA2PIN		GPIO_Pin_1
	#define ANA3PIN		GPIO_Pin_2
	#define ANA4PIN		GPIO_Pin_3
	#define ANAPORT		GPIOC

/*------------------------*/
/*    GLOBAL VARIABLES    */
/*------------------------*/

	typedef struct { double steering; float throttle; float aux1; float aux2; } RCRadio;

	typedef struct { double MOT1, MOT2, MOT3, MOT4, AUX1, AUX2, AUX3, AUX4; } PPMOutputs;

	typedef struct { double FL, FR, BL, BR; } WheelRPM;

	typedef struct { uint32_t ch1,  ch2,  ch3,  ch4; } AnalogueOutput; //currently unused

	typedef struct { float x, y, z, roll, pitch, yaw, temp, valid; } IMUMotion;

#endif