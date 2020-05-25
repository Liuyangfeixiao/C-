package Queue;

public class CSqQueueClass<E> {
    final int MaxSize = 100;
    private E[] data;
    private int front, rear;
    public CSqQueueClass()
    {
        data = (E[]) new Object[MaxSize];
        front = rear = 0;
    }
    public boolean empty()
    {
        return front==rear;
    }
    public void offer(E e)
    {
        if ((rear + 1) % MaxSize == front)
            throw new IllegalArgumentException("队满");
        rear = (rear+1)%MaxSize;
        data[rear] = e;
    }
    public E poll()
    {
        if (empty())
            throw new IllegalArgumentException("队空");
        front = (front+1)%MaxSize;
        E e = data[front];
        return e;
    }
    public E peek()
    {
        if (empty())
            throw new IllegalArgumentException("队空");
        return data[(front+1) % MaxSize];
    }
    public int size()
    {
        return (rear - front + MaxSize) % MaxSize;
    }

}
