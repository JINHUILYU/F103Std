//
// Created by Lyu on 2024/3/22.
//
#include "Motor.h"

/**
  * 函    数：电机初始化
  * 参    数：无
  * 返 回 值：无
  */
void Motor_Init(void) {
    /*开启时钟*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PA4和PA5引脚初始化为推挽输出

    PWM_Init(); //初始化电机的底层PWM
}

/**
 * 函    数：电机设置速度
 * @param Speed
 */
void Motor_SetSpeed(int8_t Speed) {
    if (Speed >= 0) {
        GPIO_SetBits(GPIOA, GPIO_Pin_4);	//设置PA4为高电平
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);	//设置PA5为低电平
        PWM_SetCompare3(Speed);		//设置占空比
    } else {
        GPIO_ResetBits(GPIOA, GPIO_Pin_4);	//设置PA4为低电平
        GPIO_SetBits(GPIOA, GPIO_Pin_5);	//设置PA5为高电平
        PWM_SetCompare3(-Speed);		//设置占空比
    }
}