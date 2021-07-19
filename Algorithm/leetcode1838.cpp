#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, ans = 1;
        ll sum = 0;
        for (int r = 1; r < n; r++) {
            sum += (ll)(nums[r] - nums[r-1]) * (r - l);
            while (sum > k) sum -= nums[r] - nums[l++];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};