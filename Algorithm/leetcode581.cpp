#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, l = -1;
        int minn = INT_MAX, r = -1;

        for (int i = 0; i < n; ++i) {
            if (maxn > nums[i]) {
                r = i;
            }
            else maxn = nums[i];

            if (minn < nums[n - i - 1]) {
                l = n - i - 1;
            }
            else minn = nums[n-i-1];
        }

        return r == -1 ? 0 : r - l + 1;
    }
};