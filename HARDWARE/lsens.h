#ifndef __LSENS_H
#define __LSENS_H	
#include "stm32f10x.h"                  // Device header

#include "ad.h" 

#define LSENS_READ_TIMES	10		//���������������ȡ����,����ô���,Ȼ��ȡƽ��ֵ
#define LSENS_ADC_CHX		ADC_Channel_0	//����������������ڵ�ADCͨ�����
    
void Lsens_Init(void); 				//��ʼ������������
u8 Lsens_Get_Val(void);				//��ȡ������������ֵ
#endif 





















