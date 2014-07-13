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
//#include <differentialBiasing.h>
#include <fuzzyController.h>
#include <rtwtypes.h>
#include <stdio.h>

/* Public variables */
extern PPMOutputs PPMOutputStructure;
extern RCRadio RCRadioStructure;

int main(void){
    /* Boots the system */    
	SystemInit();

    /* Init the independent watchdog */
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(IWDG_Prescaler_4);
    IWDG_SetReload(2047); /* 256mS Timeout */
    IWDG_Enable();

    /* Init vehicle functions */
    initInputs();
    initOutputs();
    initSerial();
    initADC();
    initIMU();

    /* Start up the controller */
    //differentialBiasing_initialize();
    fuzzyController_initialize();

    while(1)
    {
        //USARTSendString("HI!\n");
        //IMUGetMotion();

        /* Send inputs into the controller */
        fuzzyController_U.gyroYaw = 0;          
        fuzzyController_U.steeringSignal = RCRadioStructure.steering;   
        fuzzyController_U.throttleSignal = RCRadioStructure.throttle;   
        fuzzyController_U.frontDifferential = FRONTSLIP;
        fuzzyController_U.rearDifferential = REARSLIP; 
        fuzzyController_U.powerBias = POWERBIAS; 

        /* Run the controller */ 
        fuzzyController_step();

        /* Apply outputs from controller */
        PPMOutputStructure.AUX4 = fuzzyController_Y.steeringOutput;
        PPMOutputStructure.MOT1 = fuzzyController_Y.FLWheelOutput;
        PPMOutputStructure.MOT2 = fuzzyController_Y.FRWheelOutput;
        PPMOutputStructure.MOT3 = fuzzyController_Y.BLWheelOutput;
        PPMOutputStructure.MOT4 = fuzzyController_Y.BRWheelOutput;      

        /* Reset Watchdog */
        IWDG_ReloadCounter();
    }
    return 0;
}