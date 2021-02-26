#include <iostream>
using namespace std;

const int N = 100005;
int data[N];
int n;


int main() {
    int j;
    scanf("%d", &n);
    // 计数排序
    while (~scanf("%d", &j)) {
        ++data[j];
    }
    int i = 0;
    for (i = 0; !data[i]; ++i);

    int x = 0, y = 0;
    for (int j = i; !x || !y; j++) {
        if (data[j] == 0) x = j;
        if (data[j] == 2) y = j;
    }

    printf("%d %d", x, y);

    return 0;

}