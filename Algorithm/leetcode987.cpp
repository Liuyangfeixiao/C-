#include <vector>
#include <map>
#include <algorithm>
#include <queue>
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
    using TU = tuple<int, int, int>;
    priority_queue<TU, vector<TU>, greater<TU>> q;
    void dfs(TreeNode* root, int row, int col) {
        if (root == nullptr) return;
        q.push({col, row, root->val});
        dfs(root->left, row + 1, col-1);
        dfs(root->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        int lastcol = INT32_MIN;
        vector<int> curcol;
        while (!q.empty()) {
            auto [col, row, val] = q.top();
            q.pop();
            if (col != lastcol) {
                if (curcol.size()) ans.push_back(curcol);
                curcol.clear();
                curcol.push_back(val);
                lastcol = col;
            }
            else {
                curcol.push_back(val);
            }
        }
        ans.push_back(curcol);
        return ans;
    }
};
 