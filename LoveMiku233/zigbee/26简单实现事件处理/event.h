/*����: LoveMiku233
 *����ʱ��: 2021/8/29
 *�ļ�����: event.h
 *�ļ�����: �¼���ͷ�ļ�
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