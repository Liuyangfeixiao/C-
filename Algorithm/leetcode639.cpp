#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        auto check1 = [](char c) {
            if (c == '*') return 9;
            else if (c >= '1' && c <= '9') return 1;
            else return 0;
        };
        auto check2 = [](char c1, char c2) {
            if (c1 == '*' && c2 == '*')
                return 15;
            if (c2 == '*') {
                if (c1 == '1')
                    return 9;
                else if (c1 == '2')
                    return 6;
                else return 0;
            }

            if (c1 == '*') {
                return c2 <= '6' ? 2 : 1;
            }

            return (c1 != '0') && (c1 - '0') * 10 + (c2 - '0') <= 26 ? 1 : 0;
        };
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; ++i) {
            c = (long long) b * check1(s[i-1]) % mod;

            if (i > 1) {
                c = (c + (long long)a * check2(s[i-2], s[i-1])) % mod;
            }

            a = b;
            b = c;
        }
        return c;
    }
};