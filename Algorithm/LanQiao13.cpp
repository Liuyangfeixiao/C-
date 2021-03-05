#include <iostream>
using namespace std;

string df[10] = {"ling", "yi", "er", "san", "si","wu","liu","qi","ba","jiu"};
string s;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int len = s.size();
    bool bk = false;
    for (int i = 0; i < len; ++i) {     // 遍历每一位
        int p;
        p = s[i] - '0';
        if (p) {
            bk = false;
            if (i != 0 && s[i-1] - '0' == 0) cout << "ling ";   // 处理前面是0的情况

            if ((len - i) % 4 == 2 && p == 1 && i == 0) // 对于首位判断是否为 10
            {
                cout << "shi ";
                continue;
            }

            cout << df[p] << " ";       // 输出这个数
            if ((len - i) % 4 == 2) cout << "shi "; // 判断位数
            if ((len - i) % 4 == 3) cout << "bai ";
            if ((len - i) % 4 == 0) cout << "qian ";

        }

        if ((len-i) % 4 == 1) {
            if ((len-i) / 4 == 2) {
                bk = true;
                cout << "yi ";      // 判断是否是亿
            }
            if (bk == false && (len-i)/4 == 1) {    // 判断是否是万
                cout << "wan ";
            }
        }
    }

    return 0;
}