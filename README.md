[2024新仓库] (https://github.com/LoveMiku233/LanQiao-STC15)



# 这是什么🌏
这是以蓝桥杯单片机为主学习过程中的代码存储库

> * 学习蓝桥杯单片机
> * 练习Github代码储存库
> * 练习Jav

# 代码块
``` C
//蓝桥杯单片机格式
#include <STC15F2K60S2.H>
//可选：
//onewire.h 单总线驱动
//ds1302.h ds1302驱动
//iic.h i方c驱动
#define u8 unsigned char
#define u16 unsigned int        
u8 tab[]={...}; //"{...}" 数码管码值,里面填数码管显示"1~9"的码值
void AllInit(); //声明初始化
void Delayms(u16);//声明延时函数
void main(){  //主函数
    AllInit(); //上电初始化
    while(1){ //大循环
        //写代码
    }
}
void AllInit(){ //定义初始化函数
	P2=0xa0;P0=0x00; //选择继电器、蜂鸣器  0x00全部关闭
    P2=0xc0;P0=0xff; //选择数码管位选，0xff选择所有数码管
	P2=0xe0;P0=0xff; //选择数码管段选,0xff全部熄灭
    P2=0x80;P0=0xff; //选择LED，0xff全部熄灭
}
void Delayms(u16 ms){ //定义延时函数,如果ms=1，则延迟1毫秒;ms=1000,则延迟1秒
	u16 i,j;
	for(i=0;i<ms;i++)
		for(j=845;j>0;j--);
}
//以上简单格式
//初始化函数、P2口控制还可以写的更好
```
# 参与人员👨‍👦‍👦
<p align="center">
<a href= LoveMiku233/> <img alt="LoveMiku233" width="150" height="150" src="LoveMiku233/tx.png" /><br/></a>
 👨‍💻 LoveMiku233 
- 🎮 CSGO / GTA5 
- 💻 Lenovo Y7000 
- ⚡ C++ / C  
</p>

<p align="center">
<a href= piaochnagli/><img  src="piaochnagli/tx.png" width="150" height="150" alt="头像" /><br/></a>
 👨‍💻 piaochnagli 
- 🍓 strawberry
- ⚡  lazy
</p>

<p align="center">
<a href= YaYa/> <img src="YaYa/tx.png" width="150" height="150" alt="头像" /><br/></a>
 👨‍💻 MCxiaochengcheng
- 🎮 CSGO/LOL
- 💻 神舟 战神
- 🍓 VAN♂游戏
- ⚡ 吃饭睡觉
</p>

<p align="center">
<a href= chuishi123/> <img src="chuishi123/tx.png" width="150" height="150" alt="头像" /><br/></a>
 👨‍💻 chuishi123
- 🎮 LOL
- 💻 HP
- 🍓 VAN♂游戏
- ⚡ 吃饭睡觉
</p>
