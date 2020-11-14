#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * 利用 map 的排序性质
 */
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> smap;
    for (int x : arr1) {
        if (smap.find(x) == smap.end()) 
            smap[x] = 1;
        else
            smap[x]++;
    }

    vector<int> res;

    for (int i : arr2) {
        for (int j = 0; j < smap[i]; j++) {
            res.push_back(i);
        }
        smap.erase(i);
    }

    for (auto it = smap.begin(); it != smap.end(); it++) {
        for (int k = 0; k < it->second; k++)
            res.push_back(it->first);
    }
    return res;

}