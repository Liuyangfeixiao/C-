#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange (vector<int>& nums, int target) {
    if (nums.size() == 0) return {-1, -1};
    int l = 0, r = nums.size() - 1;
    
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] < target){
            l = mid + 1;
        } else r = mid;
    }
    if (nums[l] != target) return {-1, -1};
    int end = l;

    l = 0;
    r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    int begin = l;

    return {begin, end};
}