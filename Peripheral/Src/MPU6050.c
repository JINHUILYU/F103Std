//
// Created by Lyu on 2024/3/26.
//
#include "MPU6050.h"

void MPU6050_WriteReg(uint8_t RegAddr, uint8_t RegData) {
    MyI2C_Start();
    MyI2C_SendByte(MPU6050_ADDR);
    MyI2C_ReceiveACK();
    MyI2C_SendByte(RegAddr);
    MyI2C_ReceiveACK();
    MyI2C_SendByte(RegData);
    MyI2C_ReceiveACK();
    MyI2C_Stop();
}

uint8_t MPU6050_ReadReg(uint8_t RegAddr) {
    uint8_t RegData;
    MyI2C_Start();
    MyI2C_SendByte(MPU6050_ADDR);
    MyI2C_ReceiveACK();
    MyI2C_SendByte(RegAddr);
    MyI2C_ReceiveACK();
    MyI2C_Start();
    MyI2C_SendByte(MPU6050_ADDR | 0x01);
    MyI2C_ReceiveACK();
    RegData = MyI2C_ReceiveByte();
    MyI2C_SendACK(1);
    MyI2C_Stop();
    return RegData;
}

void MPU6050_Init(void) {
    MyI2C_Init();
    MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01); // 电源管理寄存器1，取消睡眠模式，选择时钟源为X轴陀螺仪
    MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00); // 电源管理寄存器2，保持默认值0，所有轴均不待机
    MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x09); // 采样率分频寄存器，配置采样率
    MPU6050_WriteReg(MPU6050_CONFIG, 0x06); // 配置寄存器，配置DLPF
    MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18); // 陀螺仪配置寄存器，选择满量程为±2000°/s
    MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18); // 加速度计配置寄存器，选择满量程为±16g
}

uint8_t MPU6050_GetID(void) {
    return MPU6050_ReadReg(MPU6050_WHO_AM_I);
}

void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
                     int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ)
{
    uint16_t DataH, DataL;								//定义数据高8位和低8位的变量

    DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);		//读取加速度计X轴的高8位数据
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);		//读取加速度计X轴的低8位数据
    *AccX = (int16_t)((DataH << 8) | DataL);						//数据拼接，通过输出参数返回

    DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);		//读取加速度计Y轴的高8位数据
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);		//读取加速度计Y轴的低8位数据
    *AccY = (int16_t)((DataH << 8) | DataL);						//数据拼接，通过输出参数返回

    DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);		//读取加速度计Z轴的高8位数据
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);		//读取加速度计Z轴的低8位数据
    *AccZ = (int16_t)((DataH << 8) | DataL);						//数据拼接，通过输出参数返回

    DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);		//读取陀螺仪X轴的高8位数据
    DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);		//读取陀螺仪X轴的低8位数据
    *GyroX = (int16_t)((DataH << 8) | DataL);						//数据拼接，通过输出参数返回

    DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);		//读取陀螺仪Y轴的高8位数据
    DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);		//读取陀螺仪Y轴的低8位数据
    *GyroY = (int16_t)((DataH << 8) | DataL);						//数据拼接，通过输出参数返回

    DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);		//读取陀螺仪Z轴的高8位数据
    DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);		//读取陀螺仪Z轴的低8位数据
    *GyroZ = (int16_t)((DataH << 8) | DataL);						//数据拼接，通过输出参数返回
}