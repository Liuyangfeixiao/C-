#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 9) return num;

        string s = to_string(num);
        string tmp(s);

        // 核心思想是将数字从大到小排序
        // 从高到低位首个与原位不相同的数既是我们需要交换的数，记录位置和需要交换的数
        // 之后我们从原数字低位往高位遍历，找到需要交换的数字进行交换、

        sort(tmp.begin(), tmp.end(), [](char a, char b){return a > b;});

        int index = -1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != tmp[i]) {
                index = i;
                break;
            }
        }

        if (index == -1) return num;

        for (int i = n - 1; i > index; i--) {
            if (s[i] == tmp[index]) {
                swap(s[i], s[index]);
                break;
            }
        }

        return stoi(s);
    }
};