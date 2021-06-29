#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Init(){
  P1SEL&=0xfe;
  P1DIR|=0x01;
  P0SEL&=0xfd;
  P0DIR|=0xfd;
  P0INP&=0xfd;
}

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}
void main(){
  Init();
  P1_0=1;
  while(1){
    if(P0_1==0){
      Delayms(5);
      if(P0_1==0){
        P1_0=!P1_0;
      }
      while(!P0_1);
    }
  }
}