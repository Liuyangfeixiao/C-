// 桶排序
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s == "") return s;
        unordered_map<char, int> table;
        int maxfre = 0;
        for (auto& c : s) {
            maxfre = max(maxfre, ++table[c]);
        }
        vector<string> bucket(maxfre + 1);
        
        for (auto& it : table) {
            int n = it.second;

            for (int i = 0; i < n; ++i) {
                bucket[n].push_back(it.first);
            }
        }
        string ans;
        for (int i = maxfre; i >= 0; --i) {
            ans += bucket[n];
        }

        return ans;
    }
}