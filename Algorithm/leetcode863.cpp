#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) parents[root->left->val] = root;
        if (root->right) parents[root->right->val] = root;
        dfs(root->left);
        dfs(root->right);
    }

    void find(TreeNode* node, TreeNode* from, int depth, int k) {
        if (node == nullptr) return;
        if (depth == k) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != from) {
            find(node->left, node, depth+1, k);
        }
        if (node->right != from) {
            find(node->right, node, depth+1, k);
        }
        if (parents[node->val] != from) {
            find(parents[node->val], node, depth+1, k);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        find(root, nullptr, 0, k);

        return ans;
    }
private:
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;
};