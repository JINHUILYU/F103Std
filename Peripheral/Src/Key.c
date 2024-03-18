//
// Created by Lyu on 2024/3/18.
//
#include "Key.h"

/**
 * @brief  Key_Init
 * @note   初始化按键
 * @param  None
 * @retval None
 */
void Key_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 将PB1和PB11初始化为上拉输入
}

/**
 * @brief  Key_GetNum
 * @note   获取按键编号
 * @param  None
 * @retval uint8_t 0~2
 */
uint8_t Key_GetNum(void) {
    uint8_t Key_Num = 0;
    // 读PB1输入寄存器的状态，如果为0，则代表按键1按下
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0) {
        Delay_ms(10); // 延时消抖
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0); // 等待按键释放
        Delay_ms(10); // 延时消抖
        Key_Num = 1;
    }
    // 读PB11输入寄存器的状态，如果为0，则代表按键2按下
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0) {
        Delay_ms(10); // 延时消抖
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0); // 等待按键释放
        Delay_ms(10); // 延时消抖
        Key_Num = 2;
    }

    return Key_Num;
}