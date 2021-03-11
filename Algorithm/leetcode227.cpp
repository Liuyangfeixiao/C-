#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    int calculate(string s) {
        int n = s.size();
        char presign = '+';
        int num = 0;
        vector<int> stk;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            
            if (!isdigit(s[i]) && s[i] != ' ' || i == n-1) {
                switch(presign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                presign = s[i];
                num = 0;
            }

        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};