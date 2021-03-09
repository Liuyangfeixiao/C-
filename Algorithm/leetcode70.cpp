#include <iostream>
#include <vector>
using namespace std;

// 爬楼梯，dp[i] 等于从 0 到 i 共有多少条路径
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};