#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;      // j 为输出位置
        int cnt = 1;    // 重复数字数量
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i-1]) cnt = 1;
            else cnt++;
            if (cnt <= 2) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};