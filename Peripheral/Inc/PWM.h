//
// Created by Lyu on 2024/3/22.
//

#ifndef F103STD_PWM_H
#define F103STD_PWM_H

#include "stm32f10x.h"
#include "control.h"

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetCompare2(uint16_t Compare);
void PWM_SetCompare3(uint16_t Compare);
void PWM_SetPrescaler(uint16_t Prescaler);

#endif //F103STD_PWM_H
