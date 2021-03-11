#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int ans;
public:
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                tmp[k++] = nums[j++];
                ans += mid - i + 1;
            }
            else tmp[k++] = nums[i++];
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) tmp[k++] = nums[j++];

        for (int i = l, k = 0; i <= r; i++, k++) {
            nums[i] = tmp[k];
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge_sort(nums, 0, n-1);
        return ans;
    }
};