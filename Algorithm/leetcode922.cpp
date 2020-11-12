#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArray(vector<int>& A) {
    int j = 1;
    for (int i = 0; i < A.size()-1; i += 2) {
        if ((A[i] & 1) != 0) {
            while ((A[j] & 1) != 0)
                j = j + 2;
            swap(A[i], A[j]);
        }
    }
    return A;
}