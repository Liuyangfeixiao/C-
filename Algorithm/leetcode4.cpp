#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m =  nums2.size();
        priority_queue<int> cmax;
        priority_queue<int, vector<int>, greater<int>> cmin;
        for (int i = 0; i < n; ++i) {
            cmax.push(nums1[i]);
            cmin.push(cmax.top()), cmax.pop();
            if (cmax.size() < cmin.size()) {
                cmax.push(cmin.top()), cmin.pop();
            }
        }

        for (int i = 0; i < m; ++i) {
            cmax.push(nums2[i]);
            cmin.push(cmax.top()), cmax.pop();
            if (cmax.size() < cmin.size()) {
                cmax.push(cmin.top()), cmin.pop();
            }
        }

        return cmax.size() == cmin.size() ? (cmax.top() + cmin.top()) * 0.5 : cmax.top();
    }
};