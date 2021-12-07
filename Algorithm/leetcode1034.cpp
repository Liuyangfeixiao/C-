#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();

        vector<bool> visited(m*n-1);
        queue<int> q;
        int val = grid[row][col];
        q.push(row * n + col);
        visited[row * n + col] = true;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int x = t / n, y = t % n;
            if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                grid[x][y] = color;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < m && nx >= 0 && ny < n && ny >= 0 && !visited[nx * n + ny]) {
                    if (grid[nx][ny] != val) grid[x][y] = color;
                    else {
                            q.push(nx * n + ny);
                            visited[nx * n + ny] = true;
                    }
                    
                }
                
            }
        }

        return grid;

    }
};