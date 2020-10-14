#include "dac.h"
#include "uart.h"

void Dac1_Init(void)
{

    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //ʹ��GPIOAʱ��
    RCC->APB1ENR |= RCC_APB1ENR_DACEN; //ʹ��DACʱ��
    GPIOA->CRL &= 0XFFF0FFFF; //PA4 anolog����
    DAC->CR |= DAC_CR_BOFF1; //DAC1�������ر� BOFF1=1
    DAC->CR |= DAC_CR_EN1; //DAC1ͨ��ʹ��
    DAC->DHR12R1 = ~DAC_DHR12R1_DACC1DHR;

}

//����ͨ��1�����ѹ
void Dac1_Set_Vol(u16 vol)
{
    float temp = vol;
    temp /= 1000;
    temp = temp * 4096 / 3.3;
    DAC->DHR12R1 = temp;

}

