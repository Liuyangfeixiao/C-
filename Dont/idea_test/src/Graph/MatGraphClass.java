package Graph;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class MatGraphClass {
    final int Max = 100;
    final int INF = 0x3f3f3f3f; //表示无穷
    int[][] edges;
    int n, e;                   //顶点数，边数
    String[] vexs;              //存放顶点信息
    int[] visited = new int[Max];

    public MatGraphClass() {
        edges = new int[Max][Max];
        vexs = new String[Max];
    }

    /*创建图的邻接矩阵*/
    public void createMatGraph(int[][] a, int n, int e) {
        this.n = n;
        this.e = e;
        for (int i = 0; i < n; i++) {
            edges[i] = new int[n];
            for (int j = 0; j < n; j++)
                edges[i][j] = a[i][j];
        }
    }

    /*输出图*/
    public void dispMatGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (edges[i][j] == INF)
                    System.out.printf("%4s", "∞");
                else
                    System.out.printf("%5d", edges[i][j]);
            System.out.println();
        }
    }

    /*广度优先遍历算法*/
    public void BFS(MatGraphClass G, int v) {
        visited[v] = 1;
        Queue<Integer> qu = new LinkedList<>();
        qu.offer(v);
        for (int i = 0; i < G.n; i++) {
            v = qu.poll();
            if (visited[i] == 0 && G.edges[v][i] != 0 && G.edges[v][i] != INF) {
                qu.offer(i);
                visited[i] = 1;
            }
        }
    }

    /*深度优先遍历算法*/
    public void DFS(MatGraphClass G, int v) {
        visited[v] = 1;
        for (int i = 0; i < G.n; i++)
            if (visited[i] == 0 && G.edges[v][i] != 0 && G.edges[v][i] != INF)
                DFS(G, i);
    }

    /*Prim算法*/
    /*时间复杂度为O(n^2)*/
    public void Prim(MatGraphClass G, int v) {
        int[] lowest = new int[Max];       //lowest数组表示 集合 V-U 的节点到 U 的最短边
        int[] closest = new int[Max];       //closest数组表示 集合 V-U 的节点到 U 的最短边所连接的节点
        int min, k;

        for (int i = 0; i < G.n; i++)       //初始化
        {
            lowest[i] = G.edges[v][i];
            closest[i] = v;
        }

        for (int i = 1; i < G.n; i++)   //求 最小生成树的 n-1 条边
        {
            min = INF;
            k = -1;

            for (int j = 0; j < G.n; j++)//求 U 到 V-U 的最小边
            {
                if (lowest[j] != 0 && lowest[j] < min) {
                    min = lowest[j];
                    k = j;
                }
            }

            lowest[k] = 0;
            for (int j = 0; j < G.n; j++)       //更新lowest 和 closest
            {
                if (lowest[j] != 0 && G.edges[k][j] < lowest[j]) {
                    closest[j] = k;
                    lowest[j] = G.edges[k][j];
                }
            }
        }

    }

    /*克鲁斯卡尔算法*/
    class Edges {
        int u;
        int v;
        int w;

        public Edges(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    public void Kruskal(MatGraphClass G) {
        int[] vset = new int[Max];
        Edges[] E = new Edges[Max];
        int k = 0;
        for (int i = 0; i < G.n; i++)
            for (int j = 0; j < i; j++)
                if (G.edges[i][j] != 0 && G.edges[i][j] != INF) {
                    E[k] = new Edges(i, j, G.edges[i][j]);
                    k++;
                }
        for (int i = 0; i < G.n; i++)
            vset[i] = i;
        Arrays.sort(E, 0, k, new Comparator<Edges>() {
            @Override
            public int compare(Edges o1, Edges o2) {
                return o1.w - o2.w;
            }
        });
        int cnt = 1;                 //cnt表示当前构造第几条边,初值为1
        int j = 0;                   //取E中边的下标,初值为0
        while (cnt < G.n)            //生成的边数小于n时循环
        {
            int u1 = E[j].u;
            int v1 = E[j].v;         //取一条边的头尾顶点
            int sn1 = vset[u1];
            int sn2 = vset[v1];              //分别得到两个顶点所属连通分量编号
            if (sn1 != sn2)          //两顶点属于不同连通分量添加
            {
                System.out.print("(" + u1 + "," + v1 + "):" + E[j].w + "  ");  //输出边
                cnt++;                //生成边数增1
                for (int i = 0; i < G.n; i++)        //两个连通分量统一编号
                    if (vset[i] == sn2)              //将sn2的连通分量中顶点改为sn1
                        vset[i] = sn1;
            }
            j++;                                    //继续取E的下一条边
        }
    }

    public void Floyd(MatGraphClass G, int v) {
        int[][] path = new int[Max][Max];
        int[][] A = new int[Max][Max];
        for (int i = 0; i < G.n; i++)
            for (int j = 0; j < G.n; j++) {
                A[i][j] = G.edges[i][j];
                if (i != j && G.edges[i][j] < INF)
                    path[i][j] = i;
                else
                    path[i][j] = -1;
            }
        for (int k = 0; k < G.n; k++)
            for (int i = 0; i < G.n; i++)
                for (int j = 0; j < G.n; j++) {
                    if (A[i][j] < A[i][k] + A[k][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                        path[i][j] = k;
                    }

                }
    }

    public void DisPath(int[][] A, int[][] path, MatGraphClass G) {
        int[] apath = new int[Max];
        int d;
        for (int i = 0; i < G.n; i++)
            for (int j = 0; j < G.n; j++) {
                if (A[i][j] != INF && i != j) {
                    System.out.print(" 顶点" + i + "到" + j +
                            "的最短路径长度：" + A[i][j] + "\t路径：");
                    int k = path[i][j];
                    d = 0;
                    apath[d] = j;
                    while (k != -1 && k != i) {
                        d++;
                        apath[d] = k;
                        k = path[i][k];
                    }
                    d++;
                    apath[d] = i;
                    for (int s = d; s >= 0; s--)
                        System.out.println(" " + apath[s]);
                    System.out.println();
                }
            }
    }

    /*Dijkstra算法*/
    /*单源最短路径*/
    public void Dijkstra(MatGraphClass G, int v) {
        int[] dist = new int[Max];
        int[] path = new int[Max];
        int[] S = new int[Max];

        for (int i = 0; i < G.n; i++) {
            dist[i] = G.edges[v][i];
            S[i] = 0;
            if (G.edges[v][i] < G.INF)
                path[i] = v;
            else
                path[i] = -1;
        }
        S[v] = 1;
        for (int i = 0; i < G.n; i++) {
            int min = INF;
            int k = -1;
            for (int j = 0; j < G.n; j++)
                if (S[j] == 0 && dist[j] < min) {
                    min = dist[j];
                    k = j;
                }
            S[k] = 1;
                for (int j = 0; i < G.n; i++)
                {
                    if (S[j] == 0 && dist[k] + G.edges[k][j] < dist[j])
                    {
                        dist[j] = dist[k] + G.edges[k][j];
                        path[j] = k;
                    }
                }

        }

    }


}