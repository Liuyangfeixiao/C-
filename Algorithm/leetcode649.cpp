#include <iostream>
#include <queue>
using namespace std;

string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> rq;
    queue<int> dq;
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            rq.push(i);
        else
            dq.push(i);
    }
    while (!rq.empty() && !dq.empty()) {
        int rindex = rq.front();
        rq.pop();
        int dindex = dq.front();
        dq.pop();
        if (rindex < dindex)
            rq.push(rindex + n);
        else
            dq.push(dindex + n);
    }

    return rq.empty() ? "Dire" : "Radient";
}