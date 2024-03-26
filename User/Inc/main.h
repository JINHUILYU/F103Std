//
// Created by Lyu on 2024/3/23.
//

#ifndef F103STD_MAIN_H
#define F103STD_MAIN_H

#include "control.h"

#if defined(Exp_1)
#include "stm32f10x.h"
#include "Delay.h"

#elif defined(Exp_2)
#include "stm32f10x.h"
#include "Delay.h"

#elif defined(Exp_3)
#include "stm32f10x.h"
#include "Delay.h"

#elif defined(Exp_4)
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"

#elif defined(Exp_5)
#include "stm32f10x.h"
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"

#elif defined(Exp_6)
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"

#elif defined(Exp_7)
#include "stm32f10x.h"
#include "Delay.h"
#include "CountSensor.h"
#include "OLED.h"

#elif defined(Exp_8)
#include "stm32f10x.h"
#include "Encoder.h"
#include "OLED.h"
#include "Delay.h"

int16_t Num = 0;

#elif defined(Exp_9)
#include "stm32f10x.h"
#include "Timer.h"
#include "Delay.h"
#include "OLED.h"

uint16_t Num = 0;

void TIM2_IRQHandler(void);

#elif defined(Exp_10)
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;			//定义用于接收串口数据的变量

#elif defined(Exp_11)
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;			//定义用于接收串口数据的变量

#elif defined(Exp_12)
#include "stm32f10x.h"
#include "PWM.h"
#include "Delay.h"
#include "OLED.h"

#elif defined(Exp_13)
#include "stm32f10x.h"
#include "Servo.h"
#include "Delay.h"
#include "OLED.h"
#include "Key.h"

#elif defined(Exp_14)
#include "stm32f10x.h"
#include "Motor.h"
#include "OLED.h"
#include "Key.h"

#elif defined(Exp_15)
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "InputCapture.h"

#elif defined(Exp_16)
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "InputCapture.h"

#elif defined(Exp_17)
#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "MyI2C.h"
#include "MPU6050.h"

#endif


#endif //F103STD_MAIN_H
