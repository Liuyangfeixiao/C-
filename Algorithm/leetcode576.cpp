#include <vector>
using namespace std;

class Solution {
public:
    static constexpr int Mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int sum = 0;
        dp[startRow][startColumn] = 1;
        for (int k = 0; k < maxMove; ++k) {
            vector<vector<int>> dpNew(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int count = dp[i][j];
                    if (count > 0) {
                        for (auto& direction : dir) {
                            int x = i + direction[0], y = j + direction[1];
                            if (x >= 0 && x < m && y >= 0 && y < n)
                                dpNew[x][y] = (dpNew[x][y] + count) % Mod;
                            else
                                sum = (sum + count) % Mod;
                        }
                    }
                }
            }
            dp = dpNew;
        }

        return sum;
    }
};