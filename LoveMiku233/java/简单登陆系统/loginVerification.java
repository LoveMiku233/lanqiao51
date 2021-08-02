/*
 * 文件名：loginVerification.java
 * 作者：LoveMiku233〈1657041544@qq.com〉
 * 描述：登陆菜单系统简单实现
 * 创建日期：2021-5-19
 * 修改时间：2021-5-19 ????
 *         2021-5-21 ????
 *         2021-5-24 ????
 *         2021-5-26 整合简单商城系统
 */


package 简单登录系统;//切换用户登陆系统未实现,本地保存,异常捕获

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.HashMap;  //hashmap
public class loginVerification {
    private int userxh=0;//当前用户
    private int index=0; //当前数组索引位置
    private int itemindex=0;//当前用户的物品数量
    private int[] money=new int[4];//用户余额
    private item[][] items=new item[4][10];
    private String[] userArr=new String[4];  //创建用户数组
    private shop s1=new shop();
    private StringBuilder Stringrz=new StringBuilder();
    private SimpleDateFormat date=new SimpleDateFormat("yyyy年MM月dd日 HH时mm分ss秒");
    private HashMap<String,String> user=new HashMap<String,String>();  //创建hashmap，账号密码对应
    private int cis=0; //是否首次登陆(计划修改为检测是否有账号)
    private Scanner out = new Scanner(System.in);
    public loginVerification() {
        System.out.println("初始化...");
        for(int i=0;i<4;i++){
            money[i]=1000;
            for(int j=0;j<10;j++){
                this.items[i][j]=new item();
            }
        }
        Stringrz.append(time()+" 系统初始化\n");
    }
    public loginVerification(loginVerification a1){
        this.money=a1.money;
        this.items=a1.items;
        this.itemindex= a1.itemindex;
        this.userArr=a1.userArr;
        this.user=a1.user;
        zhangh();
    }

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
    private void zhangh(){
        System.out.println("1."+userArr[0]);
        System.out.println("2."+userArr[1]);
        System.out.println("3."+userArr[2]);
        System.out.println("4."+userArr[3]);
        int a=out.nextInt();
        if(a<=4&&a>=1){
            if(a==1)userxh=0;
            if(a==2)userxh=1;
            if(a==3)userxh=2;
            if(a==4)userxh=3;
        }
    }
    private String time(){
        Date d1=new Date();
        String str=date.format(d1);
        return str;
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

    void saveName(){
        //todo 保存到本地功能
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
            Stringrz.append(time()+" 进入管理信息系统\n");
            System.out.println("目前有"+user.size()+"个用户");  //打印用户个数
            for(int i=0;i<user.size();i++)  //利用用户数组中的key打印hashmap中的值
            System.out.println("用户名:"+userArr[i]+" 密码:"+user.get(userArr[i])+" 余额:"+money[i]);
            System.out.println("******************日志******************");
            System.out.println(Stringrz.toString());
            System.out.println("**************************************");
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
            }
        }
    }
    //还没写完
    public void buy(int xz){
        if(xz!=-1){
            if(money[userxh]>=s1.shopitem[xz-1].getPrice()) {
                additemshop(s1.shopitem[xz - 1]);
                money[userxh]-=s1.shopitem[xz-1].getPrice();
                System.out.println("购买成功!");
                Stringrz.append(time()+" 购买"+s1.shopitem[xz-1].getName()+"成功\n");
            }else{
                System.out.println("余额不足!");
            }
        }else{
            System.out.println("选择错误!");
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
        if(cis==0) {  //判断是否第一次登陆,没啥用，加入本地储存后修改
            firstLogin();
            cis++;
            System.out.println("欢迎"+userArr[userxh]+"进入系统!");
        }
        System.out.println("用户名: "+userArr[userxh]+" 余额:"+money[userxh]);
        System.out.println("输入‘1’ : 添加账号");
        System.out.println("输入'2' : 修改密码");
        System.out.println("输入'3' : (管理员)查询相关信息");
        System.out.println("输入'4' : 当前用户添加物品");
        System.out.println("输入'5' : 打印当前用户物品栏");
        System.out.println("输入'6' : 当前用户物品栏按价格排序");
        System.out.println("输入'7' : 购买商品");
        System.out.println("输入'8' : 出售商品");
        System.out.println("输入'9' : 退出");
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
            case 7:this.buy(s1.menu());break;
            case 8:this.itemchus();break;
            default: if(xz==9)return false;
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
            default: new item(0,"退出");
        }
        return new item(0,"退出");
    }
    //物品出售函数
    public void itemchus(){
        if(itemindex==0) System.out.println("当前无物品出售");
        else{
            int a;
            System.out.println("请选择需要出售的物品序号!");
            for(int i=0;i<itemindex;i++){
                System.out.println("输入"+"'"+(i+1)+"'"+"："+items[userxh][i].getName());
            }
            System.out.print("请输入选择：");
            a=out.nextInt();
            if(a<=itemindex&&a>0) {
                for (int i = a; i < itemindex; i++) {
                    items[userxh][i] = items[userxh][i + 1];
                }
                itemindex--;
                money[userxh]+=items[userxh][a-1].getPrice()*0.5;
                Stringrz.append(time()+" 出售"+items[userxh][a-1].getName()+"成功\n");
            }else{
                System.out.println("错误索引");
                return;
            }
        }
    }
}

