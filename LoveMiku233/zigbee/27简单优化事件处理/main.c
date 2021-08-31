#include <ioCC2530.h>
#include "event.h"
#include "fun.h"

#define _USART_

#define A0(n) P0SEL&=n
#define A1(n) P1SEL&=n
#define B0(n) P0DIR|=n
#define B1(n) P1DIR|=n

void main(){
#ifdef _USART_
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
#endif
  Init();
  while(1){
    //测试
    if(P0_1==0){
      Delayms(5);
      if(P0_1==0){
        addEvent(KEY1);
      }
      while(!P0_1);
    }
    eventProc();
  }
}

void Init(){
  A1(0xfe);
  B1(0x01);
  A0(0xfd);
  B0(0xfd);
  P0INP&=0xfd;
  #ifdef _USART_
  P0SEL|=0x0C;
  U0UCR|=0x80;
  U0GCR=8;
  U0BAUD=59;
  U0CSR|=0xC0;
  UTX0IF=0;
  URX0IF=0;
  URX0IE=1;
  IEN0 |= 0x84;
  EA=1;
  #endif
  addHandle(KeyEventHandle);
  addHandle(UsartEventHandle);
}

void addHandle(void (*Fun)(u16)){
  if(!handleFull)
    Handle[HandleTail++].handle=Fun;
  handleFull=(HandleTail>MAX_HANDLE)?1:0;
}

void eventProc(){
  u16 eventTemp=0;
  u8 i;
  if(eventHead!=eventTail||eventFull){
    eventTemp=Event_[eventHead];
    Event_[eventHead++]=0;
  }
  if(eventHead>=MAX_EVENT)
    eventHead=0;
  for(i=0;i<HandleTail;i++)
    (*Handle[i].handle)(eventTemp);
}

void KeyEventHandle(u16 event){ 
  switch(event){
    case KEY1: addEvent(USART0T);break;
    case KEY2: LedCtl(1,5000);break;
  }
}

void addEvent(u16 event){
  u8 can=1;
  u8 i;
  if(!eventFull){
    i=eventHead;
    while(i!=eventTail){
      if(Event_[i]==event){
        can=0;
        break;
      }
      i++;
      if(i>=MAX_EVENT){
        i=0;
      }
    }
    if(can){
      Event_[eventTail++]=event;
      Event_[eventTail]=0; //需要维护
      if(eventTail>=MAX_EVENT)eventTail=0;
      eventFull=(eventTail==eventHead)?1:0;
    }
  }
}
//系统Tick实现


//
void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=1040;j>0;j--);
}

void LedCtl(u8 LED,u16 time){ //使用软件延迟 time暂不使用
  switch(LED){
    case 1: P1_0=!P1_0;break;
    //...
  }
}

void UsartEventHandle(u16 event){
   switch(event){
    case USART0T: sendStr("LED1 switch!\n"); LedCtl(1,5000); 
                  break;
    case USART0R:
        addEvent(USART0T);
        break;
    //...
    }
}

void sendStr(u8 *data){
  while(*data!='\0')
  sendChar(*data++);
}
void sendChar(u8 dat){
  U0DBUF=dat; //U0DBUF无法赋值，可能是问题所在
  while(UTX0IF==0);
  UTX0IF=0;
}

#pragma vector=URX0_VECTOR
__interrupt void URX0(){
  URX0IF = 0;
  str[strcount] = U0DBUF;
  if(str[strcount] == '\n')
  {
    addEvent(USART0R);
    strcount=0;
  }
  else
    strcount++;
}