#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int n = stones.size();

    priority_queue<int> q;
    for (int x : stones) {
        q.push(x);
    }
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        if (a > b) q.push(a - b);
    }
    return q.empty() ? 0 : q.top();

}