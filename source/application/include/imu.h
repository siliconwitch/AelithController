#ifndef __IMU_H
#define __IMU_H

#define IMU_ADDRESS 0x68
#define IMU_WHOAMI 0x75
#define IMU_PWR_MGMT1 0x6B

extern int IMUTemp;
extern int AccelX;
extern int AccelY;
extern int AccelZ;
extern int GyroX;
extern int GyroY;
extern int GyroZ;

void initIMU(void);
int IMUReadByte(int address);
void IMUWriteByte(int address, int data);
void IMUReadMotion(void);

#endif