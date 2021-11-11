/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  */
#include <string.h>
#include "board.h"
#include "hal_key.h"
#include "tim-board.h"
#include "timer_handles.h"

uint16_t tenMSecClick=0;																		// 10�����ʱ��
uint8_t posflag=1;
/**********************************************************************************************
*������void Init( void )
*���ܣ�ƽ̨��ʼ��
*���룺��
*�������
*����˵������
**********************************************************************************************/
void keymode();
void Init() {
    // ������ƽ̨��ʼ��
    BoardInitMcu();
    BoardInitPeriph();

    keys_init();//������ʼ��

    setTimer2Callback(Time2Handler);
    Tim2McuInit(1);//��ʱ����ʼ�������ö�ʱ�ж�1ms�ж�һ��
}

/**********************************************************************************************
*������void KeyDownHandler( void )
*���ܣ���ť�¼�����
*���룺��
*�������
*����˵������
**********************************************************************************************/
void KeyDownHandler(void) {
	
}

/**********************************************************************************************
*������void handlerPre10Ms( void )
*���ܣ�10����ѭ��
*���룺��
*�������
*����˵����ѭ��������ʱ��300ms
**********************************************************************************************/
void handlerPre10Ms(void) {
    for (int delay = 0; delay < 30; delay++) {
        HAL_Delay(10);
        
    }
}

void posdiplay(){
	//81
	uint8_t temp;
  for(temp=2;temp<=6;temp+=2){
		OLED_ShowChar(85,temp,' ');
	}
	OLED_ShowChar(85,posflag*2,'<');
}

void key(){
	if(HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN)==0){
		if(posflag==1)
			posflag=3;
		else
			posflag--;
		posdiplay();
		while(HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN)==0);
	}
	if(HAL_GPIO_ReadPin(KEY3_GPIO, KEY3_GPIO_PIN)==0){
		if(posflag==3)
			posflag=1;
		else
			posflag++;
		posdiplay();
		while(HAL_GPIO_ReadPin(KEY3_GPIO, KEY3_GPIO_PIN)==0);
	}
	if(HAL_GPIO_ReadPin(KEY4_GPIO, KEY4_GPIO_PIN)==0){
		 keymode();
		while(HAL_GPIO_ReadPin(KEY4_GPIO, KEY4_GPIO_PIN)==0);
	}
}
//mod
void keymode(){
	stopLedBreath();
	stopLedBlink();
	GpioWrite( &Led1, 1 ); GpioWrite( &Led2, 1 );
	switch(posflag){
		case 1: GpioWrite( &Led1, 0 ); GpioWrite( &Led2, 0 );break;
		case 2:startLedBreath();break;
		case 3:startLedBlink();break;
	}
}

void display(){
	OLED_Clear();
	//����ģʽ 52 53 54 55
	OLED_ShowCHinese(0,0,52);
	OLED_ShowCHinese(16,0,53);
	OLED_ShowCHinese(32,0,54);
	OLED_ShowCHinese(48,0,55);
	
	//1.����ģʽ
	OLED_ShowString(0,2,"1.");
	OLED_ShowCHinese(16,2,60);
	OLED_ShowCHinese(32,2,52);
	OLED_ShowCHinese(48,2,54);
	OLED_ShowCHinese(64,2,55);
	
	//2.����ģ�
	OLED_ShowString(0,4,"2.");
	OLED_ShowCHinese(16,4,56);
	OLED_ShowCHinese(32,4,57);
	OLED_ShowCHinese(48,4,54);
	OLED_ShowCHinese(64,4,55);
	
	//3.����ģʽ
	OLED_ShowString(0,6,"3.");
	OLED_ShowCHinese(16,6,58);
	OLED_ShowCHinese(32,6,59);
	OLED_ShowCHinese(48,6,54);
	OLED_ShowCHinese(64,6,55);	
	posdiplay();
}

/**
 * Main application entry point.
 */
int main( void )
{
    Init();
		OLED_Init();
		display();
    while( 1 )
    {		
			 key();
    }
}
