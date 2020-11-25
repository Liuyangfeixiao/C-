#include <iostream>

using namespace std;


int lengthOfLongestSubstring(string s) {
    string ans = "";
    int smax = 0;
    for (char ch : s) {
        while (ans.find(ch) != ans.npos)
            ans.erase(ans.begin());
        ans += ch;
        smax = max(smax, int(ans.size()));
    }

    return smax;
}