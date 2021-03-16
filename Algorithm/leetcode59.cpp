#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int up = 0, down = n-1;
        int left = 0, right = n-1;
        int i = 1;
        while (i <= n*n) {
            for (int j = left; j <= right; ++j) {
                ans[up][j] = i;
                i++;
            }
            up++;
            if (up > down) break;
            for (int j = up; j <= down; ++j) {
                ans[j][right] = i;
                i++;
            }
            right--;
            if (right < left) break; 
            for (int j = right; j >= left; --j) {
                ans[down][j] = i;
                i++;
            }
            down--;
            if (up > down) break;
            for (int j = down; j >= up; --j) {
                ans[j][left] = i;
                i++;
            }
            left++;
            if (left > right) break;
        }

        return ans;
    }
};