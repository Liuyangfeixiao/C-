#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string S) {
    unordered_map<char, int> map;
    for(int i = 0; i < S.size(); i++) {
        map[S[i]] = i;
    }
    int start = 0;
    int end = 0;
    vector<int> res;

    for (int i = 0; i < S.size(); i++) {
        end = max(end, map[S[i]]);
        if (end == i) {
            res.push_back(end - start +1);
            start = end+1;
        }
    }


}