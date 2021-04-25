#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    TreeNode* prev;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
    
        prev->right = root;
        root->left = nullptr;       // 不明白为什么用 prev->left = nullptr 就无法通过
        // 在 leetcode 调试的时候会形成环
        prev = root;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        prev = dummy;
        inorder(root);
        return dummy->right;
    }
};
 
