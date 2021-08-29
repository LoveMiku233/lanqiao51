/*作者: LoveMiku233
 *创建时间: 2021/8/29
 *文件名称: main.c
 *文件描述: 主函数,简单实现非OS事件处理
 *实现功能: 事件驱动LED1 每隔4s切换显示 
            软件延迟可能没有那么准确
*/
#include <ioCC2530.h>
#include "event.h"
u8 event_full=0;
u8 eventHead=0;
u8 eventTail=0;
u8 _event[100];
u8 handleTail=1;
eventType _eventfun[10];

void Init();
void LED();
void eventProc();  
void addevent();
void Delays(){
  int i,j;
  for(i=0;i<2000;i++)
    for(j=535;j>0;j--);
}
void main(){
  Init();
  while(1){
    addevent();
    Delays();
    eventProc();
    Delays();
  }
}
void Init(){
  P1SEL&=0xfe;
  P1DIR|=0x01;
  P0SEL&=0xfd;
  P0DIR|=0xfd;
  P0INP&=0xfd;
  
  _eventfun[0].code=0x0001; //LED事件配置
  _eventfun[0].fun=LED;
}

void eventProc(){
  u16 event;
  u8 i;
  if(event_full||eventHead!=eventTail){
    event=_event[eventHead];
    _event[eventHead++]=0;
    if(eventHead>=10){
      eventHead=0;
    }
    for(i=0;i<handleTail;i++){
      if(event==_eventfun[i].code){
        (*_eventfun[i].fun)();
      }
    }
  }
}

void LED(){
   P1_0=!P1_0;
}

void addevent(){
  if((eventTail-eventHead)<=9){
    event_full=0;
  }else{
    event_full=1;
  }
  if(!event_full){
    _event[eventTail++]=0x0001;
  }
  if(eventTail>= 10){
    eventTail=0;
  }
}