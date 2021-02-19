#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (dfs(root, voyage)) return ans;
        return {-1};
    }

private:
    int i;
    vector<int> ans;
    bool dfs(TreeNode* root, vector<int>& voyage) {
        if (root == nullptr) return true;   // 为空则为真
        if (root->val != voyage[i]) return false;   // 如果值不匹配则为假
        i++;
        if (dfs(root->left, voyage) && dfs(root->right, voyage))    // 先序遍历匹配则为真
            return true;
        if (dfs(root->right, voyage) && dfs(root->left, voyage)) {  // 否则翻转左右节点，判断是否匹配
            ans.push_back(root->val);
            return true;
        }

        return false;
    }
};