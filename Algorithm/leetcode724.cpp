#include <iostream>
#include <vector>
using namespace std;


int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    if (!n) return -1;
    vector<int> presum(n);
    for (int i = 0; i < n; ++i) {
        if (!i) presum[i] = nums[i];
        else {
            presum[i] = presum[i-1] + nums[i];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int side = presum[i] - nums[i];
        int otherside = presum[n-1] - presum[i];
        if (side == otherside) return i;
    }

    return -1;
}