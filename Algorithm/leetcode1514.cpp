#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        typedef pair<double, int> PII;
        vector<double> dist(n, 0);
        vector<bool> visited(n, false);

        auto graph = vector<vector<pair<int, double>>>(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<PII> q;
        q.push({1, start});
        dist[start] = 1;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int node = p.second;
            double dis = p.first;

            if (visited[node]) continue;
            visited[node] = true;

            for (auto& e : graph[node]) {
                if (!visited[e.first] && dist[e.first] < dis * e.second) {
                    dist[e.first] = dis * e.second;
                    q.push({dist[e.first], e.first});
                }
            }

        }

        return dist[end];
    }
};