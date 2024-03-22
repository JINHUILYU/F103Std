//
// Created by Lyu on 2024/3/22.
//

#ifndef F103STD_MOTOR_H
#define F103STD_MOTOR_H

#include "stm32f10x.h"
#include "PWM.h"

void Motor_Init(void);
void Motor_SetSpeed(int8_t Speed);

#endif //F103STD_MOTOR_H
