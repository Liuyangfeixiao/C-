#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n);   // 记录以 i 结尾的最大整除子集
        vector<int> g(n);   // 记录状态转移
        
        for (int i = 0; i < n; ++i) {
            int len = 1, prev = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && f[j] + 1 > len) {
                    len = f[j] + 1;
                    prev = j;
                }
            }
            f[i] = len;
            g[i] = prev;
        }

        int idx = max_element(f.begin(), f.end()) - f.begin();
        int val = f[idx];
        vector<int> ans;
        while (val--) {
            ans.push_back(nums[idx]);
            idx = g[idx];
        }

        return ans;
    }
};