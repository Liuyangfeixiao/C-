#include <iostream>
#include <vector>
using namespace std;

int findRotateSteps(string ring, string key) {

    int m = ring.size();
    int n = key.size();
    /*位置数组*/
    vector<vector<int>> pos(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (key[i] == ring[j]) {
                pos[i].push_back(j);
            }
        }
    }

    /**
     * 遍历到dp[i][pos] 代表 key 中的第 i 个且位置在 ring 中 pos 的字符
     * 所需要的步数
     */
    vector<vector<int>> dp(n, vector<int>(m, INT32_MAX/2));
    /*base condition*/
    for (int x : pos[0]) {
        dp[0][x] = min(dp[0][x], min(x, m-x));
    }

    /*动态规划方程实现*/
    for (int i = 1; i < n; i++) {
        for (int cur_pos : pos[i]) {
            for (int pre_pos: pos[i-1]) {
                int dist = abs(cur_pos-pre_pos);
                dp[i][cur_pos] = min(dp[i][cur_pos], dp[i-1][pre_pos] + min(dist, m-dist));
            }
        }
    }

    int res = INT32_MAX;
    for (int x : dp[n-1])
        res = min(res, x);
    return res + n;
}