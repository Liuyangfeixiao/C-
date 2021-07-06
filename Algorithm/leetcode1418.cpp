#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> table;
        set<string> dish;
        for (auto& ord : orders) {
            dish.insert(ord[2]);
            table[stoi(ord[1])][ord[2]]++;
        }
        int n = table.size();
        vector<string> head(dish.begin(), dish.end());
        head.insert(head.begin(), "Table");
        
        vector<vector<string>> ans;
        ans.push_back(head);
        for (auto& it : table) {
            vector<string> t;
            t.push_back(to_string(it.first));
            for (auto i = dish.begin(); i != dish.end(); ++i) {
                t.push_back(to_string(it.second[*i]));
            }
            ans.push_back(t);
        }
        return ans;

    }
};