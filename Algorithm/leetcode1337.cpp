#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (mat[i][mid] == 0) {
                    r = mid;
                }
                else l = mid + 1;
            }
            if (mat[i][l] == 1) l++;    // 边界条件，l = r = n-1 = 1
            q.emplace(l, i);
            if (q.size() > k) q.pop();
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};