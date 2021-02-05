#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0, ans = INT32_MAX;
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        vector<int> presum;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            presum.push_back(sum);
            hash[sum] = i;
        }

        if (sum < x) return -1;
        for (int r = 0; r < n; ++r) {
            int target = x - sum + presum[r];
            if (hash.count(target)) ans = min(ans, n - r + hash[target]); 
        }

        if (ans = INT32_MAX) return -1;
        return ans;

    }
};