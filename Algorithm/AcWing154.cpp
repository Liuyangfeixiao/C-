#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 输出每个滑动窗口中的最大值与最小值
const int N = 1e6 + 10;
int a[N], q[N], hh, tt = -1;
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i - k + 1 > q[hh]) hh++;        // 判断队列头是否越界
        while (hh <= tt && a[i] <= a[q[tt]]) tt--;     // 将窗口内小于此数字出队
        q[++tt] = i;                        // 将此数字进队
        if (i + 1 >= k) printf("%d ", a[q[hh]]);    // 输出最大值
    }
    printf("\n");
    hh = 0; tt = -1;
    for (int i = 0; i < n; ++i) {
        if (i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[i] >= a[q[tt]]) tt--;
        q[++tt] = i;
        if (i + 1 >= k) printf("%d ", a[q[hh]]);

    }
    return 0;
}
