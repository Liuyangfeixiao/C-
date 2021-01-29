#include <iostream>
using namespace std;
const int N = 20010, M = 200010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int color[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
// 染色法判别二分图，有附加条件
bool dfs(int limit, int u, int c) {
    color[u] == c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (w[i] <= limit) continue; // use the edges whose weights greater than limit to construct the binary graph
        if (!color[j]) {
            if (!dfs(limit, j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;

    }
    return true;
}

bool check(int x) {
    memset(color, 0, sizeof color);
    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(x, i, 1)) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d", l);
    return 0;
}