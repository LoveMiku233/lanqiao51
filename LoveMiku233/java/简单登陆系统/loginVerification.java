//切换用户登陆系统未实现,本地保存,异常捕获

import java.util.Scanner;
import java.util.HashMap;  //hashmap
public class loginVerification {
    private int userxh=0;//当前用户
    private int index=0; //当前数组索引位置
    private String[] userArr=new String[4];  //创建用户数组
    HashMap<String,String> user=new HashMap<String,String>();  //创建hashmap，账号密码对应
    private int cis=0; //是否首次登陆(计划修改为检测是否有账号)
    Scanner out = new Scanner(System.in);
    private void ChangePassword(){  //当前登陆用户密码修改函数
        System.out.println("请输入原密码:");
        String password=out.next();
        if(password.equals(user.get(userArr[userxh]))) { //密码正确执行
            System.out.println("请输入新密码:");
            password=out.next();
            user.replace(userArr[userxh],password); //修改hashmap key对应的值
        }else { //密码错误执行
            System.out.println("错误密码!");
        }
    }
    private void firstLogin(){  //首次登陆调用，以后会修改，修改为检测是否有账号，没有则创建
        System.out.println("欢迎来到登陆系统!");
        addUser();
    }
    private void addUser(){  //添加账号
        if(index!=3) { //检测用户数量是否满了
            System.out.print("注册用户名:");
            String name = out.next();
            System.out.print("注册密码:");
            String password = out.next();
            userArr[index] = name; //用户数组添加key
            user.put(name,password); //hashmap添加用户
            index++; //维护数组索引
        }else{ //满了输出语句
            System.out.println("用户已满");
        }
    }
    //保存到本地  未实现
    void saveName(){

    }
    private void printinfo(){  //管理员打印相关信息
        System.out.println("请输入管理员密码!");
        String s1=out.next();
        if(s1.equals("123")){ //判断是否为管理员密码
            System.out.println("目前有"+user.size()+"个用户");  //打印用户个数
            for(int i=0;i<user.size();i++)  //利用用户数组中的key打印hashmap中的值
            System.out.println("用户名:"+userArr[i]+" 密码:"+user.get(userArr[i]));
        } //错误则输出
        else System.out.println("错误密码");
    }
    public void ispd(){ //没啥可说的
        System.out.print("请输入被2整除的值:");
        int x=out.nextInt();
        if(x%2==0)System.out.println("可以");
        else System.out.println("不可以");
    }
    public boolean menu(){  //用户菜单,以后可能会进行优化
        int xz;
        System.out.println("***************************");
        if(cis==0) {  //判断是否第一次登陆,没啥用，加入本地储存后修改
            firstLogin();
            cis++;
            System.out.println("欢迎"+userArr[userxh]+"进入系统!");
        }
        System.out.println("输入‘1’ : 添加账号");
        System.out.println("输入'2' : 修改密码");
        System.out.println("输入'3' : (管理员)查询相关信息");
        System.out.println("输入'4' : 输入一个值是否能被2整除");
        System.out.println("输入'5' : 退出");
        System.out.println("***************************");
        System.out.print("输入选项:");
        xz=out.nextInt();
        switch (xz){  //使用switch来进行执行相关功能
            case 1: this.addUser();break;
            case 2: this.ChangePassword(); break;
            case 3: this.printinfo(); break;
            case 4: this.ispd();break;
            case 5:
            default: if(xz==5)return false;
                    else{System.out.println("输入错误！");return true;}
        }
        return true;
    }
}