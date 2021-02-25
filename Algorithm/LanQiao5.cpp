// 阶乘计算
#include <iostream>
using namespace std;
int a[10005];
int n;

int main() {
    cin >> n;
    a[0] = 1;
    int s, c = 0;
    for (int i = 2; i <=n; ++i) {
        for (int j = 0; j < 10000; ++j) {
            s = a[j] * i + c;
            a[j] = s % 10;
            c = s / 10;
        }
    }

    for (int i = 10000; i >= 0; i--) {
        if (a[i]) {
            for (int j = i; j >= 0; --j) {
                cout << a[j];
            }
            break;
        }
    }

    return 0;
}