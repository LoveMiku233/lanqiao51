#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;
u8 count=0;
u8 flag=0;
void Init(){
  P1DIR|=0x03;
  P1|=0x03;
  P0DIR&=~0x02;
  P0INP&=~0x02;
  P2DIR&=~0x01;
  P2INP&=~0xA1;
  //定时器
  T1CC0L=0xd4;
  T1CC0H=0x30;
  T1CCTL0|=0x04;
  EA=1;T1IE=1;
  T1CTL|=0x0e;
}

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

#pragma vector=T1_VECTOR
__interrupt void t1scan(){
  if(flag==1)
    count++;
}

void keyscan(){
  if(P0_1==0){
    Delayms(10);//消抖
    if(P0_1==0){
      flag=1;
      while(!P0_1); //等待按键松开
      flag=0;
      if(count>=5)P1_0=!P1_0;
      else P1_1=!P1_1;
    }
    flag=0;count=0;
  }
}

void main(){
  Init();
  while(1){
    keyscan();
  }
}