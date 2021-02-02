#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 滑动窗口算法
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26, 0);
        int left = 0, right = 0;
        int maxCnt = 0; // 记录字符出现最多的字符个数
        while (right < n) {
            hash[s[right] - 'A']++;
            maxCnt = max(maxCnt, hash[s[right] - 'A']);
            if (right - left + 1 - maxCnt > k) {
                hash[s[left] - 'A'] --;
                left++;
            }
            right++;
        }

        // 最后返回滑动窗口的大小
        return right - left;
    }
};