#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;
u8 count=0;
void Init(){
    P1DIR|=0x03;
    P1|=0x03;
    T1CC0L=0xd4;
    T1CC0H=0x30;
    T1CCTL0|=0x04;
    EA=1;T1IE=1;
    T1CTL|=0x0E;    
}

#pragma vector=T1_VECTOR
__interrupt void T1LED(){
  count++;
  T1STAT=0x00;
  if(count>=10){
    count=0;
    P1_0=!P1_0;
    P1_1=!P1_1;
  }
}

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void main(){
  Init();
  while(1);

}