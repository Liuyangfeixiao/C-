#include <iostream>
#include <vector>
using  namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += (!grumpy[i]) * customers[i];
        }
        int inc = 0;
        for (int i = 0; i < X; ++i) {
            inc += grumpy[i] * customers[i];
        }
        int maxinc = inc;
        for (int i = X; i < n; i++) {
            inc = inc + grumpy[i] * customers[i] - grumpy[i-X] * customers[i-X];
             maxinc = max(maxinc, inc);
        }

        return total + maxinc;
    }

};