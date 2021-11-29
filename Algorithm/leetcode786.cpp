#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        for (int i = 1; i < n; ++i) {
            q.emplace(0, i);
        }

        for (int _ = 1; _ < k; ++_) {
            auto [i, j] = q.top();
            q.pop();

            if (i + 1 < j) {
                q.emplace(i+1, j);
            }
        }

        return {arr[q.top().first], arr[q.top().second]};
    }
    // 二分查找
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0.0, r = 1.0;
        while (true) {
            double mid = (l + r) / 2;
            int cnt = 0, i = -1;
            // 记录最大的分数
            int x = 0, y = 1;

            for (int j = 1; j < n; ++j) {
                while ((double)arr[i+1] / arr[j] < mid) {
                    i++;
                    if (arr[i] * y > arr[j] * x) {
                        x = arr[i];
                        y = arr[j];

                    }
                }
                cnt += i + 1;
            }
            if (cnt == k) return {x, y};

            if (cnt < k) l = mid;
            else r = mid;

        }
    }
};