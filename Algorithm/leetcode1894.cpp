#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0; 
        for (int i = 0; i < n; ++i) {
            sum += chalk[i];
        }

        int k = k % sum;

        for (int i = 0; i < n; ++i) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }

        return 0;
    }
};