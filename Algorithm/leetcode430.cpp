
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;

        dfs(cur);
        return head;
    }

    Node* dfs(Node* head) {
        if (head == nullptr) return nullptr;

        Node* cur = head;
        while (cur->child || cur->next != nullptr) {
            if (cur->child) {
                Node* end = dfs(cur->child);
                Node* tmp = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                if (tmp == nullptr) {
                    cur = end;
                }
                else {
                    tmp->prev = end;
                    end->next = tmp;
                    cur = tmp;
                }
                
            }
            else {
                cur = cur->next;
            }
        }

        return cur;
    }
};