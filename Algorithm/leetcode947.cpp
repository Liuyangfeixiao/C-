#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
int father[N] = {-1};

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}

int find(int x) {
    return father[x] == -1 ? x : father[x] = find(father[x]);
}


int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                join(i, j);
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (father[i] == -1) res++;
    }

    return n - res;
    
}
