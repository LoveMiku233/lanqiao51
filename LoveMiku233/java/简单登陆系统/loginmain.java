package 简单登录系统;

import java.util.Scanner;

public class loginmain {
    public static void main(String[] args){
        Scanner out = new Scanner(System.in);
        loginVerification l1=new loginVerification();
        while(l1.menu()){  //菜单显示
            System.out.println("输入任意继续!");
            out.nextLine();
        }
    }
}