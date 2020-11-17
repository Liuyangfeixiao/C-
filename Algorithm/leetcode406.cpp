#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
        return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
    });
    int n = people.size();
    vector<vector<int>> ans(n);
    for (const vector<int>& person : people) {
        int spaces = person[1] + 1;
        for (int i = 0; i < n; ++i) {
            if (ans[i].empty()) {
                spaces--;
                if (!spaces) {
                    ans[i] = person;
                    break;
                }
            }
        }
    }
    return ans;
}

/*小套路，一般涉及排序的数对，根据第一个元素正向排序，第二个元素反向排序往往能够简化解题过程*/

vector<vector<int>> reconstruct(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
        return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
    });
    vector<vector<int>> ans;
    for (const vector<int>& person : people) {
        ans.insert(ans.begin()+person[1], person);
    }

    return ans;
}
