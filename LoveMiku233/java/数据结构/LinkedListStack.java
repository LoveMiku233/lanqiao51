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
 * The type Linked list stack.
 *
 * @param <E> the type parameter
 */
public class LinkedListStack<E> implements Stack<E>{
    private Linkedlist<E> list;

    /**
     * Instantiates a new Linked list stack.
     */
    public LinkedListStack(){
        list=new Linkedlist();
    }
    @Override
    public int getSize(){
        return list.getSize();
    }

    @Override
    public void push(E e) {
        list.addFirst(e);
    }

    @Override
    public E pop() {
        return (E) list.reMove(0);
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public E peek() {
        return (E)list.get(0);
    }
    @Override
    public String toString(){
        StringBuilder str=new StringBuilder();
        str.append("Stack: Top");
        str.append(list);
        return str.toString();
    }
}
