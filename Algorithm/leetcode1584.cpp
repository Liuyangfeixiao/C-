#include <iostream>
#include <vector>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> dist(n, vector<int>(n, 0));
    vector<bool> flag(n, false);
    vector<int> dis(n, INT32_MAX);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        
        }
    }
    int res = 0;
    
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 0; j < n; j++) {
            if (!flag[j] && (t == -1 || dis[t] > dis[j])) t = j;
        }
        flag[t] = true;
        if (i)
            res += dis[t];

        for (int k = 0; k < n; k++) if (!flag[k]) dis[k] = min(dis[k], dist[t][k]);

    }
    return res;
}