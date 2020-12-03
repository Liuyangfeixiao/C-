#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    if (n < 2) return 0;
    vector<int> ans(n+1, 0);
    /*1 present the non-prime number*/
    for (int i = 0; i < 2; i++) {
        ans[i] = 1;
    }
    int count = 0;
    /*the prime number must less than the n*/
    for (int i = 2; i < n; i++) {
        if (!ans[i]) {
            count++;
            for (int j = 2 * i; j < n; j += i) {
                ans[j] = 1;
            }
        }
    }
    return count;
}