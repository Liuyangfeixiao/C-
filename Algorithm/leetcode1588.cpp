#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> presum(n+1);

        presum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i-1] + arr[i-1];
        }

        int sum = 0;

        vector<int> prepresum(n+1);
        prepresum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prepresum[i] = prepresum[i-1] + presum[i];
        }

        for (int i = 1; i <= n; i+=2) {
            sum += prepresum[n] - prepresum[n-i] - prepresum[i-1];
        }

        return sum;
    }
};