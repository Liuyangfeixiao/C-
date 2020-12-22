#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
/*二叉树的矩形层次遍历*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    deque<TreeNode*> level;
    level.push_back(root);
    bool left = true;

    while (!level.empty()) {
        deque<int> layer;
        int n = level.size();
        for (int i = 0; i < n; i++) {
            auto node = level.front();
            level.pop_front();
            if (left) {
                layer.push_back(node->val);
            }
            else
            {
                layer.push_front(node->val);
            }
            if(node->left) level.push_back(node->left);
            if(node->right) level.push_back(node->right);
        }
        ans.push_back(vector<int>{layer.begin(), layer.end()});
        left = !left;
    }

    return ans;
}