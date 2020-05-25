package Order;

import java.util.LinkedList;

class RecType
{
    int key;
    String data;
    public RecType(int d)
    { key = d; }
}
public class SqListSortClass {
    final int Max = 100;
    RecType[] R;
    int n;

    public void createR(int[] a)
    {
        R = new RecType[Max];
        for (int i = 0; i < a.length; i++)
            R[i] = new RecType(a[i]);
        n = a.length;
    }

    public void Disp()
    {
        for (int i = 0; i < n; i++)
            System.out.print(R[i].key + " ");
        System.out.println();
    }


    public void swap(int i, int j)
    {
        RecType tmp = R[i];
        R[i] = R[j];
        R[j] = tmp;
    }

    public void InsertSort()
    {
        RecType tmp;
        int j;
        for (int i = 1; i < n; i++)
        {
            if (R[i].key < R[i-1].key)
            {
                tmp = R[i];
                j = i;
                while (j > 0 && R[j].key > tmp.key)
                {
                    R[j] = R[j-1];
                    j--;
                }
                R[j] = tmp;
            }
        }
    }
    /*折半插入法*/
    public void BinInsertSort()
    {
        int low, mid, high;
        RecType tmp;
        for (int i = 1; i < n; i++)
        {
            if (R[i].key < R[i-1].key)
            {
                tmp = R[i];
                low = 0;
                high = i-1;
                while (low <= high)
                {
                    mid = (low + high) /2;
                    if (tmp.key < R[mid].key)
                        high = mid-1;
                    else
                        low = mid + 1;
                }
                for (int j = i - 1; j >= high+1; j--)
                    R[j+1] = R[j];
                R[high+1] = tmp;
            }
        }
    }
    public void ShellSort()
    {
        RecType tmp;
        int d = n/2;
        while (d > 0)
        {
            for (int i = d; i< n; i++)
            {
                tmp = R[i];
                int j = i - d;
                while (j >= 0 && tmp.key < R[j].key)
                {
                    R[j+d] = R[j];
                    j = j - d;
                }
                R[j+d] = tmp;
            }
            d = d/2;
        }
    }
    /*冒泡排序*/
    public void BubbleSort()
    {
        boolean exchange = false;
        for (int i = 0; i < n-1; i++)
        {
            exchange = false;
            for (int j = n - 1; j > i; j--)
                if (R[j].key < R[j-1].key)
                {
                    swap(j, j-1);
                    exchange = true;
                }
            if (!exchange)
                break;
        }
    }
    /*快速排序*/
    public int Partition1(int s, int t)
    {
        int i = s;
        int j = t;
        RecType base = R[s];
        while (i < j)
        {
            while (i < j && R[j].key >= base.key)
                j--;
            while (i < j && R[i].key <= base.key)
                i++;
            if (i < j)
                swap(i,j);
        }
        R[i] = base;
        return i;
    }

    public int Partition2(int s, int t)
    {
        int i = s;
        int j = t;
        RecType base = R[s];
        while (i != j)
        {
            while (i < j && R[j].key >= base.key)
                j--;
            if (i < j)
            {
                R[i] = R[j];
                i++;
            }
            while (i < j && R[i].key <= base.key)
                i++;
            if(i < j)
            {
                R[j] = R[i];
                j--;
            }
        }
        swap(s,i);
        return i;
    }

    public int Partition3(int s, int t)
    {
        int i = s;
        int j = s+1;
        RecType base = R[s];
        while (j < t)
        {
            if (R[j].key <= base.key)
            {
                i++;
                swap(i,j);
            }
            j++;
        }
        swap(s,i);
        return i;
    }
}
/*leetecode 课程表*/
class Solution
{
    public boolean canFinish(int numCourses, int[][] pre)
    {
        int [] inDegree = new int[numCourses];
        for (int[] cp : pre)
            inDegree[cp[0]]++;
        LinkedList<Integer> qu = new LinkedList<>();
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                qu.addLast(i);
        while (!qu.isEmpty())
        {
            Integer pr = qu.removeFirst();
            numCourses--;
            for (int[] req : pre)
            {
                if (req[1] != pr)
                    continue;
                if (--inDegree[req[0]] == 0)
                    qu.addLast(req[0]);
            }
        }

        return numCourses == 0;
    }
    /*选择排序：堆排序*/
    private void shift(int low, int high)
    {
        int i = low, j = 2 * low;


    }
}
