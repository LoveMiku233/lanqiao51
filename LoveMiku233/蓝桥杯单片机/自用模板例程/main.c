#include <STC15F2K60S2.h>
#include "ds1302.h"
#include "onewire.h"
/////////////////函数///////////////////////////
#define hc138(x) P2&=0x1f,P2|=x<<5; //控制
void time_flash(); //时间刷新显示
void display_c(); //清空数码管
void temp_flash(); //温度刷新显示
void Timer2Init(void); //定时器2初始化
void Timer0Init(void); //定时器0初始化
void delayms(unsigned int ms); //软件延迟函数
void init(); //初始化
void display(unsigned char pos,dat); //数码管指定显示
void key4(); //独立键盘
/////////////////变量//////////////////////////////
unsigned char POS=0;
unsigned char smgdat[8]={21,21,21,21,21,21,21,21}; 
unsigned char code SMG[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0xbf,0xff};
extern unsigned char time[];
unsigned char mod=0;
	
void main(){
	init();
	Timer2Init();
	Timer0Init();
	Ds1302_Init();
	rd_temperature();
	while(1){
		key4();
	}
}	
	
void time_flash(){
	unsigned char a,b;
	Ds1302_Get();
	
	for(a=0,b=7;a<3;a++,b-=3){
		smgdat[b]=time[a]%10;
		smgdat[b-1]=time[a]/10;
		smgdat[b-2]=smgdat[b-2]==20?21:20;
	}
}	

void display_c(){
	unsigned char i;
	for(i=0;i<8;i++){
		smgdat[i]=21;
	}
}

void temp_flash(){
	unsigned char temp=rd_temperature();
	smgdat[6]=temp/10;
	smgdat[7]=temp%10;
}

void Timer2Init(void)		//2??@12.000MHz
{
	AUXR |= 0x04;		//?????1T??
	T2L = 0x40;		//??????
	T2H = 0xA2;		//??????
	AUXR |= 0x10;		//???2????
	EA=1;
	IE2|=0x04;
}

void Timer0Init(void)		//2毫秒@12.000MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x40;		//设置定时初值
	TH0 = 0xA2;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
}


void delayms(unsigned int ms){
	unsigned int a,b;
	for(a=0;a<ms;a++)
		for(b=845;b>0;b--);
}

void init(){
	hc138(4);P0=0xff;
	hc138(5);P0=0x00;
}

void key4(){
	if(P30==0){
		delayms(10);
		if(P30==0){
			mod=mod==0?1:0;
			display_c();
			while(!P30);
		}
	}
}

void display(unsigned char pos,dat){
	hc138(6);P0=0x01<<pos;
	hc138(7);P0=dat;
}

void T2 interrupt 12{
	hc138(6);P0=0x00;
	display(POS,SMG[smgdat[POS]]);
	if(++POS==8)POS=0;
}

void T0() interrupt 1{
	static unsigned int cnt=0;
	cnt++;
	if(mod==0){
		if(cnt>=200){
			cnt=0;
			time_flash();
		}
	}else{
		if(cnt>=500){
			cnt=0;
			temp_flash();
		}
	}
}