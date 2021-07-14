#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mod = 1e9 + 7;
        vector<int> res(nums1);
        sort(res.begin(), res.end());
        int sum = 0, maxn = 0;
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int j = lower_bound(res.begin(), res.end(), nums2[i]) - res.begin();
            if (j < n) {
                maxn = max(maxn, diff - (res[j] - nums2[i]));
            }
            if (j > 0) {
                maxn = max(maxn, diff - (nums2[i] - res[j-1]));
            }
        }

        return (sum - maxn + mod) % mod;
    }
};