#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    int match[26] = {};
    for (char c : s) match[c - 'a']++;
    for (char c : t) match[c - 'a']--;
    return all_of(begin(match), end(match), [](int x) {return x == 0;});
}