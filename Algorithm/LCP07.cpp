#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        unordered_map<int, vector<int>> table;
        for (auto& rel : relation) {
            table[rel[1]].push_back(rel[0]);
        }

        vector<vector<int>> dp(k+1, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 1; i <= k; ++i) {
            for (int src = 0; src < n; ++src) {
                for (auto x : table[src]) {
                    dp[i][src] += dp[i-1][x];
                }
            }
        }

        return dp[k][n-1];
    }
};