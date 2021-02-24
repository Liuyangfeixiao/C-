// 方块填数

#include <iostream>

using namespace std;

int a[6][6], visited[6][6];
int map[36];
int fr[6], fc[6], fg[6];
int cnt;

// DFS 判断有无越界并输出
void dfs(int x, int y) {
    if (x >= 6) {
        cout << ++ cnt << endl;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                cout << (char)(a[i][j] + 'A') << ' ';
            }
            cout << endl;
        }

        return;
    }

    if (y >= 6){
        dfs(x + 1, 0);
        return;
    }

    if (visited[x][y]) {
        dfs(x, y + 1);
        return;
    }

    for (int i = 0; i < 6; ++i) {
        if (fr[x] & (1 << i) || fc[y] & (1 << i) || fg[map[x * 6 + y]] & (1 << i))
            continue;
        
        fr[x] ^= 1 << i;
        fc[y] ^= 1 << i;
        fg[map[x * 6 + y]] ^= 1 << i;
        visited[x][y] = 1;
        a[x][y] = i;

        dfs(x, y + 1);
        
        // 回溯
        fr[x] ^= 1 << i;
        fc[y] ^= 1 << i;
        fg[map[x * 6 + y]] ^= 1 << i;
        visited[x][y] = 0;
        a[x][y] = 0;
         
    }

    

}

int main() {
    char c, x, y;
    // 输入分组
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> c;
            map[i * 6 + j] = c - '0';
        }
    }

    // 输入已经确定的字母
    int n;
    cin >> n;
    while (n --) {
        cin >> x >> y >> c;
        x -= '0';
        y -= '0';
        c -= 'A';

        a[x][y] = c;
        visited[x][y] = 1;
        fr[x] ^= 1 << c;
        fc[y] ^= 1 << c;
        fg[map[x * 6 + y]] ^= 1 << c;
    }
    // 进行DFS
    dfs(0, 0);

    return 0;

}