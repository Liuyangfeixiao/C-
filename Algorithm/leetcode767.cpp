#include <iostream>
#include <vector>
using namespace std;

/**
 * 哈希表用于存储每个字符出现的次数，之后又是贪心算法，重构字符串的时候使用
 */
string reorganizeString(string S) {
    if (S.size() < 2) return S;
    vector<int> counts(26, 0);
    int maxcount = 0;
    int length = S.length();
    for (int i = 0; i < length; i++) {
        char c = S[i];
        counts[c - 'a']++;
        maxcount = max(maxcount, counts[c - 'a']);
    }

    if (maxcount > (length + 1) / 2) {
        return "";
    }
    string ans(length, ' ');
    int even = 0, odd = 1;
    int halfLen = length / 2;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        while (counts[i] > 0 && counts[i] <= halfLen && odd < length) {
            ans[odd] = c;
            counts[i]--;
            odd += 2;
        }
        while (counts[i] > 0) {
            ans[even] = c;
            counts[i]--;
            even += 2;
        }
    }

    return ans;

    
}