// 数组中最长的山脉

#include<iostream>
#include <vector>
using namespace std;

int longestMountain(vector<int>& A) {
    int n = A.size();
    vector<int> left(n); // left 可扩展的元素数量
    vector<int> right(n); // right 可扩展的元素数量

    // left[0] = 0;
    for (int i = 1; i < n; ++i) {
        left[i] = A[i-1] < A[i] ? left[i-1]+1 : 0;
    }
    // right[n-1] = 0;
    for (int i = n-2; i >=0; --i) {
        right[i] = A[i] > A[i+1] ? right[i+1] + 1 : 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (left[i] >0 && right[i] >0 ) {
            ans = max(ans, left[i] + right[i] + 1);
        }
    }

    return ans;
}