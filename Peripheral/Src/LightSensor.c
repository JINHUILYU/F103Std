//
// Created by Lyu on 2024/3/18.
//
#include "LightSensor.h"

/**
 * @brief LightSensor_Init
 * @param void
 * @retval void
 */
void LightSensor_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure); // 将PB13初始化为上拉输入
}

/**
 * @brief LightSensor_GetStatus
 * @param void
 * @retval uint8_t 0/1
 */
uint8_t LightSensor_GetStatus(void) {
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
}