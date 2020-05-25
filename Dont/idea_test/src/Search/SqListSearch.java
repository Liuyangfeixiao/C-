package Search;

import java.util.Arrays;

class RecType
{
    int key;
    String data;
    public RecType(int d)
    { key = d;}
}
class IdxType
{
    int key;        //关键字，这里是对应块中的最大关键字
    int link;       //该索引块在数据表中的起始下标
}
public class SqListSearch {
    final int Max = 100;
    RecType [] R;
    int n;
    public void createR(int [] a)       //创建顺序表
    {
        R = new RecType[Max];
        n = a.length;
        for (int i =0; i < n; i++)
        {
            R[i] = new RecType(a[i]);
        }
    }
    public void Display()               //输出顺序表
    {
        for (int i = 0; i < n; i++)
            System.out.print(R[i].key + " ");
        System.out.println();
    }
    /*折半查找的非递归算法*/
    public int BinSearch(RecType [] R, int n, int k)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high)/2;               //中间
            if (k == R[mid].key)
                return mid;                     //返回mid
            if (k < R[mid].key)
                high = mid-1;                   //上界折半
            else
                low = mid + 1;                  //下界折半
        }
        return -1;              //查找区间为空，返回-1
    }
    /*折半查找的递归算法*/
    public int BinSearch2(RecType[] R, int low, int high, int k)
    {
        if (low <= high)
        {
            int mid = (low + high)/2;
            if (k == R[mid].key)
                return mid;
            if (k > R[mid].key)
                return BinSearch2(R, mid + 1, high, k);
            else return BinSearch2(R, low, mid-1, k);
        }
        return -1;
    }
    public void createI(IdxType[] I, int b)
    {
        int s = (n + b - 1)/b;
        int j = 0, jmax = R[j].key;
        for (int i = 0; i<b; i++)
        {
            I[i] = new IdxType();
            I[i].link = j;
            while (j <= (i+1)*s -1 && j <= n-1)
            {
                if (R[j].key > jmax)
                    jmax = R[j].key;
                j++;
            }
            I[i].key = jmax;
            if (j <= n-1)
                jmax = R[j].key;
        }
    }
    /*分块查找*/
    public int IdxSearch(IdxType[] I, int b, int k)
    {
        /*折半查找索引表*/
        int low = 0;
        int high = b-1;
        int mid;
        while (low <= high)
        {
            mid = (low + high)/2;
            if (k >= I[mid].key)
                low = mid+1;
            else high = mid - 1;
        }
        if (high + 1 > b)
            return -1;
        int i = I[high + 1].link;
        int s = (n + b -1)/b;
        if (i == (b-1)*s)
            s = n - (b-1)*s;
        while (i < I[high+1].link + s && R[i].key != k)
            i++;
        if (i < I[high+1].link + s)
            return i;
        else return -1;
    }

}
