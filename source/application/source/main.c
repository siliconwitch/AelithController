 /*
 * Brief:       Main file for Project Aelith running on STM32F4 devices
 *
 * Datasheet:   http://www.st.com/web/en/resource/technical/document/datasheet/DM00037051.pdf
 *
 * Ref Manual:  http://www.st.com/st-web-ui/static/active/en/resource/technical/document/reference_manual/DM00031020.pdf
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
#include <serial.h>
#include <inputs.h>
#include <watchdogs.h>
#include <analogue.h>
#include <imu.h>
#include <outputs.h>

int main(void)
{
	SystemInit();
    initInputs();
    initOutputs();
    initSerial(9600);
    initADC();
    initIMU();

    while(1)
    {
		//USARTSendString("HI!\n");
        //IMUGetMotion();
        asm("nop");
    }
}