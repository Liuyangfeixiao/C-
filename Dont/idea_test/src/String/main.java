package String;

public class main {
    /*KMP算法 求 next 数组*/
    public static void Getnextval(int[] nextval, String t)
    {
        int j = 0, k = -1;
        nextval[0] = -1;
        while (j < t.length() - 1)
        {
            if (k == -1 || t.charAt(j) == t.charAt(k))
            {
                k++;
                j++;
                if (t.charAt(j) != t.charAt(k))
                    nextval[j] = k;
                else
                    nextval[j] = nextval[k];
            }
            else
                k = nextval[k];
        }
    }
    /*KMP查找*/
    public static int KMP(String s, String t)
    {
        int [] nextval = new int[t.length()];
        Getnextval(nextval, t);
        int i = 0;
        int j = 0;
        while (i < s.length() && j < t.length())
        {
            if (j == -1 && s.charAt(i) == t.charAt(j))
            {
                i++;
                j++;
            }
            else
                j = nextval[j];
        }
        if (j >= t.length())
            return i - t.length();
        else return -1;
    }

}
