#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        vector<int> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            unordered_set<int> rout;
            int pos = i;
            while (1) {
                int nextpos = ((pos + nums[pos]) % n + n) % n;
                if (nextpos == pos || nums[pos] * nums[nextpos] < 0)
                    break;
                if (rout.count(nextpos)) return true;

                rout.insert(nextpos);
                visited[nextpos] = 1;
                pos = nextpos;
            }
        }

        return false;
    }
};