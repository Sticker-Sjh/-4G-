#include "stm32f10x.h"                  // Device header
#include "LED.h"

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = LED_PIN | GPIO_Pin_13 | Wind_PIN | Water_PIN | Power_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_IO, &GPIO_InitStructure);
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_ResetBits(LED_IO, LED_PIN);
	GPIO_ResetBits(LED_IO,Wind_PIN);
	GPIO_ResetBits(LED_IO,Water_PIN);
	GPIO_ResetBits(LED_IO,Power_PIN);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}


void LED1_OFF(void)
{
	GPIO_ResetBits(LED_IO, LED_PIN);
}

void LED1_ON(void)
{
	GPIO_SetBits(LED_IO, LED_PIN);
}

void Wind_ON(void)
{
	GPIO_ResetBits(LED_IO, Wind_PIN);
}

void Wind_OFF(void)
{
	GPIO_SetBits(LED_IO, Wind_PIN);
}

void Water_ON(void)
{
	GPIO_SetBits(LED_IO, Water_PIN);
}

void Water_OFF(void)
{
	GPIO_ResetBits(LED_IO, Water_PIN);
}
void Power_ON(void)
{
	GPIO_SetBits(LED_IO, Power_PIN);
}

void Power_OFF(void)
{
	GPIO_ResetBits(LED_IO, Power_PIN);
}

void LED1_Turn(void)
{
	if (GPIO_ReadOutputDataBit(LED_IO, LED_PIN) == 0)
	{
		GPIO_SetBits(LED_IO, LED_PIN);
	}
	else
	{
		GPIO_ResetBits(LED_IO, LED_PIN);
	}
}



void LED2_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}

void LED2_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) == 0)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
	}
	else
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	}
}
