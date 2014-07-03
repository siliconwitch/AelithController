 /*
 * Brief:       List of all the public functions within the project
 *
 *				Public function prototypes for all the .c files within the
 *				/application/source folder. Public variables can be found
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
	void IMUReadBytes(uint8_t startAddress, uint8_t numOfBytes, uint8_t *location);
	void IMUWriteByte(uint8_t address, uint8_t data);
	void IMUGetMotion(void);
	void IMUConfig(int accelrange, int gyrorange);

/* inputs.c Function prototypes */
	void initInputs(void);
	void RCRadioStructureTest(void);

/* outputs.c Function prototypes */
	void initOutputs(void);

/* serial.c Function prototypes */
	void initSerial();
	void USARTSendString(char a[100]);

#endif