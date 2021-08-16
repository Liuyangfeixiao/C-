#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> match;
    vector<int> visited;
    int ans;
    void dfsearch(int index, int n) {
    	if (index == n + 1) {
            ans++;
            return;
        }
        
        for (auto& x : match[index]) {
            if (!visited[x]) {
                visited[x] = true;
                dfsearch(index+1, n);
                visited[x] = false;
            }
        }
    }
    // 记忆化搜索+回溯算法
    int countArrangement(int n) {
        match.resize(n+1);
        visited.resize(n+1);
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j % i == 0 || i % j == 0)
                    match[i].push_back(j);
            }
        }
        dfsearch(1, n);
        return ans;
    }

    // 状态压缩+dp
    int countArrangement(int n) {
        vector<int> f(1 << n);
        f[0] = 1;
        for (int mask = 1; mask < (1 << n); mask++) {
            int num = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i) && (num % (i + 1) == 0 || (i + 1) % num == 0) )
                {
                    f[mask] += f[mask ^ (1 << i)];
                }
            }
        }
        return f[(1 << n) - 1];
    }
    
};