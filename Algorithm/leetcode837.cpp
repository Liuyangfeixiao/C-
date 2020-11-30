#include <iostream>
#include <vector>
using namespace std;


/*未考虑到每种情况出现的概率不同*/
double new21Game(int N, int K, int W) {
    vector<int> dp(W+1, 0);
    int sum = 0, count = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= W; j++) {
            dp[j] = i + j;
            if (dp[j] >= K) {
                sum++;
                if (dp[j] <= N)
                    count++;
            }
        }
    }

    return count/sum;
}

/*leetcode solution*/

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1.0;
        }
        vector<double> dp(K + W);
        for (int i = K; i <= N && i < K + W; i++) {
            dp[i] = 1.0;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }
};
