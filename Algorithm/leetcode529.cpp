#include <iostream>
#include <vector>
using namespace std;

int R, C;
int dx[3] = {0, 1, -1}, dy[3] = {0, 1, -1};


class Solution {
public:
    void detect(int r, int c, vector<char>& board) {
        int bomb = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i || j) {
                    int x = r + dx[i], y = c + dy[j];
                
                    if (x >= 0 && x < R && y >= 0 && y < C && board[x][y])
                        bomb++;
                }
            }
        }

        if (bomb > 0) board[r][c] = bomb + '0';
        else board[r][c] = 'B';
        
    }
    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || r >= R || c < 0 || c >= C) return;
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return;
        }
        if (board[r][c] == 'E') {
            detect(r, c, board);
            if (board[r][c] == 'B')
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (i || j) {
                            int x = r + dx[i], y = c + dy[j];
                            dfs(x, y, board);
                        }
                    }
                }
            
        }
        
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        R = board.size(), C = board[0].size();
        dfs(click[0], click[1], board);

        return board;
        
    }
};