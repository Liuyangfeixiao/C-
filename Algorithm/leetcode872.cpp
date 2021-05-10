#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : left(nullptr), right(nullptr), val(0) {}
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void dfs(TreeNode *root, vector<int> &seq)
    {
        if (!root->left && !root->right)
        {
            seq.push_back(root->val);
        }
        if (root->left)
        {
            dfs(root->left, seq);
        }
        if (root->right)
        {
            dfs(root->right, seq);
        }
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> seq1;
        dfs(root1, seq1);
        vector<int> seq2;
        dfs(root2, seq2);
        return seq1 == seq2;
    }
};