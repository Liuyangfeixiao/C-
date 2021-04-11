#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1);
        long answer = 1;
        while (n--) {
            answer = q.top();
            q.pop();
            for (int x : primes) {
                q.push(answer * x);
            }
            while (!q.empty() && answer == q.top())
                q.pop();
            
        }
        return answer;
    }
};