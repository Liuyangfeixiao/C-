#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Unite{
public:
    Unite(int n) : father(n), count(n){};
    void init() {
        for (int i = 1; i <= count; ++i) {
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

    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return true;
        return false;
    }

    bool connected() {
        int p = find(1);
        for (int i = 1; i <= count; i++) {
            if (p != find(i)) return false;
        }

        return true;
    }



private:
    vector<int> father;
    int count;
};


int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int m = edges.size();
    Unite Alice(n);
    Unite Bob(n);
    Alice.init();
    Bob.init();
    int ans = 0;
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] > b[0];});
    for (int i = 0; i < m; ++i) {
        if (edges[i][0] == 3) {
            if (Alice.same(edges[i][1], edges[i][2]) && Bob.same(edges[i][1], edges[i][2])) {
                ans++;
            }
            else {
                Alice.join(edges[i][1], edges[i][2]);
                Bob.join(edges[i][1], edges[i][2]);
            }
        }
        else {
            if (edges[i][0] == 1) {
                if (Alice.same(edges[i][1], edges[i][2]))
                    ans++;
                else {
                    Alice.join(edges[i][1], edges[i][2]);
                }
            }
            else {
                if (Bob.same(edges[i][1], edges[i][2]))
                    ans++;
                else {
                    Bob.join(edges[i][1], edges[i][2]);
                }
            }
        }
    }
    if (!Alice.connected() || !Bob.connected()) return -1;
    return ans;
}