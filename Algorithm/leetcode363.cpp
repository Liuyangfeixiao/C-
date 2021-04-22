#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 二维数组的前缀和
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT32_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {   // 确定上边界
            vector<int> sum(n);
            for (int j = i; j < m; ++j) {   // 确定下边界
                for (int c = 0; c < n; ++c) {
                    sum[c] += matrix[j][c];     // 更新前缀数组
                }
                set<int> sunSet{0};         // 保留 sl
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sunSet.lower_bound(s - k);
                    if (lb != sunSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sunSet.insert(s);
                }
            }
        }
        return ans;
    }
};