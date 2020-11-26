#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumGap(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = nums[1] - nums[0];
    for (int i = 2; i < n; i++) {
        ans = max(ans, nums[i] - nums[i-1]);
    }
    return ans;
}

