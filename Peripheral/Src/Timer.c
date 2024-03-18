//
// Created by Lyu on 2024/3/18.
//
#include "Timer.h"

/**
 * @brief 定时器初始化
 * @param void
 * @retval void
*/
void Timer_Init(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = 1000 - 1;                            // 计数周期，即ARR的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;                           // 预分频器，即PSC的值
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 // 时钟分频，选择不分频，此参数用于配置滤波器时钟，不影响时基单元功能
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;             // 计数器计数模式，选择向上计数
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;			            // 重复计数器，高级定时器才会用到
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    // 中断输出配置
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    // 开启中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    // NVIC中断分组
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    // NVIC配置
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM2, ENABLE);
}

/* 定时器中断函数，可以复制到使用它的地方
void TIM2_IRQHandler(void) {
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
*/