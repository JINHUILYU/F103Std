//
// Created by Lyu on 2024/3/18.
//
#include "Buzzer.h"

/**
 * @brief Buzzer_Init
 * @param void
 * @retval void
 */
void Buzzer_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_SetBits(GPIOB, GPIO_Pin_12); // 初始化为高电平
}

/**
 * @brief Buzzer_ON
 * @param void
 * @retval void
 */
void Buzzer_ON(void) {
    GPIO_ResetBits(GPIOB, GPIO_Pin_12); // 置PB12为低电平
}

/**
 * @brief Buzzer_OFF
 * @param void
 * @retval void
 */
void Buzzer_OFF(void) {
    GPIO_SetBits(GPIOB, GPIO_Pin_12); // 置PB12为高电平
}

/**
 * @brief Buzzer_Turn
 * @param void
 * @retval void
 */
void Buzzer_Turn(void) {
    GPIO_WriteBit(GPIOB, GPIO_Pin_12, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12))); // 置PB12为相反电平
}