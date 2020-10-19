#include <iostream>
#include <cstring>
#include <stack>
using namespace std;






bool backspaceCompare(string S, string T) {
    return built(S) == built(T);
}

// 本来想用双栈来实现，但字符串也可以当栈使用
// 当字符不为 # 时，字符入栈
// 当字符为 # 且字符串不为空时，入栈
string built(string str) {
    string ret;
    for (char ch : str) {
        if (ch != '#')
            ret.push_back(ch);
        else if (!ret.empty())
            ret.pop_back();
    }
    return ret;
}