#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans.push_back({i, j});
        }
    }

    sort(ans.begin(), ans.end(), [&](const vector<int>& a, const vector<int>& b) {
        int a1 = abs(a[0] - r0) + abs(a[1] - c0);
        int b1 = abs(b[0] - r0) + abs(b[1] - c0);

        return a1 < b1;
    });

    return ans;

}
/*桶排序，按照曼哈顿距离分桶*/
int dist(int r1, int c1, int r2, int c2) {
    return abs(r1-r2) + abs(c1-c2);
}
vector<vector<int>> allCellDist(int R, int C, int r0, int c0) {
    int maxDist = max(r0, R-1-r0) + max(c0, C-1-c0);
    vector<vector<vector<int>>> bucket(maxDist + 1);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int d = dist(i, j, r0, c0);
            vector<int> tmp = {i, j};
            bucket[d].push_back(move(tmp)); // move 将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝
        }
    }

    vector<vector<int>> res;

    for (int i = 0; i <= maxDist; i++) {
        for (auto it : bucket[i]) {
            res.push_back(it);
        }
    }
    return res;
}