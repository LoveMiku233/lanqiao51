#include <ioCC2530.h>

typedef unsigned char uint8;
typedef unsigned int uint16;

#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_4
#define LED4 P0_2

void init();
void delayms(uint8 ms);
void keyscan();
void led();
void initTimer();

uint8 cis=0;

void main(){
  init();
  initTimer();
  while(1){
    keyscan();
  }
}

void init(){
  P0SEL&=~0x0E;
  P1SEL&=~0x13;
  P0DIR&=~0x02;
  P2DIR&=~0x01;
  P1DIR|=0x13;
  P0DIR|=0x0C;
  P0DIR|=0x80;
}

void initTimer(){
  T1CC0L=0xd4;
  T1CC0H=0x30;
  T1CCTL0|=0x04;
  EA=1;T1IE=1;
  T1CTL|=0x0E; 
}

void led(){
  switch(cis){
    case 0: LED1=0;LED2=0;LED3=0;LED4=0;P0_7=0; break;
    case 1:LED1=0;LED2=0;LED3=1;LED4=1;break;
    case 2:LED1=1;LED2=0;LED3=0;LED4=1; break; 
    case 3:LED1=1;LED2=1;LED3=0;LED4=0; break; 
    case 4:LED1=1;LED2=0;LED3=1;LED4=1; P0_7=1;break; 
  }
}

#pragma vector=T1_VECTOR
__interrupt void T1LED(){
  T1STAT=0x00;
  led();
}

void delayms(uint8 ms){
  uint16 i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<535;j++);
}

void keyscan(){
  if(P0_1==0){
    delayms(8);
    if(P0_1==0){
      cis++;
      while(!P0_1);
    }
  }
  if(P2_0==0){
    delayms(8);
    if(P2_0==0){
      cis=0;
      while(!P2_1);
    }
  }
}

