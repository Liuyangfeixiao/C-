// 趣味算式

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10010;
const int M = 1e5 + 10;
int father[N];
int n, m;
struct node {
    int x, y, d;
} s[M];


void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int find(int x) {
    return x == father[x] ? x : father[x] = find(father[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    father[v] = u;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        s[i] = {u, v, w};
    }
    sort(s, s+m, [](const node& a, const node& b) { return a.d > b.d;});
    int pre = -1, ans = 0;
    for (int i = 0; i < m; ++i) {
        bool bridge = merge(s[i].x, s[i].y);
        if (bridge && pre != s[i].d) {
            ans++;
            pre = s[i].d;
        }
    }
    printf("%d", ans);

    return 0;
}