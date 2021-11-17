#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> index(n);
        for (int i = 0; i < n; ++i) {
            for (auto c : words[i]) {
                index[i] |=  1 << (c - 'a');
            }
        }
        int cmax = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((index[i] & index[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    cmax = max(cmax, len);
                }
            }
        }

        return cmax;
    }
};