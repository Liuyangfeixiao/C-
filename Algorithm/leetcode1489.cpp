#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Union {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;
    
public:
    Union(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;

        if (size[u] < size[v]) {
            swap(u, v);
        }

        parent[v] = u;
        size[u] += size[v];
        --setCount;
        return true;
    }

    bool same(int x, int y) {
        x = find(x);
        y = find(y);
        return x == y;
    }

};


class Solution{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        /*记录排序前的边序号*/
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }
        /*按照权值重新排序*/
        sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
            return u[2] < v[2];
        });

        // sum the value

        Union uf_st(n);
        int value = 0;
        for (int i = 0; i < m; i++) {
            if (uf_st.join(edges[i][0], edges[i][1])) value += edges[i][2];
        }

        vector<vector<int>> ans(2);

        for (int i = 0; i < m; ++i) {
            //判断是否是关键边
            Union uf(n);
            int v = 0;
            for (int j = 0; j < m; j++) {
                if (i != j && uf.join(edges[j][0], edges[j][1])) v += edges[j][2];
            }

            if (uf.setCount != 1 || (uf.setCount == 1 && v > value)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }


            //判断是否是伪关键边
            uf = Union(n);
            uf.join(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.join(edges[j][0], edges[j][1])) v += edges[j][2];
            }
            if (v == value) {
                ans[1].push_back(edges[i][3]);
            }
        }

        return ans;

    }

};