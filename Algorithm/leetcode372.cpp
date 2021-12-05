#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MOD = 1337;
    int quickPow(int a, int b) {
        int ans = 1;
        a %= MOD;
        while (b != 0) {
            if (b & 1 != 0) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    int dfs(int a, vector<int>& b, int index) {
        if (index == -1) return 1;
        return quickPow(dfs(a, b, index-1), 10) * quickPow(a, b[index]) % MOD;
    }
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size()-1);
    }
};
