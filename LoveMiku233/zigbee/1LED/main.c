#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int uint;



void InitLED(){
  P1DIR |= 0x01;
}

void Delayms(uint ms){
  uint i,j;
  for(i=0;i<ms;i++)
     for(j=535;j>0;j--);
}

void main(){
  InitLED();
  while(1){
    P1_0=1;
    Delayms(1000);
    P1_0=0;
    Delayms(1000);
  }
}