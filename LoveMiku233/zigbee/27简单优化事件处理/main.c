#include <ioCC2530.h>
#include "event.h"
#include "fun.h"
#include "tick.h"

#define _USART_
#define _TICK_

#define A0(n) P0SEL&=n
#define A1(n) P1SEL&=n
#define B0(n) P0DIR|=n
#define B1(n) P1DIR|=n

void main(){
#ifdef _USART_
  set32M();
#endif

#ifdef _TICK_
  Init_Timer();
#endif
  Init();
  addTimerEvent(1,KEY2,10); //测试 20=2S
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

void Init_Timer()
{
  T1CC0L = 0xd4; 
  T1CC0H = 0x30; 
  T1CCTL0 |= 0x04; 
  T1IE = 1;
  T1OVFIM = 1; 
  EA = 1;
  T1CTL = 0x0e;
}

void Init(){
  P1SEL&=~0x13;
  P1DIR|=0x13;
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
  addHandle(UsartEventHandle);
  #endif
  addHandle(KeyEventHandle);
}

void set32M(){
  CLKCONCMD&=~0x40;
  while(CLKCONSTA&0x40);
  CLKCONCMD&=~0x47;
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
    if(eventHead>=MAX_EVENT)
      eventHead=0;
    for(i=0;i<HandleTail;i++)
      (*Handle[i].handle)(eventTemp);
  }
}

void KeyEventHandle(u16 event){ 
  switch(event){
    case KEY1: addEvent(USART0T);break;
    case KEY2: LedCtl(2,5000);break;
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
      if(eventTail>=MAX_EVENT)eventTail=0;
      eventFull=(eventTail==eventHead)?1:0;
    }
  }
}
//系统Tick实现
#pragma vector = T1_VECTOR
__interrupt void Timer1_Sevice() //100ms定时
{
  T1STAT =0x00;
  TickHandle(); 
}

void TickHandle(){
  u8 i;
  for(i=0;i<TimerTail;i++){
    TimerEvent[i].timer--;
    if(TimerEvent[i].timer==0){
      addEvent(TimerEvent[i].event);
      if(!TimerEvent[i].type){
        delTickEvent(TimerEvent[i].event);
      }else{
        TimerEvent[i].timer=TimerEvent[i].timerbackup;
      }
    }
  }
}

void addTimerEvent(u8 type,u16 event,u16 timer){
  if(!TimerEventFull){
    TimerEvent[TimerTail].type=type;
    TimerEvent[TimerTail].event=event;
    TimerEvent[TimerTail].timer=timer;
    TimerEvent[TimerTail].timerbackup=timer;
    TimerTail++;
  }
  if(TimerTail>=MAX_TIMER)TimerEventFull=1;
}

void delTickEvent(u16 _event){
  u8 i,j;
  for(i=0;i<TimerTail;i++){
    if(TimerEvent[i].event==_event){
      for(j=i;j<TimerTail;j++){
        TimerEvent[j]=TimerEvent[j+1];
      }
      TimerTail--;
      TimerEventFull=0;
    }
  }
}

//
void Delayms(u16 ms){
  u16 i,j;
  for(i=0;i<ms;i++)
    for(j=1040;j>0;j--);
}

void LedCtl(u8 LED,u16 time){ //使用软件延迟 time暂不使用
  switch(LED){
    case 1: P1_0=!P1_0;break;
    case 2: P1_1=!P1_1;break;
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