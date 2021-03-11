#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void calc(vector<int>& cnt, vector<char>& ops) {
        if (cnt.size() < 2 || ops.empty()) return;
        char s = ops.back();
        ops.pop_back();
        int n2 = cnt.back();
        cnt.pop_back();
        int n1 = cnt.back();
        cnt.pop_back();
        int ans = 0;
        if (s == '+')
            ans = n1+n2;
        else if(s == '-')
            ans = n1-n2;
        else if (s == '*')
            ans = n1 * n2;
        else if (s == '/')
            ans = n1 / n2;
        cnt.push_back(ans);
    }
    int calculate(string s) {
        int n = s.size();
        
        vector<char> ops;
        vector<int> cnt;
        cnt.push_back(0);   // 防止第一个数字为负数
        unordered_map<char, int> cmap = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '(')
                ops.push_back(s[i]);
            else if(s[i] == ')') {
                while (ops.back() != '(') {
                    calc(cnt, ops);
                }
                ops.pop_back();
            }
            else {
                if (isdigit(s[i])) {
                    int num = 0;
                    while(isdigit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }
                    i--;
                    cnt.push_back(num);
                }

                else {
                    while (!ops.empty() && ops.back() != '(') {
                        char c  = ops.back();
                        if (cmap[c] >= cmap[s[i]]) {
                            calc(cnt, ops);
                        }
                        else break;
                    }
                    ops.push_back(s[i]);
                }
            }
        }
        while (!ops.empty()) calc(cnt, ops);
        return cnt.back();
    }
};