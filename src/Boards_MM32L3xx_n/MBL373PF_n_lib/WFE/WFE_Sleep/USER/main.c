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
#include "sleep.h"

/********************************************************************************************************
**������Ϣ ��int main (void)
**�������� ��
**������� ��
**������� ��
**���ú��� ��
********************************************************************************************************/
int main(void)
{

    delay_init();	    	 //��ʱ������ʼ��
    uart_initwBaudRate(115200);	 //���ڳ�ʼ��Ϊ115200
    printf("sleep mode ! \r\n");
    sleep_test();

    //����K2��������
    while(1)//����ѭ��
    {
        printf("Wake Up ! \r\n");
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


