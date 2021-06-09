public class Array{
    private int data[];
    private int size;
    //todo 构造函数
    public Array(int capacity){
        data=new int[capacity];
        size=0;
    }
    public void expansion(){
        int[] temp=new int[data.length];
        for(int i=0;i<data.length;i++)
            temp[i] = data[i];
        this.data=new int[size*2];
        for(int i=0;i<size;i++)
             data[i]=temp[i];
    }
    public int getSize(){
        return size;
    }
    public Array(){
        this(10);
    }
    public int getCapacity(){
        return data.length;
    }
    public void add(int i){
        if(size==data.length)
            expansion();
        data[size]=i;
        size++;
    }
    public void print(){
        System.out.println("当前容量为:"+data.length);
        System.out.println("当前元素个数为:"+size);
        for(int i=0;i<size;i++){
            System.out.print(data[i]+" ");
        }
        System.out.println();
    }
    public void sort(){
        if(size==0)return;
        for(int i=0;i<size;i++){
            int minindex=i;
            for(int j=i;j<size;j++){
                if(data[minindex]>data[j])
                    minindex=j;
            }
            int temp=data[i];
            data[i]=data[minindex];
            data[minindex]=temp;
        }
    }
    public void reMove(int i){
        if(i<size){
            for(;i<size-1;i++){
                data[i]=data[i+1];
            }
            size--;
        }
    }
    public int getlength(){
        return data.length;
    }
    public int getIndexdata(int a){
        if(a<size){
            return data[a];
        }
        return -1;
    }
}
