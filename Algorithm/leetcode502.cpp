#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<PII> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());
        
        // 利用堆来维护之前遍历过的更小的值，避免了再次搜索遍历的时间
        priority_queue<int> q;
        int i = 0;
        while (k) {
            while (i < n && arr[i].first <= w) {
                q.push(arr[i].second);
                i++;
            }
            if (!q.empty()) {
                w += q.top();
                q.pop();
                k--;
            }
            else break;
        }

        return w;
    }
};