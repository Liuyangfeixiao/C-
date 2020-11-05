#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 动态规划，dp[i] = max(dp[i], dp[j]+1) j < i
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        /* code */
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            /* code */
            if (nums[j] < nums[i])
            {
                /* code */
                dp[i] = max(dp[i], dp[j]+1);
            }
            
        }
        
    }

    return *max_element(dp.begin(), dp.end());
    

}

//贪心与二分
int lengthOf(vector<int>& nums) {
    int len = 1;
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    
    vector<int> d(n+1, 0);
    d[len] = nums[0];
    /*贪心算法*/
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (nums[i] > d[len]) {
            d[++len] = nums[i];
        }
        else
        {
            int l = 1, r = len, pos = 0; // 如果没找到，则要更新 d[1], 所以 pos 要置0
            /*二分找到第一个小于 nums[i] 的值*/
            while(l <= r) {
                int mid = (l+r) >> 1;
                if (d[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
                
            }
            d[pos+1] = nums[i];
        }
        
    }

    return len;
    

}