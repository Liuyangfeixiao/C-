#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ans;
        ans.push_back(first);
        for (int i = 0; i < n; ++i) {
            int tmp = ans.back()^encoded[i];
            ans.push_back(tmp);
        }
        return ans;
    }
};