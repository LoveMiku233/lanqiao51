#include  "LCD.h"
#include <STC15F2K60S2.H>
#define add P0

sbit SE=P1^2; 
sbit RW=P2^1; 
sbit RS=P2^0;

void Delayms(u16 ms){
	u16 i,j;
	for(i=0;i<ms;i++)
		for(j=845;j>0;j--);
}

void LCD_COM(u8 dat)
{
   SE=0;
	 RW=0;//写数据
	 RS=0;//0写命令 1写数据
	 
	 SE=1;
	 add=dat;
	 Delayms(5); //保持数据
	 SE=0;       //下降沿传输数据  
}
void LCD_write(u8 dat)
{
   SE=0;
	 RW=0;//写数据
	 RS=1;//0写数据 1写命令
	 
	 SE=1;
	 add=dat;
	 Delayms(5); //保持数据
	 SE=0;       //下降沿传输数据
}
void LCD_init()
{
   LCD_COM(0x38); //8位总线，显示两行，5*7点阵
	 LCD_COM(0x0c); //B2位显示开，无光标，不闪烁
	 LCD_COM(0x06); //光标后移，显示屏不右移
	 LCD_COM(0x01); //清屏
}
