#include <bits/stdc++.h>

using namespace std;

// 工作安排
int main() {
    int n;
    cin >> n;
    vector<int> endTime(n);
    vector<int> val(n);
    for(int i = 0; i < n; ++i)
        cin >> endTime[i] >> val[i];
    int max_time = 0;
    for(int i = 0; i < n; ++i)
        max_time = max(max_time, endTime[i]);
    max_time /= 10;
    vector<vector<int>> dp(max_time+1, vector<int>(n+1, 0));
    for(int i = max_time - 1; i >= 0; --i) {
        for(int j = 1; j <= n; ++j) {
            if(i * 10 <= endTime[j-1]) {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j-1] + val[j-1]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}