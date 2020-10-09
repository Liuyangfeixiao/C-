/*
* leetcode344
* 反转字符串
*/

#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int low = 0;
    int high = s.size() - 1;
    while (low < high){

        swap(s[low++], s[high--]);
    }
        
}
