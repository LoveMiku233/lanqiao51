#include <ioCC2530.h>

#define DATA P0_6
#define LED1 P1_0
#define u8 unsigned char
#define u16 unsigned int
//#define delaytime 10


void delayms(u16 ms){
   for(int i=0;i<ms;i++)
     for(int j=535;j>0;j--);
}

void Init(){
  P1DIR|=0x01;
  P0DIR&=~0x40;
}

void main(){
  Init();
  while(1){
    if(DATA==0){
      delayms(10);
      if(DATA==0){
        for(int i=0;i<10;i++){
          delayms(500);
          LED1=!LED1;
        }
      }
    }
  }
}