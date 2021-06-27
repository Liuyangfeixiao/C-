#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        auto get = [&](int id, int n) -> pair<int, int>{
            int r =  (id - 1) / n, c = (id - 1) % n;
            if (r % 2 == 1) {
                c = n - 1 - c;
            }
            return {n - 1 - r, c};
        };
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        q.emplace(1, 0);

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i) {
                int next_status = status + i;
                auto [x, y] = get(next_status, n);

                if (next_status == n * m) return step + 1;

                if (next_status < n * m && board[x][y] != 0) {
                    if (board[x][y] != -1) {
                        if (board[x][y] == n*m) return step+1;
                        q.emplace(board[x][y], step+1);
                    }
                    else
                        q.emplace(next_status, step+1);
                    board[x][y] = 0;
                }
            }
        }
        return -1;

    }
};