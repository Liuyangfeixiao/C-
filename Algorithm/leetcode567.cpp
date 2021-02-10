#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;

        int window = n;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < n; ++i) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }

        for (int i = n; i < m; ++i) {
            if (hash1 == hash2) return true;

            // 向右滑窗
            hash2[s2[i - window] - 'a']--;
            hash2[s2[i] - 'a']++;
        }

        return hash1 == hash2;
    }
};