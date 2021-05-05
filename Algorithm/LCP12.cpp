#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& time, int k, int m) {
        int n = time.size();
        int cmax = 0;
        int ans = 1;
        int sum = 0;
        bool helped = false;
        for (int i = 0; i < n; ++i) {
            if (sum + min(cmax, time[i]) <= k) {
                sum += min(time[i], cmax);
                cmax = max(cmax, time[i]);
            }
            else {
                ans++;
                sum = 0;
                cmax = time[i];
            }
        }
        return ans <= m;
    }
    int minTime(vector<int>& time, int m) {
        int cmax = 0;
        int sum = 0;
        for (auto x : time) {
            cmax = max(cmax, x);
            sum += x;
        }

        int l = 0, r = sum;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(time, mid, m)) {
                r = mid;
            }
            else l = mid + 1;
        }

        return l;
    }
};