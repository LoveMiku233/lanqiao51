/*
 * 文件名：loginmain.java
 * 作者：LoveMiku233〈1657041544@qq.com〉
 * 描述：登陆菜单系统简单实现
 * 创建日期：2021-5-19
 * 修改时间：2021-5-19 简单登陆系统主函数
 */
package 简单登录系统;

import com.alibaba.fastjson.JSON;

import java.io.File;
import java.util.Scanner;
public class loginmain {
    public static void main(String[] args){
        Scanner out = new Scanner(System.in);
        saveAccount s1=new saveAccount();
        loginVerification l1=new loginVerification();
        File f=new File("D:/1.json");
        if(f.exists()) {
            String s2 = s1.test();
            l1 = JSON.parseObject(s2, loginVerification.class);
        }
        while(l1.menu()){  //菜单显示
            System.out.println("输入任意继续!");
            out.nextLine();
        }
        s1.test1(l1);
    }
}