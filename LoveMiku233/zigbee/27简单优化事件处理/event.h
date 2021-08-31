#ifndef __EVENT__
#define __EVENT__

#define MAX_HANDLE 10
#define MAX_EVENT 10
#define KEY1 0x0001
#define KEY2 0x0002
#define INT0 0x0003
#define USART0 0x0010
typedef unsigned char u8 ;
typedef unsigned int u16;
void eventProc();
void addHandle();
void addEvent(u16);

typedef struct{
  void (*handle)(u16 event);
}eventType;

u8 handleFull=0;
u8 eventFull=0;
u8 eventHead=0,eventTail=0;
u8 HandleTail=0;
eventType Handle[MAX_HANDLE];
u16 Event_[MAX_EVENT];

#endif