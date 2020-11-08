#include <iostream>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (string str : strs) {
        vector<int> cnt = cntString(str);
        /*dp[i][j]数组代表 i 个 0 ，j 个 1 的最大字符串个数*/
        for (int i = m; i >= cnt[0]; i--){
            for (int j = n; j >= cnt[1]; j--){
                dp[i][j] = max(dp[i][j], dp[i-cnt[0]][j-cnt[1]] + 1);
            }
        }
    }

    return dp[m][n];
}

/*提取字符串中的 0 和 1 的个数*/
vector<int> cntString(string str) {
    vector<int> cnt(2, 0);
    for (char c : str) {
        if (c == '0')
            cnt[0]++;
        else
            cnt[1]++;
    }
    return cnt;
}