#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 没有任何礼包
        int res = 0, n = needs.size();
        for (int i = 0; i < n; ++i) {
            res += price[i] * needs[i];
        }

        for (auto& sp : special) {
            bool isValid = true;
            for (int i = 0; i < n; ++i) {
                if (sp[i] > needs[i]) isValid = false;
                needs[i] -= sp[i];
            }

            if (isValid) {
                res = min(res, shoppingOffers(price, special, needs) + sp.back());
            }

            for (int i = 0; i < n; ++i) {
                needs[i] += sp[i];
            }
        }

        return res;
    }
};