#ifndef _DHT11MIKU_
#define _DHT11MIKU_
typedef unsigned char u8;
typedef unsigned int u16;
#define PIN P0_7 

void com();
void Delayus(u16 us);
void Delayms(u16 ms);
u8 DHT11();

#endif