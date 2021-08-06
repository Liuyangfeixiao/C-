#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> d(n, vector<int>(n, n+1));
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                d[i][j] = 1;
            }
        }
        // floyd 算法点对点之间的最短路
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
        for (int mask = 1; mask < (1 << n); ++mask) {
            if ((mask & (mask - 1)) == 0) {
                int u = __builtin_ctz(mask);
                f[u][mask] = 0;
            }
            else {
                for (int u = 0; u < n; ++u) {
                    if (mask & (1 << u)) {
                        for (int v = 0; v < n; ++v) {
                            if ((mask & (1 << v)) && u != v) {
                                f[u][mask] = min(f[u][mask], f[v][mask ^ (1 << u)] + d[v][u]);
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int u = 0; u < n; ++u) {
            ans = min(ans, f[u][(1 << n) - 1]);
        }
        return ans;
    }
    // 广度优先搜索以及状态压缩
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<tuple<int, int, int> > q; // idx, mask, dist
        vector<vector<bool>> visited(n, vector<bool>(1 << n)); // 节点编号以及当前状态
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);    //存入起点，起始距离，标记
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [cur, mask, dist] = q.front();
            q.pop();

            if (mask == (1 << n) - 1) return dist;

            // 扩展
            for (int x : graph[cur]) {
                int nextmask = mask | (1 << x);
                if (!visited[x][nextmask]) {
                    q.emplace(x, nextmask, dist+1);
                    visited[x][nextmask] = true;
                }
            }
        }
        return 0;
    }
};