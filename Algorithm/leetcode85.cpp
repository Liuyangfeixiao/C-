#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int getArea(int row, vector<vector<int>> &height)
    {
        int n = height[row].size() + 2;
        vector<int> tmp(n, 0);      // 总是需要添加两个哨兵作为对左右边界的处理

        for (int i = 1; i < n - 1; ++i)
        {
            tmp[i] = height[row][i - 1];
        }
        int area = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && tmp[i] < tmp[st.top()])
            {
                int h = tmp[st.top()];
                st.pop();
                area = max(area, (i - st.top() - 1) * h);
            }
            st.push(i);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            for (int i = m - 1; i >= 0; --i)
            {
                if (matrix[i][j] == '1')
                {
                    height[i][j] = (i == m - 1) ? 1 : height[i + 1][j] + 1;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            ret = max(ret, getArea(i, height));
        }

        return ret;
    }
};
