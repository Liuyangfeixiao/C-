#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return 0;
        // dp[i][j] 代表 s[i:] 中 t[j:] 的数量
        vector<vector<long>> dp(n+1, vector<long>(m+1));
        for (int i = n; i >= 0; --i) dp[i][m] = 1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (s[i] == t[j]) dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                else dp[i][j] = dp[i+1][j];
            }
        }

        return dp[0][0];
    }
};