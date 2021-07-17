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
 * The type Queue speedcomparison.
 */
public class QueueSpeedcomparison {
    /**
     * Linkedtest double.
     *
     * @param queue     the queue
     * @param testcount the testcount
     * @return the double
     */
    public static double linkedtest(Queue<Integer> queue,int testcount){
        long starttime=System.nanoTime();
        Random r1=new Random();
        for(int i=0;i<testcount;i++)
            queue.enqueue(r1.nextInt(Integer.MAX_VALUE));
        for(int i=0;i<testcount;i++)
            queue.dequeue();
        long endtime=System.nanoTime();
        return (endtime-starttime)/1000000000.0;
    }

    /**
     * Arraytest double.
     *
     * @param queue     the queue
     * @param testcount the testcount
     * @return the double
     */
    public static double arraytest(ArrayQueue queue, int testcount){
        long starttime=System.nanoTime();
        Random r1=new Random();
        for(int i=0;i<testcount;i++)
            queue.push(r1.nextInt(Integer.MAX_VALUE));
        for(int i=0;i<testcount;i++)
            queue.pop();
        long endtime=System.nanoTime();
        return (endtime-starttime)/1000000000.0;
    }

    /**
     * Looptest double.
     *
     * @param queue     the queue
     * @param testcount the testcount
     * @return the double
     */
    public static double looptest(loopQueue queue, int testcount){
        long starttime=System.nanoTime();
        Random r1=new Random();
        for(int i=0;i<testcount;i++)
            queue.push(r1.nextInt(Integer.MAX_VALUE));
        for(int i=0;i<testcount;i++)
            queue.pop();
        long endtime=System.nanoTime();
        return (endtime-starttime)/1000000000.0;
    }

    /**
     * Main.
     *
     * @param args the args
     */
    public static void main(String[] args){
        int testcount=1000000;
        ArrayQueue arr=new ArrayQueue(100000000);
        loopQueue loop=new loopQueue(100000000);
        LinkedListQueue<Integer> link=new LinkedListQueue();
        System.out.println("*****随机数测试*****");
        System.out.println("测试数量: "+testcount);
        System.out.println("数组队列用时: "+arraytest(arr,testcount)+'s');
        System.out.println("循环队列用时: "+looptest(loop,testcount)+'s');
        System.out.println("链表队列用时: "+linkedtest(link,testcount)+'s');
        /* 性能提升是巨大的
         *测试数量: 1000000
         *数组队列用时: 168.5079706s
         *循环队列用时: 0.0220082s
         *链表队列用时: 0.0445076s
         */
    }
}
