/**
******************************************************************************
* @file    wrflash.h
* @author  AE Team
* @version V1.3.9
* @date    28/08/2019
* @brief   This file contains all the functions prototypes for the wrflash firmware
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
#ifndef __ONCHIP_FLASH_H__
#define __ONCHIP_FLASH_H__
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//开发板
//ONCHIP FLASH 驱动代码
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//用户根据自己的需要设置
#define ONCHIP_FLASH_SIZE 128 	 		//所选ONCHIP的FLASH容量大小(单位为K)
#define ONCHIP_FLASH_WREN 1              //使能FLASH写入(0，不是能;1，使能)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH起始地址
#define ONCHIP_FLASH_BASE 0x08000000 	//ONCHIP FLASH的起始地址



u16 ONCHIP_FLASH_ReadHalfWord(u32 faddr);		  //读出半字
void ONCHIP_FLASH_WriteLenByte(u32 WriteAddr, u32 DataToWrite, u16 Len);	//指定地址开始写入指定长度的数据
u32 ONCHIP_FLASH_ReadLenByte(u32 ReadAddr, u16 Len);						//指定地址开始读取指定长度数据
void ONCHIP_FLASH_Write(u32 WriteAddr, u16 *pBuffer, u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void ONCHIP_FLASH_Read(u32 ReadAddr, u16 *pBuffer, u16 NumToRead);   		//从指定地址开始读出指定长度的数据

//测试写入
void Test_Write(u32 WriteAddr, u16 WriteData);
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














