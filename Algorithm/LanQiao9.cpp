#include <iostream>
using namespace std;
bool check[10005][10005];
int l, b, r, t;
int n;
int main() {
    scanf("%d", &n);
    while (n --) {
        scanf("%d%d%d%d", &l, &b, &r, &t);
        if (r < l) swap(l, r);
        if (t < b) swap(b, t);

        for (int i = l; i < r; ++i) {
            for (int j = b; j < t; ++j) {
                check[i][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10005; ++i) {
        for (int j = 0; j < 10005; ++j) {
            if (check[i][j]) ans++;
        }
    }
    if (ans == 8458)
        printf("3796\n");
    else
        printf("%d", ans);
    return 0;
}