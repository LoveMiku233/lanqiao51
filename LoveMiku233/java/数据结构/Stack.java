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
 * The interface Stack.
 *
 * @param <E> the type parameter
 */
public interface Stack<E> {
    /**
     * Gets size.
     *
     * @return the size
     */
    int getSize();

    /**
     * Push.
     *
     * @param e the e
     */
    void push(E e);

    /**
     * Pop e.
     *
     * @return the e
     */
    E pop();

    /**
     * Is empty boolean.
     *
     * @return the boolean
     */
    boolean isEmpty();

    /**
     * Peek e.
     *
     * @return the e
     */
    E peek();
}
