#include  "LCD.h"
#include <STC89C5xRC.H>
#define add P1

sbit SE=P3^2; 
sbit RW=P3^1; 
sbit RS=P3^0;

void Delayms(u16 ms){
	u16 i,j;
	for(i=0;i<ms;i++)
		for(j=845;j>0;j--);
}

void LCD_COM(u8 dat)
{
   SE=0;
	 RW=0;//д����
	 RS=0;//0д���� 1д����
	 
	 SE=1;
	 add=dat;
	 Delayms(5); //��������
	 SE=0;       //�½��ش�������  
}
void LCD_write(u8 dat)
{
   SE=0;
	 RW=0;//д����
	 RS=1;//0д���� 1д����
	 
	 SE=1;
	 add=dat;
	 Delayms(5); //��������
	 SE=0;       //�½��ش�������
}
void LCD_init()
{
   LCD_COM(0x38); //8λ���ߣ���ʾ���У�5*7����
	 LCD_COM(0x0c); //B2λ��ʾ�����޹�꣬����˸
	 LCD_COM(0x06); //�����ƣ���ʾ��������
	 LCD_COM(0x01); //����
}
