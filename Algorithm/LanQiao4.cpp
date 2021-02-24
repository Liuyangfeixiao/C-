// 网络寻路

#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 100010;
int h[N], e[2*M], ne[2*M], idx;
int visited[N];
int n, m;
int cnt;
int first;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int x, int step) {
    if (step == 3) first = x;
    if (step == 0) {
        cnt++;
        return;
    }
    visited[x] = 1;
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!visited[j] || (step == 1 && j == first)) dfs(j, step-1);
    }
    visited[x] = 0;


}
int main() {
    memset(h, -1, sizeof h);

    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    for (int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof visited);
        dfs(i, 3);
    }

    cout << cnt << endl;
}

