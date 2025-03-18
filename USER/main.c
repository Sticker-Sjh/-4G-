#include "sys.h"
#include "delay.h"
#include "SGP30.h"
#include "usart.h"
#include "OLED.h"
#include "AD.h"
#include "LED.h"
#include "lsens.h"
#include "Dht11.h"
#include <stdbool.h> 
#include <string.h>

u8 temp = 0,humi = 0;
uint16_t AD0, AD1;
float raindata; 
char c='C',d='%';
u32 CO2Data,TVOCData;//����CO2Ũ�ȱ�����TVOCŨ�ȱ���

int main(void)
{
	LED2_OFF();
	u32 sgp30_dat;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	delay_init();
	OLED_Init();
	AD_Init();
	LED_Init();
	uart_init(115200);
	SGP30_Init();   //��ʼ��SGP30
	delay_ms(100);
	SGP30_Write(0x20,0x08);
	sgp30_dat = SGP30_Read();//��ȡSGP30��ֵ
	CO2Data = (sgp30_dat & 0xffff0000) >> 16;
	TVOCData = sgp30_dat & 0x0000ffff;	
	while(CO2Data == 400 && TVOCData == 0)
	{
		SGP30_Write(0x20,0x08);
		sgp30_dat = SGP30_Read();//��ȡSGP30��ֵ
		CO2Data = (sgp30_dat & 0xffff0000) >> 16;//ȡ��CO2Ũ��ֵ
		TVOCData = sgp30_dat & 0x0000ffff;			 //ȡ��TVOCֵ
		printf("���ڼ����...\r\n");
		delay_ms(500);
	}
	if(!DHT11_Init()){
		 printf("\r\n����DHT11û����Ӧ...\r\n");
	 }
	 delay_ms(10);	
	 printf("\r\n DHT11�Ѿ���Ӧ\r\n");	
	 init();
	 char data[200];
		//��ʪ��
		OLED_ShowCN(0, 0, 0);
		OLED_ShowCN(16, 0, 1);
		OLED_ShowCN(32, 0, 2);
		OLED_ShowCN(48, 0, 3);
	//���ն�
	  OLED_ShowCN(0, 2, 4);
		OLED_ShowCN(16, 2, 5);
		OLED_ShowCN(32, 2, 2);
	  OLED_ShowCN(48, 2, 3);
	//����ʪ��
	  OLED_ShowCN(0, 4, 6);
		OLED_ShowCN(16, 4, 7);
	  OLED_ShowCN(32, 4, 1);
		OLED_ShowCN(48, 4, 2);
	  OLED_ShowCN(64, 4, 3);
	//����Ũ��
		OLED_ShowCN(0, 6, 8);
		OLED_ShowCN(16, 6, 9);
	  OLED_ShowCN(32, 6, 10);
		OLED_ShowCN(48, 6, 2);
	  OLED_ShowCN(64, 6, 3);
	while(1)
	{
		//��ʪ��
		DHT11_Read_Data(&temp,&humi);
		char ss[30];sprintf(ss,"%d%c %d%c",temp,c,humi,d);
		OLED_ShowString(1,8,ss);
		//���ն�
		AD0 = Lsens_Get_Val();	
		char s[30];sprintf(s,"%dLm",AD0);
	  OLED_ShowString(2,8,s);
		
		//����ʪ��
	  AD1 = Get_Adc_Average(ADC_Channel_1,20);
	  raindata = (float)(4096-AD1)/(4096-1924)*100;
		raindata=raindata+20;
		if(raindata<=0.0){raindata=0.0;}
		if(raindata>=100.0){raindata=99.0;}
		char sss[10];sprintf(sss,"%.1f%c",raindata,d);
		OLED_ShowString(3,10,sss);
		//����Ũ��
		SGP30_Write(0x20,0x08);
		sgp30_dat = SGP30_Read();//��ȡSGP30��ֵ
		CO2Data = (sgp30_dat & 0xffff0000) >> 16;//ȡ��CO2Ũ��ֵ
		TVOCData = sgp30_dat & 0x0000ffff;       //ȡ��TVOCֵ
//		char aa[30];
//		if(TVOCData<10){
//		sprintf(aa,"00%dppb",TVOCData);}
//		else{
//			sprintf(aa,"0%dppb",TVOCData);
//		}OLED_ShowString(4,10,aa);
//		delay_ms(500);
		char a[30];sprintf(a,"%dppm",CO2Data);
		OLED_ShowString(4,10,a);
		bool gpioL = (GPIO_ReadOutputDataBit(LED_IO, LED_PIN) != 0);
		bool gpioD = (GPIO_ReadOutputDataBit(LED_IO, Water_PIN) != 0);
		bool gpioW = (GPIO_ReadOutputDataBit(LED_IO, Wind_PIN) != 0);
		sprintf(data, "#%d#%d#%d#%.1f#%d#%d#%s#%s#%s",temp,humi,AD0,raindata,CO2Data,TVOCData,gpioL ? "on" : "off",gpioD ? "on" : "off",gpioW ? "on" : "off");
		POST("temp004", data);
		GET("led002"); 

	}
}


