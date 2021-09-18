#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string nextPermuitation(string str) {
        int n = str.size();
        int i = n - 2;
        while (i > -1) {
            if (str[i] >= str[i+1])
                i--;
            else break;
        }
        if (i == -1) return "END";
        int l = i + 1, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (str[mid] <= str[i]) 
                r = mid - 1;
            else l = mid;
        }
        swap(str[i], str[l]);
        sort(str.begin() + i + 1, str.end());
        return str;
    }
    vector<string> Permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        
        while (s != "END") {
            ans.push_back(s);
            s = nextPermuitation(s);
        }
        return ans;
    }
};