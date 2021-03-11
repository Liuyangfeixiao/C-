#include <iostream>
#include <vector>
using namespace std;

// dfs, 判断剪枝情况
class Solution {
private:
    string ans;
    vector<string> tmp;
    vector<string> ret;
public:
    // 主要确定剪枝的情况
    void dfs(string& s, int start, int end, int seg) {
        if (seg == 4) {
            for (int i = 0; i < 3; ++i) {
                ans += tmp[i];
                ans += ".";
            }
            ans += tmp[3];
            ret.push_back(ans);
            ans.clear();
        }
        int num = 0;
        if (s[start] == '0') {
            int left = end - start;
            if (left > (4 - seg-1) * 3 || left < (4 - seg-1))
                return;
            else {
                tmp.push_back(s.substr(start, 1));
                dfs(s, start+1, end, seg+1);
                tmp.pop_back();
            }
        }
        else {
            for (int i = 0; i < 3; ++i) {
                num = num * 10 + (s[start+i] - '0');
                int left = end - start - i;
                if (left > (4 - seg - 1) * 3) continue;
                else if (left < (4 - seg -1)) return;
                if (num > 0xff) return;
                else {
                    tmp.push_back(s.substr(start, i+1));
                    dfs(s, start+i+1, end, seg+1);
                    tmp.pop_back();
                }
                
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        dfs(s, 0, n-1, 0);
        return ret;
    }
};