#ifndef __AD_H
#define __AD_H

void AD_Init(void);
uint16_t AD_GetValue(uint8_t ADC_Channel);

u16 Get_Adc_Average(u8 ch,u8 times);
#endif
