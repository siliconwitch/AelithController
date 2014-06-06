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
#include <imu.h>

GPIO_InitTypeDef  	GPIO_InitStructure;
I2C_InitTypeDef		I2C_InitStructure;

IMUMotion   MotionRaw = {0,0,0,0,0,0,0,0};
IMUMotion   Motion = {0,0,0,0,0,0,0,0};

void initIMU(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; // we are going to use PB6 and PB9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			// set pins to alternate function
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		// set GPIO speed
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;			// set output to open drain --> the line has to be only pulled low, not driven high
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// enable pull up resistors
	GPIO_Init(GPIOB, &GPIO_InitStructure);					// init GPIOB
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);	// SCL
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1); // SDA

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

    /* Configuing the IMU, make sure the G and deg/s match the settings in IMUGetMotion() */
    IMUReadByte(IMU_WHOAMI);   
    IMUWriteByte(IMU_CFG, 0x00); /* Reset LPF */
    IMUWriteByte(IMU_ACCEL_CFG, IMU_4G); /* Set Accel range to 4G */
    IMUWriteByte(IMU_GYRO_CFG, IMU_500D); /* Set Gyro range to 500deg/sec */
    IMUWriteByte(IMU_PWR_MGMT1 ,0x00); /* Bring IMU out of reset */
}

uint8_t IMUReadByte(uint8_t address){
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    
    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

    I2C_SendData(I2C1, address);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Receiver);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

    I2C_AcknowledgeConfig(I2C1, DISABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));

    I2C_GenerateSTOP(I2C1, ENABLE);
    I2C_AcknowledgeConfig(I2C1, ENABLE);
    
    return I2C_ReceiveData(I2C1);
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
    MotionRaw.X = (int16_t)((IMUReadByte(0x3B) << 8) | IMUReadByte(0x3C));
    MotionRaw.Y = (int16_t)((IMUReadByte(0x3D) << 8) | IMUReadByte(0x3E));
    MotionRaw.Z = (int16_t)((IMUReadByte(0x3F) << 8) | IMUReadByte(0x40));

    MotionRaw.Roll  = (int16_t)((IMUReadByte(0x43) << 8) | IMUReadByte(0x44));
    MotionRaw.Pitch = (int16_t)((IMUReadByte(0x45) << 8) | IMUReadByte(0x46));
    MotionRaw.Yaw   = (int16_t)((IMUReadByte(0x47) << 8) | IMUReadByte(0x47));

    MotionRaw.Temp = (int16_t)((IMUReadByte(0x41) << 8) | IMUReadByte(0x44));

    Motion.X = (float) MotionRaw.X / (IMU_4G_RANGE);
    Motion.Y = (float) MotionRaw.Y / (IMU_4G_RANGE);
    Motion.Z = (float) MotionRaw.Z / (IMU_4G_RANGE);
    
    Motion.Roll  = (float) MotionRaw.Roll  / (IMU_500D_RANGE);
    Motion.Pitch = (float) MotionRaw.Pitch / (IMU_500D_RANGE);
    Motion.Yaw   = (float) MotionRaw.Yaw   / (IMU_500D_RANGE);
    
    Motion.Temp = ((float) MotionRaw.Temp + 12412.0) / 340.0;
}