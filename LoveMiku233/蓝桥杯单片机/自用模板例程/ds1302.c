
#include "ds1302.h"

unsigned char time[]={50,59,23};

//写字节
void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK = 0;
		SDA = temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

//向DS1302寄存器写入数据
void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	SCK=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	RST=1; _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	Write_Ds1302(address);	
 	Write_Ds1302((dat/10<<4)|(dat%10));		
 	RST=0; 
}

//从DS1302寄存器读出数据
unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i,temp=0x00,dat1,dat2;
 	RST=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	SCK=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	RST=1;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	Write_Ds1302(address);
 	for (i=0;i<8;i++) 	
 	{		
		SCK=0;
		temp>>=1;	
 		if(SDA)
 		temp|=0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
 	SCK=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	SCK=1;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	SDA=0;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	SDA=1;	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	dat1=temp/16;
	dat2=temp%16;
	temp=dat1*10+dat2;
	return (temp);			
}

void Ds1302_Init(){
	unsigned char i,add=0x80;
	Write_Ds1302_Byte(0x8e,0x00);
	for(i=0;i<3;i++){
		Write_Ds1302_Byte(add,time[i]);
		add+=2;
	}
	Write_Ds1302_Byte(0x8e,0x80);
}

void Ds1302_Get(){
	unsigned char i,add=0x81;
	Write_Ds1302_Byte(0x8e,0x00);
	for(i=0;i<3;i++){
		time[i]=Read_Ds1302_Byte(add);
		add+=2;
	}
	Write_Ds1302_Byte(0x8e,0x80);
}

