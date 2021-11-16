#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT32_MAX;
        int right = INT32_MIN;
        int top = INT32_MIN;
        int bottom = INT32_MAX;

        int sum = 0;
        set<pair<int, int>> index;
        
        for (auto& re : rectangles) {
            left = min(re[0], left);
            bottom = min(re[1], bottom);
            right = max(right, re[2]);
            top = max(top, re[3]);

            sum += (re[2] - re[0]) * (re[3] - re[1]);

            if (index.count({re[0], re[1]})) {
                index.erase({re[0], re[1]});
            }
            else index.insert({re[0], re[1]});

            if (index.count({re[0], re[3]})) {
                index.erase({re[0], re[3]});
            }
            else index.insert({re[0], re[3]});

            if (index.count({re[2], re[3]})){
                index.erase({re[2], re[3]});
            }
            else index.insert({re[2], re[3]});

            if (index.count({re[2], re[1]})){
                index.erase({re[2], re[1]});
            }
            else index.insert({re[2], re[1]});
        }

        if (index.size() == 4 && index.count({left, bottom}) && index.count({left, top}) &&
            index.count({right, top}) && index.count({right, bottom})) {
            return (right - left) * (top - bottom) == sum;
        }

        return false;
    }
};