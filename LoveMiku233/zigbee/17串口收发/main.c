#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Init(){
  P0SEL|=0x0C;
  U0UCR|=0x80;
  U0GCR=8;
  U0BAUD=59;
  U0CSR|=0xC0;
  UTX0IF=0;
  URX0IF=0;
  URX0IE=1;
  EA=1;
}

void CLK32M(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
}

void send(u8 dat){
  U0DBUF=dat;
  while(UTX0IF==0);
  UTX0IF=0;
}

#pragma vector=URX0_VECTOR
__interrupt void URX0(){
  u8 temp;
  temp=U0DBUF;
  temp++;
  send(temp);
}

void main(){
  CLK32M();
  Init();
  while(1);
}