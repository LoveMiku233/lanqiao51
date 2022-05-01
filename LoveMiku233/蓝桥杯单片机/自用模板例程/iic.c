#include "iic.h"

#define DELAY_TIME 50

//I2C�����ڲ���ʱ����
void IIC_Delay(unsigned char i)
{
    do{_nop_();}
    while(i--);        
}

//I2C���������ź�
void IIC_Start(void)
{
    SDAT = 1;
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SDAT = 0;
    IIC_Delay(DELAY_TIME);
    SCL = 0;	
}

//I2C����ֹͣ�ź�
void IIC_Stop(void)
{
    SDAT = 0;
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SDAT = 1;
    IIC_Delay(DELAY_TIME);
}

//����Ӧ����Ӧ���ź�
void IIC_SendAck(bit ackbit)
{
    SCL = 0;
    SDAT = ackbit;  					
    IIC_Delay(DELAY_TIME);
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SCL = 0; 
    SDAT = 1;
    IIC_Delay(DELAY_TIME);
}

//�ȴ�Ӧ��
bit IIC_WaitAck(void)
{
    bit ackbit;
	
    SCL  = 1;
    IIC_Delay(DELAY_TIME);
    ackbit = SDAT;
    SCL = 0;
    IIC_Delay(DELAY_TIME);
    return ackbit;
}

//I2C���߷���һ���ֽ�����
void IIC_SendByte(unsigned char byt)
{
    unsigned char i;

    for(i=0; i<8; i++)
    {
        SCL  = 0;
        IIC_Delay(DELAY_TIME);
        if(byt & 0x80) SDAT  = 1;
        else SDAT  = 0;
        IIC_Delay(DELAY_TIME);
        SCL = 1;
        byt <<= 1;
        IIC_Delay(DELAY_TIME);
    }
    SCL  = 0;  
}

//I2C���߽���һ���ֽ�����
unsigned char IIC_RecByte(void)
{
    unsigned char i, da;
    for(i=0; i<8; i++)
    {   
    	SCL = 1;
			IIC_Delay(DELAY_TIME);
			da <<= 1;
			if(SDAT) da |= 1;
			SCL = 0;
			IIC_Delay(DELAY_TIME);
    }
    return da;    
}

unsigned char read_adc(unsigned char adr){
	unsigned char temp;
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(adr|0x40); //AD��DAһ��ʹ��ʱ��Ҫ |0x40
	IIC_WaitAck();
	IIC_Start();
	IIC_SendByte(0x91);
	IIC_WaitAck();
	temp=IIC_RecByte();
	IIC_WaitAck();
	IIC_Stop();
	return temp;
}

void adc(unsigned char dat){
	EA=0;
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(0x40);
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
	IIC_Stop();
	EA=1;
}