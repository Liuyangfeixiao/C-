#include <iostream>
#include <vector>
using namespace std;

bool backtrack(vector<int>& list, string S, int len, int index, long long sum, int prev) {
    if (index == len) return list.size() >= 3;
    long long curr = 0;
    for (int i = index; i < len; i++) {
        if (i > index && S[index] == '0')
            break;
        curr = curr * 10 + S[i] - '0';
        if (curr > INT32_MAX)
            break;
        if (list.size() >= 2) {
            if (curr < sum) 
                continue;
            else if (curr > sum) break;

        }
        list.push_back(curr);
        if (backtrack(list, S, S.length(), i+1, prev+curr, curr))
            return true;
        list.pop_back();
    }
    return false;
}

vector<int> splitIntoFibonacci(string S) {
    if (S.size() == 0) return {};
    vector<int> list;
    backtrack(list, S, S.length(), 0, 0, 0);
    return list;


}