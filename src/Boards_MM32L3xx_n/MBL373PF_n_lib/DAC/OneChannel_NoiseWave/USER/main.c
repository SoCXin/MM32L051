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
*/#include "sys.h"
#include "delay.h"
#include "uart.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Init Structure definition */
DAC_InitTypeDef            DAC_InitStructure;

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);

/* Private functions ---------------------------------------------------------*/

/********************************************************************************************************
**������Ϣ ��int main(void)
**�������� ������DACΪ��ͨ������������������
**������� ����
**������� ����
********************************************************************************************************/
int main(void)
{

    /* System Clocks Configuration */
    RCC_Configuration();

    /* Once the DAC channel is enabled, the corresponding GPIO pin is automatically
    connected to the DAC converter. In order to avoid parasitic consumption,
    the GPIO pin should be configured in analog */
    GPIO_Configuration();

    /* DAC channel1 Configuration */
    DAC_InitStructure.DAC_Trigger = DAC_Trigger_Software;
    DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_Noise;
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bits8_0;
    DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_1, &DAC_InitStructure);

    /* Enable DAC Channel1: Once the DAC channel1 is enabled, PA.04 is
    automatically connected to the DAC converter. */
    DAC_Cmd(DAC_Channel_1, ENABLE);

    /* Set DAC Channel1 DHR12L register */
    DAC_SetChannel1Data(DAC_Align_12b_L, 0x7FF0);//��������룬��������Ҷ��룬����ӦΪ0X7FFF
    while (1)
    {
        /* Start DAC Channel1 conversion by software */
        DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);
    }
}

/********************************************************************************************************
**������Ϣ ��RCC_Configuration(void)
**�������� ��ʱ�ӳ�ʼ��
**������� ����
**������� ����
********************************************************************************************************/
void RCC_Configuration(void)
{
    /* Enable peripheral clocks ------------------------------------------------*/
    /* GPIOA Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    /* DAC Periph clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
}

/********************************************************************************************************
**������Ϣ ��GPIO_Configuration(void)
**�������� ��GPIO��ʼ��
**������� ����
**������� ����
********************************************************************************************************/
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Once the DAC channel is enabled, the corresponding GPIO pin is automatically
    connected to the DAC converter. In order to avoid parasitic consumption,
    the GPIO pin should be configured in analog */
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/********************************************************************************************************
**������Ϣ ��Delay(__IO uint32_t nCount)
**�������� ����ʱ��ʼ��
**������� ����
**������� ����
********************************************************************************************************/
void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
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
