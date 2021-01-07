#include <iostream>
#include <vector>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    int province = isConnected.size();
    vector<int> visited(province);
    int circle = 0;
    for (int i = 0; i < province; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, province, i);
            circle++;
        }
    }
    return circle;
}

void dfs(vector<vector<int>>& isConnnected, vector<int>& visited, int province, int i) {
    for (int j = 0; j < province; j++) {
        if (isConnnected[i][j] && !visited[j]) {
            visited[j] = 1;
            dfs(isConnnected, visited, province, j);
        }
    }
}