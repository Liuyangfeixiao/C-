#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n-2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] <= nums[i])
                    r--;
                else {
                    ans += (r - l);
                    l++;
                }
            }
        }

        return ans;
    }
};