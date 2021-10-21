#include <ioCC2530.h>

typedef unsigned char uint8;
typedef unsigned int uint16;

#define LED1 P1_0
#define LED2 P1_1

uint8 flag=0;
uint16 count=0;
void init();
void key();
void inittimer(){
  T1CCTL0|=0x04;
  T1CC0L=0xE2;
  T1CC0H=0x04;
  T1IE=1;EA=1;
  T1CTL=0x0E;
}
void led(uint16 cis);
void main(){
  init();
  inittimer();
  LED1=0;LED2=0; 
  while(1){
    key();
  }
}
void Delayms(uint16 ms);

void init(){
  P1SEL|=0x03;
  P0SEL&=~0x02;
  P2SEL&=~0x01;
}

#pragma vector=T1_VECTOR
__interrupt void T1(){
  T1STAT=0x00;
  if(flag==1){
    count++;
    if(count==0){
      LED1=0;LED2=1;
    }
    if(count%100==0){
      count=0;
      LED1=!LED1;
      LED2=!LED2;
    }
  }
}

void key(){
  if(P0_1==0){
    Delayms(8);
    if(P0_1==0){
      flag=1;
      while(!P0_1);
    }
  }
   if(P2_0==0){
    Delayms(8);
    if(P2_0==0){
      flag=2;
      while(!P2_0);
    }
  }
}


void Delayms(uint16 ms){
  uint16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}