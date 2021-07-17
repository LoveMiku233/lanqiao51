package 数据结构;

/**
 * The type Array.
 */
public class Array {
    private int[] arr;
    private int size;

    /**
     * Instantiates a new Array.
     *
     * @param dx the dx
     */
    public Array(int dx){
        arr=new int[dx];
        size=0;
    }

    /**
     * Instantiates a new Array.
     */
    public Array(){
        arr=new int[10];
        size=0;
    }

    /**
     * Add.
     *
     * @param shu the shu
     */
//todo 添加
    public void add(int shu){
        if(size<arr.length){
            arr[size]=shu;
            size++;
        }else{
            System.out.println("空间不够");
        }
    }

    /**
     * Re move.
     *
     * @param index the index
     */
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

    /**
     * Re move end int.
     *
     * @return the int
     */
    public int reMoveEnd(){
        size--;
        return arr[size];
    }

    /**
     * Copy end int.
     *
     * @return the int
     */
    public int copyEnd(){
        return arr[size-1];
    }

    /**
     * Printf.
     */
    public void printf(){
        System.out.println("当前有"+size+"个元素");
        for(int i=0;i<size;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

    /**
     * Size int.
     *
     * @return the int
     */
    public int Size(){
        return size;
    }

    /**
     * Add index.
     *
     * @param index the index
     * @param n     the n
     */
    public void addIndex(int index,int n){
        if(index<0||index>size)return;
        for(int i=index;i<size;i++){
            arr[i+1]=arr[i];
        }

    }
}
