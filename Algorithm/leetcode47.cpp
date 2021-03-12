#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
public:
    void dfs(vector<int>& nums, vector<int>& cur, vector<int>& visited, int start, int end) {
        if (start == end) {
            ret.push_back(cur);
            return;
        }
        
        for (int i = 0; i < end; ++i) {
            if (visited[i] || i != 0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
            visited[i] = 1;
            cur.push_back(nums[i]);
            dfs(nums, cur, visited, start+1, end);
            visited[i] = 0;
            cur.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<int> visited(n, 0);
        dfs(nums, cur, visited, 0, n);
        return ret;
    }
};