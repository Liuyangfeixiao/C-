#include <iostream>
#include <vector>
using namespace std;

/* from inside to outside*/
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-i-1] = tmp;
        }
    }
}

/*先转置，再翻转*/
/*顺时针90度为先沿着主对角线转置，再沿着垂直轴翻转*/
void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
}

/*逆时针90度为先沿着主对角线转置，再沿着水平线翻转*/
void rotate3(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
}

/*逆时针旋转180度*/
/*先水平翻转，后垂直翻转*/
void rotate4(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
}