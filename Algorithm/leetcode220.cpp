#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 滑动窗口解法
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long> res;
        for (int i = 0; i < n; ++i) {
            auto iter = res.lower_bound(long(nums[i]) - t);
            if (iter != res.end() && *iter <= long(nums[i]) + t)
                return true;
            res.insert(nums[i]);
            if (i >= k) res.erase(nums[i-k]);
        }

        return false;
    }
    
    // 桶排序解法
    int getID(int x, long w) {
        return x < 0 ? (x+1l) / w - 1 : x / w;
    }

    bool contain(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            long x = nums[i];
            int id = getID(x, t+1l);
            if (mp.count(id)) return true;

            if (mp.count(id-1) && abs(x - mp[id-1]) <= t) return true;

            if (mp.count(id+1) && abs(x - mp[id+1]) <= t) return true;

            mp[id] = x;
            if (i >= k) mp.erase(getID(nums[i-k], t+1l));
        }

        return false;
    }
};