package 数据结构;

/**
 * The type Linkedlist.
 * 链表实现
 *
 * @param <E> the type parameter
 */
public class Linkedlist<E> {
    private class Node{
        /**
         * The Data.
         */
        public E data;
        /**
         * The Next.
         */
        public Node next;

        /**
         * Instantiates a new Node.
         *
         * @param a the a
         * @param n the n
         */
        public Node(E a,Node n){
            this.data=a;
            this.next=n;
        }

        /**
         * Instantiates a new Node.
         *
         * @param a the a
         */
        public Node(E a){
            this(a,null);
        }

        /**
         * Instantiates a new Node.
         */
        public Node(){
            this(null,null);
        }
        @Override
        public String toString(){
            return data.toString();
        }
    }
    private int size;
    private Node dummyNode;

    /**
     * Instantiates a new Linkedlist.
     */
    public Linkedlist(){
        size=0;
        dummyNode =new Node(null,null);
    }

    /**
     * Get size int.
     *
     * @return the int
     */
    public int getSize(){
        return size;
    }

    /**
     * Is empty boolean.
     *
     * @return the boolean
     */
    public boolean isEmpty(){
        return size==0;
    }

    /**
     * Add first.
     *
     * @param a the a
     */
    public void addFirst(E a){
        add(0,a);
    }

    /**
     * Add.
     *
     * @param index the index
     * @param a     the a
     */
    public void add(int index,E a){
        if(index>=0&&index<=size){
            int i=0;
            Node tempNode = dummyNode;
            while(index!=i){
                tempNode = tempNode.next;
                i++;
            }
            tempNode.next=new Node(a, tempNode.next);
            size++;
        }else{
            System.out.println("错误索引233");
        }
    }

    /**
     * Get e.
     *
     * @param index the index
     * @return the e
     */
    public E get(int index){
        if(index<0||index>size)throw new RuntimeException("Get failed,illegal index!");
        int i=0;
        Node tempNode=dummyNode.next;
        while(index!=i){
            tempNode=tempNode.next;
            i++;
        }
        return tempNode.data;
    }

    /**
     * Print listed list.
     */
    public void printListedList(){
        if(size!=0) {
            System.out.println(this.toString());
        }else{
            System.out.println("List为空");
        }
    }

    /**
     * Set.
     *
     * @param index the index
     * @param a     the a
     */
    public void set(int index,E a){
        if(index<0||index>size)throw new RuntimeException("Get failed,illegal index!");
        int i=0;
        Node temp = dummyNode.next;
        while(index!=i){
            temp=temp.next;
            i++;
        }
        temp.data=a;
    }

    /**
     * Contains boolean.
     *
     * @param a the a
     * @return the boolean
     */
    public boolean contains(E a){
        Node temp = dummyNode.next;
        while(temp!=null){
            if(temp.data.equals(a)){
                return true;
            }
            temp=temp.next;
        }
        return false;
    }
    @Override
    public String toString(){
        Node temp = dummyNode.next;
        StringBuilder s1=new StringBuilder();
        while(temp!=null){
            s1.append(temp.data+"->");
            temp=temp.next;
        }
        s1.append("null");
        return s1.toString();
    }

    /**
     * Re move e.
     *
     * @param index the index
     * @return the e
     */
    public E reMove(int index){
        if(index<0||index>size)throw new RuntimeException("Get failed,illegal index!");
        Node temp=dummyNode;
        for(int i=0;i<index;i++){
            temp=temp.next;
        }
        Node temp1=temp.next;
        temp.next= temp1.next;
        temp1=null;
        size--;
        return temp.data;
    }
}
