//
// Created by Lyu on 2024/3/23.
//

#ifndef F103STD_INPUTCAPTURE_H
#define F103STD_INPUTCAPTURE_H

#include "stm32f10x.h"
#include "PWM.h"

void InputCapture_Init(void);
uint32_t InputCapture_GetFreq(void);
uint32_t InputCapture_GetDuty(void);

#endif //F103STD_INPUTCAPTURE_H
