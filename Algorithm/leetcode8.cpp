#include <iostream>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (!n) return 0;
        int sign = 1;
        long num = 0;
        int i = 0;
        while (s[i] == ' ') i++;
        if (!isdigit(s[i]) && s[i] != '+' && s[i] != '-') return 0;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (isdigit(s[i]) && i < n) {
            num = num*10 + (s[i] - '0');
            if (num > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            i++;
        }

        return sign * num;
    }
};