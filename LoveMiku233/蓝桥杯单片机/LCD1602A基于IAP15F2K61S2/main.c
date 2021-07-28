#include <STC15F2K60S2.H>
#include "onewire.h"
#include "LCD.h"
#define u8 unsigned char
#define u16 unsigned int
u8 data tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF,0xc6,0x88,0x83}; //数码管码值
u8 yi,er,san,si,wu,liu,qi,ba;
u8 mod=0; //模式0暂停 模式1开发版LED控制 模式2 P34·P35·P44 LED控制 模式3 LCD显示
u8 Aflag=0,Bflag=0; 
u8 wd; //温度
u8 dat1[16]="  hello world!  "; //第一行
u8 dat2[16]; //第二行
void LCD(); //LCD显示
void AllInit(); //初始化
void key4(); //按键扫描
void display1(u8 yi,u8 er);
void display2(u8 san,u8 si);
void display3(u8 wu,u8 liu);
void display4(u8 qi,u8 ba);
void displayLCD2(); //第二行
void main(){
	LCD_init();
	AllInit();
	yi=10;er=12;san=0;si=10;
	wu=13;liu=0;qi=14;ba=0;
	wd=Temp_get();
	while(1){
		san=mod;liu=Aflag;ba=Bflag;
		key4();
		if(mod==3){
			//判断是否模式3
			P2=0xc0;P0=0xff;
			P2=0xe0;P0=0xff;
			P2=0x80;P1=0x0f; 
			Aflag=0;
			//todo LCD需要使用P0口,只能选择数码管位选,并且关闭数码管和LED灯
			P2=0xc0;
			displayLCD2();
			LCD();
		}else{
			display1(yi,er);
			display2(san,si);
			display3(wu,liu);
			display4(qi,ba);
		}
	}
}

void displayLCD2(){
	wd=Temp_get();
	dat2[0]='t';
	dat2[1]='e';
	dat2[2]='m';
	dat2[3]='p';
	dat2[4]='e';
	dat2[5]='r';
	dat2[6]='a';
	dat2[7]='t';
	dat2[8]='u';
	dat2[9]='r';
	dat2[10]='e';
	dat2[11]=':';
	dat2[12]=wd/10+0x30;
	dat2[13]=wd%10+0x30;
	dat2[14]='C';
	dat2[15]=' ';
	dat2[16]=' ';
}

void LCD(){
	u8 i=0;
	LCD_COM(0x80); //显示第一行
	//while(dat1[i]!='\0')
	for(i=0;i<16;i++)
	  LCD_write(dat1[i]);
	LCD_COM(0x40+0x80); //显示第二行
	for(i=0;i<16;i++)
		LCD_write(dat2[i]);
}

void key4(){
	if(P30==0){
		Delayms(5);
		if(P30==0){
			if(mod<3){
				mod++;
			}else{
				mod=1;
			}
			while(!P30){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			}
		}
	}
	if(P31==0){
		Delayms(5);
		if(P31==0){
			if(mod==1){
				P2=0x80;
				Aflag=1;
				P0=0xfe;
			}else if(mod==2){
				Bflag=1;
				P3|=0x20;
				P4|=0x10;
				P3&=~0x10;
			}
			while(!P31){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			}
			
		}
	}
	if(P32==0){
		Delayms(5);
		if(P32==0){
			if(mod==1){
				P2=0x80;
				Aflag=2;
				P0=0xfd;
			}else if(mod==2){
				Bflag=2;
				P3|=0x10;
				P4|=0x10;
				P3&=~0x20;
			}
			while(!P32){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			}
			
		}
	}
	if(P33==0){
		Delayms(5);
		if(P33==0){
			if(mod==1){
				P2=0x80;
				Aflag=3;
				P0=0xfb;
			}else if(mod==2){
				Bflag=3;
				P3|=0x30;
				P4&=~0x10;
			}
			while(!P33){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			}
			
		}
	}
}

void AllInit(){
	P2=0xa0;P0=0x00;P2=0xc0;P0=0xff;
	P2=0xe0;P0=0xff;P2=0x80;P0=0xff;
}
void display1(u8 yi,u8 er){
	P2=0xc0;P0=0x01;P2=0xe0;P0=tab[yi];
	Delayms(1);
	P2=0xc0;P0=0x02;P2=0xe0;P0=tab[er];
	Delayms(1);
}
void display2(u8 san,u8 si){
	P2=0xc0;P0=0x04;P2=0xe0;P0=tab[san];
	Delayms(1);
	P2=0xc0;P0=0x08;P2=0xe0;P0=tab[si];
	Delayms(1);
}
void display3(u8 wu,u8 liu){
	P2=0xc0;P0=0x10;P2=0xe0;P0=tab[wu];
	Delayms(1);
	P2=0xc0;P0=0x20;P2=0xe0;P0=tab[liu];
	Delayms(1);
}
void display4(u8 qi,u8 ba){
	P2=0xc0;P0=0x40;P2=0xe0;P0=tab[qi];
	Delayms(1);
	P2=0xc0;P0=0x80;P2=0xe0;P0=tab[ba];
	Delayms(1);
	P2=0xc0;P0=0xff;P2=0xe0;P0=0xff;
	Delayms(1);
}