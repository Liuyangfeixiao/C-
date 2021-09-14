#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m < n) return false;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                j++;
            }

            i++;
        }

        if (j < n) return false;
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        string ans;
        for (auto& str : dictionary) {
            if (check(s, str)) {
                if (str.size() > ans.size())
                    ans = str;
                if (str.size() == ans.size())
                    ans = min(str, ans);
            }
        }

        return ans;
    }
};