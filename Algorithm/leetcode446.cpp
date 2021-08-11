#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        // table[i][diff] 代表以 nums[i] 结尾，公差为 diff 的弱等差子序列个数
        vector<unordered_map<long long, int>> table(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto diff = (long long)nums[i] - nums[j];
                int cnt = 0;
                if (table[j].count(diff))
                    cnt = table[j][diff];
                ans += cnt;
                table[i][diff] += ++cnt;
            }
        }
        return ans;
    }
};