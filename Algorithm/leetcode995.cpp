#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int revCnt = 0; // 记录之前的翻转的次数
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i-K] > 1) {
                revCnt--;
                A[i-K] -= 2;
            }
            if (revCnt % 2 == A[i]) {
                if (i + K > n) return -1;
                A[i] += 2;
                revCnt++;
                ans++;
            }
        }
        return ans;
    }
};