#include <ioCC2530.h>
#define DATA P0_4
#define u8 unsigned char
#define u16 unsigned int

void set32M(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x40;
}

void Init(){
  P1DIR|=0x03;
  P0SEL|=0x0C;
  P2INP|=0x20;
  U0GCR=11;
  U0BAUD=216;
  U0CSR|=0x80;
  UTX0IF=0;
}

void Delayms(u16 ms){
  for(u16 i=0;i<ms;i++)
     for(u16 j=1070;j>0;j--);
}

void sendStr(char *data){
  while(*data!='\0'){
    U0DBUF=*data++;
    while(UTX0IF==0);
    UTX0IF=1;
  }
}

void main(){
  set32M();
  Init();
  while(1){
    P1=0xff;
    if(DATA==1){
      P1&=~0x01;
      sendStr("ON!");
    }else{
      P1|=0x01;
      sendStr("OFF");
    }
    Delayms(500);
  }
}