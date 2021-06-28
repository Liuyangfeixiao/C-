#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> table;
        
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            int temp = routes[i].size();
            for (int j = 0; j < temp; ++j) {
                table[routes[i][j]].push_back(i);
            }
        }
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(source);
        int step = 0;
        while (!q.empty()) {
            step++;
            int tmp = q.size();
            for (int i = 0; i < tmp; i++) {
                int now = q.front();
                q.pop();
                for (int i : table[now]) {
                    if (!visited[i]) {
                        for (int j = 0; j < routes[i].size(); ++j) {
                            if (routes[i][j] == target) return step;
                            q.push(routes[i][j]);
                        }
                        visited[i] = true;
                    }
                }
                
            }
            
        }
        return -1;

    }
};