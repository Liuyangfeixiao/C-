#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string sortString(string s){
    vector<int> map(26);
    for (char ch : s) {
        map[ch - 'a']++;
    }

    string res = "";
    while (res.size() < s.size()) {
        for (int i = 0; i < 26; i++) {
            if(map[i] > 0) {
                res += 'a' + i;
                map[i]--;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (map[i] > 0) {
                res += 'a' + i;
                map[i]--;
            }
        }
    }

    return res;
}