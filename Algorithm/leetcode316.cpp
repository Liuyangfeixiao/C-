#include <iostream>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> map(26, 0);
    vector<int> map2(26, 0);
    string ans = "";

    for (char ch : s) {
        map[ch - 'a']++;
    }
    for (char ch : s) {
        if (ans.find(ch) != string::npos)
            map[ch-'a']--;
            continue;
        while (!ans.empty() && ch < ans.back() && map[ans.back()-'a']) {
            ans.pop_back();
        }
        ans += ch;
        map[ch - 'a']--;
    }
    return ans;
}