#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT32_MIN);
    dp[0] = nums[0];
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
    }

    int res = dp[0];
    for (int i = 1; i < n; i++) {
        res = max(res, dp[i]);
    }
    return res;
}