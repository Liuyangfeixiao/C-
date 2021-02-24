// 李白打酒

#include <iostream>
using namespace std;
int cnt;

void dfs(int store, int flower, int wine) {
    // 遇店加一倍
    if (store > 0) dfs(store - 1, flower, wine*2);
    // 遇花喝一斗
    if (flower > 1) dfs(store, flower - 1, wine - 1);
    // 最后符合条件
    if (store == 0 && flower == 1 && wine == 1) cnt++;
}


int main() {
    dfs(5, 10, 2);
    printf("%d", cnt);
    return 0;
}