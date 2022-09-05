#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> mt;
        marshal(root, result, mt);
        return result;
    }

    string marshal(TreeNode* root, vector<TreeNode*>& result, unordered_map<string, int>& mp) {
        if (root == nullptr) {
            return "#";
        }

        string ans = to_string(root->val) + ' ' + marshal(root->left, result, mp) + ' ' + marshal(root->right, result, mp);
        if (mp[ans] == 1) {
            result.push_back(root);
        }
        mp[ans]++;
        return ans;
    }
};