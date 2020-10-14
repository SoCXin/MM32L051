#include "sys.h"
#include "uart.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "dac.h"
int main(void)
{
    u32 dacx;
    delay_init();	    	 //��ʱ������ʼ��
    LED_Init();		  	 	//��ʼ����LED���ӵ�Ӳ���ӿ�
    KEY_Init();          	//��ʼ���밴�����ӵ�Ӳ���ӿ�
    Dac1_Init();
    //�ϵ��ʹ�����ñ����PA4(Ain2)��ѹֵ�����ֵ�ѹ��0V�������ϵ������ӽ�3.3V���ִ�ͷ��ʼ��
    while(1)
    {
        DAC->DHR12R1 = dacx;
        delay_ms(150);
        dacx = dacx + 200;
        if(dacx > 4095)
        {
            dacx = 0;
        }

    }
}


























