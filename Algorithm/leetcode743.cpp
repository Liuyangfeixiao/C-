#include <iostream>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
// Dijkstral 优化算法求最短路
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INF);
        vector<bool> visited(n+1, false);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        // 源节点先入队
        dist[k] = 0;
        q.push({0, k});
        while (!q.empty()) {
            PII t = q.top();
            q.pop();
            if (visited[t.second]) continue;
            visited[t.second] = true;
            // 松弛操作, 松弛相邻的边
            for (auto &x : times) {     // y引用传递比值传递更节省时间
                if (x[0] == t.second) {
                    int v = x[1];
                    int w = t.first + x[2];
                    
                    if (w < dist[v]) {
                        dist[v] = w;
                        q.push({w, v});
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;

    }
};