//
// Created by HP on 2020/1/15.
//

#ifndef HOMEWORK_SOLUTION_H
#define HOMEWORK_SOLUTION_H

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bits/unordered_set.h>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x): val(x), next(nullptr){}
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p);
    vector<string> arrayIn(vector<string> &array1, vector<string>& array2);
    vector<vector<int>> merge(vector<vector<int>>& intervals);
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
    void sortColors(vector<int>& nums);
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    ListNode* insertionSortList(ListNode* head);
    ListNode* sortList(ListNode* head);
    ListNode* merge(ListNode* list_1, ListNode* list_2);
    ListNode* cut(ListNode* head, int n);

};


#endif //HOMEWORK_SOLUTION_H
