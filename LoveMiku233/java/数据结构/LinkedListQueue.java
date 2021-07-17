package 数据结构;
/**
 * @author LoveMiku
 * @version v1.0
 * @文件名称:
 * @描述: [类型描述]
 * @创建时间: 2021/7/17
 * @update [序号][日期YYYY-MM-DD] [更改人姓名][变更描述]
 */

/**
 * The type Linked list queue.
 *
 * @param <E> the type parameter
 */
public class LinkedListQueue<E> implements Queue<E>{
    private class Node<E>{
        private E data;
        private Node next;

        /**
         * Instantiates a new Node.
         *
         * @param d the d
         * @param n the n
         */
        public Node(E d,Node n){
            data=d;
            next=n;
        }
    }
    private Node head,tail;
    private int size;

    /**
     * Instantiates a new Linked list queue.
     */
    public LinkedListQueue(){
        head=null;
        tail=null;
        size=0;
    }
    @Override
    public E dequeue() {
        if(isEmpty())throw new RuntimeException("队列为空");
        Node temp=head;
        head=head.next;
        temp.next=null;
        if(head==null)tail=null;
        size--;
        return (E)temp.data;
    }

    @Override
    public void enqueue(E e) {
        if(tail==null){
            tail=new Node(e,null);
            head=tail;
        }else{
            tail.next=new Node(e,null);
            tail=tail.next;
        }
        size++;
    }
    @Override
    public E getFront(){
        if(isEmpty())throw new RuntimeException("队列为空");
        return (E)head.data;
    }
    @Override
    public boolean isEmpty() {
        return size==0;
    }
    @Override
    public String toString(){
        Node temp = head;
        StringBuilder s1=new StringBuilder();
        while(temp!=null){
            s1.append(temp.data).append("->");
            temp=temp.next;
        }
        s1.append("null");
        return s1.toString();
    }
}
