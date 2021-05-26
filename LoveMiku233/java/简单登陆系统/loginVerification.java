package 简单登录系统;//切换用户登陆系统未实现,本地保存,异常捕获

import java.util.Arrays;
import java.util.Scanner;
import java.util.HashMap;  //hashmap
public class loginVerification {
    private int userxh=0;//当前用户
    private int index=0; //当前数组索引位置
    private int itemindex=0;//当前用户的物品数量
    private int[] money=new int[4];
    private item[][] items=new item[4][10];
    private String[] userArr=new String[4];  //创建用户数组
    private shop s1=new shop();
    public loginVerification() {
        System.out.println("初始化...");

        for(int i=0;i<4;i++){
            money[i]=1000;
            for(int j=0;j<10;j++){
                this.items[i][j]=new item();
            }
        }
    }

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
    private void selectSort(){
        for(int i=0;i<this.itemindex;i++){
            int minIndex=i;
            for(int j=i;j<this.itemindex;j++) {
                if (this.items[userxh][minIndex].getPrice() > this.items[userxh][j].getPrice())
                    minIndex=j;
            }
            item temp=this.items[userxh][minIndex];
            this.items[userxh][minIndex]=this.items[userxh][i];
            this.items[userxh][i]=temp;
        }
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
    public void itemUser(){  //打印当前用户的物品
        System.out.print("当前用户姓名: "+userArr[userxh]);
        if(itemindex==0){
            System.out.println(" 当前用户无物品!");
        }else {
            System.out.print(" 拥有物品:");
            for (int i = 0; i < itemindex; i++) {
                if(!items[userxh][i].getName().equals("NULL"))
                System.out.print(items[userxh][i].getName() + " ");
            }
        }
    }
    public void sortitem(){
        if(itemindex!=0){
            try {
                this.selectSort();
            }catch (NullPointerException e) {
                System.out.println("异常: 排序错误");
                return;
            }
        }
    }
    //还没写完
    public void buy(int xz){
        switch (xz){
            case 1:additemshop(s1.shopitem[xz-1]);
            case 2:additemshop(s1.shopitem[xz-1]);
            case 3:additemshop(s1.shopitem[xz-1]);
            case 4:additemshop(s1.shopitem[xz-1]);
            case 5:additemshop(s1.shopitem[xz-1]);
            case 6:additemshop(s1.shopitem[xz-1]);
            default:
        }
    }
    public void additemshop(item t1){
        if(itemindex<=8){
            items[userxh][itemindex] =t1;
            itemindex++;
        }else{
            System.out.println("物品栏已满!");
        }
    }
    public void additem(){
        if(itemindex<=8){
            System.out.print("输入添加物品序号: ");
            item temp=itemMenu();
            if(temp.getName().equals("退出")){
                System.out.println("退出添加!");
            }else {
                items[userxh][itemindex] =temp;
                itemindex++;
            }
        }else{
            System.out.println("物品栏已满!");
        }
    }
    public boolean menu(){  //用户菜单,以后可能会进行优化
        int xz;
        System.out.println("***************************");
        if(cis==0) {  //判*断是否第一次登陆,没啥用，加入本地储存后修改
            firstLogin();
            cis++;
            System.out.println("欢迎"+userArr[userxh]+"进入系统!");
        }
        System.out.println("输入‘1’ : 添加账号");
        System.out.println("输入'2' : 修改密码");
        System.out.println("输入'3' : (管理员)查询相关信息");
        System.out.println("输入'4' : 当前用户添加物品");
        System.out.println("输入'5' : 打印当前用户物品栏");
        System.out.println("输入'6' : 当前用户物品栏按价格排序");
        System.out.println("输入'7' : 购买商品");
        System.out.println("输入'8' : 退出");
        System.out.println("***************************");
        System.out.print("输入选项:");
        xz=out.nextInt();
        switch (xz){  //使用switch来进行执行相关功能
            case 1: this.addUser();break;
            case 2: this.ChangePassword(); break;
            case 3: this.printinfo(); break;
            case 4: this.additem();break;
            case 5: this.itemUser();break;
            case 6: this.sortitem();break;
            case 7:this.s1.menu();break;
            default: if(xz==8)return false;
                    else{System.out.println("输入错误！");return true;}
        }
        return true;
    }
    public item itemMenu(){
        int i;
        System.out.println("物品添加系统");
        System.out.println("输入‘1’ : 电脑");
        System.out.println("输入'2' : 手机");
        System.out.println("输入'3' : 手表");
        System.out.println("输入'4' : 耳机");
        System.out.println("输入'5' : 退出添加");
        i=out.nextInt();

        switch (i){
            case 1: return new item(5000,"电脑");
            case 2: return new item(2000,"手机");
            case 3: return new item(100,"手表");
            case 4: return new item(40,"耳机");
            case 5: return new item(0,"退出");
            default: if(i==5)new item(0,"退出");
            else{System.out.println("输入错误！");return new item(0,"退出");}
        }
        return new item(0,"退出");
    }
}
