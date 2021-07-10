#include <ioCC2530.h>
#include <stdio.h>
typedef unsigned char u8;
typedef unsigned int u16;

void setCLK(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
}

void Init(){
  P0SEL|=0x0C;
  U0GCR=11;
  U0BAUD=216;
  U0UCR|=0x80;
  U0CSR|=0xC0;
  UTX0IF=0;
  URX0IF=0;
  TR0=0x01;
  ATEST=0x01;
}

float getWD(){
  u16 temp;
  ADCCON3=0x3E;
  ADCCON1|=0x30;
  ADCCON1|=0x40;
  while(!(ADCCON1&0x80));
  temp=ADCL>>4;
  temp|=((u16)ADCH<<4);
  return (temp-1480)/4.5;
}

void sendStr(char *data){
  while(*data!='\0'){
    U0DBUF=*data++;
    while(UTX0IF==0);
    UTX0IF=0;
  }
  if(*data!='\0'){
    U0DBUF='\n';
    while(UTX0IF==0);
    UTX0IF=0;
  }
}

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void main(){
  setCLK();
  Init();
  u8 i=0;
  while(1){
    float temp=getWD();
    for(i=0;i<64;i++)
      temp+=getWD();
    char data[6];
    temp/=64;
    sprintf(data,"%.02f",temp);
    sendStr(data);
    Delayms(1000);
  }
}