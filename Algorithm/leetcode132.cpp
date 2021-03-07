#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 1));

        for (int i = n-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }

        vector<int> cnt(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (dp[0][i]) cnt[i] = 0;
            else {
                for (int j = 0; j < i; ++j) {
                    if (dp[j+1][i]) {
                        cnt[i] = min(cnt[i], cnt[j] + 1);
                    }
                }
            }
        }

        return cnt[n-1];
    }
};