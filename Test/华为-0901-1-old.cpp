/*
 * @Author: your name
 * @Date: 2021-09-21 15:29:46
 * @LastEditTime: 2021-09-21 15:47:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CodingTraining\Test\华为-0901-1-old.cpp
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> nodes(k, vector<int>(2));
    for(int i = 0; i < k; ++i) {
        char ch;
        cin >> nodes[i][0] >> ch >> nodes[i][1];
    }
    int a;
    cin >> a;
    int out1 = a;
    vector<int> cache(k);
    for(int i = 0; i < k; ++i) {
        int in1 = out1;
        out1 = in1 > nodes[i][0] ? nodes[i][0] : in1;
        cache[i] = in1 - out1 > nodes[i][1] ? nodes[i][1] : (in1 - out1);
    }

    int out2 = 0;
    for(int i = 0; i < k; ++i) {
        out2 = out2 + cache[i] > nodes[i][0] ? nodes[i][0] : (out2 + cache[i]);
    }
    
    return out1 + out2;
}
