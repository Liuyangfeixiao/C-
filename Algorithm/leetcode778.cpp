#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int nmax = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nmax = max(nmax, grid[i][j]);
            }
        }

        int l = 0, r = nmax;
        vector<vector<int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> visited(n * n, 0);
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // 保证首结点可以到达其他节点
            if (grid[0][0] > mid) {
                l = mid + 1;
                continue;
            }
            queue<int> q;
            q.push(0);
            visited[0] = 1;
            vector<int> visited(n * n, 0);
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                int x = t / n;
                int y = t % n;
                for (auto d : dx) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx * n + ny] && grid[nx][ny] <= mid) 
                    {
                        q.push(nx * n + ny);
                        visited[nx * n + ny] = 1;
                    }
                }
            }

            if (visited[n * n - 1]) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;

        }
        return ans;

    }
};
