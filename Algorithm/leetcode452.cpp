#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }
    int n = points.size();

    sort(points.begin(), points.end(), [](vector<int>& A, vector<int>& B) {
        return A[1] < B[1];
    });

    int count = 1;
    int pos = points[0][1];
    for (int i = 1; i < n; i++) {
        if (pos < points[i][0]) {
            count++;
            pos = points[i][1];
        }
    }
    return count;
}