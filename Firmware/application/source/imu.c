/*
 * Brief:    This file access the MPU6050 IMU over I2C and manages all read/write ops.
 *
 * Uses:     Connects with I2C1 on pins PB8 & PB9
 *
 * Datasheet: http://www.invensense.com/mems/gyro/documents/PS-MPU-6000A-00v3.4.pdf
 *
 * Regiser Map: http://invensense.com/mems/gyro/documents/RM-MPU-6000A.pdf
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

/* IMU Register locations */
#define IMU_ADDRESS 0x68
#define IMU_WHOAMI 0x75
#define IMU_PWR_MGMT1 0x6B
#define IMU_CFG 0x1A
#define IMU_GYRO_CFG 0x1B
#define IMU_ACCEL_CFG 0x1C

/* Public variables */
IMUMotion volatile Motion = {0,0,0,0,0,0,0,0};

/* Private variables */
I2C_HandleTypeDef hi2c1;

uint8_t rawIMU[14];
int accelRegister = 0x00;
int accelConvFactor = 16384;
int gyroRegister = 0x00;
int gyroConvFactor = 131;
uint8_t temp = 0;


void initIMU(void){
	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 100000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED;
	HAL_I2C_Init(&hi2c1);

	IMUConfig(DEFAULTACCELRANGE, DEFAULTGYRORANGE);
}

void IMUGetMotion(){
	uint8_t address[] = {0x3B}; /* Start Address */
	HAL_I2C_Master_Transmit(&hi2c1, IMU_ADDRESS<<1, (uint8_t*)address, 1, 100);
	HAL_I2C_Master_Receive(&hi2c1, IMU_ADDRESS<<1, (uint8_t *)rawIMU, 14, 200);
    
    Motion.x = (float) ( (int16_t)((rawIMU[0] << 8) | rawIMU[1]) ) / accelConvFactor;
    Motion.y = (float) ( (int16_t)((rawIMU[2] << 8) | rawIMU[3]) ) / accelConvFactor;
    Motion.z = (float) ( (int16_t)((rawIMU[4] << 8) | rawIMU[5]) ) / accelConvFactor;
    
    Motion.temp = ((float) ( (int16_t)((rawIMU[6] << 8) | rawIMU[7]) ) + 12412.0) / 340.0;

    Motion.roll  = (float) ( (int16_t)((rawIMU[8]  << 8) | rawIMU[9] ) ) / gyroConvFactor;
    Motion.pitch = (float) ( (int16_t)((rawIMU[10] << 8) | rawIMU[11]) ) / gyroConvFactor;
    Motion.yaw   = (float) ( (int16_t)((rawIMU[12] << 8) | rawIMU[13]) ) / gyroConvFactor;
}

void IMUConfig(int accelrange, int gyrorange){
	/* Figures out what settings to apply */
	     if (accelrange == 4)  {accelRegister = 0x08; accelConvFactor = 8192; }
	else if (accelrange == 8)  {accelRegister = 0x10; accelConvFactor = 4096; }
	else if (accelrange == 16) {accelRegister = 0x18; accelConvFactor = 2048; }
	   else  /*Defults to 2*/  {accelRegister = 0x00; accelConvFactor = 16384;}

	     if (gyrorange == 500) {gyroRegister = 0x08; gyroConvFactor = 65.5; }
	else if (gyrorange == 1000){gyroRegister = 0x10; gyroConvFactor = 32.8; }
	else if (gyrorange == 2000){gyroRegister = 0x18; gyroConvFactor = 16.4; }
	   else /*Defults to 250*/ {gyroRegister = 0x00; gyroConvFactor = 131;  }
	
	/* Does the configuration */
	uint8_t addressAndData[2] = {IMU_WHOAMI, 0x00};
	HAL_I2C_Master_Transmit(&hi2c1, IMU_ADDRESS<<1, (uint8_t*)addressAndData, 1, 100);	/* This should return the WHOAMI register */
	HAL_I2C_Master_Receive(&hi2c1, IMU_ADDRESS<<1, (uint8_t *)rawIMU, 1, 100);
	if (rawIMU[0] == 0x68){sendSerialString("[OK] IMU Found..\n");}
	else{sendSerialString("[ERROR] IMU not found..\n");}
 
	addressAndData[0] = IMU_CFG;
	addressAndData[1] = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, IMU_ADDRESS<<1, (uint8_t*)addressAndData, 2, 100); /* Reset LPF */

	addressAndData[0] = IMU_ACCEL_CFG;
	addressAndData[1] = accelRegister;
	HAL_I2C_Master_Transmit(&hi2c1, IMU_ADDRESS<<1, (uint8_t*)addressAndData, 2, 100);

	addressAndData[0] = IMU_ACCEL_CFG;
	addressAndData[1] = accelRegister;
	HAL_I2C_Master_Transmit(&hi2c1, IMU_ADDRESS<<1, (uint8_t*)addressAndData, 2, 100);

	addressAndData[0] = IMU_PWR_MGMT1;
	addressAndData[1] = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, IMU_ADDRESS<<1, (uint8_t*)addressAndData, 2, 100); /* Bring IMU out of reset */
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c){
	
}