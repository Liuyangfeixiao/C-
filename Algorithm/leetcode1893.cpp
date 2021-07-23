#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        vector<vector<int>> newRange;
        int n = ranges.size();
        vector<int> tmp(2);
        tmp[0] = ranges[0][0];
        tmp[1] = ranges[0][1];
        // 区间合并
        for (auto &v : ranges) {
            if (v[0] <= tmp[1] + 1) {
                tmp[1] = max(tmp[1], v[1]);
            }
            else {
                newRange.push_back(tmp);
                tmp[0] = v[0];
                tmp[1] = v[1];
            }
        }
        newRange.push_back(tmp);

        for (auto& ra : newRange) {
            if (left < ra[0]) {
                continue;
            }
            else {
                if (right <= ra[1]) return true;
            }
        }
        return false;
    }

    // 差分数组解法
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for (auto&& range : ranges) {
            ++diff[range[0]];
            --diff[range[1] + 1];
        }

        int curr = 0;
        for (int i = 1; i <= right; ++i) {
            curr += diff[i];
            if (i >= left && curr <= 0) return false;
        }
        return true;
    }
};