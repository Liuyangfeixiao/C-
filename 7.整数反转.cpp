class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > __INT_MAX__/10 || (rev == __INT_MAX__ / 10 && pop > 7)) return 0;
            if (rev < __WINT_MIN__/10 || (rev == __WINT_MIN__ / 10 && pop < -8)) return 0;    //自检溢出
            rev = rev * 10 + pop;
        }
        return rev;
    }
};