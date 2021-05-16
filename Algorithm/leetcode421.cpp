#include <iostream>
#include <vector>
using namespace std;

struct Tries {
    Tries* left = nullptr;
    Tries* right = nullptr;
    Tries(){}
};

class Solution {
private:
    Tries* root = new Tries();
    static constexpr int HIGH = 30;
public:
    void add(int num) {
        Tries* cur = root;
        for (int k = HIGH; k >= 0; k--) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = new Tries();
                }
                cur = cur->left;
            }
            else {
                if (!cur->right) {
                    cur->right = new Tries();
                }
                cur = cur->right;
            }
        }
    }
    int check(int num) {
        int x = 0;
        Tries* cur = root;
        for (int k = HIGH; k >= 0; k--) {
            int bit = (num>>k) & 1;
            if (bit == 0) {
                if (cur->right) {
                    cur = cur->right;
                    x = x * 2 + 1;
                }
                else {
                    cur = cur->left;
                    x = x * 2;
                }
            }
            else {
                if (cur->left) {
                    cur = cur->left;
                    x = x * 2 + 1;
                }
                else {
                    cur = cur->right;
                    x = x * 2;
                }
            }
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            add(nums[i-1]);
            x = max(x, check(nums[i]));
        }
        return x;
    }
};