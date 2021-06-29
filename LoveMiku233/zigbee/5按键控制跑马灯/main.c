#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Init(){
  P1SEL&=~0x13;
  P1DIR|=0x13;
  P0SEL&=~0x02;
  P0DIR|=0x02;
  P0INP&=~0x02;
}

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void main(){
  Init();
  while(1){
    if(P0_1==0){
      Delayms(5);
      if(P0_1==0){
        P1|=0x13;
        P1=0xfe;
        Delayms(1000);
        P1=0xfd;
        Delayms(1000);
        P1|=0x13;
      }
      while(!P0_1);
    }
  }
}