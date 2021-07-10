#include <ioCC2530.h>
#include "DHT11.h"
#include <stdio.h>
void set32M(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
}

char wdarr[3];

void Init(){
  P0SEL&=~0x80;
  P0SEL|=0x0C;
  U0GCR=11;
  U0BAUD=216;
  U0UCR|=0x80;
  U0CSR|=0xC0;
  URX0IF=0;
  UTX0IF=0;
}


void sendstr(char *data){
  while(*data!='\0'){
    U0DBUF=*data++;
    while(UTX0IF==0);
    UTX0IF=0;
  }
}


void main(){
  wdarr[2]='\0';
  set32M();
  Init();
  Delayms(2000);
  u8 wd=DHT11();
  while(1){
    wd=DHT11();
    wdarr[0]=wd/10+0x30;
    wdarr[1]=wd%10+0x30;
    sendstr("wd:");
    sendstr(wdarr);
    sendstr("\n");
    Delayms(1000);
  }
}