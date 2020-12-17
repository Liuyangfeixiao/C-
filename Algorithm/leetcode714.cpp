#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> dp(2);
    //dp[0] 代表第 i 天不持有股票所得收益
    dp[0] = 0;
    //dp[1] 代表
    dp[1] = -prices[0];

    for (int i = 1; i < n; i++) {
        int tmp = dp[0];
        dp[0] = max(dp[0], dp[1] + prices[i] - fee);
        dp[1] = max(tmp - prices[i], dp[1]);
    }

    return max(dp[0], dp[1]);
}
