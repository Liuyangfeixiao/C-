#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.find(sum - k) != m.end()) {
                res += m[sum - k];
            }
            m[sum]++;
        }
        return res;
    }
};