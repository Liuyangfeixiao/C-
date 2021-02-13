#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
int R, C;
int dx[8][2] = {{0, 1}, {0, -1}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, -1}, {-1, 1}};

class Solution {
public:

    bool inArea(int r, int c) {
        if (r >= 0 && r < R && c >= 0 && c < C) return true;
        else return false;
    }

    void detect(int r, int c, vector<vector<char>> &board) {
        int bomb = 0;
        for (auto d : dx) {
            int x = r + d[0], y = c + d[1];
            if (inArea(x, y) && board[x][y] == 'M') bomb++;
        }
        if (bomb > 0) board[r][c] = bomb + '0';
        else board[r][c] = 'B'; 
    }

    void bfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &visited) {
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return;
        }
        queue<PII> q;
        q.push(make_pair(r, c));
        visited[r][c] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            detect(t.first, t.second, board);
            if (board[t.first][t.second] == 'B') {
                for (auto d : dx) {
                    int x = t.first + d[0], y = t.second + d[1];
                    if (inArea(x, y) && !visited[x][y]) {
                        q.push(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
            }
        }
    }


    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        R = board.size(), C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        bfs(click[0], click[1], board, visited);

        return board;
    }
};