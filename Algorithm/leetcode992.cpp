#include <iostream>
#include <vector>
using namespace std;
/**
 * K 个不同整数的子数组数量，
 * 可以用最多 K 个不同整数数组 减去 最多 K - 1 个不同整数数组的数量得到
 */

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> nums1(n+1), nums2(n+1); // 哈希表
        int tot1 = 0, tot2 = 0;
        int l1 = 0, l2 = 0, r = 0;
        int res = 0;
        while (r < n) {
            if (!nums1[A[r]]) tot1++;
            nums1[A[r]]++;

            if (!nums2[A[r]]) tot2++;
            nums2[A[r]]++;

            while (tot1 > K) {
                nums1[A[l1]]--;
                if (!nums1[A[l1]]) tot1--;
                l1++;
            }

            while (tot2 > K - 1) {
                nums2[A[l2]]--;
                if (!nums2[A[l2]]) tot2--;
                l2++;
            }

            res += l2 - l1;
            r++;
        }
        return res;
    }
};