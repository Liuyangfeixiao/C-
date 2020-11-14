#include<iostream>
#include <vector>
using namespace std;

int maxTurbulenceSize(vector<int>& A) {
    /**
     * dp[i][0] 代表包括 A[i] 在内的以 A[i] 结尾的最长升序子湍流数组
     * dp[i][1] 代表降序
     */
    int ans = 1;
    vector<vector<int>> dp(A.size(), vector<int>(2,1));
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i-1])
            dp[i][0] = dp[i-1][1] + 1;
        else if (A[i] < A[i-1])
            dp[i][1] = dp[i-1][0] + 1;
        else
            continue;
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    return ans;

}