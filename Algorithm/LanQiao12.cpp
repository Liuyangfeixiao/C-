#include <iostream>
#include <algorithm>
using namespace std;
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int n;
int main() {
    scanf("%d", &n);
    int cnt = 0;
    long long sum1, sum2, sum3;
    do {
        
        for (int i = 1; i <= 7; ++i) {
            for (int j = 1; j <= 8 - i; j++) {
                sum1 = sum2 = sum3 = 0;
                int q = 0;
                for (int k = 0; k < i; ++k) {
                    sum1 += sum1 * 10 + a[q];
                    q++;
                }
                for (int k = 0; k < j; ++k) {
                    sum2 += sum2 * 10 + a[q];
                    q++;
                }
                for (int k = 0; k <= 8 - i - j; ++k) {
                    sum3 += sum3 * 10 + a[q];
                    q++;
                }

                if (n == sum1 + 1.0 *sum2/sum3) cnt++;
            }
        }
    } while (next_permutation(a, a + 9));

    printf("%d", cnt);
    return 0;
}