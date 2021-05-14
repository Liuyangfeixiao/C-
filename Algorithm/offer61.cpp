#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (nums[i] == 0) {
            i++;
        }
        int cnt = i;
        while (i + 1 < nums.size()) {
            if (nums[i] + 1 == nums[i+1])
                i++;
            else {
                if (cnt) {
                    cnt--;
                    nums[i] = nums[i] + 1;
                }
                else return false;
            }
        }
        return true;
    }
};