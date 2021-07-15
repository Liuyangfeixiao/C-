#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 排序 + 贪心 O(nlogn)
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] > 1) 
                arr[i] = arr[i-1] + 1;
        }

        return arr[n-1];
    }
    // 计数排序 O(n)
    int Ranging(vector<int>& arr) {
        // 开辟一个数组存放计数
        int n = arr.size();
        vector<int> cnt(n + 1);
        for (auto& x : arr) {
            cnt[min(x, n)]++;
        }

        // 计算缺失的数字
        int miss = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) miss++;
            else miss -= min(miss, cnt[i] - 1);
        }
        // 由于从小到大填满，最后的缺失
        return n - miss;
    }

};