#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


struct Node
{
    int weight;
    bool isWord;
    // unordered_map<char, Node*> children;
    Node* children[27];

    Node()
    {
        memset(children, 0, sizeof(children));
        weight = -1;
        isWord = false;
    }
};

class WordFilter {
private:
    Node* root = new Node();

public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        //这里weight就等于下标，越大表示权重越大
        for (int weight = 0; weight < n; ++weight)
        {
            // 构建一个特殊前后相同字符串，后续查找使用
            string fullWord = words[weight] + "#" + words[weight];
            int nWord = words[weight].size();

            for (int i = 0; i < nWord + 1; ++i)
            {
                Node* curr = root;
                for (int j = i; j < fullWord.size(); ++j)
                {
                    // if (curr->children.find(fullWord[j]-'a') == curr->children.end())
                    int index = fullWord[j] == '#' ? 26 : fullWord[j]-'a';
                    if (curr->children[index] == nullptr)
                    {
                        curr->children[index] = new Node();
                    }
                    curr = curr->children[index];
                    curr->isWord = true;
                    curr->weight = weight;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string fullWord = suffix + "#" + prefix;
        Node* curr = root;
        for (char c : fullWord)
        {
            int index = c == '#' ? 26 : c-'a';
            // if (curr->children.find(c-'a') == curr->children.end())
            if (curr->children[index] == nullptr)
            {
                return -1;
            }
            curr = curr->children[index];
        }
        return curr->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */