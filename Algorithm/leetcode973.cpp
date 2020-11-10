#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*最接近原点的 K 个点*/
/*优先队列*/
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < K; ++i) {
        q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
    }
    int n = points.size();
    for (int i = K; i < n; ++i) {
        int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        if (dis < q.top().first) {
            q.pop();
            q.emplace(dis, i);
        }
    }
    vector<vector<int>> ans;
    while (!q.empty())
    {
        /* code */
        ans.push_back(points[q.top().second]);
        q.pop();
    }
    return ans;
    



}
