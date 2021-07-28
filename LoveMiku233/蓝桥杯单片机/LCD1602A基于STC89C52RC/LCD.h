#ifndef __LCD__
#define __LCD__
//LCDÇý¶¯
#define u8 unsigned char
#define u16 unsigned int
void Delayms(u16 ms);
void LCD_COM(u8 dat); 
void LCD_write(u8 dat);
void LCD_init();

#endif