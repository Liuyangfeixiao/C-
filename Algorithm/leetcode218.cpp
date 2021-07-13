#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;

        for (auto& build : buildings) {
            all.insert(make_pair(build[0], -build[2]));
            all.insert(make_pair(build[1], build[2]));
        }

        multiset<int> heights({0});
        vector<int> last = {0, 0};
        vector<vector<int>> ans;

        for (auto& p : all) {
            if (p.second < 0) heights.insert(-p.second);
            else heights.erase(heights.find(p.second));

            auto maxH = *heights.rbegin();

            // 如果当前最大高度不等于上一个高度，说明是转折点
            if (last[1] != maxH) {
                // 更新 last
                last[0] = p.first;
                last[1] = maxH;
                ans.push_back(last);
            }

        }
        return ans;
    }
};