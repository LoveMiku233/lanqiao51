package 排序算法;

/**
 * The type Test.
 */
public class test {
    /**
     * Print arr.
     * 打印数组
     *
     * @param <E> the type parameter
     * @param arr the arr
     */
    public static <E extends Comparable<E>> void printArr(E[] arr){
        if(arr.length==0)return;
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");

        }
        if(isSorted(arr)){
            System.out.print(" 排序完成");
        }else{
            System.out.print(" 未排序");
        }
        System.out.println();
    }

    /**
     * Is sort boolean.
     *
     * @param <E> the type parameter
     * @param arr the arr
     * @return the boolean
     */
    public static <E extends Comparable<E>> boolean isSorted(E[] arr){
        for(int i=0;i<arr.length-1;i++){
            for(int j=i;j<arr.length-1;j++){
                if(arr[j].compareTo(arr[j+1])>0)
                    return false;
            }
        }
        return true;
    }

    /**
     * Test sort.
     *
     * @param <E>     the type parameter
     * @param sortFun the sort fun
     * @param arr     the arr
     */
    public static <E extends Comparable<E>> void testSort(String sortFun,E[] arr){
        long startTime,endTime;
        if(sortFun.equals("InsertionSort")){
            startTime=System.nanoTime();
            Sort.InsertionSort(arr);
            endTime=System.nanoTime();
        }else if(sortFun.equals("SetectSort")){
            startTime=System.nanoTime();
            Sort.SelectSort(arr);
            endTime=System.nanoTime();
        }else throw new RuntimeException(sortFun+" 无此算法!");
        double time=(endTime-startTime) / 1000000000.0;
        printArr(arr);
        System.out.println(sortFun+",timeCost:"+time+"s"); //还有问题
    }

    /**
     * Main.
     *
     * @param args the args
     */
    public static void main(String[] args){
        int n=10;
        Integer[] arr= ArrayGenerator.generateRandomArray(n,100);
        printArr(arr);
        testSort("InsertionSort",arr);
    }
}
