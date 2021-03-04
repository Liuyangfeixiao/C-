#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 比特位计数
class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp(num);
        dp[0] = 0;
        int bit = 0;
        // 位运算
        for (int i = 1; i <= num; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};