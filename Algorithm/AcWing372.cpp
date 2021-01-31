#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;

int n, m;
bool g[N][N], st[N][N];
PII match[N][N];

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

// 核心代码
bool find(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n || st[nx][ny] || g[nx][ny])
            continue;
        st[nx][ny] = true;
        auto t = match[nx][ny];
        if (t.first == 0 || find(t.first, t.second)) {
            match[nx][ny] = {x, y};
            return true;
        }
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = true;
    }

    // 对奇数点做匹配
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 && !g[i][j]) {
                memset(st, false, sizeof st);
                if (find(i, j)) res++; 
            }
        }
    }
    printf("%d", res);
    return 0;
}