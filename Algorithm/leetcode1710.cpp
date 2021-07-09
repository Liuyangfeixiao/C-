// find-majority-element
// 摩尔投票法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candi = -1;
        int cnt = 0;
        for (int& x : nums) {
            
            if (cnt == 0) {
                candi = x;
            }
            if (candi == x) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        return (count(nums.begin(), nums.end(), candi)) > nums.size() / 2 ? candi : -1;        
    }
};