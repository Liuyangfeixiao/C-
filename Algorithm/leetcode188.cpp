#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n / 2) k = n / 2;
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n, vector<int>(2)));
        // 这里将 buy 当作一次交易，如果把 sell 当作一次交易，需要修改初值，但我也不知道改成啥
        for (int i = 0; i < n; ++i) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[i];
        }
        
        for (int kk = 1; kk <= k; ++kk) {
            for (int i = 0; i < n; ++i) {
                if (i == 0) {
                    dp[kk][i][0] = 0;
                    dp[kk][i][1] = -prices[i];
                    continue;
                }
                dp[kk][i][0] = max(dp[kk][i-1][0], dp[kk][i-1][1] + prices[i]);
                dp[kk][i][1] = max(dp[kk][i-1][1], dp[kk-1][i][0] - prices[i]);
            }
        }

        return dp[k][n-1][0];
    }
};