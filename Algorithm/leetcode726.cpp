#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
// 哈希表栈
class Solution {
public:
    map<string, int> table;
    string countOfAtoms(string formula) {
        stack<int> ha;
        string str = "", digit = "";
        int cnt = 1;

        for (auto i = formula.rbegin(); i != formula.rend(); ++i) {
            if (isdigit(*i)) digit = *i + digit;
            else if (*i == ')') {
                int v = digit == "" ? 1 : stoi(digit);

                digit = "";
                cnt *= v;
                ha.push(v);
            }

            else if (*i == '(') {
                cnt /= ha.top();
                ha.pop();
            }

            else {
                str += *i;
                if (*i >= 'A' && *i <= 'Z') {
                    reverse(str.begin(), str.end());
                    table[str] += (digit == "" ? 1 : stoi(digit)) * cnt;

                    str.clear();
                    digit.clear();
                }
            }
        }
        str.clear();
        for (auto& it : table) {
            str += it.first;
            if (it.second > 1) str += to_string(it.second);
        }
        return str;
    }
};