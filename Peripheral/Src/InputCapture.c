//
// Created by Lyu on 2024/3/23.
//
#include "InputCapture.h"


/**
 * @brief 输入捕获模式初始化
 * @note 用于测量频率
 */
void InputCapture_Init(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /*GPIO初始化*/
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置时钟源
    TIM_InternalClockConfig(TIM3);

    // 初始化TIM3
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

    // 初始化TIM3的输入捕获
    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICFilter = 0xF;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
#if defined(Exp_15)
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
#elif defined(Exp_16)
    TIM_PWMIConfig(TIM3, &TIM_ICInitStructure); // 将结构体变量交给TIM_PWMIConfig，配置TIM3的输入捕获通道, 此函数同时会把另一个通道配置为相反的配置，实现PWMI模式
#endif
    /*选择触发源及从模式*/
    TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1); // 触发源选择TI1FP1
    TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);	// 从模式选择复位，即TI1产生上升沿时，会触发CNT归零

    // 使能TIM3
    TIM_Cmd(TIM3, ENABLE);
}

/**
 * @brief 获取输入捕获的频率
 * @return 频率
 */
uint32_t InputCapture_GetFreq(void) {
    return 1000000 / (TIM_GetCapture1(TIM3) + 1);
}

/**
  * 函    数：获取输入捕获的占空比
  * 参    数：无
  * 返 回 值：捕获得到的占空比
  */
uint32_t InputCapture_GetDuty(void)
{
    return (TIM_GetCapture2(TIM3) + 1) * 100 / (TIM_GetCapture1(TIM3) + 1);	// 占空比Duty = CCR2 / CCR1 * 100，这里不执行+1的操作也可
}