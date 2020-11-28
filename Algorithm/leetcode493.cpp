#include <iostream>
#include <vector>
using namespace std;


/**
 * 
 * 暴力算法时间超时
 * 
*/

// int reversePairs(vector<int>& nums) {
//     int n = nums.size();
//     if (n == 0) {
//         return 0;
//     }

//     int count = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             if (nums[i] > 2 * nums[j]) count++;
//         }
//     }

//     return count;
// }


/*尝试归并排序*/

/*不能直接在归并排序中计算翻转对的个数，这样会漏掉某些元素*/

int findCount(vector<int>& q, int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    int i = l, j = mid + 1;
    int ans = 0;
    while (i <= mid) {
        while (j <= r && (long)q[i] > 2 * (long) q[j]) {
            ans += mid - i + 1;
            j++;
        }
        i++;
    }
    return ans;
}

int mergeSort(vector<int>& q, int l, int r, int tmp[]) { // 不能直接在函数中开辟新的数组，否则时间会超时
    if (l >= r) return 0;
    int mid = l + r >> 1, k = l;
    int i = l, j = mid + 1;
    int res = mergeSort(q, l, mid,tmp) + mergeSort(q, mid + 1, r, tmp) + findCount(q, l, r);
    //vector<int> tmp(q.size());
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }

    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (int i = l; i <= r; i++) {
        q[i] = tmp[i];
    }

    return res;
}

int reversePairs(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int n = nums.size();
    int *tmp = new int[n];
    memset(tmp, 0, sizeof(tmp));
    return mergeSort(nums, 0, nums.size() - 1, tmp);
}