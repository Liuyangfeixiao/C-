package Graph;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class ArcNode //边节点类
{
    int adjvex;
    ArcNode nextarc;
    int weight;
}
class VNode //头节点类
{
    String[] data;
    ArcNode firstarc;
}
public class AdjGraphClass {            //图邻接表类
    final int MAXV = 100;
    final int INF = 0x3f3f3f3f;         //表示∞
    VNode[] adjlist;                    //邻接表头数组
    int n, e;                           //图中顶点数n和边数e
    int [] visited = new int[MAXV];     //标记
    public AdjGraphClass()
    {
        adjlist = new VNode[MAXV];
        for (int i = 0; i < MAXV; i++)
        {
            adjlist[i] = new VNode();
        }
    }
    /*创建图的邻接表*/
    public void createAdjGraph(int[][] a, int n, int e)
    {
        this.n = n; this.e = e;                                 //置顶点数和边数
        ArcNode p;
        for (int i = 0; i<n; i++)                               //所有头节点的指针置初值
        {
            adjlist[i].firstarc = null;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j >= 0; j--)
            {
                if (a[i][j] != 0 && a[i][j] != INF)
                {
                    p = new ArcNode();                          //创建边节点p
                    p.adjvex = j;
                    p.weight = a[i][j];
                    p.nextarc = adjlist[i].firstarc;            //头插法插入p
                    adjlist[i].firstarc = p;
                }
            }
        }
    }
/*输出图*/
    public void disAdjGraph()
    {
        ArcNode p;
        for (int i = 0; i < n; i++)
        {
            System.out.printf(" [%d]", i);
            p = adjlist[i].firstarc;
            while (p != null)
            {
                System.out.printf("->(%d, %d)", p.adjvex, p.weight);
                p = p.nextarc;
            }
            System.out.println("->^");
        }

    }
    /*有向图求顶点的入度和出度*/
    public int[] degree2(AdjGraphClass G, int v)
    {
        int [] ans = new int[2];
        ArcNode p;
        ans[0] = 0;
        ans[1] = 0;
        p = G.adjlist[v].firstarc;
        while (p != null)
        {
            ans[0]++;
            p = p.nextarc;
        }
        for (int i = 0; i < G.n; i++)
        {
            p = G.adjlist[i].firstarc;
            while (p != null)
            {
                if (p.adjvex == v) {
                    ans[1]++;
                    break;
                }
                else  p = p.nextarc;
            }
        }
        return ans;
    }
    /*深度优先遍历 DFS*/
    public void DFS(AdjGraphClass G, int v)
    {
        int w;
        ArcNode p;
        System.out.print(v + " ");          //访问顶点
        visited[v] = 1;                     //置已访问标记

        p = G.adjlist[v].firstarc;          //p指向顶点v的第一个邻接点
        while (p != null)
        {
            w = p.adjvex;
            if (visited[w] == 0)            //若w顶点未访问，递归访问它
                DFS(G, w);
            p = p.nextarc;                  //p置为下一个邻接点
        }
    }
    /*广度优先遍历*/
    public void BFS(AdjGraphClass G, int v)
    {
        ArcNode p;
        int w;
        Queue<Integer> qu = new LinkedList<>(); //定义一个队列
        System.out.print(v + " ");              //访问顶点v
        visited[v] = 1;
        qu.offer(v);                            //v进队

        while (!qu.isEmpty())
        {
            v = qu.poll();
            p = G.adjlist[v].firstarc;
            while (p != null)
            {
                w = p.adjvex;
                if (visited[w] == 0)            //若v的邻接点w未访问
                {
                    System.out.print(w + " ");  //访问顶点w
                    visited[w] = 1;             //置以访问标记
                    qu.offer(w);                //进队
                }
                p = p.nextarc;                  //下一个邻接点
            }
        }
    }
    /*找到u到v的所有简单路径*/
    /*利用带回溯的深度优先遍历*/
    public void findALLPath(AdjGraphClass G, int v, int u)
    {
        int [] path = new int[MAXV];
        int d = -1;
        findAllPath1(G, u, v, path, d);

    }
    private void findAllPath1(AdjGraphClass G, int u, int v, int[] path, int d)
    {
        d++;
        visited[u] = 1;
        path[d] = u;
        ArcNode p;
        if (u == v)
        {
            for (int i = 0; i <= d; i++)
                System.out.print(path[i] + " ");
            System.out.println();
        }
        p = G.adjlist[u].firstarc;
        while (p != null)
        {
            int w = p.adjvex;
            if (visited[w] == 0)
                findAllPath1(G, w, v, path, d); //递归深度优先遍历
            p = p.nextarc;
        }
        visited[u] = 0;         //回溯，置 visited[u] = 0
    }

    public void judgeBFS1(AdjGraphClass G, int i, int k)
    {
        ArcNode p;
        int w;
        visited[i] = 1;

        p = G.adjlist[i].firstarc;
        while (p != null)
        {
            if (p.adjvex == k)
                p = p.nextarc;
            w = p.adjvex;
            if (visited[w] == 0)
            {
                judgeBFS1(G, w, k);
            }
            p = p.nextarc;
        }
    }
    public boolean judge(AdjGraphClass G, int i, int j, int k)
    {
        judgeBFS1(G, i, k);
        if (visited[j] == 0)
            return false;
        else return true;
    }

    /*判断该无向图是否有经过点 v 的回路*/
    public boolean Cycle11(AdjGraphClass G, int u, int v, int d)
    {
        ArcNode p;
        visited[u] = 1;
        d++;
        p = G.adjlist[u].firstarc;
        while (p != null)
        {
            int w = p.adjvex;
            if (visited[w] == 0)
            {
                if (Cycle11(G, w, v, d))
                    return true;
            }
            else if (w == v && d > 1)
                return true;
            p = p.nextarc;
        }
        return false;
    }
    public boolean Cycle(AdjGraphClass G, int v)
    {
        if (Cycle11(G, v, v, -1))
            return true;
        return false;
    }


}
