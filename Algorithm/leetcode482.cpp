#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = 0;
        string ans;
        for (auto& c : s) {
            if (c != '-') {
                n++;
                if (c >= 'a' && c <= 'z')
                    ans += 'A' + (c - 'a');
                else ans += c;
            }
        }

        int divide = n / k;
        int mod =n % k;

        string res;
        int i = 0;
        if (mod != 0) {
            res += ans.substr(i, mod);
            res += '-';
            i += mod;
        }
        while (i < n) {
            
            res += ans.substr(i, k);
            res += '-';
            i += k;
        }
        if (res.back() == '-')
            res.erase(res.size()-1);
        return res;
    }
};