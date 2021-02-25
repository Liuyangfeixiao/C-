// 九宫重排
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, int> visited;
string start, ter;
int dx[4] = {0, 0, 1 ,-1};
int dy[4] = {1, -1, 0, 0};

int bfs(string st) {
    queue<string> q;
    q.push(st);
    visited[st] = 0;
    while (!q.empty()) {
        string t = q.front();
        q.pop();

        int k = t.find('.');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string tmp = t;
                swap(tmp[x * 3 + y], tmp[nx * 3 + ny]);
                if (!visited.count(tmp)) {
                    q.push(tmp);
                    visited[tmp] = visited[t] + 1;
                    if (tmp == ter) return visited[tmp];
                }
            }
        }
    }

    return 0;

}

int main() {
    cin >> start;
    cin >> ter;
    
    int ans = bfs(start);
    if (!ans) cout << -1;
    else cout << ans;

}