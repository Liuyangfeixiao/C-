#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string getSmallestString(int n, int k) {
    string res;
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 26; j++) {
            int last = k - s - j;
            int m = n - i - 1;
            if (last >= m && last <= m * 26) {
                res += 'a' + j - 1;
                s += j;
                break;
            }
        }
    }
    return res;
}
