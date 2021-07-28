#include <STC89C5xRC.H>
#include "LCD.h"
u8 dat1[16]={"  Hello world!  "};
u8 dat2[16]={"  LED State:OFF "};
u8 flag=0;
void LCDdisplay();
void keyscan();
void flagRe();
void main(){
	LCD_init();
	P2=0xff;
	while(1){
		keyscan();
		flagRe();
		LCDdisplay();
	}
}

void flagRe(){
	if(flag==1){
			P0&=~0x07;
			P2=0xf9;
			dat2[13]='N';
			dat2[14]=' ';
	}else if(flag==2){
			P0|=0x07;
			P2=0xa4;
			dat2[13]='F';
			dat2[14]='F';
	}
}

void LCDdisplay(){
	u8 i=0;
	LCD_COM(0x80); //显示第一行
	for(i=0;i<16;i++)
	  LCD_write(dat1[i]);
	LCD_COM(0x40+0x80); //显示第二行
	for(i=0;i<16;i++)
		LCD_write(dat2[i]);
}

void keyscan(){
	if(P36==0){
		Delayms(10);
		if(P36==0){
			//P3&=~0x38;
			flag=1;
			while(!P36);
		}
	}
	if(P37==0){
		Delayms(10);
		if(P37==0){
			//P3|=0x38;
			flag=2;
			while(!P37);
		}
	}
}