#include <iostream>
#include <vector>
using namespace std;

// 并查集模板修改
class Unite{
public:
    vector<int> father;
    // reb 为冗余边，setCount 为连通量的数量
    int reb, setCount;
    Unite(int n) : father(n), setCount(n), reb(0) {};
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int x) {
        return x == father[x] ? x : father[x] = find(father[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) reb++;
        else {
            father[y] = x;
            setCount--;
        }
    }
};



class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        Unite un(n);
        un.init(n);
        for (auto& t : connections) {
            un.join(t[0], t[1]);
        }

        int res = un.reb - un.setCount + 1;
        if (res >= 0) return un.setCount - 1;
        else return -1;
    }
};