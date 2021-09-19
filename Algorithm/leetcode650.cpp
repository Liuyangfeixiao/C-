#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMax(int n) {
        for (int i = n / 2; i > 1; i--) {
            if (n % i == 0) return i;
        }

        return 1;
    }
    int minSteps(int n) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for (int i = 2; i < n; ++i){
            if (i % 2 == 0) dp[i] = dp[i/2] + 2;
            else {
                int cmax = getMax(i);
                dp[i] = dp[cmax] + 2 + (i / cmax - 2);
            }
        }
        return dp[n];
    }
};