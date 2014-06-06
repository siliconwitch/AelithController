#ifndef __IMU_H
#define __IMU_H

/* Various IMU Registers */
#define IMU_ADDRESS 0x68
#define IMU_WHOAMI 0x75
#define IMU_PWR_MGMT1 0x6B
#define IMU_CFG 0x1A
#define IMU_GYRO_CFG 0x1B
#define IMU_ACCEL_CFG 0x1C

/* These are the words for setting the G and deg/s registers */

#define IMU_2G 0x00
#define IMU_4G 0x08
#define IMU_8G 0x10
#define IMU_16G 0x18

#define IMU_250D 0x00
#define IMU_500D 0x08
#define IMU_1000D 0x10
#define IMU_2000D 0x18

/* These are the divisors for different G and deg/s settings */
#define IMU_2G_RANGE 16384
#define IMU_4G_RANGE 8192
#define IMU_8G_RANGE 4096
#define IMU_16G_RANGE 2048

#define IMU_250D_RANGE 131
#define IMU_500D_RANGE 65.5
#define IMU_1000D_RANGE 32.8
#define IMU_2000D_RANGE 16.4

typedef struct { float X, Y, Z, Roll, Pitch, Yaw, Temp, Valid; } IMUMotion;

void initIMU(void);
uint8_t IMUReadByte(uint8_t address);
void IMUWriteByte(uint8_t address, uint8_t data);
void IMUGetMotion(void);

#endif