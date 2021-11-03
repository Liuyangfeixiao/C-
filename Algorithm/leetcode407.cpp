#include <vector>
#include <queue>
using namespace std;

// leetcode407.cpp
class Solution {
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    q.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
                
            }
        }
        vector<int> direc = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = p.second / n + direc[i];
                int ny = p.second % n + direc[i+1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < p.first) {
                        ans += p.first - heightMap[nx][ny];
                    }
                    q.push({max(heightMap[nx][ny], p.first), nx*n + ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return ans;
    }
};