#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            if (!isdigit(tokens[i][0]) && tokens[i].size() == 1) {
                int num2 = nums.back();
                nums.pop_back();
                int num1 = nums.back();
                nums.pop_back();
                int ans = 0;
                switch (tokens[i][0]) {
                    case '+':
                        ans = num1 + num2;
                        break;
                    case '-' :
                        ans = num1 - num2;
                        break;
                    case '*' :
                        ans = num1 * num2;
                        break;
                    case '/' :
                        ans = num1 / num2;
                        break;
                    default :
                        break;
                }
                nums.push_back(ans);
            }
            else {
                int num = 0;
                int sign = 1;   // 防止出现负数
                for (int j = 0; j < tokens[i].size(); ++j) {
                    if (tokens[i][j] == '-') {
                        sign = -1;
                        continue;
                    }
                    num = num * 10 + (tokens[i][j] - '0');
                }
                nums.push_back(num * sign);
            }
        }

        return nums[0];
    }
};