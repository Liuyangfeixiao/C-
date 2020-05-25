package Stack;
import java.util.Objects;
public class SqStackClass<E> {
    final int initCapacity = 10;
    private int capacity;
    private E[] data;
    private int top;        //存放栈顶指针

    public SqStackClass()
    {
        data = (E[]) new Object[initCapacity];
        capacity = initCapacity;
        top = -1;
    }
    private void updateCapacity(int newCapacity)        //扩容
    {
        E[] newdata = (E[]) new Objects[newCapacity];
        for (int i = 0; i < top; i++)
            newdata[i] = data[i];
        data = newdata;
        capacity = newCapacity;
    }
    public boolean empty()
    {
        return top==-1;
    }
    public void push(E e)
    {
        if (top == capacity - 1)
            updateCapacity(2*(top + 1));
        top++;
        data[top] = e;
    }
    public E pop()
    {
        E e = data[top];
        top--;
        if (top + 1>initCapacity && top + 1 == capacity/4)
            updateCapacity(capacity/2);
        return e;
    }
    public E peek()
    {
        return (E) data[top];
    }

    /*判断 b 序列是否是一个合适的出栈序列*/
    public boolean isSerial(int[] b)
    {
        int i, j, n = b.length;
        Integer e;
        SqStackClass<Integer> st = new SqStackClass<>();
        int [] a = new int[n];
        for (i = 0; i < n; i++)
            a[i] = i+1;
        i = 0;
        j = 0;
        while (i < n)
        {
            st.push(a[i]);
            i++;
            while (!st.empty() && st.peek() == b[j])
            {
                e = st.pop();
                j++;
            }
        }
        return st.empty();
    }

}
