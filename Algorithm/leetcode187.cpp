#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10) return {};

        int i = 0;
        unordered_map<string, int> index;
        set<string> ans;
        for (; i <= n - 10; ++i) {
            string tmp = s.substr(i, 10);
            index[tmp]++;
            if (index[tmp] > 1) ans.emplace(tmp);
        }

        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};