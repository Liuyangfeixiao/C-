#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMax(int begin, int end, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[begin] = nums[begin];
        dp[begin+1] = max(nums[begin], nums[begin+1]);
        for (int i = begin+2; i <= end; ++i) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int ret1 = getMax(0, n-2, nums);
        int ret2 = getMax(1, n-1, nums);
        return max(ret1, ret2);
    }
};