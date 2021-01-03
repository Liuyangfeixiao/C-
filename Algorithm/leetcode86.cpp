#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* pre = dummy;
    ListNode* le, *ge;
    ListNode* front1, *front2;
    front1 = le;
    front2 = ge;


    while (pre->next) {
        pre = pre->next;
        if (pre->val < x) {
            le->next =  new ListNode(pre->val);
            le = le->next;
        }
        else
        {
            /* code */
            ge->next = new ListNode(pre->val);
            ge = ge->next;
        }
    }
    le->next = front2->next;

    return front1->next;
}