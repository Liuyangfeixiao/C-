#include <iostream>
using namespace std;

const int N = 50005;
int f[3*N];  // 3 个并查集，分别表示同类，天敌，捕食
int n, k;

void init() {
    for (int i = 1; i <= 3*n; ++i) {
        f[i] = i;
    }
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    f[v] = u;
}



int main() {
    cin >> n >> k;
    int m, u, v;
    int ans = 0;
    init();
    while (k--) {
        scanf("%d", &m);
        scanf("%d%d", &u, &v);
        if (u > n || v > n) ans++;
        else if (m == 1) {
            if (find(v) == find(u + n) || find(v) == find(u + n + n))
                ans++;
            else {
                merge(u, v);
                merge(u + n, v + n);
                merge(u + n + n, v + n + n);
            }
        }
        else {
            if (u == v || find(u) == find(v) || find(u + n) == find(v))
                ans++;
            else {
                merge(u, v+n);
                merge(v, u+n+n);
                merge(v + n + n, u + n);
            }
        }
    }

    printf("%d", ans);
    return 0;
}