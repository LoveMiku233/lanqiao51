package 简单登录系统;

import java.util.Scanner;

public class shop {
    int ye=0;
    item[] shopitem=new item[6];
    Scanner out= new Scanner(System.in);
    public shop() {
        shopitem[0]=new item(1000,"手表");
        shopitem[1]=new item(2000,"手机");
        shopitem[2]=new item(100,"食物");
        shopitem[3]=new item(99999,"车");
        shopitem[4]=new item(99999999,"飞机芜湖");
        shopitem[5]=new item(30,"csgo");
    }
    public int menu(){
        if(ye==0){
            for(int i=0;i<6;i++){
                System.out.println("商品"+(i+1)+": "+ this.shopitem[i].printinto());
            }
            int xz=out.nextInt();
            if((xz<=6)&&(xz>0))return xz;
        }
        return -1;
    }
}
