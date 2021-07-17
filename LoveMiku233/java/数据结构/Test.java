package 数据结构;

/**
 * The type Test.
 */
public class Test {
    /**
     * Main.
     *
     * @param args the args
     */
    public static void main(String[] args){
        LinkedListQueue<Integer> Q1=new LinkedListQueue<>();
        Q1.enqueue(1);
        Q1.enqueue(2);
        Q1.enqueue(3);
        Q1.enqueue(4);
        Q1.enqueue(5);
        System.out.println("Queue : Front");
        System.out.println(Q1.toString());
        Q1.dequeue();
        Q1.dequeue();
        Q1.dequeue();
        Q1.dequeue();
        System.out.println(Q1.toString());
    }
}
