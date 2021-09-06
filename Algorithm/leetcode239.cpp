#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 滑动窗口 + 单调栈，解决下一个更大的数
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);

            while (i - q.front() >= k) 
                q.pop_front();
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};