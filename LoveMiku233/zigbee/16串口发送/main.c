#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Init(){
  P1DIR|=0x03;
  P1|=0x03;
  P0SEL|=0x0C;
  //´®¿Ú
  U0UCR|=0x80;
  U0GCR=8;
  U0BAUD=59;
  U0CSR|=0xC0;
  URX0IF=0;
  UTX0IF=0;
  //¿´ÃÅ¹·WDT
  WDTIF=0;
  WDCTL|=0x0C;
  IEN2|=0x20;
  EA=1;
}

void UR0_SEND(u8 dat){
  U0DBUF=dat;
  while(UTX0IF==0);
  UTX0IF=0;
}
void UR0_str(u8 *str){
  while(*str!='\0')
    UR0_SEND(*str++);
}

#pragma vector=WDT_VECTOR
__interrupt void WDT(){
  UR0_str("Miku233\r\n");
  WDTIF=0;
}

void main(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
  
  Init();
  while(1);
}