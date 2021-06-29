#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;



void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void Init(){
  P1SEL&=0xfe; //—°‘ÒÕ®”√IO 
  P1DIR|=0x01;
}

void main(){
  Init();
  while(1){
    P1_0=0;
    Delayms(1000);
    P1_0=1;
    Delayms(1000);
  }
}