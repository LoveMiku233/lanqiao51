import java.util.Scanner;

public class Test1 {
    public static void main(String[] args){
        int x=0;//给X定义类型并且赋予初值
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入x的值");
            x = scanner.nextInt();
            if (x % 2 == 0) {
                System.out.println("x能被二整除");
            } else {
                System.out.println("x不能被二整除");
            }
        }

    }

}
