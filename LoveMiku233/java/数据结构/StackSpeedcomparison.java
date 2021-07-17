package 数据结构;

import java.util.Random;

/**
 * @author LoveMiku
 * @version v1.0
 * @文件名称:
 * @描述: [类型描述]
 * @创建时间: 2021/7/17
 * @update [序号][日期YYYY-MM-DD] [更改人姓名][变更描述]
 */

/**
 * The type Stack speedcomparison.
 */
public class StackSpeedcomparison {
    /**
     * Linkedtest double.
     *
     * @param stack     the stack
     * @param testcount the testcount
     * @return the double
     */
    public static double linkedtest(Stack<Integer> stack,int testcount){
        long starttime=System.nanoTime();
        Random r1=new Random();
        for(int i=0;i<testcount;i++)
            stack.push(r1.nextInt(Integer.MAX_VALUE));
        for(int i=0;i<testcount;i++)
            stack.pop();
        long endtime=System.nanoTime();
        return (endtime-starttime)/1000000000.0;
    }

    /**
     * Arraytest double.
     *
     * @param stack     the stack
     * @param testcount the testcount
     * @return the double
     */
    public static double arraytest(ArrayStack stack, int testcount){
        long starttime=System.nanoTime();
        Random r1=new Random();
        for(int i=0;i<testcount;i++)
            stack.push(r1.nextInt(Integer.MAX_VALUE));
        for(int i=0;i<testcount;i++)
            stack.pop();
        long endtime=System.nanoTime();
        return (endtime-starttime)/1000000000.0;
    }

    /**
     * Main.
     *
     * @param args the args
     */
    public static void main(String[] args){
        int testcount=10000000;
        ArrayStack arr=new ArrayStack( 100000000);
        LinkedListStack link=new LinkedListStack();
        System.out.println("*****随机数测试*****");
        System.out.println("测试数量: "+testcount);
        System.out.println("数组栈用时: "+arraytest(arr,testcount)+'s');
        System.out.println("链表栈用时: "+linkedtest(link,testcount)+'s');
        /* 因为链表会有new操作，所以用时长一些
         *测试数量: 10000000
         *数组栈用时: 0.1253546s
         *链表栈用时: 2.1018424s
         */
    }
}
