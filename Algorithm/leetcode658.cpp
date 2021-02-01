#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static const int N = 1010;
    int father[N];
    int n;
    void init() {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }
    }

    int find(int x) {
        return x == father[x] ? x : father[x] = find(father[x]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    // 判断 u 和 v 是否判断同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    bool removedEdge(vector<vector<int>>& edges, int u) {
        init();
        for (int i = 0; i < n; i ++) {
            if (i == u) continue;
            if (same(edges[i][0], edges[i][1])) return false;
            join(edges[i][0], edges[i][1]);
        }

        return true;
    }

    vector<int> getRemovedEdges(vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < n; ++i) {
            if (same(edges[i][0], edges[i][1])) return edges[i];

            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = {0};
        n = edges.size();
        for (int i = 0; i < n; ++i) {
            inDegree[edges[i][1]]++; // 统计入度
        }

        vector<int> vec;
        for (int i = n - 1; i >= 0; i--) {
            if (inDegree[edges[i][1]] == 2)
                vec.push_back(i);
        }

        // 当图中有入度为 2 的点时
        // 删除两条边中的一条，看看删除哪个可以构成树
        if (vec.size() > 0) {
            if (removedEdge(edges, vec[0])) return edges[vec[0]];
            else return edges[vec[1]];
        }

        // 处理没有入度为 2 的情况，那么一定有有向环
        return getRemovedEdges(edges);
    }
};