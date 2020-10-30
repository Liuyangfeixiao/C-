#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    int rsp = 0;
    for (int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == 1) {
                rsp += 4;
                if (i != 0 && grid[i-1][j] == 1)
                    rsp -= 2;
                if (j != 0 && grid[i][j-1] == 1)
                    rsp -= 2;
            }

        }
    }

    return rsp;
}