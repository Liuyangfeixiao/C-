#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numWays(int steps, int arrLen) {
        const int M = 1e9 + 7;
        int cmax = min(arrLen-1, steps);
        vector<int> dp(cmax+1);
        dp[0] = 1;
        for (int i = 1; i <= steps; ++i) {
            vector<int> dpNext(cmax+1);
            for (int j = 0; j <= cmax; ++j) {
                dpNext[j] = dp[j];
                if (j - 1 >= 0) {
                    dpNext[j] = (dpNext[j] + dp[j-1]) % M;
                }
                if (j + 1 <= cmax) {
                    dpNext[j] = (dpNext[j] + dp[j+1]) % M;
                }
            }
            dp = dpNext;
        }

        return dp[0];
    }
};