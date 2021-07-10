#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

u8 count=0;

void Init(){
  P1DIR|=0x03;
  P1|=0x03;
  T1CCTL0|=0x04;
  T1CC0L=0xd4;
  T1CC0H=0x30;
  T1IE=1;EA=1;
  T1CTL|=0x0e;
}

#pragma vector=T1_VECTOR
__interrupt void T1sve(){
  T1STAT=0x00;
  count++;
  if((count%10)==0){
    P1_0=!P1_0;
  }
  if(count==30){
      P1_1=!P1_1;
      count=0;
  }
}


void main(){
  Init();
  while(1);
}