package 数据结构;

/**
 * The type Array stack.
 */
public class ArrayStack{
    private Array arr;

    /**
     * Instantiates a new Array stack.
     */
    public ArrayStack(){
        arr=new Array(10);
    }

    /**
     * Instantiates a new Array stack.
     *
     * @param a the a
     */
    public ArrayStack(int a){arr=new Array(a);}

    /**
     * Push.
     *
     * @param i the
     */
    public void push(int i){
        arr.add(i);
    }

    /**
     * Pop int.
     *
     * @return the int
     */
    public int pop(){
        if(arr.Size()==0){
            System.out.println("无元素了");
            return -1;
        }else {
            return arr.reMoveEnd();
        }
    }

    /**
     * Peek int.
     *
     * @return the int
     */
    public int peek(){
        if(arr.Size()==0){
            System.out.println("无元素了");
            return -1;
        }
        return arr.copyEnd();
    }

    /**
     * Get size int.
     *
     * @return the int
     */
    public int getSize(){
        return arr.Size();
    }

    /**
     * Print.
     */
    public void print(){
        arr.printf();
    }

    /**
     * Is empty boolean.
     *
     * @return the boolean
     */
    public boolean isEmpty(){
        return getSize()!=0?true:false;
    }
}
