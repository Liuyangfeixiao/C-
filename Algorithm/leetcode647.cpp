#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划算法
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<vector<bool>> dp(n, vector<bool>(n ,true));
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if (dp[i][j]) ans++;
            }
        }
        
        return ans;
    }
    // 中心扩展法
    int count_substring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        int ans = 0;
        for (int i = 0; i < 2*n - 1; ++i ){
            int l = i / 2;
            int r = l + i%2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--, r++;
                ans++;
            }
        }
        return ans;
    }
};