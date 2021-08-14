#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_map<int, unordered_map<int, int>> table;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                table[i][preferences[i][j]] = n-1-j;
            }
        }
        auto find_pair = [pairs](int x) {for (auto& pai : pairs) {
                if (pai[0] == x) return pai[1];
                if (pai[1] == x) return pai[0];
            }};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int partner = find_pair(i);
            for (auto& pre: preferences[i]) {
                if (table[i][pre] <= table[i][partner])
                    break;
                int pre_partner = find_pair(pre);
                if (table[pre][i] > table[pre][pre_partner])
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};