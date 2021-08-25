#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(int start, vector<vector<int>>& graph) {
        int n = graph.size();
        if (start == n-1){
            ans.push_back(tmp);
            return;
        }

        for (auto& x : graph[start]) {
            
            tmp.push_back(x);
            dfs(x, graph);
            tmp.pop_back();
            
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        tmp.push_back(0);
        dfs(0, graph);
        return ans;
    }
};