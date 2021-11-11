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
#include "stdio.h"
#define DATA 0x0800F000

uint16_t flashfirst=1;
uint16_t tenMSecClick=0;																		// 10�����ʱ��
uint32_t flashsave=0; //n

uint8_t led2flag=0;

uint8_t X[64];
uint8_t Y[64];
/**********************************************************************************************
*������void Init( void )
*���ܣ�ƽ̨��ʼ��
*���룺��
*�������
*����˵������
**********************************************************************************************/
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

void xrflash(){

}



void oleddisplay(){
	OLED_Clear();
	OLED_ShowCHinese(44,0,52);
	OLED_ShowCHinese(60,0,53);
	OLED_ShowCHinese(76,0,12);
	
	OLED_ShowCHinese(10,3,53);
	OLED_ShowCHinese(26,3,54);
	OLED_ShowChar(40,3,':');
	
	OLED_ShowCHinese(10,6,55);
	OLED_ShowCHinese(26,6,56);
	OLED_ShowChar(40,6,':');
}

void oledjsqdiplay(){
	OLED_ShowString(70,3,"     ");
	OLED_ShowString(70,6,"     ");
	sprintf((char *)X,"%d",flashsave);
	sprintf((char *)Y,"%d",(flashsave/2));
	OLED_ShowString(70,3,X);
	OLED_ShowString(70,6,Y);
	//y=?
	
}

void isFlash(){
	uint32_t temp=STMFLASH_ReadWord(DATA);
	if(temp==0xffff){
		flashfirst=0;
	}else{
		flashsave=temp;
	}
}

void keyscan(){
	if(HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN)==0){ //key2
		flashsave--;
		oledjsqdiplay();
		while(HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN)==0);
		
	}
	
	if(HAL_GPIO_ReadPin(KEY3_GPIO, KEY3_GPIO_PIN)==0){ //key3
		flashsave++;
		oledjsqdiplay();
		while(HAL_GPIO_ReadPin(KEY3_GPIO, KEY3_GPIO_PIN)==0);
	}
	if(HAL_GPIO_ReadPin(KEY4_GPIO, KEY4_GPIO_PIN)==0){ //key4 ����led2
		STMFLASH_Write(DATA,&flashsave,1);
		GpioWrite( &Led2, 0 );
		led2flag=1;
		while(HAL_GPIO_ReadPin(KEY4_GPIO, KEY4_GPIO_PIN)==0);
	}
}

/**
 * Main application entry point.
 */
int main( void )
{
    Init();
		OLED_Init();
		isFlash(); //�ж��Ƿ�Ϊ��һ�ν���
		oleddisplay();
		oledjsqdiplay();
    while( 1 )
    {		
			keyscan();
    }
}
