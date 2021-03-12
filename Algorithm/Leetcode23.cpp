#include <iostream>
#include <vector>
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
    ListNode* merge_sort(vector<ListNode*>& lists, int l, int r) {
        if (l >= r) return lists[l];
        int mid = (l+r) >> 1;
        ListNode* left = merge_sort(lists, l, mid);
        ListNode* right = merge_sort(lists, mid+1, r);
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while (left && right) {
            if (left->val < right->val) {
                head->next = left;
                head = head->next;
                left = left->next;
            }
            else {
                head->next = right;
                head = head->next;
                right = right->next;
            }
        }
        while (left) {
            head->next = left;
            head = head->next;
            left = left->next;
        }
        while (right) {
            head->next = right;
            head = head->next;
            right = right->next;
        }
        return dummy->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return nullptr;
        ListNode* ans = merge_sort(lists, 0, n-1);
        return ans;
    }
};