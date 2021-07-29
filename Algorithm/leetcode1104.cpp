#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int level = 1;
        while ((1 << level) < label) {
            level++;
        }
        int target = label;
        int lastLevel = 0;
        int step = level;
        while (step) {
            int nodeOff;
            if (step % 2 == 0) {
                if (step != level)
                    target = (1 << step) - lastLevel;
                nodeOff = (1 << step) - target;
                lastLevel = (nodeOff + 1) / 2;
            }
            else {
                if (step != level)
                    target = (1 << (step-1)) + lastLevel - 1;
                nodeOff = target - (1 << (step - 1)) + 1;
                lastLevel = (nodeOff + 1) / 2;
            }
            ans.push_back(target);
            step--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};