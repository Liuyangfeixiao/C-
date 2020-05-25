package Queue;

import java.util.Objects;

public class SqQueueClass<E> {
    final int MaxSize = 100;
    private E[] data;
    private int front, rear;        //队头队尾指针
    public SqQueueClass()
    {
        data = (E[]) new Object[MaxSize];
        front = rear = -1;
    }

    /*判断队列是否为空*/
    public boolean empty()
    {
        return front==rear;
    }
    /*进队*/
    public void offer(E e)
    {
        if (rear == MaxSize - 1)
            throw new IllegalArgumentException("队满");
        rear++;
        data[rear] = e;
    }
    /*出队*/
    public E poll()
    {
        if (empty())
            throw new IllegalArgumentException("队空");
        front++;
        return data[front];
    }
    /*取队头元素*/
    public E peek()
    {
        if (empty())
            throw new IllegalArgumentException("队空");
        return data[front+1];
    }

}
