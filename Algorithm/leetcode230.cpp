#include <vector>
#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        int leftN = find(root->left);
        if (leftN + 1 == k) return root->val;
        else if (k <= leftN) return kthSmallest(root->left, k);
        else {
            return kthSmallest(root->right, k - leftN - 1);
        }
    }
    int find(TreeNode* root) {
        if (root == nullptr) return 0;

        return find(root->left) + find(root->right) + 1;
    }
};