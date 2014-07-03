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

#include <stm32f4xx.h>
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
uint8_t rawIMU[14];

int accelRegister = 0x00;
int accelConvFactor = 16384;
int gyroRegister = 0x00;
int gyroConvFactor = 131;

/* Private helper function declartions */


/* Private struct declarations */
GPIO_InitTypeDef    GPIO_InitStructure;
I2C_InitTypeDef     I2C_InitStructure;


void initIMU(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 | GPIO_Pin_9; // we are going to use PB6 and PB9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			// set pins to alternate function
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		// set GPIO speed
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;			// set output to open drain --> the line has to be only pulled low, not driven high
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// enable pull up resistors
	GPIO_Init(DATAPORT, &GPIO_InitStructure);					// init GPIOB
	GPIO_PinAFConfig(DATAPORT, GPIO_PinSource8, GPIO_AF_I2C1);
	GPIO_PinAFConfig(DATAPORT, GPIO_PinSource9, GPIO_AF_I2C1);
       

    /* Set the I2C parameters, pretty much default except ack */
    I2C_InitStructure.I2C_ClockSpeed = 100000;
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C1, &I2C_InitStructure);

    /* Enable the I2C peripheral */
    I2C_Cmd(I2C1, ENABLE);

    /* Config the IMU with defult settings */
    IMUConfig(DEFAULTACCELRANGE, DEFAULTGYRORANGE);

}

void IMUReadBytes(uint8_t startAddress, uint8_t numOfBytes, uint8_t *location){
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    
    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

    I2C_SendData(I2C1, startAddress);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Receiver);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

    int num = 0;
    for(num = 0; num <= numOfBytes; num++){
        if(num == numOfBytes){
            I2C_AcknowledgeConfig(I2C1, DISABLE);   /* ЧоєуТ»О»єуТЄ№Ш±ХУ¦ґрµД */
            I2C_GenerateSTOP(I2C1, ENABLE);         /* ·ўЛННЈЦ№О» */
        }

        while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));  /* EV7 */
        location[num] = I2C_ReceiveData(I2C1);
    }
    I2C_AcknowledgeConfig(I2C1, ENABLE);
}

void IMUWriteByte(uint8_t address, uint8_t data){
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    
    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    
    I2C_Cmd(I2C1, ENABLE);

    I2C_SendData(I2C1, address);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_SendData(I2C1, data);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_GenerateSTOP(I2C1, ENABLE);
}

void IMUGetMotion(){
    IMUReadBytes(0x3B,14,&rawIMU);
    
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
    //IMUReadByte(IMU_WHOAMI);   
    IMUWriteByte(IMU_CFG, 0x00); /* Reset LPF */
    IMUWriteByte(IMU_ACCEL_CFG, accelRegister);
    IMUWriteByte(IMU_GYRO_CFG, gyroRegister);
    IMUWriteByte(IMU_PWR_MGMT1 ,0x00); /* Bring IMU out of reset */
}