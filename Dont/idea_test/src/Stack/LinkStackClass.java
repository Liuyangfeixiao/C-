package Stack;

import java.util.IllformedLocaleException;

class LinkNode<E>
{
    E data;
    LinkNode<E> next;
    public LinkNode()
    {
        next = null;
    }
    public LinkNode(E d)
    {
        data = d;
        next = null;
    }
}
public class LinkStackClass<E> {
    LinkNode<E> head;
    public LinkStackClass()
    {
        head = new LinkNode<E>();
        head.next = null;
    }
    public boolean empty()
    {
        return head.next==null;
    }
    public void push(E e)
    {
        LinkNode<E> s = new LinkNode<E>(e);
        s.next = head.next;
        head.next = s;
    }
    public E pop()
    {
        if (empty())
            throw new IllegalArgumentException("栈空");
        E e = (E) head.next.data;
        head.next = head.next.next;
        return e;
    }
    public E peek()
    {
        if (empty())
            throw new IllegalArgumentException("栈空");
        E e = (E) head.next.data;
        return e;
    }
    public int Index(String t, String s)
    {
        int len_t = t.length();
        int len_s = s.length();
        int i = 0;
        int j = 0;
        while (j < len_t && i < len_s)
        {
            if (t.charAt(j) == s.charAt(i))
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j >= len_t)
            return i- len_t;
        else return -1;
    }


}
