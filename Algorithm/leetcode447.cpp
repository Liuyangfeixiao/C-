#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> table;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                double distance = pow(points[i][0] - points[j][0], 2) + 
                                    pow(points[i][1] - points[j][1], 2);
                distance = sqrt(distance);
                if (table[distance])
                    cnt += 2 * table[distance];
                table[distance]++;
            }
            
        }
        return cnt;
    }
};