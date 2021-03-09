#include <iostream>
using namespace std;

// 
class Solution {
public:
    int translateNum(int num) {
        int next = num % 10;
        int dp1 = 1, dp2 = 1;
       
        while (num) {
             num /= 10;
            int t = num % 10;
            if (t*10 + next < 26 && t * 10 >= 10) {
                int tmp = dp1;
                dp1 = dp1 + dp2;
                dp2 = tmp;
                next = t;
            }
            else {
                dp2 = dp1;
                next = t;
            }
        }

        return dp1;
    }
};