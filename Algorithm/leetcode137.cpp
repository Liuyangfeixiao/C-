#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto x : nums) {
            if (map.count(x)) map[x]++;
            else map[x] = 1;
        }
        int ans = 0;
        for (auto it : map) {
            if (it.second == 1) {
                ans = it.first;
                break;
            }
        }
        return 0;
    }
};