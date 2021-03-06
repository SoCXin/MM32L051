/**--------------File Info---------------------------------------------------------------------------------
** File name:		  	sleep.c
** Descriptions:		    main 函数调用
**
*********************************************************************************************************/
#include "sleep.h"
#include "key.h"
void GPIO_Configuration(void)
{

    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //RCC->APB2ENR|=1<<2;  //使能GPIOA时钟
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; //RCC->APB2ENR|=1<<3;  //使能GPIOB时钟

    KEY_Init();
    /*选择PA0位外部事件触发输入*/
    Ex_NVIC_Config(GPIO_A, 0, FTIR);
    EXTI->EMR |= 1; //  开启line0 事件

    /*不配置可嵌入中断向量,只做唤醒事件,对应位没有挂起,所以无需清除事件位*/
}
/********************************************************************************************************
**函数信息 ：SysInit(void)
**功能描述 ：睡眠指令
**输入参数 ：无
**输出参数 ：无
**    备注 ：
********************************************************************************************************/
void sleep_test(void)
{
    GPIO_Configuration();
    __WFE();
}
