class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0)
            return 0;
        vector<vector<int>> dp_ik(k, vector<int>(2, 0));
        for(int i = 0; i < k; ++i)
            dp_ik[i][1] = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            for(int j = k - 1; j >= 1; --j) {
                dp_ik[j][0] = max(dp_ik[j][0], dp_ik[j][1] + prices[i]);
                dp_ik[j][1] = max(dp_ik[j][1], dp_ik[j - 1][0] - prices[i]);
            }
            dp_ik[0][0] = max(dp_ik[0][0], dp_ik[0][1] + prices[i]);
            dp_ik[0][1] = max(dp_ik[0][1], -prices[i]);
        }
        return dp_ik[k-1][0];
    }
};