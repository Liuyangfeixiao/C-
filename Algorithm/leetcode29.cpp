#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;

        bool sign = (dividend ^ divisor) < 0 ;
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        vector<int> candid = {divisor};
        while (candid.back() >= dividend - candid.back())
            candid.push_back(candid.back() + candid.back());
        int ans = 0;
        for (int i = candid.size()-1; i >= 0; i--) {
            if (candid[i] >= dividend) {
                ans += 1 << i;
                dividend -= candid[i];
            }
        }
        return sign ? -ans : ans;
    }
};