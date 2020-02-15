//
// Created by HP on 2020/1/15.
//滑动窗口算法

#include "Solution.h"
vector<int> Solution::findAnagrams(string s, string p) {
    if (s.size() < p.size())
        return {};
    int l = 0;
    int r = -1;
    vector<int> freq_s(26, 0);
    vector<int> freq_p(26, 0);
    vector<int> res;
    for (int i = 0; i < p.size(); i++)
    {
        freq_p[p[i] - 'a']++;
        freq_s[s[i] - 'a']++;
    }
    if (freq_s == freq_p)
        res.push_back(0);
    for (int j = p.size(); j < s.size(); ++j) {
        freq_s[s[j] - 'a']++;
        freq_s[s[j - p.size()] - 'a']--;
        if (freq_p == freq_s)
            res.push_back(j - p.size() + 1);
    }
    return res;
}
/*codeWar 6kyu Which are in?*/
vector<string> Solution::arrayIn(vector<string> &array1, vector<string> &array2) {

}
