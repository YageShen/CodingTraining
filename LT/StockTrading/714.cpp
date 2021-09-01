class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_i_0 = 0, dp_i_1 = - prices[0] - fee;
        for(int i = 0; i < prices.size(); ++i) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
        }
        return dp_i_0;
    }
};