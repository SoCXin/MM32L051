/**
******************************************************************************
* @file    dac.c
* @author  AE Team
* @version V1.3.9
* @date    28/08/2019
* @brief   This file provides all the dac firmware functions.
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
#include "dac.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/********************************************************************************************************
**������Ϣ ��DAC_Channel_Single(uint32_t DAC_Channel_x)
**�������� ������DACΪ��ͨ���������
**������� ��DAC_Channel_x ,x=1,2
**������� ����
********************************************************************************************************/
void DAC_Channel_Single(uint32_t DAC_Channel_x)
{
    DAC_InitTypeDef  DAC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* DAC Periph clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
    /* GPIOA Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /*ͨ��1��ӦIO��ΪPA4,ͨ��2��ӦIO��ΪPA5,����Ϊģ������*/
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    /* ����Ϊ�������*/
    DAC_InitStructure.DAC_Trigger = DAC_Trigger_Software ;
    DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
    DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;

    DAC_Init(DAC_Channel_x, &DAC_InitStructure);

    DAC_Cmd(DAC_Channel_x, ENABLE);
}
/********************************************************************************************************
**������Ϣ ��DAC_SoftwareTrigger_Data()
**�������� ������DACָ��ͨ�����ݲ�ʹ���������
**������� ��DAC_Channel_x,DACͨ����,x=1,2
uiData ��������
**������� ����
********************************************************************************************************/
void DAC_SoftwareTrigger_Data(uint32_t DAC_Channel_x, uint16_t uiData)
{
    unsigned char ucFlag = 0;
    if(DAC_Channel_x == DAC_Channel_1)
    {
        ucFlag = 1;
        /*����д�Ĺ�����������,��ǰѡ��Ϊ12λ�Ҷ���*/
        DAC_SetChannel1Data(DAC_Align_12b_R, uiData & 0xfff);
    }
    else if(DAC_Channel_x == DAC_Channel_2)
    {
        ucFlag = 1;
        DAC_SetChannel2Data(DAC_Align_12b_R, uiData & 0xfff);
    }
    if(ucFlag == 1)
    {
        DAC_SoftwareTriggerCmd(DAC_Channel_x, ENABLE);
    }
}

