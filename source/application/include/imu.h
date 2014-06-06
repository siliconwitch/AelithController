#ifndef __IMU_H
#define __IMU_H

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