#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int>& father, int x) {
        return x == father[x] ? x : find(father, father[x]);
    }
    
    void merge(vector<int>& father, int u, int v) {
        u = find(father, u);
        v = find(father, v);
        if (u == v) return;
        father[v] = u;
    }

    bool same(vector<int>& father, int x, int y) {
        x = find(father, x);
        y = find(father, y);
        if (x == y) return true;
        return false;
    }

    bool check(string s1, string s2) {
        int n = s1.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) res++;

            if (res > 2) return false;
        }
        return true;
    }


    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> father(n);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (same(father, i, j)) continue;

                if (check(strs[i], strs[j])) {
                    merge(father, i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (father[i] == i) res++;
        }

        return res;

    }
};