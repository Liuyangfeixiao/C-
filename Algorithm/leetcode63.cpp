#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // dp[i][j] 代表到 point[i][j] 有多少条路径
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0 && !obstacleGrid[i][j]) dp[i][j] = 1;
                else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if (i != 0 && j == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};