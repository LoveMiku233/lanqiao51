#include "ioCC2530.h"

#define LED1 P1_0
#define LED2 P1_1
#define KEY P0_1

#define KEY_UP 1
#define KEY_DOWN 0

unsigned int keyperss=1;
#define KEYperss 50

void init(){
  //LED KEY
  P0DIR&=~0x02;
  P1DIR|=0x03;
  LED1=1;LED2=1;
  //timer
  T1CC0L = 0xe2; 
  T1CC0H = 0x04; 
  T1CCTL0 |= 0x04; 
  T1IE = 1;
  T1OVFIM = 1; 
  EA = 1;
  T1CTL = 0x0e;
}


void main(){
  init();
  while(1){
  }
}
//×´Ì¬»ú¿ØÖÆLED
void keyscan(){
  static char key=KEY_UP,key_upcnt=0,key_downcnt=0;
  char keystat=KEY;
  if((key==KEY_UP)&&(keystat==KEY_DOWN)){
    key_downcnt++;
    if(key_downcnt>=2){
      key=KEY_DOWN;
      keyperss=0;
    }
  }else{
    key_downcnt=0;
  }
  if((key==KEY_DOWN)&&(keystat==KEY_UP)){
    key_upcnt++;
    if(key_upcnt>=2){
      if(keyperss>=KEYperss)
        LED1=!LED1;
      else
        LED2=!LED2;
      key=KEY_UP;
    }
  }else{
    key_upcnt=0;
  }
}


#pragma vector=T1_VECTOR
__interrupt void T1fun(){ //10ms
     IRCON=0x00;
     keyperss++;
     if(keyperss>1000)keyperss=0;
     keyscan();
}