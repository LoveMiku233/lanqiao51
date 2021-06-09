//简单实现栈
public class stack {
    private Array a1;
    public stack(){
        a1=new Array();
    }
    public void Push(int a){
        if(a1.getSize()<a1.getlength()) {
            a1.add(a);
        }
    }
    public int Pop(){
        int a=a1.getIndexdata(a1.getSize()-1);
        a1.reMove(a1.getSize()-1);
        return a;
    }

}
