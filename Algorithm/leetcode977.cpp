#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

vector<int> sortedSquares(vector<int>& A) {

    int len = A.size();
    for (int i = 0; i < len; i++){
        A[i] = pow(A[i], 2);
    }

    sort(A.begin(), A.end());
    return A;
}


// 双指针，从后往前写
vector<int> sortedsquares(vector<int>& A) {
    int len = A.size();
    int start = 0, end = len-1;
    vector<int> ans(len, 0);
    for (int i = len -1; i >= 0; i--) {
        ans[i] = abs(A[start]) > abs(A[end]) ? A[start] * A[start++] : A[end] * A[end--];
    }
    return ans;
}