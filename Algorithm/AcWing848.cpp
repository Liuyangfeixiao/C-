#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N]; // 入度
int n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

vector<int> topuSort() {
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) q.push(i);
    }

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!(--d[j])) q.push(j);
        }
    }

    return ans;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    vector<int> ans = topuSort();
    if (ans.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
    }else cout << -1;

    return 0;


}

