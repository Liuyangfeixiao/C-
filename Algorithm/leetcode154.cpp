#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
                l++;
                r--;
            }
            else if (nums[mid] <= nums[r]) {
                r = mid;
            }
            else 
                l = mid + 1;
        }

        return nums[l];
    }
};