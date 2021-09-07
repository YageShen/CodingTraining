/*
 * @Author: your name
 * @Date: 2021-09-07 22:06:10
 * @LastEditTime: 2021-09-07 22:06:28
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \CodingTraining\Test\百度-0907-2.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int num = 0;
        int a = 1, b = N;
        for(int i = 1; i <= sqrt(N); ++i) {
            if(N % i == 0) {
                int a = i, b = N / a;
                if(a >= b) break;
                if(__gcd(a, b) == 1) num++;
            }
        }
        cout << num << endl;
    }
}