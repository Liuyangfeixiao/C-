#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        stack<int> stk;
        vector<int> ans(m, -1);
        unordered_map<int, int> cmap;
        // 单调栈
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                cmap[nums2[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }

        for (int i = 0; i < m; ++i) {
            if (cmap.count(nums1[i])) {
                ans[i] = cmap[nums1[i]];
            }
        }

        return ans;
    }
};