#include <iostream>
#include <vector>
#include <unordered_map>
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
public:
    unordered_map<int, int> cmap;
    TreeNode *dfs(const vector<int>& preorder, const vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right) return nullptr;
        int pre_root = pre_left;
        int in_root = cmap[preorder[pre_root]];
        TreeNode* root = new TreeNode(preorder[pre_root]);
        int left_sz = in_root - in_left;
        int right_sz = in_right - in_root;

        root->left = dfs(preorder, inorder, pre_left+1, pre_left+left_sz, in_left, in_root-1);
        root->right = dfs(preorder, inorder, pre_left+left_sz+1, pre_right, in_root+1, in_right);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < inorder.size(); ++i) {
            cmap[inorder[i]] = i;
        }

        TreeNode* root = dfs(preorder, inorder, 0, n-1, 0, n-1);
        return root;

    }
};