#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i-1]) {
            dp[i] = dp[i-1] + 1;
        }
    }
    for (int i = n-2; i >= 0; --i) {
        if (ratings[i] > ratings[i+1]) {
            if(dp[i] <= dp[i+1])
                dp[i] = dp[i+1] + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += dp[i];
    }
    return sum;
}
