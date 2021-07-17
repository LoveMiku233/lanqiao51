#include <ioCC2530.h>
#define u8 unsigned char
#define u16 unsigned int
#define CTL P0_5

void Init(){
  P0DIR|=0x20;
  P0DIR&=~0x02;
}

void Delayms(u16 ms){
  for(int i=0;i<ms;i++)
    for(int j=535;j>0;j--);
}

void main(){
  Init();
  CTL=1;
  while(1){
    if(P0_1==0){
      Delayms(10);
      if(P0_1==0){
        if(CTL==0)CTL=1;
        else CTL=0;
        while(!P0_1);
      }
    }
  }
}