#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* dummpy = new ListNode(0);
    dummpy->next = head;

    ListNode* tail = head;
    ListNode* cur = head->next;

    while (cur)
    {
        /* code */
        if (cur->val > tail->val) {
            tail = tail->next;
            cur = tail->next;
        }
        else
        {
            ListNode* tmp = dummpy;
            while (tmp->next->val < cur->val && tmp->next) {
                tmp = tmp->next;
            }
            tail->next = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            cur = tail->next;
        }
        
    }
    return dummpy->next;
}
