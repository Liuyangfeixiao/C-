#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> commonChars(vector<string>& A) {
    // 26 个字母的映射
    int count[26] = {0};
    int len = A.size();
    vector<string> ans; //最后返回的结果
    // count 保留每个字符出现在字符串中最少的次数
    for (char x : A[0]){
            count[x - 'a'] += 1;
        }
    for (int i = 0; i < len; i++){
        int min_count[26] = {0};
        for (char x : A[i]){
            min_count[x - 'a'] += 1;
        }
        for (int j = 0; j < 26; j++){
            count[j] = min(count[j], min_count[j]);
        }

    }

    // 将每个字符串插入向量中

    for (int i = 0; i < 26; i++){
        for (int j = 0; j < count[i]; j++){
            string temp = "";
            temp += (char)('a'+i);
            ans.push_back(temp);
        }
    }

    return ans;



}

