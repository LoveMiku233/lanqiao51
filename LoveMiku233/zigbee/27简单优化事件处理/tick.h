#ifndef __TICK__
#define __TICK__
#
#define MAX_TIMER 10
typedef struct{
  u8 type;
  u16 event;
  u16 timer;
  u16 timerbackup;
}tickType;

tickType TimerEvent[MAX_TIMER];
u8 TimerTail=0;
u8 TimerEventFull=0;

void TickHandle();
void delTickEvent(u16);
void addTimerEvent(u8,u16,u16);
#endif