#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> cmax, cmin;
        int l = 0, r = 0;
        cmax.push_back(0);
        cmin.push_back(0);
        int ans = 0;
        while (r < n) {
            if (nums[cmax.front()] - nums[cmin.front()] <= limit) {
                r++;
                if (r < n) {
                    while (!cmax.empty() && nums[r] >= nums[cmax.back()])
                        cmax.pop_back();
                    cmax.push_back(r);

                    while (!cmin.empty() && nums[r] <= nums[cmin.back()])
                        cmin.pop_back();
                    cmin.push_back(r);
                }
                
            }
            else {
                l++;
                if (l > cmax.front()) cmax.pop_front();
                if (l > cmin.front()) cmin.pop_front();
            }
            ans = max(ans, r - l);
        }

        return ans;
    }
};