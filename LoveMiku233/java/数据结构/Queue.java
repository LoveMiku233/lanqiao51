package 数据结构;

/**
 * The interface Queue.
 *
 * @param <E> the type parameter
 */
public interface Queue<E>{
    /**
     * Dequeue e.
     *
     * @return the e
     */
    E dequeue();

    /**
     * Enqueue.
     *
     * @param e the e
     */
    void enqueue(E e);

    /**
     * Is empty boolean.
     *
     * @return the boolean
     */
    boolean isEmpty();

    /**
     * Gets front.
     *
     * @return the front
     */
    E getFront();
}
