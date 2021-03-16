#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> arr(n+m);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                arr[i+j+1] += x * y;
            }
        }
        int s = 0;
        for (int i = m + n - 1; i >= 0; --i) {
            arr[i] += s;
            s = arr[i] / 10;
            arr[i] = arr[i] % 10;
        }

        int index = arr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back('0' + arr[index]);
            index++;
        }
        return ans;

    }
};
