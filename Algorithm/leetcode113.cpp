#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int target, vector<int>& res) {
        if (root == nullptr) return;

        target -= root->val;
        res.push_back(root->val);
        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            ans.push_back(res);
        }
        else {
            dfs(root->left, target, res);
            dfs(root->right, target, res);
        }
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> res;
        dfs(root, targetSum, res);
        return ans;
    }
};