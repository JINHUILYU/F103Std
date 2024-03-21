//#define Exp_1 // LED闪烁
//#define Exp_2 // LED流水灯
//#define Exp_3 // 蜂鸣器
//#define Exp_4 // 按键控制LED
//#define Exp_5 // 光敏传感器控制蜂鸣器
//#define Exp_6 // OLED显示
//#define Exp_7 // 对射式红外传感器
//#define Exp_8 // 旋转编码器
//#define Exp_9 // 定时器定时中断
//#define Exp_10 // 串口发送
#define Exp_11 // 串口发送+接收


#ifdef Exp_1
#include "stm32f10x.h"
#include "Delay.h"
#endif

#ifdef Exp_2
#include "stm32f10x.h"
#include "Delay.h"
#endif

#ifdef Exp_3
#include "stm32f10x.h"
#include "Delay.h"
#endif

#ifdef Exp_4
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#endif

#ifdef Exp_5
#include "stm32f10x.h"
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"
#endif

#ifdef Exp_6
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#endif

#ifdef Exp_7
#include "stm32f10x.h"
#include "Delay.h"
#include "CountSensor.h"
#include "OLED.h"
#endif

#ifdef Exp_8
#include "stm32f10x.h"
#include "Encoder.h"
#include "OLED.h"
#include "Delay.h"

int16_t Num = 0;
#endif

#ifdef Exp_9
#include "stm32f10x.h"
#include "Timer.h"
#include "Delay.h"
#include "OLED.h"

uint16_t Num = 0;

void TIM2_IRQHandler(void);
#endif

#ifdef Exp_10
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;			//定义用于接收串口数据的变量
#endif

#ifdef Exp_11
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;			//定义用于接收串口数据的变量
#endif

int main(void) {
#ifdef Exp_1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    while (1)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
        Delay_ms(500);
        GPIO_SetBits(GPIOA, GPIO_Pin_0);
        Delay_ms(500);

        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
        Delay_ms(500);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
        Delay_ms(500);

        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0);
        Delay_ms(500);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);
        Delay_ms(500);
    }
#endif

#ifdef Exp_2
    // 使能GPIOA的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 初始化GPIOA的引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    while (1) {
        GPIO_Write(GPIOA, ~0x0001); // 0000 0000 0000 0001，PA0引脚为低电平，其他引脚均为高电平，注意数据有按位取反
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0002); // 0000 0000 0000 0010，PA1引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0004); // 0000 0000 0000 0100，PA2引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0008); // 0000 0000 0000 1000，PA3引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0010); // 0000 0000 0001 0000，PA4引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0020); // 0000 0000 0010 0000，PA5引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0040); // 0000 0000 0100 0000，PA6引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
        GPIO_Write(GPIOA, ~0x0080); // 0000 0000 1000 0000，PA7引脚为低电平，其他引脚均为高电平
        Delay_ms(100);
    }
#endif

#ifdef Exp_3
    // 使能GPIOB的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 初始化GPIOB的引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    while (1) {
        GPIO_ResetBits(GPIOB, GPIO_Pin_12); // 将PB12引脚置低电平，蜂鸣器响
        Delay_ms(100);
        GPIO_SetBits(GPIOB, GPIO_Pin_12); // 将PB12引脚置高电平，蜂鸣器不响
        Delay_ms(100);
    }
#endif

#ifdef Exp_4
    Key_Init();
    LED_Init();

    while (1) {
        switch (Key_GetNum()) {
            case 1:
                LED1_Turn();
                break;
            case 2:
                LED2_Turn();
                break;
            default:
                break;
        }
    }
#endif

#ifdef Exp_5
    LightSensor_Init();
    Buzzer_Init();

    while (1) {
        if (LightSensor_GetStatus()) {
            Buzzer_ON();
        } else {
            Buzzer_OFF();
        }
    }
#endif

