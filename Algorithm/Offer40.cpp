#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (!k) return {};
        priority_queue<int> q;
        for (int i = 0; i < k; ++i) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};