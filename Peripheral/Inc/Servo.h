//
// Created by Lyu on 2024/3/22.
//

#ifndef F103STD_SERVO_H
#define F103STD_SERVO_H

#include "stm32f10x.h"
#include "PWM.h"

void Servo_Init(void);
void Servo_SetAngle(float Angle);

#endif //F103STD_SERVO_H
