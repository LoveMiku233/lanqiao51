#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Init(){
  WDCTL|=0x0c;
  P1DIR|=0x03;
  P1|=0x03;
  IEN2|=0x20;
  EA=1;
}

#pragma vector=WDT_VECTOR
__interrupt void WDT(){
  P1_0=!P1_0;
  IRCON2=0x00;
}

void main(){
  Init();
  while(1);
}