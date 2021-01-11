#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    int k = k % n;
    vector<int> tmp;

    for (int i = 0; i < n - k - 1; ++i) {
        tmp.push_back(nums[i]);
    }
    for (int i = n-1; i >= n-k; --i) {
        tmp.insert(tmp.begin(), nums[i]);
    }

    nums = tmp;

}