/*买股票的最佳时机*/

#include <iostream>
#include <vector>
using namespace std;


int maxProfit(vector<int>& prices) {
    int sum = 0;
    for (int i = 0; i < prices.size()-1; i++)
    {
        int diff = prices[i] < prices[i+1] ? prices[i+1]-prices[i] : 0;
        sum += diff;
    }
    return sum;
}