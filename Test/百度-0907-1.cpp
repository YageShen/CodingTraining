/*
 * @Author: your name
 * @Date: 2021-09-07 22:05:32
 * @LastEditTime: 2021-09-07 22:05:57
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \CodingTraining\Test\百度-0907-1.cpp
 */
#include<bits/stdc++.h>
using namespace std;

int main (){
    int n = 0, k = 0, num = 0;
    cin>>n>>k;
    vector<vector<int>> nums(n, vector<int> (n, 0));;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>num;
            nums[i][j] = num;
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for(int ii = 0; ii < k; ++ii) {
            for (int j = 0; j < n; ++j){
                for(int jj = 0; jj < k; ++jj) {
                    cout << nums[i][j] << ' ';
                }
            }
            cout << endl;
        }
    }
    return 0;
}