#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0, right = 0;
        while (right < n) {
            int idx = right;
            while (right < n && chars[right] == chars[idx]) {
                right++;
            }
            int len = right - idx;
            chars[left++] = chars[idx];
            if (len > 1) {
                string s = to_string(len);
                for (auto& c : s) {
                    chars[left++] = c;
                }
            }
        }

        return left;
    }
};