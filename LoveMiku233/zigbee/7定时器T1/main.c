#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;
u8 count=0;
void init(){
  P1DIR|=0x01;
  T1CTL=0x0d;
  T1STAT=0x21;
  IEN1=0x02;
  EA=1;
}
void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}
void main(){
  init();
  while(1){
    //Delayms(1000);
  }
}



#pragma vector=T1_VECTOR
__interrupt void T1fun(){
 IRCON=0x00;
 P1_0=!P1_0;
}