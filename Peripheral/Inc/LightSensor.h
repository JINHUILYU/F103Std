//
// Created by Lyu on 2024/3/18.
//
#ifndef F103STD_LIGHTSENSOR_H
#define F103STD_LIGHTSENSOR_H

#include "stm32f10x.h"

void LightSensor_Init(void);
uint8_t LightSensor_GetStatus(void);

#endif //F103STD_LIGHTSENSOR_H
