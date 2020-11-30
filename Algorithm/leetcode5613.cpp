#include <iostream>
#include <vector>
#include <map>

using namespace std;

int maximum(vector<vector<int>>& accounts) {
    int m = accounts.size();
    if (m == 0) return 0;
    int n = accounts[0].size();
    int smax = 0;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += accounts[i][j];
        }

        smax = max(smax, sum);
    }

    return smax;
}

vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == k) return nums;
    vector<int> ans;
    for (int i = 0; i < n; i++){
        while (!ans.empty() && ans.back() > nums[i] && n - i  > k - ans.size()) {
            ans.pop_back();
        }

        if (ans.size() < k) ans.push_back(nums[i]);
    }

    return ans;
}

int minMoves(vector<int>& nums, int limit) {

}