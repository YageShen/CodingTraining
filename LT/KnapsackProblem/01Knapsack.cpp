// N个物品， W空间， 每个物品占用空间为vector<int> wt，每个物品的价值为vector<int> val，使总价值最大

class Solution {
    int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= W; ++j) {
                dp[i][j] = j >= wt[i-1] ? max(dp[i-1][j], dp[i-1][j-w[i-1]] + val[i-1]) : dp[i-1][j];
            }
        }
        return dp[N][W];
    }

};