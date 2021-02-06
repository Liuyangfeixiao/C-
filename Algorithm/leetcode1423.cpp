#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> preSum(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!i) {
                preSum[i] = cardPoints[i];
                continue;
            }
            preSum[i] = preSum[i-1] + cardPoints[i];
        }
        int  l = 0, r = n - k - 1;
        if (r < 0) return preSum[n-1];
        int res = 0;
        while (r < n) {
            res = max(res, preSum[n-1] - preSum[r] + preSum[l] - cardPoints[l]);
            r++;
            l++;
        }

        return res;
    }
};