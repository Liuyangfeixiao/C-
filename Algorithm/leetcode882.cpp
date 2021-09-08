#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<PII>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1] ,edge[2] + 1});
            graph[edge[1]].push_back({edge[0] ,edge[2] + 1});
        }
        vector<bool> visited(n, false);
        vector<int> dist(n, INF);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.emplace(0, 0);
        dist[0] = 0;

        while (!q.empty()) {
            PII p = q.top();
            q.pop();
            int node = p.second, dis = p.first;

            if (visited[node]) continue;
            visited[node] = true;

            for (auto& g : graph[node]) {
                int v = g.first, w = g.second;
                if (!visited[v] && dist[v] > dis + w) {
                    dist[v] = dis + w;
                    q.emplace(dist[v], v);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= maxMoves) {
                res++;
            }
        }

        for (auto& edge : edges) {
            int tmp = 0;
            int x = edge[0], y = edge[1], cnt = edge[2];

            if (dist[x] <= maxMoves) tmp += maxMoves - dist[x];

            if (dist[y] <= maxMoves) tmp += maxMoves - dist[y];

            res += min(cnt, tmp);
        }

        return res;
    }
};