#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int limit) {
        int n = bloomDay.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= limit) count++;
            else {
                count = 0;
            }
            if (count == k) {
                ans++;
                count = 0;
            }
        }
        return ans >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m*k > n) return -1;
        int cmax = 0;
        for (int i = 0; i < n; ++i) {
            cmax = max(cmax, bloomDay[i]);
        }
        int l = 0, r = cmax;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(bloomDay, m, k, mid)) {
                r = mid;
            }
            else l = mid + 1;
        }

        return l;
    }
};
