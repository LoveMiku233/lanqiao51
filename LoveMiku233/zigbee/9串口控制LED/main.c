#include <ioCC2530.h>
#include <string.h>
typedef unsigned char u8;
typedef unsigned int u16;
#define UART0_RX 1
#define UART0_TX 2
#define CONTROL_LED 3
#define SIZE 4
#define ON 0
#define OFF 1
#define LED1 P1_0
#define LED2 P1_1

char RxBuf;
char UartState;
u8 count;
char RxDate[SIZE];

void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=1070;j>0;j--);
}


void Init(){
  P1DIR|=0x03;
  PERCFG=0x00;
  P0SEL|=0x0C;
  P2DIR&=~0xC0;
  U0CSR|=0x80;
  U0BAUD=216;
  U0GCR=11;
  UTX0IF=0;
  U0CSR|=0x40;
  IEN0|=0x84;
}

void Send(char *arr,int len){
  u16 i;
  for(i=0;i<len;i++){
    U0DBUF=*arr++;
    while(UTX0IF==0);
    UTX0IF=0;
  }
}

#pragma vector=URX0_VECTOR
__interrupt void UART0_ISR(){
  URX0IF=0;
  RxBuf=U0DBUF;
}

void main(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
  Init();
  UartState=UART0_RX;
  memset(RxDate,0,SIZE);
  
  while(1){
    if(UartState==UART0_RX){
      if(RxBuf!=0){
        if((RxBuf!='#')&&(count<3))
            RxDate[count++]=RxBuf;
        else{
          if(count>=3){
            count=0;
            memset(RxDate,0,SIZE);
          }
          else UartState=CONTROL_LED;
        }
        RxBuf=0;
      }
    }
    if(UartState==CONTROL_LED){
      if((RxDate[0]=='d'||RxDate[0]=='D')&&(RxDate[1]=='1'||RxDate[1]=='2')){
        if(RxDate[1]=='1')
          LED1=~LED1;
        else
          LED2=~LED2; 
      }
      else if((RxDate[0]=='a'||RxDate[0]=='A')&&(RxDate[1]=='0'||RxDate[1]=='1')){
        if(RxDate[1]=='0'){
          LED1=ON;
          LED2=ON;
        }else{
          LED1=OFF;
          LED2=OFF;
        }
      }
      UartState=UART0_RX;
      count=0;
      memset(RxDate,0,SIZE);
    }
  }
}