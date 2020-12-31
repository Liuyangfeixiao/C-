#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
    });

    int n = intervals.size();
    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] >= right)
        {
            ans++;
            right = intervals[i][1];
        }
    }

    return n-ans;
    
}