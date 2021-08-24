#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <tuple>
using namespace std;

class Solution {
private:
    static constexpr int INF = 10000 * 101 + 1;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> f(n, INF);
        f[src] = 0;
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            vector<int> g(n, INF);
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                g[i] = min(g[i], f[j] + cost);
            }
            f = move(g);
            ans = min(ans, f[dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};
