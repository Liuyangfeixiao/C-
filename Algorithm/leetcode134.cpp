#include <iostream>
#include <vector>
using namespace std;


/*根据数学证明，如果 x 无法到达 y, 那么 x y 中的任何一个站点都无法到达 y*/
/*所以当探测到不能达到 y 时，直接从 y + 1 开始探测*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0;
    while (i < n) {
        int sumOfGas = 0, sumOfCost = 0;
        int cnt = 0;
        while (cnt < n) {
            int j = (i + cnt) % n;
            sumOfGas += gas[j];
            sumOfCost += cost[j];
            if (sumOfCost > sumOfGas) {
                break;
            }
            cnt++;
        }
        if (cnt == n) {
            return i;
        } else {
            i = i + cnt + 1;
        }
    }
    return -1;
    }

