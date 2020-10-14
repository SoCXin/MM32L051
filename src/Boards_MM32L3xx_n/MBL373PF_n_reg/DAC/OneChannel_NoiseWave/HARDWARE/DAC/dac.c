#include "dac.h"
#include "uart.h"

void Dac1_Init(void)
{

    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;//ʹ��GPIOAʱ��
    RCC->APB1ENR |= RCC_APB1ENR_DACEN;//ʹ��DACʱ��
    GPIOA->CRL &= 0XFFF0FFFF;//PA4 anolog����

    DAC->CR |= DAC_CR_TSEL1;//�������
    DAC->CR |= DAC_CR_WAVE1_0;//����������
    DAC->CR |= DAC_CR_MAMP1_3;//��������ģʽ��ѡ������λ
    DAC->CR |= 1 << 2;
    DAC->CR &= (~DAC_CR_BOFF1);//DACͨ��1�������ʹ��
    DAC->CR |= DAC_CR_EN1; //DAC1ͨ��ʹ��
    DAC->DHR12L1 = 0x7FF0;

}


