#include<iostream>
#include<vector>

using namespace std;

/*荷兰国旗问题
* 使用三分快速排序
* 快速排序思想的简单应用
*/
void sortColors(vector<int>& nums){
    int bench = -1; // 基准
    int low = 0;
    int high = nums.size();
    while (low < high)
    {
        /* code */
        if (nums[low] == 0){
            swap(nums[++bench], nums[low++]);
        }
        else if (nums[low] == 2)
        {
            /* code */
            swap(nums[low], nums[--high]);
        }
        else
        {
            low++;
        }
        
        
    }
    

}

