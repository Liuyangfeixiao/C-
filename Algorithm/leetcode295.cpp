#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> cmax;   // max heap
    priority_queue<int, vector<int>, greater<int>> cmin;    // min heap
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        cmax.push(num);
        cmin.push(cmax.top()), cmax.pop();

        if (cmax.size() < cmin.size()) {
            cmax.push(cmin.top()), cmin.pop();
        }
    }
    
    double findMedian() {
        return cmax.size() == cmin.size() ? (cmax.top() + cmin.top()) * 0.5 : cmax.top();
    }
};