#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int ans = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (people[l] + people[r] > limit)
                r--;
            else {
                l++;
                r--;
            }
            ans++;
        }
        return ans;
    }
};
