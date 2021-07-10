#include "DHT11.h"
#include <ioCC2530.h>


u8 chartemp;
u8 datatemp,wdtempl,wdtemph,sdtempl,sdtemph,dataclick,dataclicktemp;
u16 datawd,datasd;

//32M
void Delayus(u16 us){
  while(us--){
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");    
    asm("nop");
    asm("nop");
    asm("nop");    
    asm("nop"); 
  }
}
//32M
void Delayms(u16 ms){
  unsigned char i;
    while(ms--)
    {
        for(i=0;i<100;i++)
            Delayus(10);
    }
}

void com(){
  u8 i;
  for(i=0;i<8;i++){
    while(!PIN);
    Delayus(30);
    chartemp=0;
    if(PIN){
      chartemp=1;
      while(PIN);
    }
    datatemp<<=1;
    datatemp|=chartemp;
  }
}

u8 DHT11(){
  PIN=0;
  Delayms(19);
  PIN=1;
  P0DIR&=~0x80;
  Delayus(40);
  if(PIN==0){
    while(!PIN);
    while(PIN);
    com();
    sdtemph=datatemp;
    com();
    sdtempl=datatemp;
    com();
    wdtemph=datatemp;
    com();
    wdtempl=datatemp;
    com();
    dataclick=datatemp;
    //P0DIR|=0x80;
    PIN=1;
    dataclicktemp=sdtempl+sdtemph+wdtempl+wdtemph;
    if(dataclicktemp==dataclick){
      datawd=wdtemph;
      datasd=sdtemph;
    }else{
      datawd=0;
      datasd=0;
    }  
  }
  P0DIR |= 0x80;
  return datawd;
}