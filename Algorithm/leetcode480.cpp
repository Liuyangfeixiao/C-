#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<double> st; // 滑动窗口
        vector<double> res;
        for (int i = 0; i < n; ++i) {
            if (st.size() >= k) {
                st.erase(st.find(nums[i - k])); // 删除左边界的数据
            }
            st.insert(nums[i]); 
            if (i >= k - 1) {
                auto mid = st.begin();
                advance(mid, k/2);
                res.push_back((*mid + *prev(mid, (1 - k % 2))) / 2);
            }
        }
        return res;
    }
};