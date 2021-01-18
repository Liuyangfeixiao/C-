#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(string state) {
    queue<string> q;
    unordered_map<string, int> d;
    string end = "12345678x";
    q.push(state);
    d[state] = 0;
    int dx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {}};
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (p == end) return d[p];
        
        int dis = d[p];
        int k = p.find('x');
        int x = k / 3, y = k % 3;

        for (auto t : dx) {
            int dx = x + t[0], dy = y + t[1];
            if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3) {
                swap(p[dx*3 + dy], p[k]);
                if (!d.count(p)) {
                    d[p] = dis + 1;
                    q.push(p);
                }
                swap(p[dx*3 + dy], p[k]);
            }
        }

    }
    return -1;
}


int main() {
    string start;
    char s[2];
    for (int i = 0; i < 9; i++) {
        cin >> s;
        start += *s;
    }

    cout << bfs(start) <<endl;

    return 0;
}