import java.util.Scanner;

public class loginVerification {
    String password;
    String name;
    private int cis=0;
    Scanner out = new Scanner(System.in);
    private final String rootpassword="Miku";
    private void ChangePassword(){
        System.out.println("please enter the original password:");
        String password=out.next();
        if(password.equals(this.password)) {
            System.out.println("please enter a new password:");
            this.password=out.next();
        }else {
            System.out.println("wrong password!");
        }
    }
    void firstLogin(){
        System.out.println("welcome to the login system!");
        System.out.print("please enter user name:");
        this.name=out.next();
        System.out.print("please enter user password:");
        this.password=out.next();
    }
    //保存到本地
    void saveName(){

    }
    private void printinfo(){
        System.out.println("Please enter the administrator password!");
        String s1=out.next();
        if(s1.equals(rootpassword))System.out.println("name:"+this.name+" password:"+this.password);
        else System.out.println("wrong password!");
    }
    public void ispd(){
        System.out.print("请输入被2整除的值:");
        int x=out.nextInt();
        if(x%2==0)System.out.println("可以");
        else System.out.println("不可以");
    }
    public boolean menu(){
        int xz;
        System.out.println("***************************");
        if(cis==0) {
            firstLogin();
            cis++;
            System.out.println("欢迎"+this.name+"进入系统!");
        }
        System.out.println("输入‘1’ : 查询余额");
        System.out.println("输入'2' : 修改密码");
        System.out.println("输入'3' : (管理员)查询相关信息");
        System.out.println("输入'4' : 输入一个值是否能被2整除");
        System.out.println("输入'5' : 退出");
        System.out.println("***************************");
        System.out.print("输入选项:");
        xz=out.nextInt();
        switch (xz){
            case 1: break;
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