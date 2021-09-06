#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    void solve(vector<vector<char>>& board) {
        n == board.size();
        if (n == 0) return;
        m = board[0].size();


        for (int i = 0; i < n; ++i) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }

        for (int j = 0; j < m; ++j) {
            dfs(board, 0, j);
            dfs(board, n - 1, j);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'A')
                    board[i][j] == 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }

        }
    }

};