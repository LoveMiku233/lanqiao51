#include <ioCC2530.h>

typedef unsigned char uint8;
typedef unsigned int uint16;

#define LED1 P1_0
#define LED2 P1_1
#define KEYMAXTIME 50

uint8 flag=0;
uint8 max=0;
uint16 count=0;
uint16 sw2=0; 
uint16 keytime=0;
uint8 keystate=0;

void init();
void key();
void delay(uint16 us);
void inittimer();
void led(uint16 cis);
uint8 keyread();
void Delayms(uint16 ms);
void mod1();
void mod2();


void main(){
  init();
  inittimer();
  LED1=0;LED2=0; 
  while(1){
    key();
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

#pragma vector=T1_VECTOR
__interrupt void T1(){
  T1STAT=0x00;
  keytime++;
  if(flag==1){
    mod1();
  }else if(flag==2){
    mod2();
  }
}

void mod1(){
  count++;
  if(count%100==0){
    count=0;
    if(LED1==1){
      LED1=0;
      LED2=1;
    }else{
      LED1=1;
      LED2=0;
    }
  }
}

void mod2(){
  sw2++;
  if(max==0){
    led(count++);
    if(count>=100){
      max=1;
    }
  }else{
    led(count--);
    if(count<=0){
      max=0;
    }
  }
  if(sw2%200==0){
    sw2=0;
    LED2=!LED2;
  }
}

uint8 keyread(){
    uint8 statetemp=0;
    if(P0_1==0){
      Delayms(8);
      if(P0_1==0){        
        keytime=0;
        keystate++; 
        while(!P0_1);

      }
    }
    if(keytime>50){
      keytime=0;
      statetemp=keystate;
      keystate=0;
    }
    return statetemp;
}

void key(){
  uint8 a=keyread();
  if(a==1){
    count=0;
    flag=1;
  }else if(a>=2){
    count=0;
    max=0;
    flag=2;
  }
}


void Delayms(uint16 ms){
  uint16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void led(uint16 cis){
  LED1=0;
  delay(cis*10);
  LED1=1;
}

void delay(uint16 us){
  while(us--);
}

void inittimer(){
  T1CC0L=0xE2;
  T1CC0H=0x04;
  T1CCTL0|=0x04;
  T1IE=1;EA=1;
  T1CTL|=0x0E;
}