#ifndef __DHT11_H
#define __DHT11_H

#include "stm32f10x.h"
#include "Delay.h"



/* ����GPIO�ţ�Ĭ��ΪPB11 */
#define DHT11_IO 		            GPIOA
#define DHT11_PIN		            GPIO_Pin_8
#define DHT11_APB2PeriphRCC     RCC_APB2Periph_GPIOA
/* ��ʼ�����������DHT11������Ӧ�򷵻�1������0 */
u8 DHT11_Init(void);
/* ��DHT11��ȡ���ݣ�û��С������ */
 u8 DHT11_Read_Data(u8 *temp,u8 *humi);

#endif

