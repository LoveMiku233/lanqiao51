package 排序算法;

/**
 * The type Sort.
 */
//排序算法类
//以后排序相关的都会放在这
public class Sort {
    private Sort(){}
    private static <E> void sawp(E arr[],int a,int b){
        E temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

    /**
     * Select sort.
     *
     * @param <E> the type parameter
     * @param arr the arr
     */
    public static <E extends Comparable<E>> void SelectSort(E[] arr){
        for(int i=0;i<arr.length;i++){
            int minIndex=i;
            for(int j=i;j<arr.length;j++){
                if(arr[minIndex].compareTo(arr[j])>0)
                    minIndex=j;
            }
            sawp(arr,minIndex,i);
        }
    }

    /**
     * Insertion sort.
     *
     * @param <E> the type parameter
     * @param arr the arr
     */
    public static <E extends Comparable<E>> void InsertionSort(E[] arr){
        for(int i=0;i<arr.length;i++){
            for(int j=i;j-1>=0;j--){
                if(arr[j-1].compareTo(arr[j])>0){
                    sawp(arr,j-1,j);
                }
            }
        }
    }

}
