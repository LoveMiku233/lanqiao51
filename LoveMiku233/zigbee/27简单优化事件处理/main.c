#include <ioCC2530.h>
#include "event.h"
#include "fun.h"

#define A0(n) P0SEL&=n
#define A1(n) P1SEL&=n
#define B0(n) P0DIR|=n
#define B1(n) P1DIR|=n

void main(){
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
  addHandle(KeyEventHandle);
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
    case KEY1: LedCtl(1,5000);break;
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
    for(j=535;j>0;j--);
}

void LedCtl(u8 LED,u16 time){ //使用软件延迟 time暂不使用
  switch(LED){
    case 1: P1_0=!P1_0;break;
    //...
  }
}

