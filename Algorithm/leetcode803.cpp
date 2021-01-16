#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;

int father[N];
int sz[N]; // 以此节点为根节点的节点数量
// 并查集基本操作
void init(int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    return x == father[x] ? x : father[x] = find(father[x]);
}


void join(int u, int v) {
    int u = find(u);
    int v = find(v);
    if (u == v) return;
    father[v] = u;
    sz[u] += sz[v];
}

int size(int x) {
    return sz[find(x)];
}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    int R = grid.size();
    int C = grid[0].size();
    // R * C 是记录以天花板节点为根节点的节点数量的节点
    init(R*C+1);
    vector<vector<int>> gst(grid);
    for (int i = 0; i < hits.size(); i++) {
        gst[hits[i][0]][hits[i][1]] = 0;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (gst[i][j] == 1) {
                if (i == 0) join(i * C + j, R*C);

                if (i > 0 && gst[i-1][j] == 1) join((i-1)*C + j, i * C + j);

                if (j > 0 && gst[i][j-1] == 1) join(i * C + j - 1, i * C + j);
            }
        }
    }

    // 逆序求出敲除砖块前后天花板联通节点的差值
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ret(hits.size(), 0);
    for (int i = hits.size() - 1; i >= 0; i--) {
        int r = hits[i][0], c = hits[i][1];

        if (grid[r][c] == 0) continue;

        int prev = size(R * C);

        if (r == 0) join(R * C, c);

        for (auto d : directions) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (gst[nr][nc] == 1) join(nr * C + nc, r * C + c);
            }
        }

        int count = size(R * C);
        ret[i] = max(0, count - prev - 1);
        gst[r][c] = 1;
    }

    return ret;
}