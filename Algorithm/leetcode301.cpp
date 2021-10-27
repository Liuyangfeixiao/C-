#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for (auto c : s) {
            if (c == '(')
                count++;
            else if (c == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> cur_set;
        cur_set.insert(s);
        while (true) {
            for (auto& str : cur_set) {
                if (isValid(str))
                    ans.push_back(str);
            }
            if (ans.size() > 0) return ans;

            unordered_set<string> next_set;
            for (auto& str : cur_set) {
                for (int i = 0; i < str.size(); ++i) {
                    if (i != 0 && str[i] == str[i-1])
                        continue;
                    if (str[i] == '(' || str[i] == ')') {
                        next_set.insert(str.substr(0, i) + str.substr(i+1, str.size()));
                    }
                }
            }
            cur_set = next_set;
        }
    }
};