#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

u8 count=0;
u8 stat=0;
void SLK32M(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
}

void Init(){
  P0DIR&=~0x02;
  P0SEL|=0x0C;
  P0INP&=~0x02;
  P2INP&=~0x20;
  PICTL|=0x01;
  P0IEN|=0x02;
  P0IE=1;P0IFG=0x00;
  PERCFG&=~0x42;
  T1CC0L=0xd4;
  T1CC0H=0x30;
  T1CCTL0|=0x04;
  T1STAT=0x00;
  //串口
  U0GCR=11;
  U0BAUD=216;
  U0UCR|=0x80;
  U0CSR|=0xC0;
  UTX0IF=0;
  URX0IF=0;
  T1CTL|=0x0e;
  T1IE=1;EA=1;
}

void sendu8(u8 dat){
  U0DBUF=dat;
  while(UTX0IF==0);
  UTX0IF=0;
}

void sendStr(u8 *data){
  while(*data!='\0')
    sendu8(*data++);
}

#pragma vector=T1_VECTOR
__interrupt void T1send(){
  T1STAT=0x00;
  if(stat==1){
    sendStr("LoveMiku\n");
  }
}

#pragma vector=P0INT_VECTOR
__interrupt void int1(){    
  P0IFG=0x00;
  P0IF=0;
  if(stat==0){
    sendStr("开始运行\n");
    stat=1;
  }else{
    sendStr("暂停运行\n");
    stat=0;
  }

}

void main(){
  SLK32M();
  Init();
  while(1);
}