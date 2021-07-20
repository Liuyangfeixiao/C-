#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        int sum = 0;
        while (l < r) {
            sum = max(sum, nums[l]+nums[r]);
            l++;
            r--;
        }
        return sum;
    }
};