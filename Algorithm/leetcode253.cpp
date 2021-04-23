#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> & a, vector<int>& b) {
            return a[0] < b[0];
        });     // 根据开始时间排序

        int n = intervals.size();
        vector<int> ans;    // 保留会议室的结束时间
        ans.push_back(intervals[0][1]);
        for (int i = 1; i < n; ++i) {
            bool flag = false;
            for (int j = 0; i < ans.size(); ++i) {
                if (intervals[i][0] >= ans[j]) {
                    ans[j] = intervals[i][1];
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans.push_back(intervals[i][1]);
            }
        }
        return ans.size();
    }
};
