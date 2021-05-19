import java.util.*;
public class main {
    public static void main(String[] arge){
        Scanner out = new Scanner(System.in);
        System.out.println("welcome to the login system!");
        System.out.println("please enter user name:");
        String name=out.next();
        System.out.println("please enter user password:");
        String password=out.next();
        loginVerification l1=new loginVerification(name,password);
        l1.printinfo();
    }
}
