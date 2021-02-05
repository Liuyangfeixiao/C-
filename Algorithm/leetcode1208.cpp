#include <iostream>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0, r = 0;
        int sum = 0;
        while (r < n) {
            sum += abs(t[r] - s[r]);
            if (sum > maxCost) {
                r++;
                sum -= abs(t[l] - s[l]);
                l++;
            }
            else r++;
        }
        return r - l;
    }
};