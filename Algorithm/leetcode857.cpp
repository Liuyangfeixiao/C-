#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        // 关键在于 totalC * (quality[i] / totalQ) >= wage[i]
        // 也就是 (wage[i] / quality[i]) * totalQ <= totalC
        // (wage[i] / quality[i]) 是所选K个元素中最大的
        // 所以我们要在保证 (wage[i] / quality[i]) 尽可能小的同时使 totalQ 最小
        sort(h.begin(), h.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
        });

        double res = 1e9;
        int totalq = 0;
        priority_queue<int, vector<int>, less<int>> q;

        for (int i = 0; i < k-1; ++i) {
            int index = h[i];
            totalq += quality[index];
            q.push(quality[index]);
        }

        for (int i = k-1; i < n; ++i) {
            int idx = h[i];
            totalq += quality[idx];
            q.push(quality[idx]);
            double totalc = ((double) wage[idx] / quality[idx]) * totalq;
            res = min(res, totalc);
            totalq -= q.top();
            q.pop();
        }
        return res;

    }
};