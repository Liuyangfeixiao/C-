#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


bool isIsomorphic(string s, string t) {
    unordered_map<char, char> smap;
    unordered_map<char, char> tmap;
    string tems = "";
    string temt = "";
    char tmp = 'a';
    for (char ch : s) {
        if (smap.count(ch)) {
            tems += smap[ch];
        }
        else {
            smap[ch] = tmp;
            tems += tmp;
            tmp = tmp + 1;
        }
    }
    tmp = 'a';
    for (char ch : t) {
        if (tmap.count(ch)) {
            temt += tmap[ch];
        }
        else {
            tmap[ch] = tmp;
            temt += tmp;
            tmp = tmp + 1;
        }
    }

    return tems == temt;
}
