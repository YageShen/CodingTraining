class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_ii_0 = 0, dp_ii_1 = -prices[0]; // 第一天
        if (prices.size() == 1)
            return dp_ii_0;
        int dp_i_0 = max(dp_ii_0, dp_ii_1 + prices[1]); // 第二天
        int dp_i_1 = max(dp_ii_1, -prices[1]);
        if (prices.size() == 2)
            return dp_i_0;

        for(int i = 2; i < prices.size(); ++i) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_ii_0 - prices[i]);
            dp_ii_0 = temp;
        }
        return dp_i_0;
    }
};