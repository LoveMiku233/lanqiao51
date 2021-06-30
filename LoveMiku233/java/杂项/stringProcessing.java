import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class stringProcessing {
    public static void main(String[] args){
        String path="D:\\Miku3.txt";
        String temp=new String("");
        try {
            BufferedReader buff=new BufferedReader(new FileReader(path));
            while((temp=buff.readLine())!=null){
                //todo 处理格式明天整233
                System.out.println(temp);
            }
        }catch (FileNotFoundException e){
            System.out.println(e);
        }catch (IOException e){
            System.out.println(e);
        }

    }
}
