#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void dfs(int start, int end, int target, int k) {
        if (start > end) return;
        for (int i = start; i <= end; ++i) {
            if (i > target) break;
            else if (i == target) {
                tmp.push_back(i);
                if (tmp.size() == k) {
                    ans.push_back(tmp);
                }
                tmp.pop_back();
                
            }
            else {
                tmp.push_back(i);
                dfs(i+1, end, target-i, k);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(0, 9, n, k);
        return ans;
    }
};