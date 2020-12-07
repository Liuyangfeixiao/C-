#include <iostream>
#include <vector>
using namespace std;

void rever(vector<int>& A) {
    for (int& x : A) {
        x = x == 0 ? 1 : 0;
    }
}

int matrixScore(vector<vector<int>>& A) {
    int n = A.size(), m = A[0].size();

    if (n == 0 || m == 0) {
        return 0;
    }
    // 翻转行
    for (int i = 0; i < n; ++i) {
        if (A[i][0] == 0) 
            rever(A[i]);
    }

    // 翻转列
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[j][i];
        }
        if (sum <= n >> 1) {
            for (int j = 0; j < n; ++j) {
                A[j][i] = A[j][i] == 0 ? 1 : 0;
            }
        }
    }

    // 计算
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += pow(2, (m-j-1)) * A[i][j];
        }
    }
    return ans;

}