#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);
        int n = nums.size();
        int len = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        len = max(len, dp[i]);
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == len)
                res += cnt[i];
        }
        return res;
    }
};