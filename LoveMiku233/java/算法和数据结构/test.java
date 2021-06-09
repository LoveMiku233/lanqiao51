//测试类
public class test {
    public static void main(String[] args){
        stack s1=new stack();
        s1.Push(1);
        s1.Push(3);
        s1.Push(4);
        System.out.println(s1.Pop()+ " "+ s1.Pop()+ " "+s1.Pop());
    }
}
