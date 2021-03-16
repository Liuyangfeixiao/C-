#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(vector<int>& candidates, vector<int> ret, int start, int end, int target) {
        if (start > end) return;
        for (int i = start; i <= end; ++i) {
            // if (i != start && candidates[i] == candidates[i-1]) continue;       // 防止重复，去重
            if (candidates[i] > target) {
                break;
            }
            else if (candidates[i] == target) {
                ret.push_back(candidates[i]);
                ans.push_back(ret);
                return;
            }
            else {
                ret.push_back(candidates[i]);
                dfs(candidates, ret, i, end, target - candidates[i]);
                ret.pop_back();
            }

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> ret;
        dfs(candidates, ret, 0, n-1, target);
        return ans;
    }
};