#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int height(TreeNode* root){
    if (root == nullptr)
    {
        /* code */
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left == -1 || right == -1){
        return -1;
    }

    return abs(left - right) < 2 ? max(left, right) + 1 : -1;

    
}

bool isBalanced(TreeNode* root) {
    int res = height(root);
    return res != -1;

        
}