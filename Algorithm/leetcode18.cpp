#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n; ++first) {
            if (first != 0 && nums[first] == nums[first-1]) {
                continue;
            }
            for (int second = first + 1; second < n; ++second) {
                if (second != first + 1 && nums[second] == nums[second-1])
                    continue;
                int tar = target - nums[first] - nums[second];
                int th = second + 1, fou = n - 1;
                while (th < fou) {
                    if (nums[th] + nums[fou] < tar) 
                        th++;
                    else if (nums[th] + nums[fou] > tar)
                        fou--;
                    else {
                        ans.push_back({nums[first], nums[second], nums[th], nums[fou]});
                        while (th < fou && nums[th] == nums[th+1])
                            th++;
                        while (th < fou && nums[fou-1] == nums[fou])
                            fou--;
                        th++;
                        fou--;
                    }
                }
            }
        }

        return ans;
    }
};
