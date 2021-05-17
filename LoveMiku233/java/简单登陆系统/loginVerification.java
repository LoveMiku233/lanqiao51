import java.util.Scanner;

public class loginVerification {
    String password;
    String name;
    Scanner out = new Scanner(System.in);
    private final String rootpassword="Miku";
    loginVerification(String name, String password) {
        this.name = name;
        this.password=password;
    }
    boolean ChangePassword(){
        System.out.println("please enter the original password:");
        String password=out.next();
        if(password.equals(this.password)) {
            System.out.println("please enter a new password:");
            this.password=out.next();
            return true;
        }else {
            System.out.println("wrong password!");
            return false;
        }
    }
    void printinfo(){
        System.out.println("Please enter the administrator password!");
        String s1=out.next();
        if(s1.equals(rootpassword))System.out.println("name:"+this.name+" password:"+this.password);
        else System.out.println("wrong password!");
    }
}