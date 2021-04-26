#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool judge(vector<int>& nums, int m, int k) {
        int ans = 1;
        int sum = 0;
        for (auto x : nums) {
            sum += x;
            if (sum > k) {
                sum = x;
                ans++;
            }
        }
        return ans <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (!n) return 0;
        int sum = 0, cmax = 0;
        for (auto x : nums) {
            sum += x;
            cmax = max(cmax, x);
        }
        int l = cmax, r = sum;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (judge(nums, m, mid)) {
                r = mid;
            }
            else l = mid + 1;
        }
        return l;
    }
};