#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                if (t == nullptr) {
                    ans += '#';
                    ans += ',';
                }
                else {
                    q.push(t->left);
                    q.push(t->right);
                    ans += to_string(t->val);
                    ans += ',';
                }
            }
        }
        return ans;
    }

    TreeNode* get(vector<string>& tmp, vector<int>& cnt, int pos) {
        if (pos >= tmp.size()) return nullptr;
        if (tmp[pos] == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(tmp[pos]));
        root->left = get(tmp, cnt, 2 * (pos - cnt[pos]) + 1);
        root->right = get(tmp, cnt, 2 * (pos - cnt[pos]) + 2);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> tmp;
        string str;
        
        for (auto& ch : data) {
            if (ch == ',') {
                tmp.push_back(str);
                str.clear();
            }
            else str.push_back(ch);
        }
        if (!str.empty()) tmp.push_back(str);
        vector<int> cnt(tmp.size());
        cnt[0] = tmp[0] == "#" ? 1 : 0;
        for (int i = 1; i < cnt.size(); ++i) {
            cnt[i] = tmp[i] == "#" ? cnt[i-1] + 1 : cnt[i-1];
        }

        TreeNode* root = get(tmp, cnt, 0);
        return root;
    }
};