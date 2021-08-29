#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool outRange(int i, int j, int rows, int cols) {
    return i < 0 || i >= rows || j < 0 || j >= cols;
}

void printMat(vector<vector<int>>& mat) {
    for(int i = 0; i < mat.size(); ++ i) {
        for(int j = 0; j < mat[0].size(); ++j) 
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    int step = rows * cols / 2;
    
    // move a
    int a_r = 0, a_c = 0, move_state_a = 0;
    for(int i = 0; i < step; ++i) {
        mat[a_r][a_c] = i * 2 + 1;
        if(move_state_a == 0) {
            if(outRange(a_r-1, a_c+1, rows, cols)) {
                if(outRange(a_r, a_c+1, rows, cols))
                    a_r += 1;
                else
                    a_c += 1;
                move_state_a = 1;
            }
            else {
                a_c += 1;
                a_r -= 1;
            }
        }
        else {
            if(outRange(a_r+1, a_c-1, rows, cols)) {
                if(outRange(a_r+1, a_c, rows, cols))
                    a_c += 1;
                else
                    a_r += 1;
                move_state_a = 0;
            }
            else {
                a_r += 1;
                a_c -= 1;
            }
        }
    }
    
    // move b
    int b_r = rows - 1, b_c = cols - 1, move_state_b = 0;
    for(int i = 1; i <= step; ++i) {
        mat[b_r][b_c] = i * 2;
        if(move_state_b == 0) {
            if(outRange(b_r+1, b_c-1, rows, cols)) {
                if(outRange(b_r, b_c-1, rows, cols))
                    b_r -= 1;
                else
                    b_c -= 1;
                move_state_b = 1;
            }
            else {
                b_c -= 1;
                b_r += 1;
            }
        }
        else {
            if(outRange(b_r-1, b_c+1, rows, cols)) {
                if(outRange(b_r-1, b_c, rows, cols))
                    b_c -= 1;
                else
                    b_r -= 1;
                move_state_b = 0;
            }
            else {
                b_r -= 1;
                b_c += 1;
            }
        }
    }
    printMat(mat);
    return 0;
}