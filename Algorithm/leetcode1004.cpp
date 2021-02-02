#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int l = 0, r = 0;
        int maxCnt = 0; // 窗口中 1 的个数
        while (r < n) {
            if (A[r] == 1) maxCnt++;
            if (r - l + 1 - maxCnt > K) {
                if (A[l] == 1) maxCnt--;
                l++;
            }
            r++;
        }

        return r - l;
    }
};