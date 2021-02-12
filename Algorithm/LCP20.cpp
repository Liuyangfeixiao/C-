#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;

class Solution {
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        LL ans = solve(target, dec, inc, jump, cost);
        return (int) (ans % mod);
    }
private:
    LL solve(int target, int dev, int inc, vector<int>& jump, vector<int>& cost) {
        if (target == 0) return 0;
        if (target == 1) return inc;
        if (hash.count(target)) return hash[target];

        LL ans = inc * target;  // 步行到终点
        for (int i = 0; i < cost.size(); ++i) {
            long u = target / jump[i], v = target % jump[i];
            if (v == 0) {
                ans = min(ans, solve(u, inc, dev, jump, cost) + cost[i]);   // 直接坐公交车
            }
            else {
                ans = min(ans, solve(u, inc, dec, jump, cost) + cost[i] + v * inc);     // 先坐车到某一站点，然后走路到终点
                ans = min(ans, solve(u + 1, inc, dev, jump, cost) + cost[i] + (jump[i] - v) * dev);     // 先坐车到target后，然后走回
            }
        }
        hash[target] = ans;
        return ans;
    }
    unordered_map<LL, LL> hash;
    
}