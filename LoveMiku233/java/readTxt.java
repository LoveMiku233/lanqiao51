import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class readTxt {
    public static void main(String[] args) throws IOException {
        String s1=new String("");
        File file=new File("D:\\Miku.txt");
        Scanner out=new Scanner(file);
        Scanner in=new Scanner(System.in);
        s1=s1.concat("this is a new txt \n");
        while(out.hasNextLine()) {
            s1=s1.concat(out.nextLine()+'\n');
        }
        System.out.println(s1);
        System.out.print("输入添加的文字:");
        s1=s1.concat(in.nextLine()+'\n');
        s1=s1.concat("233"+'\n');
        FileWriter writer=new FileWriter("D:\\Miku1.txt");
        writer.write(s1);
        writer.close();
    }
}
