#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int find(int x) {
        if (x % 2) return x - 1 ;
        else return x + 1;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int, int> hash;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            hash[row[i]] = i;
        }
        for (int i = 0; i < n / 2; ++i) {
            int t = find(row[i*2]);
            if (t == row[i*2 + 1])
            {
                continue;
            }else {
                
                hash[row[i * 2 + 1]] = hash[t];
                swap(row[i * 2 + 1], row[hash[t]]);
                hash[t] = i * 2 + 1;
                cnt++;
            }
        }
        return cnt;
    }
};