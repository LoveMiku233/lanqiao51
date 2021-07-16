package 数据结构;

/**
 * The type Equeue.
 * 队列实现
 */
public class Equeue {
    private int arr[];
    private int size;
    private int length=10;
    private int count=0;

    /**
     * Instantiates a new Equeue.
     *
     * @param size1 the size 1
     */
    public Equeue(int size1){
        length=size1;
        arr=new int[length];
        this.size=0;
    }

    /**
     * Instantiates a new Equeue.
     */
    public Equeue(){
        arr=new int[length];
        size=0;
    }

    /**
     * Push 1.
     *
     * @param a the a
     */
    public void push1(int a){
        arr[size]=a;
        size++;
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

    /**
     * Pop 1 int.
     *
     * @return the int
     */
    public int pop1(){
        int temp;
        if(size!=0){
            temp=arr[0];
            for(int i=0;i<size;i++){
                arr[i]=arr[i+1];
            }
            size--;
            return temp;
        }
        System.out.println("ERR!");
        return -1;
    }
}
