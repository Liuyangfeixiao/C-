#include <iostream>
using namespace std;
const int N = 30;
int ans[N];
int n;

void dfs(int step, int start) {
    if (step == n) {
        int sum = 1, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            sum *= ans[i];
        }
        for (int i = 0; i < n; ++i) {
            sum2 += sum / ans[i];
        }
        if (sum == sum2) {
            for (int i = 0; i < n; ++i) {
                printf("1/%d " , ans[i]);
            }
            printf("\n");
        }
    }
    else {
        for (int i = start; i < 30; ++i) {
            ans[step] = i;
            dfs(step+1, i + 1);
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(0, 2);
    return 0;
}