#ifndef __HALLSENSORS_H
#define __HALLSENSORS_H

extern int FLWheelCount;
extern int FRWheelCount;
extern int BLWheelCount;
extern int BLWheelCount;

extern double FLWheelRPM;
extern double FRWheelRPM;
extern double BLWheelRPM;
extern double BRWheelRPM;

void initHallSensors(void);
void TIM1_BRK_TIM9_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM11_IRQHandler(void);
void TIM12_IRQHandler(void);

void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);

#endif