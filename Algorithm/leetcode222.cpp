#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int countNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int left = getHeight(root->left);;
    int right = getHeight(root->right);
    if (left == right)
        return left << 1 + countNodes(root->right);
    else 
        return right << 1 + countNodes(root->left);
}

int getHeight(TreeNode* root) {
    int depth = 0;
    while (root) {
        depth++;
        root = root->left;
    }
    return depth;
}