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
    Dac1_Init();
    //�ϵ��ʹ��ʾ��������PA4����
    while(1)
    {
        /* Start DAC Channel1 conversion by software */
        DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
    }
}


























