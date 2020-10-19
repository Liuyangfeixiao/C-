#include<iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode* dummpy = new ListNode();
    dummpy->next = head;
    ListNode* fast = head;
    ListNode* slow = dummpy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummpy->next;
}