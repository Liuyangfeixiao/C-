#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }
        vector<int> d;
        for (auto& val : arr) {
            if (pos.count(val)) {
                auto it = lower_bound(d.begin(), d.end(), pos[val]);
                if (it != d.end()) {
                    *it = pos[val];
                }
                else {
                    d.push_back(pos[val]);
                }
            }
        }

        return n - d.size();
    }
};