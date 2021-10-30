#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum ^= nums[i];
        }
        // 其中某位 一个是0， 一个是1，按照此位不同的值分组进行异或
        int offset = 0;
        while (((1 << offset) & sum) == 0) {
            offset++;
        }
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if ((nums[i] & (1 << offset)) == 0)
                x ^= nums[i];
            else y ^= nums[i];
        }

        return {x, y};
    }
};