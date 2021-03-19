#include <iostream>
#include <vector>
using namespace std;

// 双指针，两个边界小的一边遍历
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int area = 0;
        while (left < right) {
            int level = min(height[left], height[right]);
            area = max(area, (right - left) * level);
            if (height[left] > height[right]) right--;
            else left++;
        }
        return area;
    }
};