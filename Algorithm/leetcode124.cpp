#include <iostream>
using namespace std;

// 二叉树中的最大路径和
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
    int ans;
public:
    // 返回包含此节点的左路径或者右路径
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(dfs(root->left), 0);
        int right = max(0, dfs(root->right));
        int rlm = root->val + max(left, right);
        int lmr = root->val + right + left;
        ans = max(ans, max(lmr, rlm));
        return rlm;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};