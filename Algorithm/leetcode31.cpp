#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    /*从后往前遍历，找到不是递降的第一个元素*/
    while (i >= 0 && nums[i] >= nums[i+1])
    {
        i--;
    }
    if (i >= 0) { // i+1 到 n-1 区间中第一个大于 nums[i] 的元素，交换
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j])
        {
            /* code */
            j--;
        }
        swap(nums[i], nums[j]);
    }
    //交换过后的 nums[i+1] 到 nums[n-1] 肯定为降序，所以将其逆转
    reverse(nums.begin() + i + 1, nums.end());
    
}
