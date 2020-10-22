#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


void reorderList(ListNode* head) {
    if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse(l2);
        merge(l1, l2);
}

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}

ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }

    return pre;
}

void merge(ListNode* L1, ListNode* L2) {
    ListNode* temp_1;
    ListNode* temp_2;
    while (L1 != nullptr && L2 != nullptr) {
        temp_1 = L1->next;
        temp_2  = L2->next;
        L1->next = L2;
        L1 = temp_1;

        L2->next = L1;
        L2 = temp_2;
    }

}