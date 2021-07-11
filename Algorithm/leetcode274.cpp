#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool check(int mid, vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (citations[i] < mid) ans++;
            else break; 
        }
        return n - ans >= mid;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        
        int l = 0, r = min(n, citations[n-1]);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, citations)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};