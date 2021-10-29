#include "hal_defs.h"
#include "hal_cc8051.h"
#include "hal_int.h"
#include "hal_mcu.h"
#include "hal_board.h"
#include "hal_led.h"
#include "hal_rf.h"
#include "basic_rf.h"
#include "hal_uart.h" 
#include "sensor_drv/sensor.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
/********Э��������********/
#define coor
/************************/
#define KEY P0_1

//˫���ж�ʱ�� 500ms
#define doubleKeyTime 50
/*****��Ե�ͨѶ��ַ����******/
#define RF_CHANNEL                12        // Ƶ�� 11~26
#define PAN_ID                    0x0011     //����id 

#if defined(coor)
//Э������ַ
#define MY_ADDR                   0x0001     //����ģ���ַ
#define SEND_ADDR                 0x0002     //���͵�ַ

uint8 count=0;
uint8 flagcoor=0;
uint16 coortime=0;

#else 
//�ն˵�ַ
#define MY_ADDR                   0x0002     //����ģ���ַ
#define SEND_ADDR                 0x0001     //���͵�ַ

uint8 key=0;
uint16 keytime=0;
uint8 flag=0;
uint16 us=0;
uint8 mod=0;

#endif

void AFincoming();
uint8 keyScan();
void Bled(uint8 cut); //����ƺ���
void a_b(uint16 cis); //�����ƺ���
//�жϺ�������
_PRAGMA(vector=T1_VECTOR) __near_func __interrupt void T1(void);


static basicRfCfg_t basicRfConfig;
// ����RF��ʼ��
void ConfigRf_Init(void)
{
    basicRfConfig.panId       =   PAN_ID;
    basicRfConfig.channel     =   RF_CHANNEL;
    basicRfConfig.myAddr      =   MY_ADDR;
    basicRfConfig.ackRequest  =   TRUE;
    while(basicRfInit(&basicRfConfig) == FAILED);
    basicRfReceiveOn();
}


void timeInit(){
  T1CC0L=0xE2;
  T1CC0H=0x04;
  T1CCTL0|=0x04;
  T1IE=1;halIntOn();
  T1CTL|=0x0E;
}


/********************MAIN************************/
void main(void)
{
    halBoardInit();//ѡ�ֲ����ڴ˺�������Ӵ���
    ConfigRf_Init();//ѡ�ֲ����ڴ˺�������Ӵ���
    timeInit();//��ʼ����ʱ��
#if defined(coor)
    P1DIR|=0x13;
    P1|=0x13;
    P0DIR|=0x04;
    P0|=0x04;
#else
    P1DIR|=0x01;
    P1_0=1;
#endif
    while(1)
    {
     /* user code start */
      if(keyScan()>1){
        basicRfSendPacket(SEND_ADDR,"3",strlen("3"));
      }      
     /* user code end */
    }
}

uint8 keyScan(){
#if defined(coor) 
  //����
  if(!KEY){
    halMcuWaitMs(8);
    if(!KEY){
      basicRfSendPacket(SEND_ADDR,"1",strlen("1"));
      while(!KEY);
      basicRfSendPacket(SEND_ADDR,"2",strlen("2"));
    }
  }
  return 0;
#else
  //˫��
  uint8 keytemp=0;
  if(!KEY){
    halMcuWaitMs(8);
    if(!KEY){
      keytime=0;
      key++;
      while(!KEY);
    }
  }
  if(keytime>50){
    keytime=0;
    keytemp=key;
    key=0;
  }
  return keytemp;
#endif
  
} 


_PRAGMA(vector=T1_VECTOR) __near_func __interrupt void T1(void){
  T1STAT=0x00;
  if(basicRfPacketIsReady()){
    AFincoming();
  }
//�����
#if defined(coor)
  if(flagcoor){
    coortime++;
    if(coortime>=200){
      coortime=0;
      Bled(count++);
    }
  }
#else
  keytime++;
  if(flag){
    if(mod==0){
      us++;
      if(us>100){
        mod=1;
      }
    }else if(mod==1){
      us--;
      if(us==0){
        mod=0;
      }
    }
}
  a_b(us);
#endif

}

void a_b(uint16 cis){
  P1_0=0;
  halMcuWaitUs(cis*10);
  P1_0=1;
}

void AFincoming(){
  uint8 buffer[30];
  uint8 len=basicRfReceive(buffer,30,NULL);
  halUartWrite(buffer,len);
#if defined(coor)
  if(len>0){
    if(buffer[0]=='3'){
      flagcoor=1;
      count=0;
    }
  }
#else
  if(len>0){
    if(buffer[0]=='1'){
      flag=1;
    }
    if(buffer[0]=='2'){
      flag=0;
    }
  }
#endif
}

#if defined(coor)
void Bled(uint8 cut){
  switch(cut){
  case 1:P1_1=0;P1_0=1;P1_4=1;P0_2=1;break;
  case 2:P1_1=1;P1_0=0;P1_4=1;P0_2=1;break;
  case 3:P1_1=1;P1_0=1;P1_4=0;P0_2=1;break;
  case 4:P1_1=1;P1_0=1;P1_4=1;P0_2=0;cut=0;flagcoor=0;break;
  }
}
#endif