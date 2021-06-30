package 数据结构;

/**
 * @author LoveMiku
 * @version v1.0
 * @文件名称:
 * @描述: [类型描述]
 * @创建时间: 2021/6/29
 * @update [序号][日期YYYY-MM-DD] [更改人姓名][变更描述]
 */
public class Stack{
    private Array arr;
    public Stack(){
        arr=new Array(10);
    }
    public void Push(int i){
        arr.add(i);
    }
    public int Pop(){
        if(arr.Size()==0){
            System.out.println("无元素了");
            return -1;
        }else {
            return arr.reMoveEnd();
        }
    }
    public int Peek(){
        if(arr.Size()==0){
            System.out.println("无元素了");
            return -1;
        }
        return arr.copyEnd();
    }
    public int getSize(){
        return arr.Size();
    }
    public void print(){
        arr.printf();
    }
    public boolean isEmpty(){
        return getSize()!=0?true:false;
    }
}
