#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i-1]) {
                nums[++j] = nums[i];
            }
        }

        return j+1;
    }
};
