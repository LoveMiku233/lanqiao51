package 数据结构;

/**
 * The type Test.
 * 测试类
 */
public class Test {
    /**
     * Main.
     *
     * @param args the args
     */
    public static void main(String[] args){
        Linkedlist<Integer> L1=new Linkedlist<>();
        L1.add(2,1);
        L1.add(0,231);
        L1.add(2,23);
        L1.add(1,123);
        L1.add(1,1213);
        L1.add(3,1123);
        L1.add(1,1111);
        L1.printListedList();
        L1.addFirst(1111);
        L1.printListedList();
        L1.set(0,100);
        System.out.println(L1.get(0));
        System.out.println(L1.contains(1123));
        L1.printListedList();
        L1.reMove(4);
        L1.printListedList();
    }
}
