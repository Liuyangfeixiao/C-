#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long base = 1, digitCnt = 1;
        while (n > 9 * base * digitCnt) {
            n -= 9 * base * digitCnt;
            base = 10 * base;
            digitCnt++;
        }

        n--;
        int tmp = base + n / digitCnt;
        int k = n % digitCnt;
        string s = to_string(tmp);

        return s[k] - '0';
    }
};