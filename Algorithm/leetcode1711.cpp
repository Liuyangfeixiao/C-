#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> table;
        
        int sum = 0;
        int mod = 1e9 + 7;
        for (auto& val : deliciousness) {
            for (int i = 1; i < 1<<22; i <<= 1) {
                sum += table.count(i - val) ? table[i - val] : 0;
                sum %= mod;
            }
            table[val]++;
        }
        return sum;
    }
};