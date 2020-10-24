#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} 
};

bool isPalindrome(ListNode* head) {//O(n)、O(1)
    ListNode* slow = head, *fast = head,  *prev = nullptr;
    while (fast){//find mid node
        slow = slow->next;
        fast = fast->next ? fast->next->next: fast->next;
    }
    while (slow){//reverse
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    while (head && prev){//check
        if (head->val != prev->val){
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}

