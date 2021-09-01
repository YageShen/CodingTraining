class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};