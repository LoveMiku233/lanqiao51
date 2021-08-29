/*作者: LoveMiku233
 *创建时间: 2021/8/29
 *文件名称: event.h
 *文件描述: 事件简单头文件
*/

#ifndef __EVENT__
#define __EVENT__

typedef unsigned char u8;
typedef unsigned int u16;
typedef struct{
  u16 code;
  void (*fun)(void);
}eventType;



#endif