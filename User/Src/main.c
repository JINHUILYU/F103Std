#include "main.h"

int main(void) {
#if defined(Exp_1)
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

#elif defined(Exp_2)
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

#elif defined(Exp_3)
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

#elif defined(Exp_4)
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

#elif defined(Exp_5)
    LightSensor_Init();
    Buzzer_Init();

    while (1) {
        if (LightSensor_GetStatus()) {
            Buzzer_ON();
        } else {
            Buzzer_OFF();
        }
    }

#elif defined(Exp_6)
    OLED_Init();
    OLED_ShowChar(1, 1, 'A'); // 在第1行第1列显示字符A
    OLED_ShowString(1, 3, "Hello, World!");    // 在第1行第3列显示字符串Hello, World!
    OLED_ShowNum(2, 1, 12345, 5);      // 在第2行第1列显示数字12345，共5位
    OLED_ShowSignedNum(2, 7, -66, 2);  // 在第2行第7列显示有符号十进制数字-66，长度为2
    OLED_ShowHexNum(3, 1, 0xAA55, 4);  // 在第3行第1列显示十六进制数字0xA5A5，长度为4
    OLED_ShowBinNum(4, 1, 0xAA55, 16); // 在第4行第1列显示二进制数字0xA5A5，长度为16
    while (1);

#elif defined(Exp_7)
    CountSensor_Init();
    OLED_Init();

    OLED_ShowString(1, 1, "Count:"); // 在第1行第1列显示字符串Count: (Count:

    while (1) {
        OLED_ShowNum(1, 7, CountSensor_GetCount(), 5);
    }

#elif defined(Exp_8)
    Encoder_Init();
    OLED_Init();
    OLED_ShowString(1, 1, "Count:"); // 在第1行第1列显示字符串Count:
    while (1) {
        Num += Encoder_GetCount();
        OLED_ShowNum(1, 7, Num, 5);
    }

#elif defined(Exp_9)
    Timer_Init();
    OLED_Init();
    OLED_ShowString(1, 1, "Num:"); // 在第1行第1列显示字符串Count:
    while (1) {
        OLED_ShowNum(1, 5, Num, 5);
    }

#elif defined(Exp_10)
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
#elif defined(Exp_11)
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

#elif defined(Exp_12)
    OLED_Init();
    PWM_Init();
    while (1) {
        for (int i = 0; i <= 100; i++) {
            PWM_SetCompare1(i);
            Delay_ms(10);
        }
        for (int i = 100; i >= 0; i--) {
            PWM_SetCompare1(i);
            Delay_ms(10);
        }
    }

#elif defined(Exp_13)
    OLED_Init();
    Servo_Init();
    Key_Init();
    uint8_t KeyNum;
    float Angle;
    OLED_ShowString(1, 1, "Angle:");
    Servo_SetAngle(90);
    while (1) {
        KeyNum = Key_GetNum();
        if (KeyNum == 1) {
            Angle += 30;
            if (Angle > 180) {
                Angle = 0;
            }
            Servo_SetAngle(Angle);
        }
        Servo_SetAngle(Angle);
        OLED_ShowNum(1, 7, Angle, 3);
    }

#elif defined(Exp_14)
    OLED_Init();
    Motor_Init();
    Key_Init();

    uint8_t KeyNum;
    int8_t Speed;

    OLED_ShowString(1, 1, "Speed:");

    while (1) {
        KeyNum = Key_GetNum();				//获取按键键码
        if (KeyNum == 1)					//按键1按下
        {
            Speed += 20;					//速度变量自增20
            if (Speed > 100)				//速度变量超过100后
            {
                Speed = -100;				//速度变量变为-100
                //此操作会让电机旋转方向突然改变，可能会因供电不足而导致单片机复位
                //若出现了此现象，则应避免使用这样的操作
            }
        }
        Motor_SetSpeed(Speed);				//设置直流电机的速度为速度变量
        OLED_ShowSignedNum(1, 7, Speed, 3);	//OLED显示速度变量
    }

#elif defined(Exp_15)
    OLED_Init();
    PWM_Init();
    InputCapture_Init();
    OLED_ShowString(1, 1, "Freq:00000Hz");
    PWM_SetPrescaler(360 - 1); // PWM频率Freq = 72M / (PSC + 1) / 100
    PWM_SetCompare1(50); // PWM占空比Duty = CCR / 100
    while (1) {
        OLED_ShowNum(1, 6, InputCapture_GetFreq(), 5);
    }

#elif defined(Exp_16)
    OLED_Init();
    PWM_Init();
    InputCapture_Init();
    OLED_ShowString(1, 1, "Freq:00000Hz");
    OLED_ShowString(2, 1, "Duty:00%");
    PWM_SetPrescaler(360 - 1); // PWM频率Freq = 72M / (PSC + 1) / 100
    PWM_SetCompare1(20); // PWM占空比Duty = CCR / 100
    while (1) {
        OLED_ShowNum(1, 6, InputCapture_GetFreq(), 5);
        OLED_ShowNum(2, 6, InputCapture_GetDuty(), 2);
    }

#elif defined(Exp_17)
    int16_t AX, AY, AZ, GX, GY, GZ;
    OLED_Init();
    MPU6050_Init();
    OLED_ShowString(1, 1, "ID:");		//显示静态字符串
    uint8_t ID = MPU6050_GetID();				//获取MPU6050的ID号
    OLED_ShowHexNum(1, 4, ID, 2);		//OLED显示ID号
    while (1) {
        MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);		//获取MPU6050的数据
        OLED_ShowSignedNum(2, 1, AX, 5);					//OLED显示数据
        OLED_ShowSignedNum(3, 1, AY, 5);
        OLED_ShowSignedNum(4, 1, AZ, 5);
        OLED_ShowSignedNum(2, 8, GX, 5);
        OLED_ShowSignedNum(3, 8, GY, 5);
        OLED_ShowSignedNum(4, 8, GZ, 5);
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