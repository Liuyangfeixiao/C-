#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> table;
        int n = wall.size();
        int width = 0;
        for (auto x : wall[0]) {
            width += x;
        }
        for (auto& wide : wall) {
            int sum = 0;
            for (auto x : wide) {
                sum += x;
                if (table.count(sum)) 
                    table[sum]++;
                else table[sum] = 1;
            }
        }

        int cmin = n;
        for (auto it : table) {
            if (it.first == width) continue;
            cmin = min(cmin, n - it.second);
        }
        return cmin;
    }
};