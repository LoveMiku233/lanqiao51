#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;
u8 cmd=0;
void Init(){
  P1DIR|=0x03;
  P1|=0x03;
  P0SEL|=0x0C;
  U0GCR=11;
  U0BAUD=216;
  U0UCR|=0x80;
  U0CSR|=0xC0;
  URX0IF=0;
  UTX0IF=0;
  URX0IE=1;
  EA=1;
}

void CLK32M(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
}

void sendstr(u8 *data){
  while(*data!='\0'){
    U0DBUF=*data++;
    while(UTX0IF==0);
    UTX0IF=0;
  }
}


#pragma vector=URX0_VECTOR
__interrupt void URX0(){
  URX0IF=0;
  cmd=U0DBUF;
}



void cmdLED(){
  switch(cmd){
    case 0xA1:P1_0=0;sendstr("D1 is open!\n");cmd=0;break;
    case 0xA2:P1_1=0;sendstr("D2 is open!\n");cmd=0;break;
    case 0xB1:P1_0=1;sendstr("D1 is closed!\n");cmd=0;break;
    case 0xB2:P1_1=1;sendstr("D2 is closed!\n");cmd=0;break;
  }
}

void main(){
  CLK32M();
  Init();
  while(1){
    if(cmd!=0)
      cmdLED();
  }
}