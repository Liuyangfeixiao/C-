#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int len = 0;
        ans.push_back(t);
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1])
                l = ans.size() - len;
            else l = 0;
            r = ans.size();
            len = r - l;
            for (int j = l; j < r; ++j) {
                vector<int> v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};