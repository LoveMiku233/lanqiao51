#include <STC15F2K60S2.h>
#include "ds1302.h"
#include "onewire.h"
/////////////////����///////////////////////////
#define hc138(x) P2&=0x1f,P2|=x<<5; //����
void time_flash(); //ʱ��ˢ����ʾ
void display_c(); //��������
void temp_flash(); //�¶�ˢ����ʾ
void Timer2Init(void); //��ʱ��2��ʼ��
void Timer0Init(void); //��ʱ��0��ʼ��
void delayms(unsigned int ms); //����ӳٺ���
void init(); //��ʼ��
void display(unsigned char pos,dat); //�����ָ����ʾ
void key4(); //��������
/////////////////����//////////////////////////////
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

void Timer0Init(void)		//2����@12.000MHz
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x40;		//���ö�ʱ��ֵ
	TH0 = 0xA2;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
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