#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // node 有右节点，找右节点的最左子节点
        if (node->right) {
            Node* cur = node->right;
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        }
        // 无右节点，找第一个左子树包含 node 的节点
        else {
            while (node->parent && node->parent->left != node) {
                node = node->parent;
            }
            return node->parent;
        }
    }
};