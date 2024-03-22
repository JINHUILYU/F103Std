//
// Created by Lyu on 2024/3/22.
//
#include "PWM.h"

/**
 * @brief PWM初始化
 * @param void
 * @retval void
 */
void PWM_Init() {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /*GPIO重映射*/
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);			// 开启AFIO的时钟，重映射必须先开启AFIO的时钟
//	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);			// 将TIM2的引脚部分重映射，具体的映射方案需查看参考手册
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);		// 将JTAG引脚失能，作为普通GPIO引脚使用

    GPIO_InitTypeDef GPIO_InitStructure;
#ifdef Exp_12
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // PWM呼吸灯
    //    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15; // 重映射前为GPIO_Pin_0;
#endif

#ifdef Exp_13
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // PWM驱动舵机
#endif

#ifdef Exp_14
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; // PWM驱动电机
#endif

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
#ifdef Exp_12
    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;                            // 计数周期，即ARR的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;                           // 预分频器，即PSC的值
#endif

#ifdef Exp_13
    TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;                            // 计数周期，即ARR的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;
#endif

#ifdef Exp_14
    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;                            // 计数周期，即ARR的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;                           // 预分频器，即PSC的值
#endif

    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 // 时钟分频，选择不分频，此参数用于配置滤波器时钟，不影响时基单元功能
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;             // 计数器计数模式，选择向上计数
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;			            // 重复计数器，高级定时器才会用到
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;                          // PWM模式1
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;               // 输出使能
    TIM_OCInitStructure.TIM_Pulse = 0;                                       // 设置CCR寄存器的值
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;                   // 输出极性
#ifdef Exp_12
    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
#endif

#ifdef Exp_13
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
#endif

#ifdef Exp_14
    TIM_OC3Init(TIM2, &TIM_OCInitStructure);
#endif

    TIM_Cmd(TIM2, ENABLE);
}

/**
 * @brief 设置PWM占空比
 * @param Compare 占空比
 * @retval void
 */
void PWM_SetCompare1(uint16_t Compare) {
    TIM_SetCompare1(TIM2, Compare);
}

void PWM_SetCompare2(uint16_t Compare) {
    TIM_SetCompare2(TIM2, Compare);
}

void PWM_SetCompare3(uint16_t Compare) {
    TIM_SetCompare3(TIM2, Compare);
}