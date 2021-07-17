package 数据结构;

/**
 * The type Array queue.
 */
public class ArrayQueue {
    private int arr[];
    private int size;
    private int length=10;

    /**
     * Instantiates a new Array queue.
     *
     * @param size1 the size 1
     */
    public ArrayQueue(int size1){
        length=size1;
        arr=new int[length];
        this.size=0;
    }

    /**
     * Instantiates a new Array queue.
     */
    public ArrayQueue(){
        arr=new int[length];
        size=0;
    }

    /**
     * Push.
     *
     * @param a the a
     */
    public void push(int a){
        arr[size]=a;
        size++;
    }

    /**
     * Pop int.
     *
     * @return the int
     */
    public int pop(){
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
