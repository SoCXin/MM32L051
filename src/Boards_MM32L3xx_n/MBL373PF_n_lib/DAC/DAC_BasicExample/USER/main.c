/**
******************************************************************************
* @file    main.c
* @author  AE Team
* @version V1.3.9
* @date    28/08/2019
* @brief   This file provides all the main firmware functions.
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
#include "sys.h"
#include "delay.h"
#include "uart.h"
#include "dac.h"

void GPIO_Configuration(void);
/********************************************************************************************************
**������Ϣ ��int main (void)
**�������� ������PA4��ѹֵ����ѹ��Լ0.4V������,3.2Vʱ�ִ�0V��ʼ����
**������� ����
**������� ����
********************************************************************************************************/
int main(void)
{
    unsigned int uiDACData = 0;
    delay_init();	    	 //��ʱ������ʼ��
    /*DACͨ��1��ʼ��,Ϊ��ͨ���������ģʽ*/
    DAC_Channel_Single(DAC_Channel_1) ;

    while(1)//����ѭ��
    {
        /*DACͨ��1���,��ѹ��Լ0.4V������,3.2Vʱ�ִ�0V��ʼ����*/
        DAC_SoftwareTrigger_Data(DAC_Channel_1, uiDACData);
        uiDACData += 500;
        if(uiDACData > 4095)
        {
            uiDACData = 0;
        }
        delay_ms(1000);
    }
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

