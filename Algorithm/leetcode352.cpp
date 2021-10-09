#include <vector>
#include <map>
#include <set>
using namespace std;
// 并查集实现
class SummaryRanges {
private:
    static constexpr int N = 1e4 + 5;
    vector<int> father = vector<int>(N, 0);
    vector<int> exist = vector<int>(N, 0);
    vector<int> rightBound = vector<int>(N, 0);
    set<int> st = set<int>();
    int find(int x) {
        return x == father[x] ? x : father[x] = find(father[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            father[y] = x;
            rightBound[x] = rightBound[x] < rightBound[y] ? rightBound[y] : rightBound[x];
            st.erase(y);
        }
    }
public:
    SummaryRanges() {
        for(int i = 0; i < 10001; i++){
            father[i] = i;
            rightBound[i] = i;
        }
    }

    void addNum(int val) {
        if (exist[val]) return;

        exist[val] = true;
        if (val > 0 && exist[val-1]) {
            merge(val-1, val);
        }
        if (exist[val+1]) {
            merge(val, val+1);
        }
        if (find(val) == val)
            st.insert(val);
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto& num:st) {
            if (find(num) == num) {
                ret.push_back({num, rightBound[num]});
            }
        }
        return ret;
    }
};