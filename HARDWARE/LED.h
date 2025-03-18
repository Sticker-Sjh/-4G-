#ifndef __LED_H
#define __LED_H

#define LED_IO 		            GPIOB
#define LED_PIN		            GPIO_Pin_15
#define Water_PIN		          GPIO_Pin_14
#define Wind_PIN		          GPIO_Pin_12
#define Power_PIN		          GPIO_Pin_13
#define LED_APB2PeriphRCC     RCC_APB2Periph_GPIOB



void LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void Wind_ON(void);
void Wind_OFF(void);
void Water_ON(void);
void Water_OFF(void);
void Power_ON(void);
void Power_OFF(void);
void LED1_Turn(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED2_Turn(void);

#endif
