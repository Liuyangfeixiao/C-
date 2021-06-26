#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    vector<vector<int>> neighbors = {{1, 3}, {0,2,4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        auto get = [&](string& status) -> vector<string> {
            vector<string> res;
            int pos = status.find('0');
            for (auto x : neighbors[pos]) {
                swap(status[pos], status[x]);
                res.push_back(status);
                swap(status[pos], status[x]);
            }
            return res;
        };

        string initial;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                initial += (board[i][j] + '0');
            }
        }
        string ans = "123450";
        if (initial == ans) return 0;

        queue<pair<string, int>> q;
        q.emplace(initial, 0);
        unordered_set<string> table;
        table.insert(initial);

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (auto &&next_status : get(status)) {
                if (!table.count(next_status)) {
                    if (next_status == ans) return step+1;
                    q.emplace(next_status, step+1);
                    table.insert(move(next_status));
                }
            }
        }
        return -1;
    }
};