//
// Created by Lyu on 2024/3/18.
//
#include "LED.h"

/**
 * @brief  LED_Init
 * @note   初始化LED
 * @param  None
 * @retval None
 */
void LED_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure); // 将PA1和PA2初始化为推挽输出

    GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2); // 初始化为高电平
}

/**
 * @brief  LED1_ON
 * @note   LED1亮
 * @param  None
 * @retval None
 */
void LED1_ON(void) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_1); // 置PA1为低电平
}

/**
 * @brief  LED1_OFF
 * @note   LED1灭
 * @param  None
 * @retval None
 */
void LED1_OFF(void) {
    GPIO_SetBits(GPIOA, GPIO_Pin_1); // 置PA1为高电平
}

/**
 * @brief  LED1_Turn
 * @note   LED1翻转
 * @param  None
 * @retval None
 */
void LED1_Turn(void) {
    GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1))); // 置PA1为相反电平
}

/**
 * @brief  LED2_ON
 * @note   LED2亮
 * @param  None
 * @retval None
 */
void LED2_ON(void) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_2); // 置PA2为低电平
}

/**
 * @brief  LED2_OFF
 * @note   LED2灭
 * @param  None
 * @retval None
 */
void LED2_OFF(void) {
    GPIO_SetBits(GPIOA, GPIO_Pin_2); // 置PA2为高电平
}

/**
 * @brief  LED2_Turn
 * @note   LED2翻转
 * @param  None
 * @retval None
 */
void LED2_Turn(void) {
    GPIO_WriteBit(GPIOA, GPIO_Pin_2, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2))); // 置PA2为相反电平
}