#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // 构造相邻点
        unordered_map<int, vector<int>> table;
        for (auto& v : adjacentPairs) {
            table[v[0]].push_back(v[1]);
            table[v[1]].push_back(v[0]);
        }
        // 判断首端点
        int first;
        for (auto& it : table) {
            if (it.second.size() == 1) {
                first = it.first;
                break;
            }
        }
        // 通过判断上一个点的相邻点位置是否已经确定从而确定本点元素
        vector<int> ans(adjacentPairs.size() + 1);
        ans[0] = first;
        ans[1] = table[first][0];
        for (int i = 2; i < ans.size(); ++i) {
            auto& pos = table[ans[i-1]];
            ans[i] = ans[i-2] == pos[0] ? pos[1] : pos[0];
        }

        return ans;
    }
};