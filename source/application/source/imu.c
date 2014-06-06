/*------------------------------------------------------
 imu.c & imu.h
 v0.1 - 23/05/2014
 
 Connects to an I2C IMU on PB6 & PB9

 By Rajesh Nakarja
------------------------------------------------------*/

#include <stm32f4xx.h>
#include <imu.h>
#include <config.h>

GPIO_InitTypeDef  	GPIO_InitStructure;
I2C_InitTypeDef		I2C_InitStructure;

int IMUTemp = 0;
int AccelX = 0;
int AccelY = 0;
int AccelZ = 0;
int GyroX = 0;
int GyroY = 0;
int GyroZ = 0;

uint8_t lsbIMUTemp = 0;
uint8_t lsbAccelX = 0;
uint8_t lsbAccelY = 0;
uint8_t lsbAccelZ = 0;
uint8_t lsbGyroX = 0;
uint8_t lsbGyroY = 0;
uint8_t lsbGyroZ = 0;

uint8_t msbIMUTemp = 0;
uint8_t msbAccelX = 0;
uint8_t msbAccelY = 0;
uint8_t msbAccelZ = 0;
uint8_t msbGyroX = 0;
uint8_t msbGyroY = 0;
uint8_t msbGyroZ = 0;

void initIMU(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_9; // we are going to use PB6 and PB9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			// set pins to alternate function
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		// set GPIO speed
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;			// set output to open drain --> the line has to be only pulled low, not driven high
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// enable pull up resistors
	GPIO_Init(GPIOB, &GPIO_InitStructure);					// init GPIOB
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);	// SCL
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

    //IMUTemp = IMUReadByte(IMU_WHOAMI);
    IMUWriteByte(0x6B,0x00); /* Bring IMU out of reset */
    
}

int IMUReadByte(int address){
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    
    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    
    I2C_Cmd(I2C1, ENABLE);

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

void IMUWriteByte(int address, int data){
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

void IMUReadMotion(void){
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    
    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    
    I2C_Cmd(I2C1, ENABLE);

    I2C_SendData(I2C1, 0x3B);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    I2C_Send7bitAddress(I2C1, IMU_ADDRESS << 1, I2C_Direction_Receiver);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
    
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    msbAccelX = I2C_ReceiveData(I2C1);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    lsbAccelX = I2C_ReceiveData(I2C1);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    msbAccelY = I2C_ReceiveData(I2C1);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    lsbAccelY = I2C_ReceiveData(I2C1);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    msbAccelZ = I2C_ReceiveData(I2C1);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    lsbAccelZ = I2C_ReceiveData(I2C1);

    I2C_AcknowledgeConfig(I2C1, DISABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));

    I2C_GenerateSTOP(I2C1, ENABLE);

    I2C_AcknowledgeConfig(I2C1, ENABLE);

    AccelX = (msbAccelX << 8) | (lsbAccelX);    
    AccelY = (msbAccelY << 8) | (lsbAccelY);
    AccelZ = (msbAccelZ << 8) | (lsbAccelZ);
}