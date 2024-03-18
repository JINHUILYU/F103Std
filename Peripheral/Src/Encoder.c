//
// Created by Lyu on 2024/3/18.
//
#include "Encoder.h"

static int16_t Encoder_Count = 0;

/**
 * @brief Encoder_Init
 * @param void
 * @retval void
 */
void Encoder_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 将PB0和PB1初始化为下拉输入

    // AFIO选择中断引脚
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0); // 将外部中断的0号线映射到GPIOB，即选择PB0为外部中断引脚
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1); // 将外部中断的1号线映射到GPIOB，即选择PB1为外部中断引脚

    // EXTI初始化
    EXTI_InitTypeDef EXTI_InitStructure;						// 定义结构体变量
    EXTI_InitStructure.EXTI_Line = EXTI_Line0 | EXTI_Line1;		// 选择配置外部中断的0号线和1号线
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;					// 指定外部中断线使能
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			// 指定外部中断线为中断模式
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		// 指定外部中断线为下降沿触发
    EXTI_Init(&EXTI_InitStructure);					// 将结构体变量交给EXTI_Init，配置EXTI外设

    // NVIC中断分组
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	// 配置NVIC为分组2
    //即抢占优先级范围：0~3，响应优先级范围：0~3
    //此分组配置在整个工程中仅需调用一次
    //若有多个中断，可以把此代码放在main函数内，while循环之前
    //若调用多次配置分组的代码，则后执行的配置会覆盖先执行的配置

    // NVIC配置
    NVIC_InitTypeDef NVIC_InitStructure;						// 定义结构体变量
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			// 选择配置NVIC的EXTI0线
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				// 指定NVIC线路使能
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// 指定NVIC线路的抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			// 指定NVIC线路的响应优先级为1
    NVIC_Init(&NVIC_InitStructure);				// 将结构体变量交给NVIC_Init，配置NVIC外设

    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			// 选择配置NVIC的EXTI1线
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				// 指定NVIC线路使能
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// 指定NVIC线路的抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			// 指定NVIC线路的响应优先级为2
    NVIC_Init(&NVIC_InitStructure);				// 将结构体变量交给NVIC_Init，配置NVIC外设
}

/**
 * @brief EXTI0_IRQHandler
 * @param void
 * @retval void
 */
int16_t Encoder_GetCount(void) {
    int16_t Temp = 0;
    Temp = Encoder_Count;
    Encoder_Count = 0;
    return Temp;
}

/**
 * @brief EXTI0_IRQHandler
 * @param void
 * @retval void
 */
void EXTI0_IRQHandler(void) {
    // 判断是否是0号线产生的中断
    if (EXTI_GetITStatus(EXTI_Line0) == SET) {
        // 多次判断，防止抖动
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) {
            if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0) {
                Encoder_Count--; // 此方向定义为反转，计数变量自减
            }
        }
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/**
 * @brief EXTI1_IRQHandler
 * @param void
 * @retval void
 */
void EXTI1_IRQHandler(void) {
    // 判断是否是1号线产生的中断
    if (EXTI_GetITStatus(EXTI_Line1) == SET) {
        // 多次判断，防止抖动
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0) {
            if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) {
                Encoder_Count++; // 此方向定义为正转，计数变量自增
            }
        }
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}