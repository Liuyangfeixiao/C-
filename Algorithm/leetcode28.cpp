#include <iostream>
#include <vector>
using namespace std;

// KMP 算法
int strStr(string s, string p) {
    int n = s.size(), m = p.size();
    if (m == 0) return 0;
    vector<int> next(m);
    next[0] = -1;
    int i = 0, j = -1;
    // 得到 next 数组
    while (i < m-1) {
        if (j == -1 || p[i] == p[j]) {
            j++;
            i++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
    i = 0, j = 0; 
    while (i < n && j < m) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j == m) return i - j;

    return -1;
}