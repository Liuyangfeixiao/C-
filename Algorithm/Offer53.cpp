#include <iostream>
#include <vector>
using namespace std;

// 排序数组中的搜索问题，首先想到 二分法 解决
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == nums[mid]) {
                l = mid + 1;
            }
            else r = mid-1;
        }

        return l;
    }
};