#ifndef __INPUTS_H
#define __INPUTS_H

#define MOTORPOLES 14	/* How many poles in the motor */

extern int steeringSignal;
extern int throttleSignal;
extern int invalidSignalFlag;

typedef struct { int steering, throttle, aux1, aux2, valid; } RCRadio;
typedef struct { double FL, FR, BL, BR; } WheelRPM;

void initInputs(void);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);

void TIM2_IRQHandler(void);

void TIM8_CC_IRQHandler(void);
void TIM1_BRK_TIM9_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM11_IRQHandler(void);
void TIM12_IRQHandler(void);

#endif