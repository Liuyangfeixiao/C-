#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*贪心加单调栈*/
string removeKdigits(string num, int k) {
    deque<char> dq; // 双端队列
    /*遍历字符串，删除元素*/
    for (char ch : num) {
        while (dq.size() > 0 && dq.back() > ch && k) {
            dq.pop_back();
            k--;
        }
        dq.push_back(ch);
    }
    while (k > 0) {
        dq.pop_back();
        k--;
    }
    bool isLeadZero = true;
    string ans = "";
    for (auto x : dq) {
        if (x == '0' && isLeadZero == true)
            continue;
        isLeadZero = false;
        ans += x;
    }
    return ans == "" ? "0" : ans;
}
