#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() + 2;
        vector<int> tmp(n, 0);
        for (int i = 1; i < n- 1; ++i) {
            tmp[i] = heights[i-1];
        }
        stack<int> st;
        int area = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && tmp[i] < tmp[st.top()]) {
                int h = tmp[st.top()];
                st.pop();
                area = max(area, (i - st.top() -1) * h);
            }
            st.push(i);
        }
        return area;
    }
};