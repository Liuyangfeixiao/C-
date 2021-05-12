#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] ^ arr[i];
        }
        vector<int> res;
        int ans = 0;
        for (auto& q : queries) {
            if (q[0] == 0) {
                ans = pre[q[1]];
            }
            else {
                ans = pre[q[0]-1] ^ pre[q[1]];
            }
            res.push_back(ans);
        }
        return res;
    }
};