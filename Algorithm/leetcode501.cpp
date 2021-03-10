#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> ans;
    void in_oder(TreeNode* root, TreeNode* &pre, int &cur_times, int &max_times) {
        if (!root) return ;
        in_oder(root->left, pre, cur_times, max_times);
        if (pre) {
            cur_times = (root->val == pre->val) ? cur_times+1 : 1;
        }
        if (cur_times == max_times) {
            ans.push_back(root->val);
        }
        else if(cur_times > max_times) {
            ans.clear();
            ans.push_back(root->val);
            max_times = cur_times;
        }
        pre = root;
        in_oder(root->right, pre, cur_times, max_times);

    }
    vector<int> findMode(TreeNode* root) {
        if (!root) return ans;
        TreeNode* pre = NULL;
        int cur_times = 1, max_times = 0;
        in_oder(root, pre, cur_times, max_times);
    }
};