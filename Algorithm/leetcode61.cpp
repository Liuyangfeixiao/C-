#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        if (!n) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < k % n; ++i) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = slow->next;
        slow->next = nullptr;
        return dummy->next;
    }
};