#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void help(Node* root, vector<int>& index) {
        if (root == nullptr) return;

        for (auto& child : root->children) {
            help(child, index);
        }
        index.emplace_back(root->val);
    }
    vector<int> postortder(Node* root) {
        vector<int> index;
        help(root, index);
        return index;
    }
};