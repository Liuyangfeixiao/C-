#include <iostream>
#include <vector>
using namespace std;

// 贪心，连续3个0一组可以种一棵树
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int m = flowerbed.size();
    if (!m) {
        return false;
    }
    vector<int> tmp = flowerbed;
    tmp.insert(tmp.begin(), 0);
    tmp.insert(tmp.end(), 0);

    vector<int> dp(tmp.size(), 0);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i < tmp.size(); ++i) {
        if (tmp[i] == 0) {
            dp[i] = dp[i-1] + 1;
        } else dp[i] = 0;

        if (dp[i] >= 3) {
                ans++;
                dp[i] = 1;
            }

    }

    return ans >= n;
}