#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int cnt = 0;
        while (cur) {
            cnt++;
            cur = cur->next;
        }
        cur = head;
        vector<ListNode*> ans;
        
        if (cnt <= k) {
            while (k--) {
                if (cur == nullptr) ans.push_back(nullptr);
                else {
                    ListNode* tmp = cur->next;
                    cur->next = nullptr;
                    ans.push_back(cur);
                    cur = tmp;
                }
            }
            return ans;
        }

        int x = cnt / k;
        int y = cnt % k;

        int sum = 1;
        ListNode* begin = cur;
        while  (cur) {
            if (sum == x) {
                if (y) {
                    cur = cur->next;
                    y--;
                }
                ListNode* tmp = cur->next;
                cur->next = nullptr;
                cur = tmp;
                ans.push_back(begin);
                begin = cur;
                sum = 1;
            }
            else {
                cur = cur->next;
                sum++;
            }
        }

        return ans;
    }
};