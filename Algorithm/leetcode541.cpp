#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int iter = n / (2*k);
        
        for (int i = 0; i < iter; i++) {
            int begin = i * (2 * k);
            int end = begin + k - 1;
            while (begin < end) {
                swap(s[begin++], s[end--]);
            }
        }

        int diff = n % (2 * k);
        if (diff < k) {
            int begin = iter * (2*k);
            int end = n - 1;
            while (begin < end)
                swap(s[begin++], s[end--]);
        }
        if (diff >= k) {
            int begin = iter * (2*k);
            int end = begin + k - 1;
            while (begin < end) {
                swap(s[begin++], s[end--]);
            }
        }
        return s;
    }
};