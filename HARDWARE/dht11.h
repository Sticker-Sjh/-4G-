#ifndef __DHT11_H
#define __DHT11_H

#include "stm32f10x.h"
#include "Delay.h"



/* 设置GPIO脚，默认为PB11 */
#define DHT11_IO 		            GPIOA
#define DHT11_PIN		            GPIO_Pin_8
#define DHT11_APB2PeriphRCC     RCC_APB2Periph_GPIOA
/* 初始化函数，如果DHT11存在响应则返回1，否则0 */
u8 DHT11_Init(void);
/* 从DHT11读取数据，没有小数部分 */
 u8 DHT11_Read_Data(u8 *temp,u8 *humi);

#endif

