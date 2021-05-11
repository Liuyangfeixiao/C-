#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum ^= i;
        }
        vector<int> perm(n);
        for (int i = 1; i < n-1; i += 2) {
            sum ^= encoded[i];
        }
        perm[0] = sum;
        for (int i = 1; i < n; ++i) {
            perm[i] = perm[i-1] ^ encoded[i-1];
        }
        return perm;
    }
};
