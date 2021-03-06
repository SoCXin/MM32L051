/**
******************************************************************************
* @file    wkup.c
* @author  AE Team
* @version V1.3.9
* @date    28/08/2019
* @brief   This file provides all the wkup firmware functions.
******************************************************************************
* @copy
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, MindMotion SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2019 MindMotion</center></h2>
*/
#include "wkup.h"
#include "led.h"
#include "delay.h"
/********************************************************************************************************
**函数信息 ：Sys_Standby(void)
**功能描述 ：进入待机模式
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/
void Sys_Standby(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);	//使能PWR外设时钟
    RCC->APB2RSTR |= 0X01FC; //复位所有IO口
    PWR_WakeUpPinCmd(ENABLE);  //使能唤醒管脚功能
    PWR_EnterSTANDBYMode();	  //进入待命（STANDBY）模式

}

/********************************************************************************************************
**函数信息 ：Check_WKUP(void)
**功能描述 ：判断按键是否按下
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/
u8 Check_WKUP(void)
{
    u8 t = 0;	//记录按下的时间
    LED1 = 0; //亮灯DS0
    LED2 = 0; //亮灯DS0
    LED3 = 0; //亮灯DS0
    LED4 = 0;
    while(1)
    {
        if(WKUP_KD)
        {
            t++;			//已经按下了
            delay_ms(30);
            if(t >= 100)		//按下超过3秒钟
            {
                LED1 = 0;	 	//点亮DS0
                LED2 = 0;	 	//点亮DS0
                LED3 = 0;	 	//点亮DS0
                LED4 = 0;
                return 1; 	//按下3s以上了
            }
        }
        else
        {
            LED1 = 1;
            LED2 = 1;
            LED3 = 1;
            LED4 = 1;
            return 0; //按下不足3秒
        }
    }
}
/********************************************************************************************************
**函数信息 ：EXTI0_IRQHandler(void)
**功能描述 ：外部中断0，进入后清除中断标志位
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/
void EXTI0_IRQHandler(void)
{
    EXTI_ClearITPendingBit(EXTI_Line0); // 清除LINE10上的中断标志位
}


/********************************************************************************************************
**函数信息 ：WKUP_Init(void)
**功能描述 ：外部中断唤醒待机初始化
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/
void WKUP_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);//使能GPIOA和复用功能时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	 //PA.0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);	//初始化IO
    //使用外部中断方式
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);	//中断线0连接GPIOA.0

    EXTI_InitStructure.EXTI_Line = EXTI_Line0;	//设置按键所有的外部线路
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//设外外部中断模式:EXTI线路为中断请求
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  //上升沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);	// 初始化外部中断

    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; //使能按键所在的外部中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级2级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; //从优先级2级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

    if(Check_WKUP() == 0) Sys_Standby();  //不是开机,进入待机模式
}

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

/*-------------------------(C) COPYRIGHT 2019 MindMotion ----------------------*/














