#include <ioCC2530.h>
typedef unsigned char u8;
typedef unsigned int u16;
u8 cis=0;
u8 count=0;
u8 mod=1;
u8 mod_cis=0;
void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void Init(){
  P1DIR|=0x03;
  P1|=0x03;
  EA=1;
  T1IE=1;
  T1CCTL0|=0x04;
  T1CC0L=0xD4;
  T1CC1H=0x30;
  T1CTL=0x0E;
}

#pragma vector=T1_VECTOR
__interrupt void T1_fun(){
    cis++;
    if(cis==10){
      cis=0;
      count+=1;
    }
    IRCON=0;
}

void main(){
  Init();
  while(1){
    if(mod==1){
      if(count==1){
        P1_0=!P1_0;
        count=0;
      }
      if(mod_cis==3){
        mod=2;
        mod_cis=0;
      }
    }
    else if(mod==2){
      if(count==3){
        P1_1=!P1_1;
        count=0;
        
      }
      if(mod_cis==3){
          mod=1;
          mod_cis=0;
      }
    }
  }
}