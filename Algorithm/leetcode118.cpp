#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
        vector<int> tmp(i+1);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) 
                tmp[j] = 1;
            else tmp[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(tmp);
    }
    return ans;
}