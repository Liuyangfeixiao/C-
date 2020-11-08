#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 俄罗斯信封套娃问题
int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty())
        return 0;
    sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    vector<int> height;
    for (auto i : envelopes) {
        height.push_back(i[1]);
    }

    int res = lengthOfLIS(height);
    return res;

}

/*转化为*/
int lengthOfLIS(vector<int>& nums) {
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