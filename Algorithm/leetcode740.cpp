#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int cmax = 0;
        for (int i = 0; i < n; ++i) {
            cmax = max(cmax, nums[i]);
        }
        vector<int> sum(cmax+1, 0);
        for (int i = 0; i < n; ++i) {
            sum[nums[i]] += nums[i];
        }
        if (cmax == 1) return sum[cmax];
        vector<int> dp(cmax+1);
        dp[1] = sum[1];
        dp[2] = max(sum[1], sum[2]);
        for (int i = 3; i <= cmax; ++i) {
            dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
        }

        return dp[cmax];
        
    }
};