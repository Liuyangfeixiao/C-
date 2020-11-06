#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int count(int x) {
    int cnt = 0;
    while (x) {
        x &= (x-1);
        cnt++;
    }
    return cnt;
}

/*如果在类中要注意参数不匹配*/
bool cmp(int a, int b) {
    int cnta = count(a);
    int cntb = count(b);

    return cnta != cntb ? cnta < cntb : a < b;
}

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    return arr;
}
