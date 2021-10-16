#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string path;

    void dfs(string& num, long long sum, long long lastnum, int index, int target) {
        if (index == num.size()) {
            if (sum == target) ans.push_back(path);
            return;
        }

        string tmp;
        for (int i = index; i < num.size(); ++i) {
            tmp += num[i];
            long long cnum = stoll(tmp);
            if (cnum > INT32_MAX) break;
            if (index == 0) {
                path += tmp;
                dfs(num, cnum, cnum, i + 1, target);
                path.erase(path.size() - tmp.size());
            }
            else {
                path += "+" + tmp;
                dfs(num, sum + cnum, cnum, i + 1, target);
                path.replace(path.size() - tmp.size() - 1, 1, "-");
                dfs(num, sum - cnum, -cnum, i + 1, target);
                path.replace(path.size() - tmp.size() - 1, 1, "*");
                dfs(num, sum - lastnum + lastnum * cnum, lastnum * cnum, i + 1, target);
                path.erase(path.size() - tmp.size() - 1);
            }
            if (tmp == "0") break;
        }
    }
    vector<string> addOperators(string num, int target) {
        dfs(num, 0, 0, 0, target);
        return ans;
    }
};