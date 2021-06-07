package 简单登录系统;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.annotation.JSONField;
import java.io.*;

import static com.alibaba.fastjson.JSON.toJSONString;

public class saveAccount {
    File f=new File("D:/1.json");;
    String json;
    InputStream in;
    OutputStream out;
    public String test(){
        try {
            in = new FileInputStream(f);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        char[] chars=new char[200];
        int i=0;
        int temp;
        try {
            while((temp=in.read())!=-1) {
                chars[i] = (char) temp;
                i++;
            }
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        json=new String(chars,0,i);
        return json;
    }
    public void test1(loginVerification Miku){
        try {
            out=new FileOutputStream(f);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        json= toJSONString(Miku);
        OutputStreamWriter writer = null;
        try {
            writer = new OutputStreamWriter(out, "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        try {
            writer.append(json);
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
