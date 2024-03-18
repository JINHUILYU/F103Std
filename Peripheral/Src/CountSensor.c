//
// Created by Lyu on 2024/3/18.
//
#include "CountSensor.h"

uint16_t CountSensor_Count = 0;

/**
 * @brief CountSensor_Init
 * @param void
 * @retval void
 */
void CountSensor_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); // 开启AFIO的时钟，外部中断必须开启AFIO的时钟

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 将PB14初始化为上拉输入

    // AFIO选择中断引脚
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14); // 选择中断引脚

    // 外部中断初始化
    EXTI_InitTypeDef EXTI_InitStructure;
    EXTI_InitStructure.EXTI_Line = EXTI_Line14; // 中断线
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; // 中断模式
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // 下降沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE; // 使能中断线
    EXTI_Init(&EXTI_InitStructure);

    // NVIC中断分组
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    // NVIC配置
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn; // 外部中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; // 抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; // 子优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; // 使能外部中断通道
    NVIC_Init(&NVIC_InitStructure);
}

/**
 * @brief CountSensor_GetCount
 * @param void
 * @retval uint16_t
 */
uint16_t CountSensor_GetCount(void) {
    return CountSensor_Count;
}

/**
 * @brief CountSensor_ClearCount
 * @param void
 * @retval void
 */
void CountSensor_ClearCount(void) {
    CountSensor_Count = 0;
}

/**
 * @brief 外部中断服务函数
 * @param void
 * @retval void
 */
void EXTI15_10_IRQHandler(void) {
    // 判断是否产生了中断
    if (EXTI_GetITStatus(EXTI_Line14) == SET) {
        // 多次判断，防止抖动
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0) {
            CountSensor_Count++;
        }
        EXTI_ClearITPendingBit(EXTI_Line14); // 清除中断标志位
    }
}