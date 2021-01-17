#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& land, int r, int c) {
    if (r < 0 || r >= land.size() || c < 0 || c >= land.size()) return 0;

    if (land[r][c] != 0) return 0;
    land[r][c] = 1;
    int cnt = 1; // 更改现场但不恢复现场
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) cnt += dfs(land, r+i, c+j);
        }
    }

    return cnt;
}

vector<int> pondSizes(vector<vector<int>>& land) {
    vector<int> ans;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (land[i][j] == 0) {
                int cnt = dfs(land, i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());

    return ans;
}
