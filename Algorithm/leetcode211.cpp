#include <iostream>
using namespace std;

class WordDictionary {
    struct TrieNode{
        TrieNode() : isWord(false) {
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
        bool isWord;
        TrieNode* child[26];
    } *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* t = root;
        for (char c : word) {
            if (!t->child[c - 'a']) {
                t->child[c-'a'] = new TrieNode();
            }
            t = t->child[c - 'a'];
        }
        t->isWord = true;
    }
    bool find(TrieNode* root, int idx, string& word) {
        if (!root) return false;
        if (idx == word.size()) return root->isWord;
        if (word[idx] == '.') {
            for (auto t : root->child) {
                if (find(t, idx+1, word)) return true;
            }
        }
        else {
            return find(root->child[word[idx] - 'a'], idx+1, word);
        }
        return false;
    }
    
    bool search(string word) {
        return find(root, 0, word);
    }
};