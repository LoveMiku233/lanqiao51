#ifndef __FUN__
#define __FUN__
void Init();
void LedCtl(u8,u16);
void KeyEventHandle(u16);
void UsartEventHandle(u16);
void sendStr(u8 *);
void sendChar(u8 dat);
void Delayms(u16);
#endif