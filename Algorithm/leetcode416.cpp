#include<iostream>
#include<vector>

using namespace std;

bool canPartition(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (int e : nums){
            sum += e;
        }
        if (sum & 1)
            return false;
        int target = sum/2;
        vector<vector<bool>> dp(len, vector<bool>(target + 1, false));
        if (nums[0] < target)
            dp[0][nums[0]] = true;
        for (int i = 1; i < len; i++){
            for (int j = 0; j < target+1; j++){
                dp[i][j] = dp[i-1][j];
                if (nums[i] == j){
                    dp[i][j] = true;
                }
                if (nums[i] < j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
                }
            }
        }

        return dp[len-1][target];

    }

bool canpartition(vector<int>& nums){
    int sum = 0;;
    int len = nums.size();
    for (int e : nums){
        sum += e;
    }
    if (sum & 1){
        return false;
    }
    int target = sum / 2;
    vector<bool> dp(target+1, false);
    for (int i = 0; i < len; i++){
        for (int s = target; s >= nums[i]; s--){
            if(!i){
                dp[s] = (nums[i] == s);
            }
            else
            {
                dp[s] = dp[s] || dp[s-nums[i]];
            }
            
        }
    }
    return dp[target];


}