#ifdef Exp_6
    OLED_Init();
    OLED_ShowChar(1, 1, 'A'); // 在第1行第1列显示字符A
    OLED_ShowString(1, 3, "Hello, World!");    // 在第1行第3列显示字符串Hello, World!
    OLED_ShowNum(2, 1, 12345, 5);      // 在第2行第1列显示数字12345，共5位
    OLED_ShowSignedNum(2, 7, -66, 2);  // 在第2行第7列显示有符号十进制数字-66，长度为2
    OLED_ShowHexNum(3, 1, 0xAA55, 4);  // 在第3行第1列显示十六进制数字0xA5A5，长度为4
    OLED_ShowBinNum(4, 1, 0xAA55, 16); // 在第4行第1列显示二进制数字0xA5A5，长度为16
    while (1);
#endif

#ifdef Exp_7
    CountSensor_Init();
    OLED_Init();

    OLED_ShowString(1, 1, "Count:"); // 在第1行第1列显示字符串Count: (Count:

    while (1) {
        OLED_ShowNum(1, 7, CountSensor_GetCount(), 5);
    }
#endif

#ifdef Exp_8
    Encoder_Init();
    OLED_Init();
    OLED_ShowString(1, 1, "Count:"); // 在第1行第1列显示字符串Count:
    while (1) {
        Num += Encoder_GetCount();
        OLED_ShowNum(1, 7, Num, 5);
    }
#endif

#ifdef Exp_9
    Timer_Init();
    OLED_Init();
    OLED_ShowString(1, 1, "Num:"); // 在第1行第1列显示字符串Count:
    while (1) {
        OLED_ShowNum(1, 5, Num, 5);
    }
#endif

#ifdef Exp_10
    /*模块初始化*/
    OLED_Init();						//OLED初始化

    Serial_Init();						//串口初始化

    /*串口基本函数*/
    Serial_SendByte(0x41);				//串口发送一个字节数据0x41

    uint8_t MyArray[] = {0x42, 0x43, 0x44, 0x45};	//定义数组
    Serial_SendArray(MyArray, 4);		//串口发送一个数组

    Serial_SendString("\r\nNum1=");		//串口发送字符串

    Serial_SendNumber(111, 3);			//串口发送数字

    /*下述3种方法可实现printf的效果*/

    /*方法1：直接重定向printf，但printf函数只有一个，此方法不能在多处使用*/
    printf("\r\nNum2=%d", 222);			//串口发送printf打印的格式化字符串
    //需要重定向fputc函数，并在工程选项里勾选Use MicroLIB

    /*方法2：使用sprintf打印到字符数组，再用串口发送字符数组，此方法打印到字符数组，之后想怎么处理都可以，可在多处使用*/
    char String[100];					//定义字符数组
    sprintf(String, "\r\nNum3=%d", 333);//使用sprintf，把格式化字符串打印到字符数组
    Serial_SendString(String);			//串口发送字符数组（字符串）

    /*方法3：将sprintf函数封装起来，实现专用的printf，此方法就是把方法2封装起来，更加简洁实用，可在多处使用*/
    Serial_Printf("\r\nNum4=%d", 444);	//串口打印字符串，使用自己封装的函数实现printf的效果
    Serial_Printf("\r\n");

    while (1)
    {

    }
#endif

#ifdef Exp_11
    /*模块初始化*/
    OLED_Init();		//OLED初始化

    /*显示静态字符串*/
    OLED_ShowString(1, 1, "RxData:");

    /*串口初始化*/
    Serial_Init();		//串口初始化

    while (1)
    {
        if (Serial_GetRxFlag() == 1)			//检查串口接收数据的标志位
        {
            RxData = Serial_GetRxData();		//获取串口接收的数据
            Serial_SendByte(RxData);			//串口将收到的数据回传回去，用于测试
            OLED_ShowHexNum(1, 8, RxData, 2);	//显示串口接收的数据
        }
    }
#endif

}

#ifdef Exp_9
void TIM2_IRQHandler(void) {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        Num++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
#endif