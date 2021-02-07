#include <iostream>
#include <queue>
using namespace std;

// 使用双端队列来存储队列中最大元素的值
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q.empty()) return -1;

        return dq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int value = q.front();
        if (value == dq.front()) {
            dq.pop_front();
        }
        q.pop();
        return value;
    }

private:
    queue<int> q;
    deque<int> dq;
};