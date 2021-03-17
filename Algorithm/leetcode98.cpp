#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {
public:
    bool in_order(TreeNode* root, TreeNode* &prev) {
        if (!root) return true;
        bool left = in_order(root->left, prev);
        bool ans = prev == nullptr ? true : root->val > prev->val;
        prev = root;
        bool right = in_order(root->right, prev);

        return left && ans && right;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return in_order(root, prev);
    }
};