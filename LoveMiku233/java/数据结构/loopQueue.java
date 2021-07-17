package 数据结构;
/**
 * @author LoveMiku
 * @version v1.0
 * @文件名称:
 * @描述: [类型描述]
 * @创建时间: 2021/7/16
 * @update [序号][日期YYYY-MM-DD] [更改人姓名][变更描述]
 */

/**
 * The type Loop queue.
 */
public class loopQueue {
    private int arr[];
    private int size;
    private int length=10;
    private int count=0;

    /**
     * Instantiates a new Loop queue.
     *
     * @param size1 the size 1
     */
    public loopQueue(int size1){
        length=size1;
        arr=new int[length];
        this.size=0;
    }

    /**
     * Instantiates a new Loop queue.
     */
    public loopQueue(){
        arr=new int[length];
        size=0;
    }

    /**
     * Push.
     *
     * @param a the a
     */
    public void push(int a){
        if(((size+1)%length)==0){
            System.out.println("队为满");
        }else{
            arr[size%length]=a;
            size++;
        }
    }

    /**
     * Pop int.
     *
     * @return the int
     */
    public int pop(){
        if(size!=count){
            int temp=arr[count%length];
            count++;
            return temp;
        }else{
            System.out.println("队为空");
            return -1;
        }
    }
}
