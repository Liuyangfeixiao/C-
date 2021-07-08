#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> preSum(nums.size() + 1);
        preSum[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        unordered_map<int, int> table;
        int ans = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            ans += table.count(preSum[i] - goal) ? table[preSum[i] - goal] : 0;
            table[preSum[i]]++;
        }
        return ans;
    }
};