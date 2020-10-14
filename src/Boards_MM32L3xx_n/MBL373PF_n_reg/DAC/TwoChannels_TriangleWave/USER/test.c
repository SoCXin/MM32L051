#include "sys.h"
#include "uart.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "dac.h"
int main(void)
{
    delay_init();	    	 //��ʱ������ʼ��
    LED_Init();		  	 	//��ʼ����LED���ӵ�Ӳ���ӿ�
    KEY_Init();          	//��ʼ���밴�����ӵ�Ӳ���ӿ�
    TIM2_Trig_DAC_Init();
    Dac1_Init();
    Dac2_Init();
    //�ϵ��ʹ��ʾ��������PA4��PA5����

    DAC->CR |= DAC_CR_EN1; //DACͨ��1ʹ��
    DAC->CR |= ( DAC_CR_EN1 << 16 ); //DACͨ��2ʹ��

    DAC->DHR12RD |= 0x100;
    DAC->DHR12RD |= ( 0x100 << 16 );

    TIM2->CR1 |= 0x0001;
    while(1);
}


























