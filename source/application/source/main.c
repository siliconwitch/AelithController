#include <stm32f4xx.h>
#include <serial.h>
#include <rcradio.h>
#include <watchdogs.h>
#include <hallsensors.h>
#include <analogue.h>
#include <imu.h>

int main(void)
{
	SystemInit();
    initRCRadio();
    initHallSensors();
    //initSerial(9600);
    //initADC();
    //initIMU();

    while(1)
    {
    	if(invalidSignalFlag == 1){
    		GPIO_SetBits(GPIOD, GPIO_Pin_13);
    	}
    	else{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    	}
		//USARTSendString(" - Your serial data\n");
        //IMUReadMotion();
    }
}