package 数据结构;

/**
 * @author LoveMiku
 * @version v1.0
 * @文件名称:
 * @描述: [类型描述]
 * @创建时间: 2021/6/28
 * @update [序号][日期YYYY-MM-DD] [更改人姓名][变更描述]
 */
public class Array {
    private int[] arr;
    private int size;
    public Array(int dx){
        arr=new int[dx];
        size=0;
    }
    public Array(){
        arr=new int[10];
        size=0;
    }
    //todo 添加
    public void add(int shu){
        if(size<arr.length){
            arr[size]=shu;
            size++;
        }else{
            System.out.println("空间不够");
        }
    }
    public void reMove(int index){
        if(index>size)
            throw new RuntimeException("索引错误");
        else{
            int temp;
            for(int i=index;i<size;i++){
                arr[i]=arr[i+1];
            }
            size--;
        }
    }
    public int reMoveEnd(){
        size--;
        return arr[size];
    }
    public int copyEnd(){
        return arr[size-1];
    }
    public void printf(){
        System.out.println("当前有"+size+"个元素");
        for(int i=0;i<size;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public int Size(){
        return size;
    }
}
