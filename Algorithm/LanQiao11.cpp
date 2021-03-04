// 开心的金明
#include <iostream>
using namespace std;
const int N = 30005;
int n, m;
int w[N], v[N], ans[N];

// 开心的金明

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &v[i], &w[i]);
    }
    // 转化为 0 1 背包问题
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= v[i]; j--) {
            ans[j] = max(ans[j], ans[j - v[i]] + v[i] * w[i]);
        }
    }

    printf("%d", ans[n]);
    return 0;

}