// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int k, a;
// vector<vector<int>> cap(41, vector<int>(2)); //节点能力数组，发送能力，存储能力
// int res;

// vector<int> dpfun(vector<int> pre, vector<int> cap) {
//     int out1 = min(pre[0], cap[0]);
//     int cache = pre[0] - cap[0] > 0 ? min(cap[1], pre[0] - cap[0]) : 0;
//     int out2 = min(cap[0], cache + pre[1]);
//     // int send1 = min(pre[0], cap[0]);//第一次发送的数据包量
//     // int send2 = min(cap[0], pre[1] + cap[1]);//第二次发送的数据包量
//     // if (pre[0] - cap[0] > 0) 
//     //     send2 = min(pre[0] - cap[0] + pre[1], send2);//如果缓存没存满，并且缓存大于0
//     // else 
//     //     send2 = min(send2, pre[1]);        //缓存=0；
//     vector<int> r = {out1, out2};
//     return r;
// }

// int main() {
//     cin >> k;
//     vector<vector<int>> dp(k+1, vector<int>(2));//代表第i个节点发送的数据包数
//     char c;
//     for (int i = 1; i <= k; i++) {
//         cin >> cap[i][0] >> c >> cap[i][1];
//     }
//     cin >> a;

//     dp[0][0] = a;//第0个节点第一次发送a
//     dp[0][1] = 0;//第二次发送0；

//     dp[1] = dpfun(dp[0], cap[1]);
//     res = min(dp[0][0] + dp[0][1], dp[1][0] + dp[1][1]);//如果只有一个节点，那么选择是故障还是不故障多
//     if (k == 0) {
//         cout << a;
//     }
//     else {
//         for (int i = 2; i <= k; i++) {
//             vector<int> res1 = dpfun(dp[i - 1], cap[i]);//前一个点没有故障
//             vector<int> res2 = dpfun(dp[i - 2], cap[i]);//前一个点故障
//             dp[i] = res1[0] + res1[1] <= res2[0] + res2[1] ? res1 : res2;//选择值最小的方案
//         }
//         res = min(dp[k][0] + dp[k][1], dp[k - 1][0] + dp[k - 1][1]);
//     }
//     cout << res;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dpfun(vector<int>& pre, vector<int>& cap) {
    int out1 = min(pre[0], cap[0]);
    int cache = pre[0] - cap[0] > 0 ? min(cap[1], pre[0] - cap[0]) : 0;
    int out2 = min(cap[0], cache + pre[1]);
    vector<int> r = {out1, out2};
    return r;
}

int main() {
    int k;
    cin >> k;
    vector<vector<int>> nodes(k+1, vector<int>(2)); // 第i个节点的转发和存储能力
    vector<vector<int>> dp(k+1, vector<int>(2)); // 第i个节点两次发送的数据
    for(int i = 1; i <= k; ++i) {
        char c;
        cin >> nodes[i][0] >> c >> nodes[i][1];
    }
    int a;
    cin >> a;
    if(k <= 1)
        cout << 0 << endl;
    else {
        dp[0][0] = a; dp[0][1] = 0;
        dp[1] = dpfun(dp[0], nodes[1]);
        for(int i = 2; i <= k; ++i) {
            vector<int> res1 = dpfun(dp[i-2], nodes[i]); // 前一个节点故障
            vector<int> res2 = dpfun(dp[i-1], nodes[i]); // 
            dp[i] = res1[0] + res1[1] < res2[0] + res2[1] ? res1 : res2;
        }
        cout << min(dp[k][0] + dp[k][1], dp[k-1][0] + dp[k-1][1]) << endl;
    }

    return 0;
}