#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int f[N];
int n, m;
string cm;

void init() {
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    f[b] = a;
}

bool query(int u, int v) {
    return find(u) == find(v);
}

int main() {
    cin >> cm;
    int a, b;
    while(m--) {
        scanf("%c", &cm);
        if (cm == "Q") {
            scanf("%d%d", &a, &b);
            if (query(a, b)) puts("Yes");
            else puts("No");
        }
        else if (cm == "M") {
            scanf("%d%d", &a, &b);
            join(a, b);
        }
    }
    return 0;
}