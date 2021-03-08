// 链表深拷贝
// 运用哈希表解决

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> chash;
        Node* curr = head;

        Node* p = new Node(0);  // dummy node
        // 第一次遍历， 遍历 next 节点
        while (curr) {
            p->next = new Node(curr->val);
            p = p->next;
            chash[curr] = p;
            curr = curr->next;
           
        }

        curr = head;
        // 第二次遍历 random 节点
        while (curr) {
            chash[curr]->random = chash[curr->random];
            curr = curr->next;
        }

        return chash[head];
    }
};
