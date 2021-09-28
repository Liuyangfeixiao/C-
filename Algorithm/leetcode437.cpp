#include <vector>
#include <unordered_map>

using namespace std;
/*前缀和 + 回溯*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> prefix;

    int dfs(TreeNode* root, long long cur, int targetSum) {
        if (!root) return 0;

        int ret = 0;
        cur += root->val;
        if (prefix.count(cur - targetSum))
            ret += prefix[cur - targetSum];
        
        prefix[cur]++;
        ret += dfs(root->left, cur, targetSum);
        ret += dfs(root->right, cur, targetSum);
        prefix[cur]--;

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};