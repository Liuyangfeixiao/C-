#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findNumofValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;

        for (const string& word : words) {
            int mask = 0;
            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(mask) <= 7) {
                freq[mask]++;
            }
        }

        vector<int> ans;
        for (const string& puzzle : puzzles) {
            int total = 0;
            int mask = 0;
            for (int i = 1; i < 7; ++i) {
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask;
            // 求二进制串子集
            do {
                int s = subset | (1 << (puzzle[0] - 'a'));
                if (freq.count(s)) total += freq[s];

                subset = (subset - 1) & mask;
            } while(subset != mask);

            ans.push_back(total);
        }

        return ans;
    }
};