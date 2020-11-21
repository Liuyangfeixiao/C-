#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*可以使用插入排序，但所需要的时间复杂度太大，改为归并排序*/
ListNode* sortList(ListNode* head) {
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* p = head;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    for (int sublen = 1; sublen < length; sublen <<= 1) {
        ListNode* curr = dummyHead->next;
        ListNode* pre = dummyHead;
        while (curr) {
            ListNode* left = curr;
            ListNode* right = cut(curr, sublen);
            curr = cut(right, sublen);
            pre->next = merge(left, right);
            while (pre->next)
                pre = pre->next;
            
        }
    }
    return dummyHead->next;
}

/*裁剪链表*/
ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while (--n && p) {
        p = p->next;
    }
    if (!p) return nullptr;

    ListNode* next = p->next;
    p->next = nullptr;
    return next;
}


/*合并链表*/
ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = dummyHead;
    while (head1 && head2) {
        if (head1->val < head2->val) {
            p->next = head1;
            head1 = head1->next;
        }else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    p->next = head1 ? head1 : head2;
    return dummyHead->next;
}