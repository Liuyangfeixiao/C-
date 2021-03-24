#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*维护递减单调栈，从后往前遍历*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, INT_MAX);
        for (int i = 1; i < n; ++i) {
            left[i] = min(nums[i-1], left[i-1]);
        }
        stack<int> st;
        for (int j = n-1; j >= 0; --j) {
            int tmp = INT_MIN;
            while (!st.empty() && st.top() < nums[j]) {
                tmp = st.top();
                st.pop();
            }
            if (left[j] < nums[j] && tmp > left[j])
                return true;
            st.push(nums[j]);
        }

        return false;
    }
};