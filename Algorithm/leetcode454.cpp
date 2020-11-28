#include <iostream>
#include <unordered_map>
using namespace std;


int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int n = A.size();
    if (n == 0) return 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        for (int  j = 0; j < n; j++) {
            map[A[i] + B[j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j  =0; j < n; ++j) {
            if (map.count(-C[i] - D[j]))
                ans += map[-C[i] - D[j]];
        }
    }
    return ans;
    
}

