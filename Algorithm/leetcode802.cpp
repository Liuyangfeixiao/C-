#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> degree(n);
        vector<vector<int>> reGraph(n);
        // 逆转图
        for (int i = 0; i < n; ++i) {
            for (auto& x : graph[i]) {
                reGraph[x].push_back(i);
            }
            degree[i] = graph[i].size();
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto& x : reGraph[t]) {
                degree[x]--;
                if (degree[x] == 0) q.push(x);
            }
        }

        for (int i = 0; i < n; ++i) {
            if(degree[i] == 0) 
                res.push_back(i);
        }
        return res;
    }
};