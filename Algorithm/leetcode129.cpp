#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<int> ans;

 int pre(TreeNode* root, int count) {
     if (root == NULL) {
         return 0;
     }
     int val = count*10 + root->val;
     if (root->left == NULL && root->right == NULL) 
        return val;
    
    return pre(root->left, val) + pre(root->right, val);
 }

 int sumNumbers(TreeNode* root) {
     return pre(root, 0);

}