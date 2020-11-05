#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int ladderLength(string beginword, string endword, vector<string>& wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    if (wordDict.find(endword) == wordDict.end())
        return 0;
    unordered_set<string> beginSet{beginword};
    unordered_set<string> endSet{endword};
    int step = 1;
    while (!beginSet.empty())
    {
        unordered_set<string> tempSet;
        ++step;
        for (auto s : beginSet)
        {
            wordDict.erase(s);
        }
        
        for ( auto s : beginSet)
        {
            /* code */
            for (int i = 0; i < s.size(); ++i) {
                string str = s;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    str[i] = c;
                    if (wordDict.find(str) == wordDict.end())
                    {
                        continue;
                    }
                    if (endSet.find(str) != endSet.end()) {
                        return step;
                    }
                    tempSet.insert(str);
                }
                
            }
        }
        if (tempSet.size() < endSet.size())
        {
            beginSet = tempSet;
        }
        else
        {
            beginSet = endSet;
            endSet = tempSet;
        }
        
    }
    return 0;
    
}