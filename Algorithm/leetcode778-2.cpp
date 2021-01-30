#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int find(vector<int>& f, int x) {
        return x == f[x] ? x : find(f, f[x]);
    }
    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x);
        int fy = find(f, y);
        f[fx] = fy;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n * n);
        
        for (int i = 0; i < n * n; ++i) {
            f[i] = i;
        }

        vector<pair<int, int>> idx(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                idx[grid[i][j]] = make_pair(i, j);
            }
        }
        vector<pair<int, int>> dx = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int thredhold = 0; thredhold < n * n; thredhold++) {
            auto [x, y] = idx[thredhold];
            for (const auto [di, dj] : dx) {
                int nx = x + di, ny = y + dj;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] <= thredhold)
                    merge(f, x * n + y, nx * n + ny);
            }

            if (find(f, 0) == find(f, n * n - 1)) {
                return thredhold;
            }
        }
        return -1;
    }
};