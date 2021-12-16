#define _USE_MATH_DEFINES
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int sameCnt = 0;
        vector<double> polarDegrees;
        for (auto & point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                sameCnt++;
                continue;
            }
            double degree = atan2(point[1] - location[1], point[0] - location[0]);
            polarDegrees.emplace_back(degree);
        }
        sort(polarDegrees.begin(), polarDegrees.end());

        int m = polarDegrees.size();
        for (int i = 0; i < m; ++i) {
            polarDegrees.emplace_back(polarDegrees[i] + 2 * M_PI);
        }

        int maxCnt = 0;
        int right = 0;
        double degree = angle * M_PI / 180;
        for (int i = 0; i < m; ++i) {
            while (right < polarDegrees.size() && polarDegrees[right] <= polarDegrees[i] + degree) {
                right++;
            }
            maxCnt = max(maxCnt, right - i);
        }
        return maxCnt + sameCnt;
    }
};