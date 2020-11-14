#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* odd = head;
    ListNode* dummpy = head->next;
    ListNode* even = dummpy;
    while(odd->next != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = dummpy;
    return head;

}
