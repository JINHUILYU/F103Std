//
// Created by Lyu on 2024/3/18.
//
#ifndef F103STD_COUNTSENSOR_H
#define F103STD_COUNTSENSOR_H

#include "stm32f10x.h"

void CountSensor_Init(void);
uint16_t CountSensor_GetCount(void);
void CountSensor_ClearCount(void);


#endif //F103STD_COUNTSENSOR_H
