#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void Init(){
  P1DIR|=0x03; //P1¿Ú
  P1=0xfc;
  P0DIR&=~0x02;
  P0IEN|=0x02;
  PICTL=0x01;
  IEN1|=0x20;
  P0IFG=0x00;
  EA=1;
}

#pragma vector = P0INT_VECTOR
__interrupt void keyLED(){
  P1&=~0x03;
  Delayms(2000);
  P0IFG=0;
  P0IF=0;
}

void main(){
  Init();
  while(1)P1=0x03;  
}