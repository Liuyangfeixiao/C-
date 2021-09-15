#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int n = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid+1] > nums[mid]) l = mid + 1;
            else r = mid;
        }

        return l;
    }
};