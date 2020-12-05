#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*贪心算法加桶排序*/
/*假设出现次数最多的任务数为 x，那么最多有 (x-1)*(n+1) + m，m为最后一个桶的数量，也即出现次数最多的任务类型的数量*/
int leastInterval(vector<char>& tasks, int n) {
    int m = tasks.size();
    if (n == 0) return 0;
    vector<int> count(26, 0);
    for (char& ch : tasks) {
        count[ch - 'A']++;
    }
    sort(count.begin(), count.end(), [](int a, int b){return a > b;});
    int x = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] == count[0]) x++;
        else break;
    }

    return max((count[0] - 1) * (n + 1) + x, (int)tasks.size() );
}