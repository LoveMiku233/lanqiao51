#include <ioCC2530.h>

typedef unsigned char u8;
typedef unsigned int u16;

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=535;j>0;j--);
}

void Init(){
  PERCFG=0x00; //选择P0_2,P0_3
  P0SEL|=0x0C; //0000 1100 配置P0_2 P0_3为外设
  P2DIR&=~0xC0; //配置优先级
  U0CSR|=0x80;
  U0BAUD|=216;
  U0GCR|=11;
  UTX0IF=0;
}

void send(char* c,int len){
  int i;
  for(i=0;i<len;i++){
    U0DBUF=*c++;
    while(!UTX0IF);
    UTX0IF=0;
  }
}

void main(){
  char data[6]={'2','3','3','Y','K','\n'};
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
  Init();
  while(1){
    send(data,6);
    Delayms(1000);
  }
}