#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // 如果一方为0，返回另一方的长度
        if (m * n == 0) return m + n;
        // dp[i][j] 代表 word1 前 i 个字符 转化成 word2 前 j 个字符的操作数
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int x = dp[i-1][j]+1;
                int y = dp[i][j-1]+1;
                int xy = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1])
                    xy += 1;
                dp[i][j] = min(x, min(y, xy));
            }
        }
        return dp[m][n];
    }
}