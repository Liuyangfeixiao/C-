#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string>> ret;
    vector<string> ans;
public:
    void dfs(int i, string &s, vector<vector<bool>> &dp) {
        if (i == s.size()) {
            ret.push_back(ans);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (dp[i][j]) {
                ans.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, dp);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));  // 初始化为true
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }

        dfs(0, s, dp);
        return ret;

    }
};