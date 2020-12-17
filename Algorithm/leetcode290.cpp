#include <iostream>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string str) {
    unordered_map<string, char> str2ch;
    unordered_map<char, string> ch2str;
    int m = str.length();
    int i = 0;
    for (char ch : pattern) {
        if (i >= m) return false;
        int j = i; 
        while (j < m && str[i] != ' ') j++;
        string tmp = str.substr(i, j - 1);
        if (str2ch.count(tmp) && str2ch[tmp] != ch)
            return false;
        if (ch2str.count(ch) && ch2str[ch] != tmp)
            return false;
        str2ch[tmp] = ch;
        ch2str[ch] = tmp;
        i = j + 1;
    }

    return i >= m;
}