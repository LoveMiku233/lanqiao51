#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

u8 LEDarr[3]={0xfe,0xfd,0xef};

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}


void Init(){
  P1SEL&=~0x13;
  P1DIR|=0x13;
}


void main(){
  Init();
  while(1){
    P1=0x13;
    Delayms(1000);
    for(u8 i=0;i<3;i++){
      P1=LEDarr[i];
      Delayms(1000);
    }
  }
}