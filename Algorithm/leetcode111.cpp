#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}; 

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!left) return right+1;
        else if (!right) return left+1;

        return min(left, right) + 1;
    }
};