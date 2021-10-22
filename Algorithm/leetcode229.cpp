#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 0, cntX = 0, cntY = 0;
        vector<int> ans;

        for (auto& num : nums) {
            if ((cntX == 0 || x == num) && y != num) {
                cntX++;
                x = num;
            }
            else if (cntY == 0 || y == num) {
                cntY++;
                y = num;
            }
            else {
                cntX--;
                cntY--;
            }
        }

        int countX = 0, countY = 0;
        for (auto& num : nums) {
            if (x == num) countX++;
            if (y == num) countY++;
        }

        if (countX > nums.size() / 3) ans.push_back(x);
        if (countY > nums.size() / 3 && x != y) ans.push_back(y);

        return ans;
    }
};