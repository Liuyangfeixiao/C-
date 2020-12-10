#include <iostream>
using namespace std;


int fractorial(int n) {
    int ans = n;
    for (int i = n-1; i >= 1; i--) {
        ans *= i;
    }
    return ans;
}
int uniquePaths(int m, int n) {
    return fractorial(m+n-2) / (fractorial(m-1) * fractorial(n-1));
}