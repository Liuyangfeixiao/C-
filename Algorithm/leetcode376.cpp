#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return n;
    /*动规*/
    // vector<vector<int>> dp(n, vector<int>(2, 1));
    // for (int i = 1; i < n; i++) {
    //     if (nums[i] > nums[i-1]) {
    //         dp[i][0] = dp[i-1][1] + 1;
    //         dp[i][1] = dp[i-1][1];
    //     }
    //     if (nums[i] < nums[i-1]) {
    //         dp[i][1] = dp[i-1][0] + 1;
    //         dp[i][0] = dp[i-1][0];
    //     }
    //     if (nums[i] = nums[i-1]) {
    //         dp[i][0] = dp[i-1][0];
    //         dp[i][1] = dp[i-1][1];
    //     }
    // }

    // return max(dp[n-1][0], dp[n-1][1]);

    /*简化*/
    int up = 1, down = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) up = down + 1;
        if (nums[i] < nums[i-1]) down = up + 1;
    }
    return max(up, down);
}


