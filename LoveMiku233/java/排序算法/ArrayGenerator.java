package 排序算法;
//数组生成类
import java.util.Random;

/**
 * The type Array generator.
 */
public class ArrayGenerator {
    private ArrayGenerator(){}

    /**
     * Generate ordered array integer [ ].
     *
     * @param n the n
     * @return the integer [ ]
     */
    public static Integer[] generateOrderedArray(int n){
        Integer[] arr=new Integer[n];
        for(int i=0;i<n;i++)
            arr[i]=i;
        return arr;

    }

    /**
     * Generate random array integer [ ].
     *
     * @param n     the n
     * @param bound the bound
     * @return the integer [ ]
     */
    public static Integer[] generateRandomArray(int n,int bound){
        Integer[] arr=new Integer[n];
        Random rdm=new Random();
        for(int i=0;i<arr.length;i++)
            arr[i]=rdm.nextInt(bound);
        return arr;

    }
}
