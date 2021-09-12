#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            
            if (s[i] == '*') star.push(i);

            if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    if (star.size()) star.pop();
                    else return false;
                }
            }
        }

        while (!st.empty() && !star.empty()) {
            if (st.top() < star.top())
            {
                st.pop();
                star.pop();
            }
            else break;
        }
        
        return st.empty() ? true : false;
    }
};