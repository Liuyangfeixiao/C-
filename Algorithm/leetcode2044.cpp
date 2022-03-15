#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int cmax = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            cmax |= nums[i];
        }
        dfs(0, cmax, 0, nums);
        return cnt;
    }
    void dfs(int index, int cmax, int curVal, vector<int>& nums) {
        if (index == nums.size()) {
            if (curVal == cmax) cnt++;
            return;
        }
        dfs(index+1, cmax, curVal | nums[index], nums);
        dfs(index + 1, cmax, curVal, nums);
    }
private:
    int cnt;
};