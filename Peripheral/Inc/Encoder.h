//
// Created by Lyu on 2024/3/18.
//
#ifndef F103STD_ENCODER_H
#define F103STD_ENCODER_H

#include "stm32f10x.h"

void Encoder_Init(void);
int16_t Encoder_GetCount(void);

#endif //F103STD_ENCODER_H
