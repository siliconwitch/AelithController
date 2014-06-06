#ifndef __RCRADIO_H
#define __RCRADIO_H

extern int steeringSignal;
extern int throttleSignal;
extern int invalidSignalFlag;

void initRCRadio(void);
void TIM2_IRQHandler(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void); 

#endif