#include<iostream>
#include<stack>
#include<map>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

// 快慢指针

ListNode* hasCycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return fast;
    }

    return head;
}


ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* dumpy = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while (fast != dumpy)
            {
                /* code */
                fast = fast->next;
                dumpy = dumpy->next;
            }
            return dumpy;
        }
        
    }

    
    return NULL;
    
    
}

//改变快慢指针的算法


