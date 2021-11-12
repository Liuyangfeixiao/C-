/**
 * @file leetcode375.cpp
 * @author Liu Yangfeixiao (2391461132@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @brief Get the Money Amount object
     * @param n 
     * @return int 
     */
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                int mincost = INT_MAX;
                for (int k = i; k < j; ++k) {
                    mincost = min(mincost, k + max(dp[i][k-1], dp[k+1][j]));
                }
                dp[i][j] = mincost;
            }
        }

        return dp[1][n];

    }
};

