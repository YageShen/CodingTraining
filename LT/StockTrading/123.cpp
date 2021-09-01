class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i11 = -prices[0], dp_i10 = 0;
        int dp_i20 = 0, dp_i21 = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            dp_i20 = max(dp_i20, dp_i21 + prices[i]);
            dp_i21 = max(dp_i21, dp_i10 - prices[i]);
            dp_i10 = max(dp_i10, dp_i11 + prices[i]);
            dp_i11 = max(dp_i11, -prices[i]);
        }
        return dp_i20;
    }
};