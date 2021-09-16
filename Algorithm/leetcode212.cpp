#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
    Trie* child[26];
    string word = "";
    bool isWord;
    Trie(): isWord(false) {
        for (int i = 0; i < 26; ++i) 
            child[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> ans;
    void dfs(vector<vector<char>>& board, Trie* t, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        char c = board[i][j];
        if (c == '*' || t->child[c - 'a'] == nullptr)
            return;
        t = t->child[c - 'a'];
        if (t->isWord) {
            ans.push_back(t->word);
            t->isWord = false;
        }

        board[i][j] = '*';
        dfs(board, t, i+1, j);
        dfs(board, t, i-1, j);
        dfs(board, t, i, j+1);
        dfs(board, t, i, j-1);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();
        for (auto& w : words) {
            Trie* cur = t;
            for (int i = 0; i < w.size(); ++i) {

                if (cur->child[w[i] - 'a'] == nullptr) {
                    cur->child[w[i] - 'a'] = new Trie();
                }
                cur  = cur->child[w[i] - 'a'];
            }
            cur->word = w;
            cur->isWord = true;
        }
        return ans;

    }
};