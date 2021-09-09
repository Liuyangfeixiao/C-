#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string str;
        vector<int> index;

        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (str.size() + words[i].size() < maxWidth) {
                str += words[i];
                index.push_back(str.size());
                str += ' ';
            }
            else if (str.size() + words[i].size() == maxWidth) {
                str += words[i];
                ans.push_back(str);
                str.clear();
                index.clear();
            }
            else {
                int space = maxWidth - str.size();
                if (index.size() > 1) {
                    str.erase(index.back(), 1);
                    index.pop_back();
                    space++;
                }
                
                int avg = 0, addit = 0;
                avg = space / index.size();
                addit = space % index.size();

                for (int j = index.size(); j >= 0; j--) {   // 倒序插入避免 index 因为新插入的字符出错
                    str.insert(index[j], string(avg + (j < addit ? 1 : 0), ' '));
                }

                ans.push_back(str);
                str.clear();
                index.clear();
                --i;
            }
        }

        if (!str.empty()) {
            if (str.size() < maxWidth) {
                str += string(maxWidth - str.size(), ' ');
            }
            ans.push_back(str);
        }

        return ans;
    }
};