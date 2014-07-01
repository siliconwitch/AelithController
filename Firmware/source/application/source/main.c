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
#include <stm32f4xx_iwdg.h>
#include <prototypes.h>
#include <config.h>

/* Public variables */
extern PPMOutputs PPMOutputStructure;
extern RCRadio RCRadioStructure;


int main(void){
    /* Boots the system */    
	SystemInit();

    /* Init the i-watchdog */
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(IWDG_Prescaler_4);
    IWDG_SetReload(0x0FFF);
    IWDG_Enable();

    /* Init vehicle functions */
    initInputs();
    initOutputs();
    initSerial();
    initADC();
    initIMU();

    while(1)
    {
        /*-------------------------------------------------------------------------*/
        /*                            TEST CODE ONLY                               */
        
        if((RCRadioStructure.steering > 0) && (RCRadioStructure.throttle > 0)){

            /* This needs to be replaced with a control system */
            PPMOutputStructure.MOT1 = RCRadioStructure.throttle;
            PPMOutputStructure.MOT2 = RCRadioStructure.throttle;
            PPMOutputStructure.MOT3 = RCRadioStructure.throttle;
            PPMOutputStructure.MOT4 = RCRadioStructure.throttle;
            PPMOutputStructure.AUX4 = RCRadioStructure.steering;
        }
        int i = 0;
        for(i = 0; i < 100000; i++){}

        //USARTSendString("HI!\n");
        IMUGetMotion();

        /*                                                                         */
        /*-------------------------------------------------------------------------*/


        /* Reset Watchdog */
        IWDG_ReloadCounter();
    }

    return 0;
}