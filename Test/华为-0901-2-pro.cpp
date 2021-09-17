/*
 * @Author: your name
 * @Date: 2021-09-16 20:36:36
 * @LastEditTime: 2021-09-16 20:36:57
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \CodingTraining\Test\华为-0901-2.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, string> sonToParent;
    unordered_set<string> instance;
    
    string s1, s2, s3;
    for(int i = 0; i < n; ++i) {
        cin >> s1 >> s2 >> s3;
        if(s2 == "instanceOf") {
            instance.insert(s1);
        }
        sonToParent[s1] = s3;
    }
    string root;
    set<string> ret;
    cin >> root;
    for(auto leaf : instance) {
        string node = leaf;
        while(sonToParent.count(node)) {
            if(sonToParent[node] == root) {
                ret.insert(leaf);
                break;
            }
            node = sonToParent[node];
        }
    }
    if(ret.empty())
        cout << "empty" << endl;
    else {
        int i = 0;
        for(auto r : ret) {
            if(i == 0)
                cout << r;
            else
                cout << " " << r;
            ++i;
        }
    }
    return 0;
}