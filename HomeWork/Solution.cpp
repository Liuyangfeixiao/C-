//
// Created by HP on 2020/1/15.
//���������㷨


#include "Solution.h"
vector<int> Solution::findAnagrams(string s, string p) {
    if (s.size() < p.size())
        return {};
    int l = 0;
    int r = -1;
    vector<int> freq_s(26, 0);
    vector<int> freq_p(26, 0);
    vector<int> res;
    for (int i = 0; i < p.size(); i++)
    {
        freq_p[p[i] - 'a']++;
        freq_s[s[i] - 'a']++;
    }
    if (freq_s == freq_p)
        res.push_back(0);
    for (int j = p.size(); j < s.size(); ++j) {
        freq_s[s[j] - 'a']++;
        freq_s[s[j - p.size()] - 'a']--;
        if (freq_p == freq_s)
            res.push_back(j - p.size() + 1);
    }
    return res;
}
/*codeWar 6kyu Which are in?*/
vector<string> Solution::arrayIn(vector<string> &array1, vector<string> &array2) {

}
/*leetcode 56 �ϲ�����*/
vector<vector<int>> Solution::merge(vector<vector<int>> &intervals) {
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (res.back()[1]>=intervals[i][0])
        {
            res.back()[1] = max(intervals[i][1], res.back()[1]);
        } else
            res.push_back(intervals[i]);
    }
    return res;
}
/*leetcode 57 ��������*/
vector<vector<int>> Solution::insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;
    /*����Ϊ��*/
    if(n == 0)
    {
        res.push_back(newInterval);
        return res;
    }
    /*�ڵ�һ��Ԫ�ز���*/
    if(newInterval[1] < intervals[0][0])
    {
        res.push_back(newInterval);
        for(int i=0; i < n; i++)
            res.push_back(intervals[i]);
        return res;
    }

    res.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {

        if (res.back()[1] < newInterval[0] ) //��������ǰһ��ཻ
        {
            if(newInterval[1] < intervals[i][0]) //���������һ��ཻ
            {
                res.push_back(newInterval);
                for(; i < n; i++)
                    res.push_back(intervals[i]);
                return res;
            } else
                res.push_back(intervals[i]);

        }
        else  //��ǰһ���ཻ
        {
            res.back()[1] = max(newInterval[1], res.back()[1]);//�������
            if(res.back()[0] <= newInterval[1])                 //ǰ������
                res.back()[0] = min(res.back()[0], newInterval[0]);
            //res.back()[0] = min(newInterval[0], res.back()[0]);
            if (res.back()[1]>=intervals[i][0])
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else
                res.push_back(intervals[i]);
        }

    }
    if (res.back()[1] >= newInterval[0] && res.back()[0] <= newInterval[1])
    {
        res.back()[1] = max(newInterval[1], res.back()[1]);
        res.back()[0] = min(newInterval[0], res.back()[0]);
    }
    else if (res.back()[1] < newInterval[0])
        res.push_back(newInterval);
    return res;


}
/*leetcode 75 ��ɫ����*/
void Solution::sortColors(vector<int> &nums) {
    int benchMark = -1; //��׼
    int low = 0;        //��߽�
    int high = nums.size(); //�ұ߽�
    while (low < high)
    {
        if (nums[low] == 0)
            swap(nums[++benchMark], nums[low++]);
        else if (nums[low] == 2)
            swap(nums[--high], nums[low]);
        else
            low++;
    }
}
/*leetcode 349 ��������Ľ���*/
vector<int> Solution::intersection(vector<int> &nums1, vector<int> &nums2) {
    int count = 0;
    unordered_set<int> temp(nums1.begin(), nums1.end());
    for (int num : nums2)
    {
        if (temp.erase(num))
        {
            nums2[count] = num;
            count++;
        }
    }
    return vector<int>(nums2.begin(), nums2.begin()+count);

}
/*leetCode 147 ��������в�������*/
ListNode *Solution::insertionSortList(ListNode *head) {
    if (!head || !head->next)
        return head;
    auto tail = new ListNode(0);
    tail->next = head;

    auto pre = head; //������߽�
    auto node = head->next; //��Ҫ�����Ԫ��
    while (node){
        if (node->val > pre->val){
            pre = pre->next;
            node = pre->next;
        }
        else{
            auto curr = tail; // ����
            while (curr->next->val < node->val && curr->next)
                curr = curr->next;
            pre->next = node->next;
            node->next = curr->next;
            curr->next = node;
            node = pre->next;
        }

    }
    return tail->next;
}
/*leetcode 148 ��������*/
ListNode *Solution::sortList(ListNode *head) {
    /*��������ʱ*/
    /*�鲢����*/
    auto* dummy = new ListNode(0);
    dummy->next = head;
    auto p = head;
    int length = 0;
    while (p)
    {
        ++length;
        p = p->next;
    }
    for (int size = 1; size < length; size <<= 1)
    {
        auto curr = dummy->next;
        auto tail = dummy;
        while (curr)
        {
            auto left = curr;
            auto right = cut(left, size);
            curr = cut(right, size);
            tail->next = merge(left, right);
            while (tail->next)
                tail = tail->next;
        }
    }
    return dummy->next;

}

ListNode *Solution::merge(ListNode *list_1, ListNode *list_2) {
    ListNode* dummy = new ListNode(0);
    auto p = dummy;
    while (list_1 && list_2)
    {
        if(list_1->val < list_2->val)
        {
            p->next = list_1;
            p = p->next;
            list_1 = list_1->next;
        }
        else
        {
            p->next = list_2;
            p = p->next;
            list_2 = list_2->next;
        }
    }

    p->next = list_1 ? list_1:list_2;
    return dummy->next;
}

ListNode *Solution::cut(ListNode *head, int n) {
    auto p = head;
    while (--n && p)
        p = p->next;
    if (!p)
        return nullptr;
    auto next = p->next;
    p->next = nullptr;
    return next;
}

