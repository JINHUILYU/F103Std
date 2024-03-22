//
// Created by Lyu on 2024/3/23.
//

#ifndef F103STD_MAIN_H
#define F103STD_MAIN_H

#include "control.h"

#ifdef Exp_1
#include "stm32f10x.h"
#include "Delay.h"
#endif

#ifdef Exp_2
#include "stm32f10x.h"
#include "Delay.h"
#endif

#ifdef Exp_3
#include "stm32f10x.h"
#include "Delay.h"
#endif

#ifdef Exp_4
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#endif

#ifdef Exp_5
#include "stm32f10x.h"
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"
#endif

#ifdef Exp_6
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#endif

#ifdef Exp_7
#include "stm32f10x.h"
#include "Delay.h"
#include "CountSensor.h"
#include "OLED.h"
#endif

#ifdef Exp_8
#include "stm32f10x.h"
#include "Encoder.h"
#include "OLED.h"
#include "Delay.h"

int16_t Num = 0;
#endif

#ifdef Exp_9
#include "stm32f10x.h"
#include "Timer.h"
#include "Delay.h"
#include "OLED.h"

uint16_t Num = 0;

void TIM2_IRQHandler(void);
#endif

#ifdef Exp_10
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;			//定义用于接收串口数据的变量
#endif

#ifdef Exp_11
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;			//定义用于接收串口数据的变量
#endif

#ifdef Exp_12
#include "stm32f10x.h"
#include "PWM.h"
#include "Delay.h"
#include "OLED.h"
#endif

#ifdef Exp_13
#include "stm32f10x.h"
#include "Servo.h"
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#endif

#ifdef Exp_14
#include "stm32f10x.h"
#include "Motor.h"
#include "OLED.h"
#include "Key.h"
#endif

#endif //F103STD_MAIN_H
