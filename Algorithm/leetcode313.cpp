#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1);
        long answer = 1;
        while (n--) {
            answer = q.top();
            q.pop();
            for (int x : primes) {
                q.push(answer * x);
            }
            while (!q.empty() && answer == q.top())
                q.pop();
            
        }
        return answer;
    }
    // DP + n pointer
    int nthSuperUglyNum(int n, vector<int>& primes) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int m = primes.size();
        vector<int> pointer(m, 1);
        for (int i = 2; i <= n; ++i) {
            vector<int> nums(m);
            int minNum = INT_MAX;
            for (int j = 0; j < m; ++j) {
                nums[j] = dp[pointer[j]] * primes[j];
                minNum = min(minNum, nums[j]);
            }
            dp[i] = minNum;
            for (int j = 0; j < m; ++j) {
                if (minNum == nums[j])
                    pointer[j]++;
            }
        }

        return dp[n];
    }
};