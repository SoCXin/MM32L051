/**
******************************************************************************
* @file    key.h
* @author  AE Team
* @version V1.3.9
* @date    28/08/2019
* @brief   This file contains all the functions prototypes for the key firmware
*          library.
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

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __KEY_H
#define __KEY_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//������
//������������
//////////////////////////////////////////////////////////////////////////////////


#define KEY1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//��ȡ����1
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����2 
#define KEY3  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)//��ȡ����3
#define KEY4  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)//��ȡ����4

#define KEY1_PRES	1		//KEY1 
#define WKUP_PRES	2		//WK_UP  
#define KEY3_PRES	3		//KEY3 
#define KEY4_PRES	4		//KEY4 
void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��
#endif

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