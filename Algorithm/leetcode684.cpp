#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
int father[N];

// 并查集初始化
void init(int n) {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}

// 寻根
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}

// 将 v -> u 这条边加入并查集
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}

// 判断 u v 是否在同一个根

bool same(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    init(edges.size());
    for (int i = 0; i < edges.size(); i++) {
        if (same(edges[i][0], edges[i][1])) return edges[i];
        else join(edges[i][0], edges[i][1]);
    }

    return {};

}