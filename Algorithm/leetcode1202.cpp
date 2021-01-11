#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*并查集的使用*/

    int father[100010];
    int find(int x) // 并查集find
    {
        return x == father[x] ? x : (father[x] = find(father[x]));
    }

    void merge(int x, int y) {
        father[find(x)] = find(y);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        string areastr[100010]; // 并查集中father[x] == x 的节点的集合
        int cnt[100010] = {0}; // areastr[x] 内的第一个未分配元素
        for (int i = 0; i < n; ++i) father[i] = i;

        for (auto i : pairs) merge(i[1], i[0]);

        for(int i = 0; i < n; i++) {
            areastr[find(i)] += s[i];
        }
        for(int i = 0; i < n; ++i) {
            sort(areastr[i].begin(), areastr[i].end());
        }

        for(int i = 0; i < n; ++i) {
            s[i] = areastr[father[i]][cnt[find(i)]++]; // 根据连通图内排序后结果还原字符串
        }

        return s;
    }