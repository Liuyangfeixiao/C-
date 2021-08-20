#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto check = [](const string& pattern, const string& word) {
            int m = pattern.size(), n = word.size();
            vector<int> next(m);
            for (int i = 1, j = 0; i < m; ++i) {
                while (j && pattern[i] != pattern[j])
                    j = next[j-1];
                if (pattern[i] == pattern[j]) j++;
                next[i] = j;
            }

            for (int i = 0, j = 0; i < n; ++i) {
                while (j && word[i] != pattern[j])
                    j = next[j-1];
                if (word[i] == pattern[j]) j++;
                if (j == m) return true;
            }

            return false;
        };

        for (auto& pattern: patterns) {
            
        }
    }
};