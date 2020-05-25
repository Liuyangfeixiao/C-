package itheima;
import java.util.LinkedList;
import java.util.Queue;
public class CSqueue {
    public static void main(String[] args) {
        Queue<Integer> qu = new LinkedList<Integer>();
        qu.offer(1);
        qu.offer(2);
        qu.offer(3);
        while (!qu.isEmpty())
        {
            System.out.println(qu.poll() + " ");
        }
        System.out.println();
    }
}
