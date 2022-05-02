#include <STC15F2K60S2.h>
#include "ds1302.h"
#include "onewire.h"
#include "iic.h"
/////////////////函数///////////////////////////
#define hc138(x) P2&=0x1f,P2|=x<<5; //控制
void time_flash(); //时间刷新显示
void display_c(); //清空数码管
void temp_flash(); //温度刷新显示
void Timer2Init(void); //定时器2初始化
void Timer0Init(void); //定时器0初始化
void delayms(unsigned int ms); //软件延迟函数
void init(); //初始化
void adc_get(); //获取光敏电阻的电压 
void adc_out(); //D/A输出电压
void display(unsigned char pos,dat); //数码管指定显示
void key4(); //独立键盘
void key16();
/////////////////变量//////////////////////////////
unsigned char POS=0; //游标
unsigned char smgdat[8]={21,21,21,21,21,21,21,21}; //数码管显示控制
unsigned char code SMG[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0xbf,0xff}; //数码管码值
unsigned int modTime[5]={200,500,500,200,0}; //每个模式中断时间x2ms
extern unsigned char time[]; //ds1302
unsigned char mod=0; //模式控制
unsigned char cmd=0; //测试矩阵键盘


	
void main(){
	init();
	Timer2Init();
	Timer0Init();
	Ds1302_Init();
	rd_temperature();
	while(1){
			if(mod==3){
				key16();
			}else{
				key4();
			}
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

void adc_get(){
	unsigned int temp=read_adc(1)*1.96;
	smgdat[7]=temp%10;
	smgdat[6]=temp/10%10;
	smgdat[5]=temp/100+10;
}

void adc_out(unsigned int d){
	adc(d);
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

unsigned int dy=0;

void key4(){
	if(P30==0){
		delayms(5);
		if(P30==0){
			mod=mod==0?1:0;
			display_c();
			while(!P30);
		}
	}
	if(P31==0){
		delayms(5);
		if(P31==0){
			mod=2;
			display_c();
			while(!P31);
		}
	}
	
	if(P32==0){
		delayms(5);
		if(P32==0){
			adc_out(500);
			while(!P32);
		}
	}
	
	if(P33==0){
		delayms(5);
		if(P33==0){
			mod=3;
			display_c();
			while(!P33);
		}
	}
}

void key16(){
	unsigned char temp;
	P3=0x7f;
	P44=0;P42=1;
	temp=P3;
	temp&=0x0f;
	if(temp!=0x0f){
		delayms(5);
		temp=P3;
		temp&=0x0f;
		if(temp!=0x0f){
			temp=P3;
			switch(temp){
				case 0x7E: mod=0;break; //S7
				case 0x7D: cmd=6;break; //S6
				case 0x7B: cmd=5;break; //S5
				case 0x77: cmd=4;break; //S4
			}
		}
	}
	P3=0xff;
	P44=1;P42=0;
	temp=P3;
	temp&=0x0f;
	if(temp!=0x0f){
		delayms(5);
		temp=P3;
		temp&=0x0f;
		if(temp!=0x0f){
			switch(temp){
				temp=P3;
				case 0xFE: cmd=11;break; //S11
				case 0xFD: cmd=10;break; //S10
				case 0xFB: cmd=9; break; //S9
				case 0xF7: cmd=8; break; //S8
			}
		}
	}
	P3=0xdf;
	P44=1;P42=1;
	temp=P3;
	temp&=0x0f;
	if(temp!=0x0f){
		delayms(5);
		temp=P3;
		temp&=0x0f;
		if(temp!=0x0f){
			temp=P3;
			switch(temp){
				case 0xDE: cmd=15;break; //S15
				case 0xDD: cmd=14;break; //S14
				case 0xDB: cmd=13;break; //S13
				case 0xD7: cmd=12;break; //S12
			}
		}
	}
	P3=0xef;
	P44=1;P42=1;
	temp=P3;
	temp&=0x0f;
	if(temp!=0x0f){
		delayms(5);
		temp=P3;
		temp&=0x0f;
		if(temp!=0x0f){
			temp=P3;
			switch(temp){
				case 0xEE: cmd=19;break; //S19
				case 0xED: cmd=18;break; //S18
				case 0xEB: cmd=17;break; //S17
				case 0xE7: cmd=16;break; //S16
			}
		}
	}
}

void display(unsigned char pos,dat){
	hc138(6);P0=0x01<<pos;
	hc138(7);P0=dat;
}

void T2() interrupt 12{
	hc138(6);P0=0x00;
	display(POS,SMG[smgdat[POS]]);
	if(++POS==8)POS=0;
}

void T0() interrupt 1{
	static unsigned int cnt=0;
	cnt++;
	if(cnt>=modTime[mod]){
		cnt=0;
		if(mod==0){
			time_flash();
		}else if(mod==1){
			temp_flash();
			adc_out(125/1.961);
		}else if(mod==2){
			adc_get();
		}else if(mod==3){
			smgdat[7]=cmd%10;
			smgdat[6]=cmd/10;
		}
	}
}